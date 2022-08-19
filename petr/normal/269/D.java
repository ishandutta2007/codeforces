import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static class Panel implements Comparable<Panel> {
        int left;
        int right;
        int height;
        int bestFlow = 0;

        public int compareTo(Panel o) {
            return o.height - height;
        }
    }

    static class Tree {
        Tree left;
        Tree right;
        long heapBy;
        int l;
        int r;
        int original;
        int thisOriginal;
        Panel src;

        public Tree leftmost() {
            if (left == null) return this;
            return left.leftmost();
        }

        public Tree rightmost() {
            if (right == null) return this;
            return right.rightmost();
        }

        public int getBestOriginal(boolean skipLeftmost, boolean skipRightmost) {
            if (!skipLeftmost && !skipRightmost)
                return original;
            int res = 0;
            if ((!skipLeftmost || left != null) && (!skipRightmost || right != null))
                res = Math.max(res, thisOriginal);
            if (left != null) res = Math.max(res, left.getBestOriginal(skipLeftmost, false));
            if (right != null) res = Math.max(res, right.getBestOriginal(false, skipRightmost));
            return res;
        }

        public void updateOriginal() {
            original = 0;
            thisOriginal = 0;
            if (src.left == l && src.right == r) {
                thisOriginal = Math.min(r - l, src.bestFlow);
                original = thisOriginal;
            }
            if (left != null) {
                original = Math.max(original, left.original);
            }
            if (right != null) {
                original = Math.max(original, right.original);
            }
        }
    }

    TreePair split(Tree root, int middle) {
        if (root == null) {
            return new TreePair();
        }
        if (root.r <= middle) {
            TreePair pair = split(root.right, middle);
            root.right = pair.left;
            root.updateOriginal();
            pair.left = root;
            return pair;
        } else {
            TreePair pair = split(root.left, middle);
            root.left = pair.right;
            pair.right = root;
            return pair;
        }
    }

    TreePair split2(Tree root, int middle) {
        if (root == null) {
            return new TreePair();
        }
        if (root.l < middle) {
            TreePair pair = split2(root.right, middle);
            root.right = pair.left;
            root.updateOriginal();
            pair.left = root;
            return pair;
        } else {
            TreePair pair = split2(root.left, middle);
            root.left = pair.right;
            root.updateOriginal();
            pair.right = root;
            return pair;
        }
    }

    static class TreePair {
        Tree left;
        Tree right;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int t = in.nextInt();
        Panel top = new Panel();
        top.left = (int) -1e9;
        top.right = (int) 1e9;
        top.height = t;
        top.bestFlow = top.right - top.left;
        Panel[] all = new Panel[n + 2];
        all[0] = top;
        Panel bottom = new Panel();
        bottom.left = (int) -1e9;
        bottom.right = (int) 1e9;
        bottom.height = 0;
        all[1] = bottom;
        for (int i = 2; i < all.length; ++i) {
            all[i] = new Panel();
            all[i].height = in.nextInt();
            all[i].left = in.nextInt();
            all[i].right = in.nextInt();
        }
        doit(all);
        out.println(bottom.bestFlow);
    }

    private void doit(Panel[] all) {
        Random r = new Random(System.currentTimeMillis() + 321479371);

        for (int i = 0; i < all.length; ++i) {
            int j = i + r.nextInt(all.length - i);
            Panel tmp = all[j];
            all[j] = all[i];
            all[i] = tmp;
        }
        Arrays.sort(all);
        Tree root = null;
        for (Panel p : all) {
            Tree cur = new Tree();
            cur.l = p.left;
            cur.r = p.right;
            cur.src = p;
            cur.heapBy = r.nextLong();
            cur.updateOriginal();
            if (root == null) {
                root = cur;
                continue;
            }
            TreePair s1 = split(root, cur.l);
            TreePair s2 = split2(s1.right, cur.r);
            Tree untouchedLeft = s1.left;
            Tree untouchedRight = s2.right;
            Tree interesting = s2.left;
            if (interesting.left == null && interesting.right == null) {
                p.bestFlow = Math.max(p.bestFlow, Math.min(p.right - p.left, interesting.src.bestFlow));
                cur.updateOriginal();
                Tree res = untouchedLeft;
                if (interesting.l < cur.l) {
                    Tree nxt = new Tree();
                    nxt.l = interesting.l;
                    nxt.r = cur.l;
                    nxt.src = interesting.src;
                    nxt.heapBy = r.nextLong();
                    nxt.updateOriginal();
                    res = merge(res, nxt);
                }
                res = merge(res, cur);
                if (cur.r < interesting.r) {
                    interesting.l = cur.r;
                    interesting.updateOriginal();
                    res = merge(res, interesting);
                }
                res = merge(res, untouchedRight);
                root = res;
            } else {
                Tree lt = interesting.leftmost();
                if (lt.r == lt.src.right) {
                    p.bestFlow = Math.max(p.bestFlow, Math.min(lt.r - p.left, lt.src.bestFlow));
                }
                Tree rt = interesting.rightmost();
                if (rt.l == rt.src.left) {
                    p.bestFlow = Math.max(p.bestFlow, Math.min(p.right - rt.l, rt.src.bestFlow));
                }
                p.bestFlow = Math.max(p.bestFlow, interesting.getBestOriginal(true, true));
                cur.updateOriginal();
                if (lt.l < cur.l) {
                    lt.left = null;
                    lt.right = null;
                    lt.r = cur.l;
                    lt.updateOriginal();
                    untouchedLeft = merge(untouchedLeft, lt);
                }
                if (cur.r < rt.r) {
                    rt.left = null;
                    rt.right = null;
                    rt.l = cur.r;
                    rt.updateOriginal();
                    untouchedRight = merge(rt, untouchedRight);
                }
                root = merge(untouchedLeft, merge(cur, untouchedRight));
            }
        }
    }

    private Tree merge(Tree left, Tree right) {
        if (left == null) return right;
        if (right == null) return left;
        if (left.heapBy > right.heapBy) {
            left.right = merge(left.right, right);
            left.updateOriginal();
            return left;
        } else {
            right.left = merge(left, right.left);
            right.updateOriginal();
            return right;
        }
    }

    }

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }
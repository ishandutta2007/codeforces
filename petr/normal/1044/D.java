import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.HashMap;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int numQueries = in.nextInt();
            Map<Integer, TaskD.Item> seen = new HashMap<>();
            int last = 0;
            for (int qi = 0; qi < numQueries; ++qi) {
                int t = in.nextInt();
                if (t == 1) {
                    int l = in.nextInt();
                    int r = in.nextInt();
                    int x = in.nextInt();
                    l ^= last;
                    r ^= last;
                    x ^= last;
                    if (l > r) {
                        int tmp = l;
                        l = r;
                        r = tmp;
                    }
                    ++r;
                    TaskD.Item left = seen.get(l);
                    if (left == null) {
                        left = new TaskD.Item();
                        seen.put(l, left);
                    }
                    TaskD.Item right = seen.get(r);
                    if (right == null) {
                        right = new TaskD.Item();
                        seen.put(r, right);
                    }
                    left.compress();
                    right.compress();
                    TaskD.Item lp = left.parent;
                    TaskD.Item rp = right.parent;
                    if (lp != rp) {
                        lp.parent = rp;
                        lp.xorToParent = x ^ left.xorToParent ^ right.xorToParent;
                    }
                } else if (t == 2) {
                    int l = in.nextInt();
                    int r = in.nextInt();
                    l ^= last;
                    r ^= last;
                    if (l > r) {
                        int tmp = l;
                        l = r;
                        r = tmp;
                    }
                    ++r;
                    TaskD.Item left = seen.get(l);
                    TaskD.Item right = seen.get(r);
                    if (left == null || right == null) {
                        last = -1;
                    } else {
                        left.compress();
                        right.compress();
                        if (left.parent != right.parent) {
                            last = -1;
                        } else {
                            last = left.xorToParent ^ right.xorToParent;
                        }
                    }
                    out.println(last);
                    if (last == -1) last = 1;
                } else throw new RuntimeException();
            }
        }

        static class Item {
            TaskD.Item parent;
            int xorToParent;

            public Item() {
                parent = this;
                xorToParent = 0;
            }

            public void compress() {
                TaskD.Item root = this;
                int xorToRoot = 0;
                while (root.parent != root) {
                    xorToRoot ^= root.xorToParent;
                    root = root.parent;
                }
                TaskD.Item cur = this;
                while (cur.parent != root) {
                    TaskD.Item next = cur.parent;
                    int xorToNext = cur.xorToParent;
                    cur.parent = root;
                    cur.xorToParent = xorToRoot;
                    xorToRoot ^= xorToNext;
                    cur = next;
                }
                if (xorToRoot != cur.xorToParent) {
                    throw new RuntimeException();
                }
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
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
}
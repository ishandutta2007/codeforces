import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collections;
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
    static class Segment {
        int kind;
        int left;
        int right;
        int v;

        Segment(int kind, int left, int right) {
            this.kind = kind;
            this.left = left;
            this.right = right;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int m = in.nextInt();
        int[] b = new int[m];
        for (int i = 0; i < m; ++i) b[i] = in.nextInt();
        int max = 0;
        for (int x : b) max = Math.max(max, x);
        int cnt = 0;
        int[] last = new int[max + 1];
        int[] plast = new int[max + 1];
        int[] beforep = new int[max + 1];
        int[] prev = new int[m + 1];
        int[] cover3 = new int[max + 1];
        int[] cover2 = new int[max + 1];
        int[] cover1 = new int[max + 1];
        Arrays.fill(plast, -1);
        Arrays.fill(last, -1);
        Arrays.fill(beforep, -1);
        Arrays.fill(cover3, -1);
        Arrays.fill(cover2, -1);
        Arrays.fill(cover1, -1);
        List<Segment> all = new ArrayList<Segment>();
        for (int i = 0; i < m; ++i) {
            int v = b[i];
            prev[i] = last[v];
            if (last[v] < 0) {
                ++cnt;
                all.add(new Segment(1, 0, i - 1));
            } else {
                all.add(new Segment(1, last[v] + 1, i - 1));
                if (plast[v] >= 0 && last[v] - plast[v] != i - last[v]) {
                    Segment seg = new Segment(2, beforep[v] + 1, i - 1);
                    all.add(seg);
                    seg.v = v;
                    int now = beforep[v];
                    if (cover1[v] < now) {
                        addNice(prev, now, cover1[v], all, v);
                        cover1[v] = now;
                    }
                    if (cover2[v] < now) {
                        addNice(prev, now, cover2[v], all, v);
                        cover2[v] = now;
                    }
                    if (cover3[v] < now) {
                        addNice(prev, now, cover3[v], all, v);
                        cover3[v] = now;
                    }
                    cover3[v] = cover2[v];
                    cover2[v] = cover1[v];
                    cover1[v] = i;
                    beforep[v] = plast[v];
                }
            }
            plast[v] = last[v];
            last[v] = i;
        }
        for (int v = 0; v <= max; ++v)
            if (last[v] >= 0) {
                all.add(new Segment(1, last[v] + 1, m - 1));
                Segment seg = new Segment(2, beforep[v] + 1, m - 1);
                all.add(seg);
                seg.v = v;
                int now = beforep[v];
                if (cover1[v] < now) {
                    addNice(prev, now, cover1[v], all, v);
                    cover1[v] = now;
                }
                if (cover2[v] < now) {
                    addNice(prev, now, cover2[v], all,v );
                    cover2[v] = now;
                }
                if (cover3[v] < now) {
                    addNice(prev, now, cover3[v], all, v);
                    cover3[v] = now;
                }
                cover3[v] = cover2[v];
                cover2[v] = cover1[v];
                cover1[v] = m;
                prev[m] = last[v];
                now = m;
                if (cover1[v] < now) {
                    addNice(prev, now, cover1[v], all,v );
                    cover1[v] = now;
                }
                if (cover2[v] < now) {
                    addNice(prev, now, cover2[v], all,v );
                    cover2[v] = now;
                }
                if (cover3[v] < now) {
                    addNice(prev, now, cover3[v], all,v);
                    cover3[v] = now;
                }
            }
        int q = in.nextInt();
        Segment[] req = new Segment[q];
        for (int i = 0; i < q; ++i) {
            int left = in.nextInt() - 1;
            int right = in.nextInt() - 1;
            req[i] = new Segment(3 + i, left, right);
            all.add(req[i]);
        }
        int[] answer = new int[q];
        Collections.sort(all, new Comparator<Segment>() {
            @Override
            public int compare(Segment o1, Segment o2) {
                int z = o1.left - o2.left;
                if (z != 0) return z;
                return o1.kind - o2.kind;
            }
        });
        int[] anyTree = new int[m];
        int[] addTree = new int[m];
        for (Segment s : all) {
            if (s.left > s.right) continue;
            if (s.kind == 1) {
                updatetree(addTree, 0, 1);
                updatetree(addTree, s.right + 1, -1);
            } else if (s.kind == 2) {
                updatetree(anyTree, 0, 1);
                updatetree(anyTree, s.right + 1, -1);
            } else {
                /*for (Segment ss : all) {
                    if (ss.kind == 2 && ss.left <= s.left && ss.right >= s.right) {
                        System.out.println(ss.left + 1 + " " + (ss.right + 1) + " " + ss.v);
                    }

                } */
                int res = cnt + 1;
                int delta = gettree(addTree, s.right);
                res -= delta;
                if (gettree(anyTree, s.right) > 3 * delta) --res;
                answer[s.kind - 3] = res;
            }
        }
        for (int x : answer) out.println(x);
    }

    private void addNice(int[] prev, int last, int first, List<Segment> all, int v) {
        while (last > first) {
            Segment seg = new Segment(2, prev[last] + 1, last - 1);
            seg.v = v;
            all.add(seg);
            last = prev[last];
        }
    }

    private int gettree(int[] addTree, int at) {
        int s = 0;
        while (at >= 0) {
            s += addTree[at];
            at = (at & (at + 1)) - 1;
        }
        return s;
    }

    private void updatetree(int[] addTree, int at, int by) {
        while (at < addTree.length) {
            addTree[at] += by;
            at |= (at + 1);
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

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
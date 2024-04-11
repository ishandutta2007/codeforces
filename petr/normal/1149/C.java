import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final int INF = (int) 1e8;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            String str = in.next();
            char[] s = str.toCharArray();
            int[] balance = new int[s.length + 1];
            for (int i = 0; i < s.length; ++i) {
                balance[i + 1] = balance[i] + (s[i] == '(' ? 1 : -1);
            }
            TaskC.Tree t = new TaskC.Tree(balance);
            out.println(t.maxac2b[0]);
            for (int i = 0; i < q; ++i) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                if (a > b) {
                    int tt = a;
                    a = b;
                    b = tt;
                }
                if (s[a] != s[b]) {
                    if (s[a] == '(') {
                        t.upd(a + 1, b, -2);
                    } else {
                        t.upd(a + 1, b, 2);
                    }
                    char tc = s[a];
                    s[a] = s[b];
                    s[b] = tc;
                }
                out.println(t.maxac2b[0]);
            }
        }

        static class Tree {
            int[] maxac2b;
            int[] maxa;
            int[] maxa2b;
            int[] maxc2b;
            int[] max2b;
            int[] delta;
            int size;

            public Tree(int[] initial) {
                size = initial.length;
                maxac2b = new int[size * 4 + 10];
                maxa = new int[size * 4 + 10];
                maxa2b = new int[size * 4 + 10];
                maxc2b = new int[size * 4 + 10];
                max2b = new int[size * 4 + 10];
                delta = new int[size * 4 + 10];
                initTree(0, 0, size - 1, initial);
            }

            private void initTree(int root, int rl, int rr, int[] initial) {
                if (rl == rr) {
                    maxa[root] = initial[rl];
                    max2b[root] = -2 * initial[rl];
                    maxac2b[root] = 0;
                    maxa2b[root] = maxc2b[root] = -initial[rl];
                } else {
                    int rm = (rl + rr) >> 1;
                    initTree(root * 2 + 1, rl, rm, initial);
                    initTree(root * 2 + 2, rm + 1, rr, initial);
                    update(root);
                }
            }

            private void update(int root) {
                int c1 = root * 2 + 1;
                int c2 = root * 2 + 2;
                maxa[root] = -INF;
                max2b[root] = -INF;
                maxa2b[root] = -INF;
                maxc2b[root] = -INF;
                maxac2b[root] = -INF;
                maxa[root] = Math.max(maxa[root], maxa[c1]);
                maxa[root] = Math.max(maxa[root], maxa[c2]);
                max2b[root] = Math.max(max2b[root], max2b[c1]);
                max2b[root] = Math.max(max2b[root], max2b[c2]);
                maxac2b[root] = Math.max(maxac2b[root], maxac2b[c1]);
                maxac2b[root] = Math.max(maxac2b[root], maxac2b[c2]);
                maxa2b[root] = Math.max(maxa2b[root], maxa2b[c1]);
                maxa2b[root] = Math.max(maxa2b[root], maxa2b[c2]);
                maxc2b[root] = Math.max(maxc2b[root], maxc2b[c1]);
                maxc2b[root] = Math.max(maxc2b[root], maxc2b[c2]);
                maxa2b[root] = Math.max(maxa2b[root], maxa[c1] + max2b[c2]);
                maxc2b[root] = Math.max(maxc2b[root], max2b[c1] + maxa[c2]);
                maxac2b[root] = Math.max(maxac2b[root], maxa[c1] + maxc2b[c2]);
                maxac2b[root] = Math.max(maxac2b[root], maxa2b[c1] + maxa[c2]);
                maxa[root] += delta[root];
                max2b[root] -= 2 * delta[root];
                maxa2b[root] -= delta[root];
                maxc2b[root] -= delta[root];
            }

            public void upd(int left, int right, int by) {
                internalUpd(0, 0, size - 1, left, right, by);
            }

            private void internalUpd(int root, int rl, int rr, int left, int right, int by) {
                if (left > right) return;
                if (left == rl && right == rr) {
                    delta[root] += by;
                    maxa[root] += by;
                    max2b[root] -= 2 * by;
                    maxa2b[root] -= by;
                    maxc2b[root] -= by;
                    return;
                }
                int rm = (rl + rr) >> 1;
                internalUpd(root * 2 + 1, rl, rm, left, Math.min(rm, right), by);
                internalUpd(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right, by);
                update(root);
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
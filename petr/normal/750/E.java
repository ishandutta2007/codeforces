import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final int INF = (int) 1e9;
        public static final int STATES = 6;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            String s = in.next();
            int[] tree = new int[STATES * STATES * (4 * n + 4)];
            initTree(tree, 0, 0, n - 1, s);
            for (int i = 0; i < q; ++i) {
                int left = in.nextInt() - 1;
                int right = in.nextInt() - 1;
                int[] best = new int[STATES];
                Arrays.fill(best, INF);
                best[0] = 0;
                int[] tmp = new int[STATES];
                getTree(tree, 0, 0, n - 1, left, right, best, tmp);
                int got = tmp[4];
                if (got >= INF) got = -1;
                out.println(got);
            }
        }

        private void getTree(int[] tree, int root, int rl, int rr, int left, int right, int[] best, int[] tmp) {
            if (left > right) return;
            if (rl == left && rr == right) {
                apply(best, 0, tree, root * STATES * STATES, tmp, 0);
                System.arraycopy(tmp, 0, best, 0, STATES);
                return;
            }
            int rm = (rl + rr) >> 1;
            getTree(tree, root * 2 + 1, rl, rm, left, Math.min(rm, right), best, tmp);
            getTree(tree, root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right, best, tmp);
        }

        private void initTree(int[] tree, int root, int rl, int rr, String s) {
            if (rl == rr) {
                singleDigit(s.charAt(rl) - '0', tree, STATES * STATES * root);
            } else {
                int rm = (rl + rr) >> 1;
                initTree(tree, root * 2 + 1, rl, rm, s);
                initTree(tree, root * 2 + 2, rm + 1, rr, s);
                unite(tree, STATES * STATES * (root * 2 + 1), tree, STATES * STATES * (root * 2 + 2), tree, STATES * STATES * root);
            }
        }

        private void unite(int[] tree1, int o1, int[] tree2, int o2, int[] tree, int o) {
            Arrays.fill(tree, o, o + STATES * STATES, INF);
            for (int dst = 0; dst < STATES; ++dst) {
                for (int mid = 0; mid < STATES; ++mid) {
                    for (int src = 0; src < STATES; ++src) {
                        tree[o + dst * STATES + src] = Math.min(tree[o + dst * STATES + src], tree2[o2 + dst * STATES + mid] + tree1[o1 + mid * STATES + src]);
                    }
                }
            }
        }

        private void apply(int[] tree1, int o1, int[] tree2, int o2, int[] tree, int o) {
            Arrays.fill(tree, o, o + STATES, INF);
            for (int dst = 0; dst < STATES; ++dst) {
                for (int mid = 0; mid < STATES; ++mid) {
                    tree[o + dst] = Math.min(tree[o + dst], tree2[o2 + dst * STATES + mid] + tree1[o1 + mid]);
                }
            }
        }

        private void singleDigit(int digit, int[] tree, int o) {
            Arrays.fill(tree, o, o + STATES * STATES, INF);
            for (int src = 0; src < STATES; ++src) {
                int dst = src;
                if (digit == 2) {
                    if (src == 0) dst = 1;
                } else if (digit == 0) {
                    if (src == 1) dst = 2;
                } else if (digit == 1) {
                    if (src == 2) dst = 3;
                } else if (digit == 7) {
                    if (src == 3) dst = 4;
                } else if (digit == 6) {
                    if (src == 3 || src == 4) dst = 5;
                }
                tree[o + dst * STATES + src] = 0;
                if (dst != src)
                    tree[o + src * STATES + src] = 1;
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
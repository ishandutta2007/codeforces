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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        long[] posContrib;
        long[] treeContrib;
        int[] remap;
        boolean[] haveRemap;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt();
            posContrib = new long[10 * n];
            for (int i = 0; i < n; ++i) {
                int z = a[i];
                int p10 = 1;
                while (z > 0) {
                    int d = z % 10;
                    posContrib[i * 10 + d] += p10;
                    z /= 10;
                    p10 *= 10;
                }
            }
            treeContrib = new long[10 * 4 * n];
            remap = new int[10 * 4 * n];
            haveRemap = new boolean[4 * n];
            initTree(0, 0, n - 1);
            for (int i = 0; i < q; ++i) {
                int kind = in.nextInt();
                if (kind == 1) {
                    int left = in.nextInt() - 1;
                    int right = in.nextInt() - 1;
                    int src = in.nextInt();
                    int dst = in.nextInt();
                    treeRemap(0, 0, n - 1, left, right, src, dst);
                } else if (kind == 2) {
                    int left = in.nextInt() - 1;
                    int right = in.nextInt() - 1;
                    out.println(treeSum(0, 0, n - 1, left, right));
                } else throw new RuntimeException();
            }
        }

        private long treeSum(int root, int rl, int rr, int left, int right) {
            if (left > right) {
                return 0;
            }
            if (left == rl && right == rr) {
                long res = 0;
                for (int i = 0; i < 10; ++i) {
                    res += remap[root * 10 + i] * treeContrib[root * 10 + i];
                }
                return res;
            } else {
                propagate(root, true);
                int rm = (rl + rr) >> 1;
                long res = treeSum(root * 2 + 1, rl, rm, left, Math.min(rm, right)) +
                        treeSum(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right);
                return res;
            }
        }

        private void treeRemap(int root, int rl, int rr, int left, int right, int src, int dst) {
            if (left > right) {
                return;
            }
            if (left == rl && right == rr) {
                for (int i = 0; i < 10; ++i) if (remap[root * 10 + i] == src) remap[root * 10 + i] = dst;
                haveRemap[root] = true;
            } else {
                propagate(root, false);
                int rm = (rl + rr) >> 1;
                treeRemap(root * 2 + 1, rl, rm, left, Math.min(rm, right), src, dst);
                treeRemap(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right, src, dst);
                update(root);
            }
        }

        private void update(int root) {
            for (int i = 0; i < 10; ++i) {
                treeContrib[root * 10 + i] = 0;
            }
            for (int i = 0; i < 10; ++i) {
                for (int child = root * 2 + 1; child <= root * 2 + 2; ++child) {
                    treeContrib[root * 10 + remap[child * 10 + i]] += treeContrib[child * 10 + i];
                }
            }
        }

        private void propagate(int root, boolean needUpdate) {
            if (haveRemap[root]) {
                haveRemap[root] = false;
                for (int child = root * 2 + 1; child <= root * 2 + 2; ++child) {
                    haveRemap[child] = true;
                    for (int i = 0; i < 10; ++i) {
                        remap[child * 10 + i] = remap[root * 10 + remap[child * 10 + i]];
                    }
                }
                for (int i = 0; i < 10; ++i) {
                    remap[root * 10 + i] = i;
                }
                if (needUpdate) update(root);
            }
        }

        private void initTree(int root, int rl, int rr) {
            for (int i = 0; i < 10; ++i) {
                remap[root * 10 + i] = i;
            }
            haveRemap[root] = false;
            if (rl == rr) {
                for (int i = 0; i < 10; ++i) treeContrib[root * 10 + i] = posContrib[rl * 10 + i];
            } else {
                int rm = (rl + rr) >> 1;
                initTree(root * 2 + 1, rl, rm);
                initTree(root * 2 + 2, rm + 1, rr);
                for (int i = 0; i < 10; ++i) {
                    treeContrib[root * 10 + i] = treeContrib[(root * 2 + 1) * 10 + i] + treeContrib[(root * 2 + 2) * 10 + i];
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
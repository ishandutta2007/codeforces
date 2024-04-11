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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        private int[] alpha;
        private int[] len;
        private double[] dx;
        private double[] dy;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            alpha = new int[4 * n + 10];
            len = new int[4 * n + 10];
            dx = new double[4 * n + 10];
            dy = new double[4 * n + 10];
            initTree(0, 0, n - 1);
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt();
                int y = in.nextInt() - 1;
                int z = in.nextInt();
                if (x == 1) {
                    addLen(0, 0, n - 1, y, z);
                } else {
                    rotate(0, 0, n - 1, y, z);
                }
                out.println(String.format("%.15f %.15f", dx[0], dy[0]));
            }
        }

        private void rotate(int root, int rl, int rr, int from, int by) {
            if (rr < from) return;
            if (rl >= from) {
                alpha[root] += by;
                if (alpha[root] >= 360) alpha[root] -= 360;
            } else {
                int rm = (rl + rr) / 2;
                rotate(root * 2 + 1, rl, rm, from, by);
                rotate(root * 2 + 2, rm + 1, rr, from, by);
            }
            updateVector(root, rl == rr);
        }

        private void addLen(int root, int rl, int rr, int at, int by) {
            if (rl == rr) {
                len[root] += by;
            } else {
                int rm = (rl + rr) / 2;
                if (at <= rm) {
                    addLen(root * 2 + 1, rl, rm, at, by);
                } else {
                    addLen(root * 2 + 2, rm + 1, rr, at, by);
                }
            }
            updateVector(root, rl == rr);
        }

        private void initTree(int root, int rl, int rr) {
            if (rl == rr) {
                len[root] = 1;
                alpha[root] = 0;
            } else {
                int rm = (rl + rr) / 2;
                initTree(root * 2 + 1, rl, rm);
                initTree(root * 2 + 2, rm + 1, rr);
            }
            updateVector(root, rl == rr);
        }

        private void updateVector(int root, boolean leaf) {
            double cdx;
            double cdy;
            if (leaf) {
                cdx = len[root];
                cdy = 0;
            } else {
                cdx = dx[root * 2 + 1] + dx[root * 2 + 2];
                cdy = dy[root * 2 + 1] + dy[root * 2 + 2];
            }
            if (alpha[root] != 0) {
                double ca = Math.cos(alpha[root] * Math.PI / 180.0);
                double sa = Math.sin(alpha[root] * Math.PI / 180.0);
                double tmp = cdx * ca + cdy * sa;
                cdy = -cdx * sa + cdy * ca;
                cdx = tmp;
            }
            dx[root] = cdx;
            dy[root] = cdy;
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
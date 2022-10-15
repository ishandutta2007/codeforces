import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Niyaz Nigmatullin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int m = in.nextInt();
            int[][] edges = new int[n][n];
            for (int[] e : edges) Arrays.fill(e, Integer.MAX_VALUE);
            for (int i = 0; i < m; i++) {
                int from = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                int w = in.nextInt();
                edges[from][to] = Math.min(edges[from][to], w);
            }
            int[][][] dp = new int[n][n + 1][n + 1];
            for (int[][] e : dp) {
                for (int[] f : e) {
                    Arrays.fill(f, Integer.MAX_VALUE);
                }
            }
            for (int i = 0; i < n; i++) {
                dp[i][n][n] = 0;
            }
            int[][][] ndp = new int[n][n + 1][n + 1];
            int[][] bestLeft = new int[n][n + 1];
            int[][] bestRight = new int[n + 1][n];
            for (int it = 1; it < k; it++) {
                for (int[] e : bestLeft) Arrays.fill(e, Integer.MAX_VALUE);
                for (int[] e : bestRight) Arrays.fill(e, Integer.MAX_VALUE);
                for (int[][] e : ndp) {
                    for (int[] f : e) Arrays.fill(f, Integer.MAX_VALUE);
                }
                for (int oldLeft_ = -1; oldLeft_ < n; oldLeft_++) {
                    int oldLeft = oldLeft_ == -1 ? n : oldLeft_;
                    for (int left = oldLeft_ + 1; left < n; left++) {
                        int[] bLLeft = bestLeft[left];
                        for (int right = left + 1; right <= n; right++) {
                            bLLeft[right] = Math.min(bLLeft[right], dp[left][oldLeft][right]);
                        }
                    }
                }
                for (int left_ = -1; left_ < n; left_++) {
                    int left = left_ == -1 ? n : left_;
                    int[] bRLeft = bestRight[left];
                    for (int right = left_ + 1; right < n; right++) {
                        for (int oldRight = right + 1; oldRight <= n; oldRight++) {
                            bRLeft[right] = Math.min(bRLeft[right], dp[right][left][oldRight]);
                        }
                    }
                }
                for (int left_ = -1; left_ < n; left_++) {
                    int left = left_ == -1 ? n : left_;
                    int[] bLeft = left == n ? null : bestLeft[left];
                    int[] eLeft = left == n ? null : edges[left];
                    for (int v = left_ + 1; v < n; v++) {
                        for (int right = v + 1; right <= n; right++) {
                            int[] bRight = right == n ? null : bestRight[left];
                            int[] eRight = right == n ? null : edges[right];
                            int cur = Integer.MAX_VALUE;
                            if (left != n && eLeft[v] != Integer.MAX_VALUE) {
//                            int best = Integer.MAX_VALUE;
//                            for (int oldLeft_ = -1; oldLeft_ < left; oldLeft_++) {
//                                int oldLeft = oldLeft_ == -1 ? n : oldLeft_;
//                                best = Math.min(best, dp[left][oldLeft][right]);
//                            }
                                int best = bLeft[right];
                                if (best != Integer.MAX_VALUE) {
                                    cur = Math.min(cur, best + eLeft[v]);
                                }
                            }
                            if (right != n && eRight[v] != Integer.MAX_VALUE) {
//                            int best = Integer.MAX_VALUE;
//                            for (int oldRight = right + 1; oldRight <= n; oldRight++) {
//                                best = Math.min(best, dp[right][left][oldRight]);
//                            }
                                int best = bRight[right];
                                if (best != Integer.MAX_VALUE) {
                                    cur = Math.min(cur, best + eRight[v]);
                                }
                            }
                            ndp[v][left][right] = cur;
                        }
                    }
                }
                int[][][] t = dp;
                dp = ndp;
                ndp = t;
            }
            int ans = Integer.MAX_VALUE;
            for (int[][] e : dp)
                for (int[] f : e)
                    for (int z : f) ans = Math.min(ans, z);
            out.println(ans == Integer.MAX_VALUE ? -1 : ans);
        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }

    static class FastScanner extends BufferedReader {
        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }


        public int read() {
            try {
                int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
                return ret;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

        static boolean isWhiteSpace(int c) {
            return c >= 0 && c <= 32;
        }

        public int nextInt() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int ret = 0;
            while (c >= 0 && !isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                ret = ret * 10 + c - '0';
                c = read();
            }
            return ret * sgn;
        }

        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                return null;
            }
        }

    }
}
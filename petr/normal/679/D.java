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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final int INF = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] d = new int[n][n];
            for (int i = 0; i < n; ++i) {
                Arrays.fill(d[i], INF);
                d[i][i] = 0;
            }
            for (int i = 0; i < m; ++i) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                d[a][b] = d[b][a] = 1;
            }
            int[] deg = new int[n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (d[i][j] == 1) ++deg[i];
                }
            }
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }

            double[][] pr = new double[n][n];
            double[][] cmax = new double[n][n];
            double[] total = new double[n];
            int[] count = new int[n];

            double res = 0.0;
            for (int a = 0; a < n; ++a) {
                for (double[] x : pr) Arrays.fill(x, 0);
                Arrays.fill(count, 0);
                double one = 1.0 / n;
                for (int b = 0; b < n; ++b) {
                    int cd = d[a][b];
                    ++count[cd];
                    double by = one / deg[b];
                    for (int c = 0; c < n; ++c) {
                        if (d[b][c] == 1) {
                            pr[cd][c] += by;
                        }
                    }
                }

                double cur = 0.0;
                for (int got = 0; got < n; ++got)
                    if (count[got] > 0) {
                        double tg = one;
                        if (count[got] > 1) {
                            Arrays.fill(total, 0);
                            for (int at = 0; at < n; ++at) {
                                if (pr[got][at] > 0) {
                                    double cpr = pr[got][at];
                                    int[] dd = d[at];
                                    for (int b = 0; b < n; ++b) {
                                        int bd = dd[b];
                                        double omax = cmax[b][bd];
                                        if (cpr > omax) {
                                            total[b] += cpr - omax;
                                            cmax[b][bd] = cpr;
                                        }
                                    }
                                }
                            }
                            for (int b = 0; b < n; ++b) {
                                tg = Math.max(tg, total[b]);
                            }
                            for (int at = 0; at < n; ++at) {
                                if (pr[got][at] > 0) {
                                    int[] dd = d[at];
                                    for (int b = 0; b < n; ++b) {
                                        int bd = dd[b];
                                        cmax[b][bd] = 0;
                                    }
                                }
                            }
                        }
                        cur += tg;
                    }
                res = Math.max(res, cur);
            }

            out.println(String.format("%.10f", res));
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
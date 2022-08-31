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

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            if (n <= 5) {
                int ne = n * (n - 1) / 2;
                int[][] d = new int[n][n];
                for (int mask = 0; mask < (1 << ne); ++mask) {
                    for (int[] x : d) Arrays.fill(x, INF);
                    for (int i = 0; i < n; ++i) d[i][i] = 0;
                    int t = mask;
                    int nre = 0;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < i; ++j) {
                            if ((t & 1) != 0) {
                                d[i][j] = d[j][i] = 1;
                                ++nre;
                            }
                            t >>= 1;
                        }
                    }
                    floyd(n, d);
                    int de = 0;
                    for (int[] x : d)
                        for (int y : x) {
                            de = Math.max(de, y);
                        }
                    if (de >= INF) de = -1;

                    for (int[] x : d) Arrays.fill(x, INF);
                    for (int i = 0; i < n; ++i) d[i][i] = 0;
                    t = mask;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < i; ++j) {
                            if ((t & 1) == 0) {
                                d[i][j] = d[j][i] = 1;
                            }
                            t >>= 1;
                        }
                    }
                    floyd(n, d);
                    int dw = 0;
                    for (int[] x : d)
                        for (int y : x) {
                            dw = Math.max(dw, y);
                        }
                    if (dw >= INF) dw = -1;
                    if (Math.min(de, dw) == k) {
                        out.println(nre);
                        t = mask;
                        for (int i = 0; i < n; ++i) {
                            for (int j = 0; j < i; ++j) {
                                if ((t & 1) != 0) {
                                    d[i][j] = 1;
                                    out.println(i + 1 + " " + (j + 1));
                                }
                                t >>= 1;
                            }
                        }
                        return;
                    }
                }
                out.println(-1);
                return;
            } else {
                if (k == 2) {
                    out.println(n - 1);
                    for (int i = 0; i < n - 1; ++i) {
                        out.println(i + 1 + " " + (i + 2));
                    }
                } else if (k == 3) {
                    out.println(n - 1);
                    out.println("1 2");
                    for (int i = 3; i <= n; ++i) {
                        if (i % 2 == 0) {
                            out.println("2 " + i);
                        } else {
                            out.println("1 " + i);
                        }
                    }
                } else {
                    out.println(-1);
                    return;
                }
            }

        }

        private void floyd(int n, int[][] d) {
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                    }
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
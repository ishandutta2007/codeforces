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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int MAX_INTER = 61;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int compressedSize = (n + 63) >> 6;
            long[][][] can = new long[2 * MAX_INTER][n][compressedSize];
            for (int i = 0; i < m; ++i) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                int t = in.nextInt();
                can[t][u][v >> 6] |= (1L << (v & 63));
            }
            for (int kind = 2; kind < 2 * MAX_INTER; ++kind) {
                for (int a = 0; a < n; ++a) {
                    for (int b = 0; b < n; ++b) {
                        if ((can[kind - 2][a][b >> 6] & (1L << (b & 63))) != 0) {
                            int o = (kind - 2) ^ 1;
                            for (int c = 0; c < compressedSize; ++c) {
                                can[kind][a][c] |= can[o][b][c];
                            }
                        }
                    }
                }
            }
            long[][] best = new long[2 * MAX_INTER][n];
            for (int kind = 0; kind < 2 * MAX_INTER; ++kind) {
                for (int a = 0; a < n; ++a) {
                    for (int b = 0; b < n; ++b) {
                        if ((can[kind][a][b >> 6] & (1L << (b & 63))) != 0) {
                            best[kind][a] = Math.max(best[kind][a], 1L << (kind >> 1));
                        } else if (kind >= 2 && (can[kind - 2][a][b >> 6] & (1L << (b & 63))) != 0) {
                            best[kind][a] = Math.max(best[kind][a], (1L << ((kind >> 1) - 1)) + best[(kind - 2) ^ 1][b]);
                        } else if (kind >= 2) {
                            best[kind][a] = Math.max(best[kind][a], best[kind - 2][a]);
                        }
                    }
                }
            }
            long res = best[2 * (MAX_INTER - 1)][0];
            if (res > (long) 1e9 * (long) 1e9) {
                res = -1;
            }
            out.println(res);
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
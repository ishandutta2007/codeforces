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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String[] field = new String[n];
            for (int i = 0; i < n; ++i) field[i] = in.next();
            byte[][][][] answer = new byte[n][n][][];
            long[] rows = new long[n];
            long[] columns = new long[n];
            for (int r2 = 0; r2 < n; ++r2) {
                for (int c2 = 0; c2 < n; ++c2) {
                    if (field[r2].charAt(c2) == '#') {
                        rows[r2] |= 1L << c2;
                        columns[c2] |= 1L << r2;
                    }
                }
            }
            for (int r2 = 0; r2 < n; ++r2) {
                for (int c2 = 0; c2 < n; ++c2) {
                    answer[r2][c2] = new byte[r2 + 1][c2 + 1];
                    for (int r1 = r2; r1 >= 0; --r1) {
                        for (int c1 = c2; c1 >= 0; --c1) {
                            int best = Math.max(r2 - r1 + 1, c2 - c1 + 1);
                            for (int r = r1; r <= r2; ++r) {
                                if (((rows[r] >> c1) & ((1L << (c2 - c1 + 1)) - 1)) == 0) {
                                    int cur = 0;
                                    if (r > r1) {
                                        cur += answer[r - 1][c2][r1][c1];
                                    }
                                    if (r < r2) {
                                        cur += answer[r2][c2][r + 1][c1];
                                    }
                                    best = Math.min(best, cur);
                                }
                            }
                            for (int c = c1; c <= c2; ++c) {
                                if (((columns[c] >> r1) & ((1L << (r2 - r1 + 1)) - 1)) == 0) {
                                    int cur = 0;
                                    if (c > c1) {
                                        cur += answer[r2][c - 1][r1][c1];
                                    }
                                    if (c < c2) {
                                        cur += answer[r2][c2][r1][c + 1];
                                    }
                                    best = Math.min(best, cur);
                                }
                            }
                            answer[r2][c2][r1][c1] = (byte) best;
                        }
                    }
                }
            }
            out.println(answer[n - 1][n - 1][0][0]);
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
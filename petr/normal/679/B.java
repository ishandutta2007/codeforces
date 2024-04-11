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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long m = in.nextLong();
            long maxSide = root3(m);
            int[] best = new int[(int) maxSide + 1];
            long[] via = new long[(int) maxSide + 1];
            for (long s = 2; s < best.length; ++s) {
                best[((int) s)] = best[((int) (s - 1))];
                via[((int) s)] = via[((int) (s - 1))];
                long min = (s - 1) * (s - 1) * (s - 1);
                long max = s * s * s - 1;
                int already = 1;
                while (true) {
                    long ss = root3(max - min);
                    if (already + best[((int) ss)] >= best[((int) s)]) {
                        best[((int) s)] = already + best[((int) ss)];
                        via[((int) s)] = min + via[((int) ss)];
                    }
                    if (ss == 0) break;
                    min += ss * ss * ss;
                    ++already;
                }
            }
            long res = best[((int) maxSide)];
            long resVia = via[((int) maxSide)];
            {
                long min = maxSide * maxSide * maxSide;
                long max = m;
                int already = 1;
                while (true) {
                    long ss = root3(max - min);
                    if (already + best[((int) ss)] >= res) {
                        res = already + best[((int) ss)];
                        resVia = min + via[((int) ss)];
                    }
                    if (ss == 0) break;
                    min += ss * ss * ss;
                    ++already;
                }
            }
            out.println(res + " " + resVia);
        }

        private long root3(long m) {
            long maxSide = Math.max(0, (long) (Math.floor(Math.pow(m, 1.0 / 3)) - 1));
            while (maxSide * maxSide * maxSide <= m) ++maxSide;
            return maxSide - 1;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
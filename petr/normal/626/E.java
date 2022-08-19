import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] x = new long[n];
            for (int i = 0; i < n; ++i) x[i] = in.nextLong();
            Random random = new Random(543154315431L + System.currentTimeMillis());
            for (int i = 0; i < n; ++i) {
                int j = i + random.nextInt(n - i);
                long t = x[i];
                x[i] = x[j];
                x[j] = t;
            }
            Arrays.sort(x);
            long[] psum = new long[n + 1];
            for (int i = 0; i < n; ++i) psum[i + 1] = psum[i] + x[i];

            long bp = -1;
            long bq = 0;
            int bmedian = -1;
            int btake = -1;
            boolean bodd = false;

            for (int median = 0; median < n; ++median) {
                {
                    // odd
                    int left = -1;
                    int right = Math.min(median, n - median - 1);
                    while (right - left > 1) {
                        int middle = (left + right) / 2;
                        long p1 = psum[n] - psum[n - middle] + psum[median + 1] - psum[median - middle];
                        long q1 = 2 * middle + 1;
                        long p2 = x[n - middle - 1] + x[median - middle - 1];
                        long q2 = 2;
                        if (p1 * q2 >= p2 * q1) {
                            right = middle;
                        } else {
                            left = middle;
                        }
                    }
                    long p = psum[n] - psum[n - right] + psum[median + 1] - psum[median - right];
                    long q = 2 * right + 1;
                    p -= q * x[median];
                    if (p * bq > q * bp) {
                        bp = p;
                        bq = q;
                        bmedian = median;
                        btake = right;
                        bodd = true;
                    }
                }
                if (median + 1 < n) {
                    // even
                    int left = -1;
                    int right = Math.min(median, n - median - 2);
                    while (right - left > 1) {
                        int middle = (left + right) / 2;
                        long p1 = psum[n] - psum[n - middle] + psum[median + 2] - psum[median - middle];
                        long q1 = 2 * middle + 2;
                        long p2 = x[n - middle - 1] + x[median - middle - 1];
                        long q2 = 2;
                        if (p1 * q2 >= p2 * q1) {
                            right = middle;
                        } else {
                            left = middle;
                        }
                    }
                    long p = psum[n] - psum[n - right] + psum[median + 2] - psum[median - right];
                    long q = 2 * right + 2;
                    p -= q / 2 * x[median];
                    p -= q / 2 * x[median + 1];
                    if (p * bq > q * bp) {
                        bp = p;
                        bq = q;
                        bmedian = median;
                        btake = right;
                        bodd = false;
                    }
                }
            }

            out.println(2 * btake + (bodd ? 1 : 2));
            out.print(x[bmedian]);
            if (!bodd) {
                out.print(" ");
                out.print(x[bmedian + 1]);
            }
            for (int i = 0; i < btake; ++i) {
                out.print(" ");
                out.print(x[bmedian - 1 - i]);
                out.print(" ");
                out.print(x[n - 1 - i]);
            }
            out.println();
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
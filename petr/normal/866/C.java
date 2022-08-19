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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int r = in.nextInt();
            int[] f = new int[n];
            int[] s = new int[n];
            double[] p = new double[n];
            for (int i = 0; i < n; ++i) {
                f[i] = in.nextInt();
                s[i] = in.nextInt();
                p[i] = in.nextInt() / 100.0;
            }
            double left = 0;
            double right = 0;
            for (int i = 0; i < n; ++i) right += s[i];
            for (int i = 0; i < n; ++i) right *= 1.0 / p[i];
            double[][] res = new double[n + 1][r + 1];
            while ((right - left) / Math.max(1.0, right) > 1e-10) {
                double mid = (left + right) / 2;
                Arrays.fill(res[n], 0.0);
                for (int i = n - 1; i >= 0; --i) {
                    for (int have = 0; have <= r; ++have) {
                        double alt = 0;
                        if (have >= f[i]) {
                            alt += p[i] * (f[i] + res[i + 1][have - f[i]]);
                        } else {
                            alt += p[i] * (f[i] + mid);
                        }
                        if (have >= s[i]) {
                            alt += (1 - p[i]) * (s[i] + res[i + 1][have - s[i]]);
                        } else {
                            alt += (1 - p[i]) * (s[i] + mid);
                        }
                        res[i][have] = Math.min(alt, mid);
                    }
                }
                if (res[0][r] < mid) {
                    if (right <= mid) break;
                    right = mid;
                } else {
                    if (left >= mid) break;
                    left = mid;
                }
            }
            out.println((left + right) / 2);
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
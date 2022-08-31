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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            int max = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                max = Math.max(max, a[i]);
            }
            Arrays.sort(a);
            long[] w1 = new long[2 * max + 1];
            long[] w2 = new long[2 * max + 1];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (a[i] > a[j]) {
                        ++w1[a[i] - a[j] + max];
                        ++w2[a[j] - a[i] + max];
                    }
                }
            }
            long[] w = mul(w2, mul(w1, w1));
            long s = 0;
            for (int i = 0; i < 3 * max; ++i) {
                s += w[i];
            }
            double res = s;
            for (int i = 0; i < 3; ++i) {
                res /= (n * (n - 1)) / 2;
            }
            out.printf(String.format("%.15f", res));
        }

        private long[] mul(long[] a, long[] b) {
            long[] c = new long[a.length + b.length - 1];
            for (int i = 0; i < a.length; ++i)
                for (int j = 0; j < b.length; ++j)
                    c[i + j] += a[i] * b[j];
            return c;
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
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            double[] p = new double[n];
            for (int i = 0; i < n; ++i) {
                p[i] = Math.round(100.0 * in.nextDouble());
            }
            double[] pr = new double[1 << n];
            for (int i = 1; i < (1 << n); ++i) {
                int a = Integer.numberOfTrailingZeros(i);
                pr[i] = pr[i ^ (1 << a)] + p[a];
            }
            for (int i = 0; i < (1 << n); ++i) {
                if (pr[i] < 100.0) {
                    pr[i] = 100.0 / (100.0 - pr[i]);
                } else {
                    pr[i] = 0;
                }
            }
            for (int bit = 0; bit < n; ++bit) {
                for (int i = 0; i < (1 << n); ++i)
                    if ((i & (1 << bit)) != 0) {
                        pr[i] -= pr[i ^ (1 << bit)];
                    }
            }
            double[] s = new double[n];
            for (int i = 0; i < (1 << n); ++i)
                if (Integer.bitCount(i) < k) {
                    for (int j = 0; j < n; ++j)
                        if ((i & (1 << j)) == 0 && p[j] > 0) {
                            s[j] += p[j] * pr[i];
                        }
                }
            for (int i = 0; i < n; ++i) {
                if (i > 0) out.print(" ");
                out.print(String.format("%.10f", s[i] / 100.0));
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }
}
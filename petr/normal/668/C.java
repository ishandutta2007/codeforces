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
            double[] pmax = new double[n];
            double[] pmin = new double[n];
            for (int i = 0; i < n; ++i) {
                pmax[i] = in.nextDouble();
            }
            for (int i = 0; i < n; ++i) {
                pmin[i] = in.nextDouble();
            }
            for (int i = 1; i < n; ++i) {
                pmax[i] += pmax[i - 1];
            }
            for (int i = n - 2; i >= 0; --i) {
                pmin[i] += pmin[i + 1];
            }
            double[] ra = new double[n + 1];
            double[] rb = new double[n + 1];
            ra[n] = 1;
            rb[n] = 1;
            for (int i = 1; i < n; ++i) {
                double alpha = pmax[i - 1];
                double beta = pmin[i];
                double sum = 1 + alpha - beta;
                double prod = alpha;
                double d = sum * sum - 4 * prod;
                d = Math.sqrt(Math.max(d, 0)) / 2.0;
                ra[i] = sum / 2.0 + d;
                rb[i] = sum / 2.0 - d;
            }
            for (int i = 0; i < n; ++i) {
                if (i > 0) out.print(" ");
                out.print(rb[i + 1] - rb[i]);
            }
            out.println();
            for (int i = 0; i < n; ++i) {
                if (i > 0) out.print(" ");
                out.print(ra[i + 1] - ra[i]);
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
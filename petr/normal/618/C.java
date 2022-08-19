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
            long[] x = new long[n];
            long[] y = new long[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            for (int i = n - 1; i >= 0; --i) {
                x[i] -= x[0];
                y[i] -= y[0];
            }
            int j = -1;
            long dj = Long.MAX_VALUE;
            for (int i = 1; i < n; ++i) {
                long d = x[i] * x[i] + y[i] * y[i];
                if (d < dj) {
                    dj = d;
                    j = i;
                }
            }
            long a = -y[j];
            long b = x[j];
            long dk = Long.MAX_VALUE;
            int k = -1;
            for (int i = 0; i < n; ++i) {
                long v = Math.abs(a * x[i] + b * y[i]);
                if (v == 0) continue;
                if (v < dk) {
                    dk = v;
                    k = i;
                }
            }
            out.println(1 + " " + (j + 1) + " " + (k + 1));
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
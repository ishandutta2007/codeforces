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
            long n = in.nextLong();
            long[] a = new long[(int) 1e5];
            long[] b = new long[(int) 1e5];
            int pa = 0;
            int pb = 0;
            for (long i = 1; i * i <= n; ++i) {
                if (n % i == 0) {
                    long upto = n / i;
                    a[pa++] = upto * (upto - 1) / 2 * i + upto;
                    if (i < upto) {
                        long j = upto;
                        upto = n / j;
                        b[pb++] = upto * (upto - 1) / 2 * j + upto;
                    }
                }
            }
            for (int i = 0; i < pb; ++i) out.print(b[i] + " ");
            for (int i = pa - 1; i >= 0; --i) out.print(a[i] + " ");
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
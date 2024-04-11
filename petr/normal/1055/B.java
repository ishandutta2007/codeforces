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
            int n = in.nextInt();
            int m = in.nextInt();
            long l = in.nextInt();
            long[] a = new long[n + 2];
            for (int i = 1; i <= n; ++i) a[i] = in.nextInt();
            int count = 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] > l && a[i - 1] <= l) ++count;
            }
            for (int qi = 0; qi < m; ++qi) {
                int t = in.nextInt();
                if (t == 0) out.println(count);
                else {
                    int p = in.nextInt();
                    long d = in.nextInt();
                    if (a[p] > l && a[p - 1] <= l) --count;
                    if (a[p + 1] > l && a[p] <= l) --count;
                    a[p] += d;
                    if (a[p] > l && a[p - 1] <= l) ++count;
                    if (a[p + 1] > l && a[p] <= l) ++count;
                }
            }
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
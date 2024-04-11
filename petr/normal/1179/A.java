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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            int[] a = new int[2 * n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            int max = -1;
            for (int x : a) max = Math.max(max, x);
            int start = 0;
            int nextOp = 1;
            int[] a1 = new int[n + 1];
            int[] a2 = new int[n + 1];
            while (a[start] != max) {
                int x = a[start++];
                int y = a[start];
                a1[nextOp] = x;
                a2[nextOp] = y;
                a[start] = Math.max(x, y);
                a[start + n - 1] = Math.min(x, y);
                ++nextOp;
            }
            for (int i = 0; i < q; ++i) {
                long when = in.nextLong();
                if (when < nextOp) {
                    out.println(a1[(int) when] + " " + a2[(int) when]);
                } else {
                    long skips = when - nextOp;
                    skips %= (n - 1);
                    out.println(a[start] + " " + a[(int) (start + 1 + skips)]);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
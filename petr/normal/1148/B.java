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
            int na = in.nextInt();
            int nb = in.nextInt();
            long ta = in.nextLong();
            long tb = in.nextLong();
            int k = in.nextInt();
            long[] a = new long[na];
            for (int i = 0; i < na; ++i) {
                a[i] = in.nextLong();
            }
            long[] b = new long[nb];
            for (int i = 0; i < nb; ++i) {
                b[i] = in.nextLong();
            }
            if (k >= na) {
                out.println(-1);
                return;
            }
            int at = 0;
            long res = -1;
            for (int i = 0; i <= k; ++i) {
                long when = a[i] + ta;
                while (at < b.length && b[at] < when) ++at;
                int fin = at + (k - i);
                if (fin >= b.length) {
                    out.println(-1);
                    return;
                }
                res = Math.max(res, b[fin] + tb);
            }
            out.println(res);
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
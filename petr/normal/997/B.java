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
        int BUBEN = 30000;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            boolean[] can = buildOne(n, 5 - 1, 10 - 1, 50 - 1);
            boolean[] can2 = buildOne(n, 50 - 10, 50 - 5, 50 - 1);
            long min = n;
            long max = 50 * n;
            long res = max - min + 1;
            for (long a = min; a <= min + BUBEN && a <= max; ++a) {
                if (!can[(int) (a - min)]) --res;
            }
            for (long a = Math.max(min + BUBEN + 1, max - BUBEN); a <= max; ++a) {
                if (!can2[(int) (max - a)]) --res;
            }
            out.println(res);
        }

        private boolean[] buildOne(long n, int a, int b, int c) {
            boolean[] can = new boolean[BUBEN + 1];
            can[0] = true;
            for (int i = 0; i < n; ++i) {
                boolean updated = false;
                for (int j = can.length - 1; j >= 0; --j)
                    if (can[j]) {
                        if (j + a < can.length && !can[j + a]) {
                            can[j + a] = true;
                            updated = true;
                        }
                        if (j + b < can.length && !can[j + b]) {
                            can[j + b] = true;
                            updated = true;
                        }
                        if (j + c < can.length && !can[j + c]) {
                            can[j + c] = true;
                            updated = true;
                        }
                    }
                if (!updated) break;
            }
            return can;
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
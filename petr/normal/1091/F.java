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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] len = new long[n];
            for (int i = 0; i < n; ++i) {
                len[i] = in.nextLong();
            }
            String types = in.next();
            long am1 = 0;
            long am2 = 0;
            boolean have3 = false;
            boolean have5 = false;
            long res = 0;
            for (int i = 0; i < n; ++i) {
                long x = len[i];
                switch (types.charAt(i)) {
                    case 'L': {
                        res += x;
                        {
                            long by = Math.min(am1, x);
                            am1 -= by;
                            x -= by;
                            res += by;
                        }
                        {
                            long by = Math.min(am2, x);
                            am2 -= by;
                            x -= by;
                            res += 2 * by;
                        }
                        if (have3) {
                            long by = x;
                            x -= by;
                            res += 3 * by;
                        }
                        if (have5) {
                            long by = x;
                            x -= by;
                            res += 5 * by;
                        }
                        if (x != 0) throw new RuntimeException();
                        break;
                    }

                    case 'W': {
                        res += 2 * x;
                        am1 += x;
                        have3 = true;
                        break;
                    }

                    case 'G': {
                        long y = Math.min(am1, x);
                        res += 2 * y;
                        x -= y;
                        am2 += 2 * y;
                        am1 -= y;

                        res += 3 * x;
                        am2 += x;
                        have5 = true;
                    }
                }
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
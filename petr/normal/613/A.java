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
            long x0 = in.nextLong();
            long y0 = in.nextLong();
            double maxd = 0;
            double mind = 1e100;
            long px = -1;
            long py = -1;
            long fx = -1;
            long fy = -1;
            for (int i = 0; i <= n; ++i) {
                long x = i == n ? fx : (in.nextLong() - x0);
                long y = i == n ? fy : (in.nextLong() - y0);
                double d = x * x + y * y;
                maxd = Math.max(maxd, d);
                mind = Math.min(mind, d);
                if (i > 0) {
                    if ((px - x) * (-x) + (py - y) * (-y) > 0 && (x - px) * (-px) + (y - py) * (-py) > 0) {
                        long a = y - py;
                        long b = px - x;
                        long c = -(a * x + b * y);
                        mind = Math.min(mind, c * (double) c / (a * (double) a + b * (double) b));
                    }
                } else {
                    fx = x;
                    fy = y;
                }
                px = x;
                py = y;
            }
            out.println(Math.PI * (maxd - mind));
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
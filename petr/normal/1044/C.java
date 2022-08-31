import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
            int[] x = new int[n];
            int[] y = new int[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            int minx = Integer.MAX_VALUE;
            int miny = Integer.MAX_VALUE;
            int maxx = Integer.MIN_VALUE;
            int maxy = Integer.MIN_VALUE;
            for (int i = 0; i < n; ++i) {
                if (x[i] < minx) minx = x[i];
                if (y[i] < miny) miny = y[i];
                if (x[i] > maxx) maxx = x[i];
                if (y[i] > maxy) maxy = y[i];
            }
            int[] res = new int[n + 1];
            Arrays.fill(res, (maxx - minx) * 2 + (maxy - miny) * 2);
            res[3] = 0;
            for (int i = 0; i < n; ++i) {
                res[3] = Math.max(res[3], (maxx + maxy - x[i] - y[i]) * 2);
                res[3] = Math.max(res[3], (maxx - miny - x[i] + y[i]) * 2);
                res[3] = Math.max(res[3], (-minx + maxy + x[i] - y[i]) * 2);
                res[3] = Math.max(res[3], (-minx - miny + x[i] + y[i]) * 2);
            }
            for (int i = 3; i <= n; ++i) {
                out.print(res[i]);
                out.print(" ");
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

    }
}
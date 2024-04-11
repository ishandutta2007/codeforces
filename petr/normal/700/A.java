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
            int l = in.nextInt();
            int v1 = in.nextInt();
            int v2 = in.nextInt();
            int k = in.nextInt();
            double gain = 1.0 / v1 - 1.0 / v2;
            double together = 1.0 / (v1 + v2);
            double left = 0;
            double right = l / (double) v1;
            while (right - left > 1e-7 * Math.max(1.0, right)) {
                double middle = (left + right) / 2;
                double needBus = (l / (double) v1 - middle) / gain;
                double time = 0;
                for (int first = 0; first < n; first += k) {
                    if (first + k < n)
                        time += 2 * needBus * together;
                    else
                        time += needBus / v2;
                }
                if (time <= middle) {
                    right = middle;
                } else {
                    left = middle;
                }
            }
            out.println((left + right) / 2);
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
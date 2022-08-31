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
            int q = in.nextInt();
            int first = 0;
            int second = 1;
            for (int i = 0; i < q; ++i) {
                int t = in.nextInt();
                if (t == 1) {
                    int delta = in.nextInt();
                    delta = -delta;
                    if (delta < 0) delta += n;
                    if (delta >= n) delta -= n;
                    if ((delta & 1) == 0) {
                        first += delta;
                        second += delta;
                    } else {
                        int tmp = first + delta + 1;
                        first = second + delta - 1;
                        second = tmp;
                    }
                    if (first >= n) first -= n;
                    if (second >= n) second -= n;
                } else {
                    int tmp = first;
                    first = second;
                    second = tmp;
                }
            }
            for (int i = 0; i * 2 < n; ++i) {
                if (i > 0) out.print(" ");
                out.print(first + 1);
                out.print(" ");
                out.print(second + 1);
                first += 2;
                if (first >= n) first -= n;
                second += 2;
                if (second >= n) second -= n;
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
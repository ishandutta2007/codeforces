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
            int height = in.nextInt();
            int width = in.nextInt();
            int length = height * width;
            int pos = 0;
            for (int r1 = 0, r2 = height - 1; r1 <= r2; ++r1, --r2) {
                for (int c1 = 0, c2 = width - 1; c1 < width; ++c1, --c2) {
                    if (r1 == r2 && c1 > c2) break;
                    out.println((r1 + 1) + " " + (c1 + 1));
                    ++pos;
                    if (r1 == r2 && c1 >= c2) break;
                    out.println((r2 + 1) + " " + (c2 + 1));
                    ++pos;
                }
            }
            if (pos != length) throw new RuntimeException();
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
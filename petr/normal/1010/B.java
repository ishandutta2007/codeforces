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
            int m = in.nextInt();
            int n = in.nextInt();
            boolean[] inverted = new boolean[n];
            for (int i = 0; i < n; ++i) {
                out.println(1);
                out.flush();
                int y = in.nextInt();
                if (y == 0 || y == -2) {
                    return;
                }
                inverted[i] = y < 0;
            }
            int min = 1;
            int max = m;
            int ptr = 0;
            while (true) {
                int mid = (min + max) / 2;
                out.println(mid);
                out.flush();
                int y = in.nextInt();
                if (y == 0 || y == -2) {
                    return;
                }
                if (inverted[ptr % n]) y = -y;
                ++ptr;
                if (y < 0) {
                    max = mid - 1;
                } else {
                    min = mid + 1;
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
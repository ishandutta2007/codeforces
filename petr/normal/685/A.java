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
            int m = in.nextInt();
            int digits_n = digits(n - 1);
            int digits_m = digits(m - 1);
            if (digits_n + digits_m > 7) {
                out.println(0);
                return;
            }
            out.println(rec(0, 0, n, m, digits_n, digits_m, 0));
        }

        private int rec(int val, int at, int n, int m, int digits_n, int digits_m, int used) {
            if (at == digits_n) {
                if (val >= n) return 0;
                val = 0;
            } else if (at == digits_n + digits_m) {
                if (val >= m) return 0;
                return 1;
            }
            int res = 0;
            for (int x = 0; x < 7; ++x)
                if ((used & (1 << x)) == 0) {
                    res = res + rec(val * 7 + x, at + 1, n, m, digits_n, digits_m, used | (1 << x));
                }
            return res;
        }

        private int digits(int val) {
            if (val < 7) return 1;
            return 1 + digits(val / 7);
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
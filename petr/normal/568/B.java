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
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[][] c = new int[n + 1][n + 1];
            c[0][0] = 1;
            for (int i = 1; i <= n; ++i) {
                c[i][0] = 1;
                for (int j = 1; j <= n; ++j) {
                    c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MODULO;
                }
            }
            long[] ways = new long[n + 1];
            long[] waysNice = new long[n + 1];
            ways[0] = 1;
            waysNice[0] = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 1; i + j <= n; ++j) {
                    waysNice[i + j] = (waysNice[i + j] + waysNice[i] * c[n - i - 1][j - 1]) % MODULO;
                    int mult = (j == 1) ? 2 : 1;
                    ways[i + j] = (ways[i + j] + mult * ways[i] * c[n - i - 1][j - 1]) % MODULO;
                }
            }
            long res = (ways[n] - waysNice[n] + MODULO) % MODULO;
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

    }
}
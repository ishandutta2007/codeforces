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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final long MODULO = (long) 1e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long d = in.nextInt() - 1;
            int[] p = new int[n];
            p[0] = -1;
            for (int i = 1; i < n; ++i) {
                p[i] = in.nextInt() - 1;
            }
            int[] ways = rec(n, p, 0);
            long[] invs = new long[n + 2];
            invs[1] = 1;
            for (int i = 2; i < invs.length; ++i) {
                invs[i] = (MODULO - invs[((int) (MODULO % i))] * (MODULO / i) % MODULO) % MODULO;
                if (invs[i] * i % MODULO != 1) throw new RuntimeException();
            }
            long res = 0;
            for (int i = 0; i <= n; ++i) {
                long prod = ways[i];
                for (int j = 0; j <= n; ++j)
                    if (i != j) {
                        prod = prod * (d - j) % MODULO;
                        int by = i - j;
                        if (by < 0) {
                            by = -by;
                            prod = -prod;
                        }
                        prod = prod * invs[by] % MODULO;
                    }
                res = (res + prod) % MODULO;
            }
            if (res < 0) res += MODULO;
            out.println(res);
        }

        private int[] rec(int n, int[] p, int root) {
            int[] res = new int[n + 1];
            Arrays.fill(res, 1);
            for (int i = 0; i < n; ++i)
                if (p[i] == root) {
                    int[] child = rec(n, p, i);
                    for (int j = 0; j < res.length; ++j) {
                        res[j] = (int) (res[j] * (long) child[j] % MODULO);
                    }
                }
            for (int i = 0; i + 1 < res.length; ++i) {
                res[i + 1] = (int) ((res[i + 1] + res[i]) % MODULO);
            }
            return res;
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
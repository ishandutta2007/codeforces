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
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = removeSquares(in.nextInt());
            Arrays.sort(a);

            int[][] c = new int[n + 1][n + 1];
            c[0][0] = 1;
            for (int i = 1; i < c.length; ++i) {
                c[i][0] = 1;
                for (int j = 1; j < c.length; ++j) {
                    c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MODULO;
                }
            }

            int[] fact = new int[n + 1];
            fact[0] = 1;
            for (int i = 1; i < fact.length; ++i) {
                fact[i] = (int) (i * (long) fact[i - 1] % MODULO);
            }

            int i = 0;
            int[] ways = new int[]{1};

            while (i < n) {
                int j = i;
                while (j < n && a[j] == a[i]) ++j;

                int m = j - i;

                int[] nways = new int[j + 1];
                for (int old = 0; old < ways.length; ++old) {
                    long w = ways[old];
                    for (int blocks = 1; blocks <= m; ++blocks) {
                        for (int intoOld = 0; intoOld <= old && intoOld <= blocks; ++intoOld) {
                            nways[old - intoOld + (m - blocks)] = (int) ((nways[old - intoOld + (m - blocks)] + w * c[old][intoOld] % MODULO * c[i + 1 - old][blocks - intoOld] % MODULO * c[m - 1][blocks - 1] % MODULO * fact[m] % MODULO) % MODULO);
                        }
                    }
                }

                i = j;
                ways = nways;
            }

            out.println(ways[0]);
        }

        private int removeSquares(int x) {
            for (int i = 2; i * i <= x; ++i) {
                while (x % (i * i) == 0) {
                    x /= i * i;
                }
            }
            return x;
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
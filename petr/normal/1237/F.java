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
        static final long MODULO = 998244353;
        static long[] invs;
        static long[] facts;
        static long[] invfacts;

        static {
            int k = (int) 5000;
            invs = new long[k + 2];
            invs[1] = 1;
            for (int i = 2; i <= k + 1; ++i) {
                invs[i] = ((MODULO - (MODULO / i) * (long) invs[(int) (MODULO % i)] % MODULO) % MODULO);
            }
            facts = new long[k + 2];
            invfacts = new long[k + 2];
            facts[0] = 1;
            invfacts[0] = 1;
            for (int i = 1; i <= k + 1; ++i) {
                facts[i] = (facts[i - 1] * (long) i % MODULO);
                invfacts[i] = (invfacts[i - 1] * (long) invs[i] % MODULO);
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int h = in.nextInt();
            int w = in.nextInt();
            int n = in.nextInt();
            boolean[] rowTaken = new boolean[h];
            boolean[] colTaken = new boolean[w];
            for (int i = 0; i < 2 * n; ++i) {
                rowTaken[in.nextInt() - 1] = true;
                colTaken[in.nextInt() - 1] = true;
            }
            int rowFree = 0;
            for (boolean x : rowTaken) if (!x) ++rowFree;
            int colFree = 0;
            for (boolean x : colTaken) if (!x) ++colFree;
            int[] rowWays = findWays(rowTaken);
            int[] colWays = findWays(colTaken);
            long res = 0;
            for (int nr = 0; nr < rowWays.length; ++nr)
                if (rowWays[nr] > 0) {
                    for (int nc = 0; nc < colWays.length && nr + 2 * nc <= colFree && nc + 2 * nr <= rowFree; ++nc)
                        if (colWays[nc] > 0) {
                            res += rowWays[nr] * (long) colWays[nc] % MODULO * facts[rowFree - 2 * nr] % MODULO * invfacts[rowFree - 2 * nr - nc] % MODULO
                                    * facts[colFree - 2 * nc] % MODULO * invfacts[colFree - 2 * nc - nr];
                            res %= MODULO;
                        }
                }
            out.println(res);
        }

        private int[] findWays(boolean[] rowTaken) {
            int[][] ways = new int[3][rowTaken.length / 2 + 1];
            ways[2][0] = 1;
            int cur = -1;
            for (int i = 0; i < rowTaken.length; ++i) {
                cur = i % 3;
                int prev = (i + 2) % 3;
                int pprev = (i + 1) % 3;
                Arrays.fill(ways[cur], 0);
                for (int j = 0; j < ways[cur].length; ++j) {
                    if (ways[prev][j] > 0) {
                        ways[cur][j] += ways[prev][j];
                    }
                    if (ways[pprev][j] > 0 && !rowTaken[i] && !rowTaken[i - 1]) {
                        ways[cur][j + 1] += ways[pprev][j];
                    }
                    if (ways[cur][j] >= MODULO) ways[cur][j] -= MODULO;
                }
            }
            return ways[cur];
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
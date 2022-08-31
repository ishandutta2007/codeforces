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
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            int[][] ways = new int[n / 2 + 1][k + 1];
            int[][] nways = new int[n / 2 + 1][k + 1];
            ways[0][0] = 1;
            int prev = 0;
            for (int cur : a) {
                int delta = cur - prev;
                prev = cur;
                for (int[] y : nways) Arrays.fill(y, 0);
                for (int numGroup = 0; numGroup < ways.length; ++numGroup) {
                    for (int imbalance = 0; imbalance + numGroup * delta <= k; ++imbalance) {
                        int old = ways[numGroup][imbalance];
                        if (old == 0) continue;
                        int newImbalance = imbalance + numGroup * delta;
                        nways[numGroup][newImbalance] = (int) ((nways[numGroup][newImbalance] + old * (long) (numGroup + 1)) % MODULO);
                        if (numGroup + 1 < ways.length) {
                            nways[numGroup + 1][newImbalance] += old;
                            if (nways[numGroup + 1][newImbalance] >= MODULO)
                                nways[numGroup + 1][newImbalance] -= MODULO;
                        }
                        if (numGroup > 0) {
                            nways[numGroup - 1][newImbalance] = (int) ((nways[numGroup - 1][newImbalance] + old * (long) numGroup) % MODULO);
                        }
                    }
                }
                int[][] tmp = ways;
                ways = nways;
                nways = tmp;
            }
            long s = 0;
            for (int imd = 0; imd <= k; ++imd) {
                s += ways[0][imd];
            }
            out.println(s % MODULO);
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
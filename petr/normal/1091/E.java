import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final long INF = (long) 1e18;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] d = new int[n];
            for (int i = 0; i < n; ++i) d[i] = in.nextInt();
            Random random = new Random(54731573551331L + System.currentTimeMillis());
            for (int i = 1; i < n; ++i) {
                int j = random.nextInt(i + 1);
                int t = d[i];
                d[i] = d[j];
                d[j] = t;
            }
            Arrays.sort(d);
            reverse(d);

            int[] counts = new int[n + 1];
            for (int x : d) ++counts[x];

            long psum = 0;
            long sumBelow = 0;
            int countBelow = counts[0];
            long[] da = new long[n];
            long[] db = new long[n + 1];

            for (int k = 0; k <= n; ++k) {
                if (k > 0) {
                    sumBelow += counts[k] * (long) k;
                    countBelow += counts[k];
                    if (d[k - 1] <= k) {
                        sumBelow -= d[k - 1];
                        countBelow -= 1;
                    } else {
                        --counts[d[k - 1]];
                    }
                    if (countBelow > n - k) throw new RuntimeException();
                    psum += d[k - 1];
                    long deltaAfter = psum - k * (long) (k - 1) - sumBelow - (n - k - countBelow) * (long) k;
                    if (deltaAfter - k > 0) {
                        deltaAfter = INF;
                    }
                    da[k - 1] = deltaAfter;
                }
                long deltaBefore = psum - k * (long) (k + 1) - sumBelow - (n - k - countBelow) * (long) (k + 1);
                db[k] = deltaBefore;
            }

            long total = 0;
            for (int x : d) total += x;

            int ptr = 0;

            long[] daPrefix = buildPrefix(da);

            long[] dbSuffix = buildSuffix(db);

            int[] res = new int[n + 1];
            int resCnt = 0;

            for (int us = n; us >= 0; --us) {
                if ((total + us) % 2 != 0) continue;
                while (ptr < d.length && d[ptr] > us) ++ptr;

                if (daPrefix[ptr] - us <= 0 && dbSuffix[n - ptr + 1] + us <= 0) {
                    res[resCnt++] = us;
                }
            }

            for (int i = resCnt - 1; i >= 0; --i) {
                out.print(res[i] + " ");
            }
            if (resCnt == 0) out.print(-1);
            out.println();
        }

        private long[] buildPrefix(long[] da) {
            long[] daPrefix = new long[da.length + 1];
            daPrefix[0] = -INF;
            for (int i = 0; i < da.length; ++i) {
                daPrefix[i + 1] = Math.max(daPrefix[i], da[i]);
            }
            return daPrefix;
        }

        private long[] buildSuffix(long[] db) {
            long[] dbSuffix = new long[db.length + 1];
            dbSuffix[0] = -INF;
            for (int i = 0; i < db.length; ++i) {
                dbSuffix[i + 1] = Math.max(dbSuffix[i], db[db.length - 1 - i]);
            }
            return dbSuffix;
        }

        private void reverse(int[] d) {
            for (int i = 0, j = d.length - 1; i < j; ++i, --j) {
                int t = d[i];
                d[i] = d[j];
                d[j] = t;
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
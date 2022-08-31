import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.IOException;
import java.util.HashMap;
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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        long[] max = new long[60];
        Map<Long, Long> cache = new HashMap<>();

        {
            max[0] = 0;
            for (int i = 1; i < max.length; ++i) {
                long extra = (1L << i) - 1;
                max[i] = max[i - 1] + extra;
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long s = in.nextLong();
            long mult = 1;
            long res = 0;
            for (int a = 0; ; ++a) {
                if (a > 0) {
                    mult += 1L << a;
                    if (mult > s) break;
                }
                long multb = mult;
                for (int b = 0; ; ++b) {
                    if (b > 0) {
                        multb += 1L << b;
                        if (multb > s) break;
                    }
                    long curs = s - multb;
                    curs -= (1L << b) - 1;
                    if (curs < 0) break;
                    long maxExtra = max[Math.max(0, a - 1)] + max[Math.max(0, b - 1)];
                    if (curs > maxExtra) {
                        long more = (curs - maxExtra + multb - 1) / multb;
                        curs -= multb * more;
                    }
                    for (long extra = curs; extra >= 0; extra -= multb) {
                        res += rec(extra, Math.max(0, a - 1), Math.max(0, b - 1));
                    }
                }
            }
            out.println(res);
        }

        private long rec(long need, int a, int b) {
            if (a < b) {
                int t = a;
                a = b;
                b = t;
            }
            if (need < 0) return 0;
            if (need == 0) return 1;
            if (need > max[a] + max[b]) return 0;
            long key = (((need << 6) + a) << 6) + b;
            Long cached = cache.get(key);
            if (cached != null) return cached;
            long res;
            if (a == b) {
                res = rec(need, a - 1, b - 1) + 2 * rec(need - ((1L << a) - 1), a - 1, b - 1) + rec(need - ((1L << a) - 1) * 2, a - 1, b - 1);
            } else {
                res = rec(need, a - 1, b) + rec(need - ((1L << a) - 1), a - 1, b);
            }
            cache.put(key, res);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
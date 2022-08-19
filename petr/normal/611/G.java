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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        static final long MODULO = (long) (1e9 + 7);
        long[] x;
        long[] y;

        long tri(int a, int b, int c) {
            long dx1 = x[b] - x[a];
            long dy1 = y[b] - y[a];
            long dx2 = x[c] - x[a];
            long dy2 = y[c] - y[a];
            return -dx1 * dy2 + dy1 * dx2;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            x = new long[n];
            y = new long[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextLong();
                y[i] = in.nextLong();
            }
            Summer xs = new Summer(x);
            Summer ys = new Summer(y);

            long a = 0;
            for (int i = 1; i + 1 < n; ++i) {
                a += tri(0, i, i + 1);
            }
            long middle = a / 2;
            long res = 0;
            long eq = 0;
            long sum = 0;
            long accumulated = 0;
            int cnt = 0;
            long amRes = 0;
            long amEq = 0;

            for (int start = 0; start < n; ++start) {
                if (cnt > 0) {
                    long sub = tri(start - 1, start, (start + cnt) % n);
                    sum -= sub;
                    long sx = xs.getSum((start + 1) % n, cnt);
                    long sy = ys.getSum((start + 1) % n, cnt);
                    sx -= x[start - 1] * cnt;
                    sy -= y[start - 1] * cnt;
                    sx %= MODULO;
                    sy %= MODULO;
                    long dx1 = x[start] - x[start - 1];
                    long dy1 = y[start] - y[start - 1];
                    long ss = -dx1 * sy + dy1 * sx;
                    accumulated = (accumulated - ss) % MODULO;
                    if (accumulated < 0) accumulated += MODULO;
                    --cnt;
                }
                while (true) {
                    long extra = tri(start, (start + cnt + 1) % n, (start + cnt + 2) % n);
                    if (sum + extra > middle) {
                        break;
                    }
                    sum += extra;
                    accumulated = (accumulated + sum) % MODULO;
                    ++cnt;
                }
                res = (res + accumulated) % MODULO;
                amRes += cnt;
                if (sum * 2 == a) {
                    eq = (eq + sum) % MODULO;
                    ++amEq;
                }
            }
            if (2 * amRes - amEq != n * (long) (n - 3)) throw new RuntimeException();
            res = ((2 * res - eq) % MODULO + MODULO) % MODULO;
            res = (a % MODULO * (n * (long) (n - 3) / 2 % MODULO) - res) % MODULO;
            res = (res + MODULO) % MODULO;
            out.println(res);
        }

        static class Summer {
            long[] pref;
            int n;

            public Summer(long[] x) {
                n = x.length;
                pref = new long[n + 1];
                for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + x[i];
            }

            long getSum(int start, int cnt) {
                if (start + cnt <= n) {
                    return pref[start + cnt] - pref[start];
                } else {
                    return pref[n] - pref[start] + pref[(start + cnt) % n];
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
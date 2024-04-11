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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long r1 = (2 * System.currentTimeMillis() + 1) * 57341564387151L;
            long r2 = (2 * System.currentTimeMillis() + 1) * 78674631561475L;
            int n = in.nextInt();
            long[] x = new long[n];
            long[] y = new long[n];
            long[] ox = new long[n];
            long[] oy = new long[n];
            long sx = 0;
            long sy = 0;
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextLong();
                y[i] = in.nextLong();
                ox[i] = x[i];
                oy[i] = y[i];
                sx += x[i];
                sy += y[i];
                x[i] *= n;
                y[i] *= n;
            }
            for (int i = 0; i < n; ++i) {
                x[i] -= sx;
                y[i] -= sy;
            }
            boolean[] removed = new boolean[n];
            for (int i = 0; i < n; ++i)
                if (!removed[i]) {
                    for (int j = i + 1; j < n; ++j)
                        if (!removed[j] && x[i] + x[j] == 0 && y[i] + y[j] == 0) {
                            removed[i] = true;
                            removed[j] = true;
                            break;
                        }
                }
            boolean needMiddle = n % 2 != 0;
            if (needMiddle) {
                for (int i = 0; i < n; ++i)
                    if (x[i] == 0 && y[i] == 0) {
                        needMiddle = false;
                        removed[i] = true;
                        break;
                    }
            }
            int first = 0;
            while (first < n && removed[first]) ++first;
            if (first >= n) {
                out.println(-1);
                return;
            }
            long[] ps = new long[n];
            long[] qs = new long[n];
            long[] val1 = new long[n];
            long[] val2 = new long[n];
            long[] balance = new long[n];
            int[] nextSameHash = new int[n];
            int[] firstByHash = new int[1 << 15];
            int[] firstGeneration = new int[1 << 15];
            int curGeneration = 0;
            int res = 0;
            outer:
            for (int second = needMiddle ? first : first + 1; second < n; ++second)
                if (!removed[second]) {
                    long ax = x[first] + x[second];
                    long ay = y[first] + y[second];
                    long p = -ay;
                    long q = ax;
                    if (p == 0 && q == 0) throw new RuntimeException();
                    long g = gcd(Math.abs(p), Math.abs(q));
                    p /= g;
                    q /= g;
                    if (p < 0 || (p == 0 && q < 0)) {
                        p = -p;
                        q = -q;
                    }
                    for (int i = 0; i < res; ++i) {
                        if (ps[i] == p && qs[i] == q) {
                            continue outer;
                        }
                    }
                    ++curGeneration;
                    int numNonZero = 0;
                    long e1 = -p * (sx / n) - q * (sy / n);
                    long e2 = -p * (sx % n) - q * (sy % n);
                    e1 += e2 / n;
                    e2 %= n;
                    if (e2 < 0) {
                        e2 += n;
                        e1 -= 1;
                    }
                    for (int i = 0; i < n; ++i)
                        if (!removed[i]) {
                            long v1 = p * ox[i] + q * oy[i] + e1;
                            long v2 = e2;
                            if (v1 < 0 && v2 > 0) {
                                ++v1;
                                v2 -= n;
                            }
                            if (v1 == 0 && v2 == 0) continue;
                            int delta;
                            if (v1 > 0 || v2 > 0) {
                                delta = 1;
                            } else {
                                delta = -1;
                                v1 = -v1;
                                v2 = -v2;
                            }
                            if (v1 < 0 || v2 < 0) throw new RuntimeException();
                            long u = Long.reverse(v1 * r1) + Long.reverse(v2 * r2);
                            int h = (int) (u & (firstByHash.length - 1)); // FIXME
                            if (firstGeneration[h] < curGeneration) {
                                firstGeneration[h] = curGeneration;
                                firstByHash[h] = -1;
                            }
                            int a = firstByHash[h];
                            while (a >= 0) {
                                if (val1[a] == v1 && val2[a] == v2) {
                                    if (balance[a] == 0) ++numNonZero;
                                    balance[a] += delta;
                                    if (balance[a] == 0) --numNonZero;
                                    break;
                                }
                                a = nextSameHash[a];
                            }
                            if (a < 0) {
                                nextSameHash[i] = firstByHash[h];
                                firstByHash[h] = i;
                                val1[i] = v1;
                                val2[i] = v2;
                                balance[i] = delta;
                                ++numNonZero;
                            }
                        }
                    if (numNonZero == 0) {
                        ps[res] = p;
                        qs[res] = q;
                        ++res;
                    }
                }
            out.println(res);
        }

        private long gcd(long a, long b) {
            while (b > 0) {
                long t = a % b;
                a = b;
                b = t;
            }
            return a;
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
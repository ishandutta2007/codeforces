import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        static final int MODULO = 998244353;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            FastFourierTransformModulo fft = new FastFourierTransformModulo(MODULO);
            int n = in.nextInt();
            int k = in.nextInt();
            Map<Integer, int[]> cache = new HashMap<>();
            int[] got = doit(n, k, cache, fft);
            for (int i = 1; i <= k; ++i) {
                if (i > 1) out.print(" ");
                out.print(i < got.length ? got[i] : 0);
            }
            out.println();
        }

        private int[] doit(int n, int k, Map<Integer, int[]> cache, FastFourierTransformModulo fft) {
            int[] res = cache.get(n);
            if (res != null) return res;
            res = new int[Math.min(k, n) + 1];
            if (n == 1) {
                res[0] = 1;
                res[1] = 1;
            } else if (n == 0) {
                res[0] = 1;
            } else {
                int n1 = n / 2;
                int n2 = n - n1;
                int[] r1 = doit(n1, k, cache, fft);
                int[] r2 = doit(n2, k, cache, fft);
                int[] r1m = doit(n1 - 1, k, cache, fft);
                int[] r2m = doit(n2 - 1, k, cache, fft);
                int[] prod = fft.mul(r1, r2);
                int[] prodm = fft.mul(r1m, r2m);
                for (int i = 0; i < res.length; ++i) {
                    if (i < prod.length) {
                        res[i] = (res[i] + prod[i]) % MODULO;
                    }
                    if (i > 0 && i - 1 < prodm.length) {
                        res[i] = (res[i] + prodm[i - 1]) % MODULO;
                    }
                }
            }
            cache.put(n, res);
            return res;
        }

    }

    static class MathUtils {
        public static int nextPowerOfTwo(int x) {
            if (x < 0 || x > (1 << 30)) throw new RuntimeException();
            if (x == 0) return 1;
            if ((x & (x - 1)) == 0) return x;
            return Integer.highestOneBit(x) << 1;
        }

        static int log2(int x) {
            if (x <= 0 || (x & (x - 1)) != 0) throw new RuntimeException();
            return Integer.numberOfTrailingZeros(x);
        }

    }

    static class FastFourierTransformModulo {
        final int MODULO;
        final int[] roots;
        Map<FastFourierTransformModulo.CacheKey, int[]> cache = new HashMap<>();

        public FastFourierTransformModulo(int MODULO) {
            for (int i = 2; i * i <= MODULO; ++i) if (MODULO % i == 0) throw new RuntimeException();
            this.MODULO = MODULO;
            int t = MODULO - 1;
            int p2 = 0;
            while (t % 2 == 0) {
                t /= 2;
                ++p2;
            }
            if (p2 == 0) throw new RuntimeException();
            roots = new int[p2 + 1];
            int start;
            for (start = 2; ; ++start)
                if (pow(start, (MODULO - 1) / 2) != 1) break;
            int pw = MODULO - 1;
            for (int i = 0; i < p2; ++i) {
                roots[i] = pow(start, pw);
                pw /= 2;
            }
        }

        public int[] mul(int[] a, int[] b) {
            int len = MathUtils.nextPowerOfTwo(a.length + b.length - 1);
            FastFourierTransformModulo.CacheKey ca = new FastFourierTransformModulo.CacheKey(a, len);
            if (cache.containsKey(ca)) {
                a = cache.get(ca).clone();
            } else {
                a = Arrays.copyOf(a, len);
                fft(a, false);
                cache.put(ca, a.clone());
            }
            FastFourierTransformModulo.CacheKey cb = new FastFourierTransformModulo.CacheKey(b, len);
            if (cache.containsKey(cb)) {
                b = cache.get(cb).clone();
            } else {
                b = Arrays.copyOf(b, len);
                fft(b, false);
                cache.put(cb, b.clone());
            }
            int[] c = pointwiseMultiply(a, b);
            fft(c, true);
            {
                int mult = pow(c.length, MODULO - 2);
                for (int i = 0; i < c.length; ++i) {
                    c[i] = (int) (c[i] * (long) mult % MODULO);
                }
            }
            return c;
        }

        public int[] pointwiseMultiply(int[] a, int[] b) {
            if (a.length != b.length) throw new RuntimeException();
            int[] c = new int[a.length];
            for (int i = 0; i < a.length; ++i) {
                c[i] = (int) (a[i] * (long) b[i] % MODULO);

            }
            return c;
        }

        private int pow(int a, int k) {
            if (k == 0) return 1;
            if (k % 2 == 0)
                return pow((int) (a * (long) a % MODULO), k / 2);
            return (int) (a * (long) pow(a, k - 1) % MODULO);
        }

        public void fft(int[] arr, boolean inv) {
            if (MathUtils.nextPowerOfTwo(arr.length) != arr.length) throw new RuntimeException();
            int n = arr.length;
            int[] invbits = FastFourierTransformModulo.InvBitsCache.INSTANCE.getInvBits(n);
            for (int i = 0; i < n; ++i) {
                int j = invbits[i];
                if (j > i) {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
            for (int p2 = 1, pow2 = 1; p2 < n; p2 *= 2, pow2 += 1) {
                int w = roots[pow2];
                if (inv) w = pow(w, MODULO - 2);
                for (int big = 0; big < n; big += 2 * p2) {
                    int cur = 1;
                    for (int small = big; small < big + p2; ++small) {
                        int i = small;
                        int j = small + p2;
                        int u = arr[i];
                        int o = arr[j];
                        int v = (int) (o * (long) cur % MODULO);
                        arr[i] = u + v;
                        if (arr[i] >= MODULO) arr[i] -= MODULO;
                        arr[j] = u - v;
                        if (arr[j] < 0) arr[j] += MODULO;
                        cur = (int) (cur * (long) w % MODULO);
                    }
                }
            }
        }

        public static int calcInvBits(int at, int total) {
            int res = 0;
            int rev = total >> 1;
            for (int p2 = 1; p2 < total; p2 <<= 1, rev >>= 1)
                if ((at & p2) != 0)
                    res |= rev;
            return res;
        }

        static class CacheKey {
            int[] a;
            int len;

            public CacheKey(int[] a, int len) {
                this.a = a;
                this.len = len;
            }


            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                FastFourierTransformModulo.CacheKey cacheKey = (FastFourierTransformModulo.CacheKey) o;

                if (len != cacheKey.len) return false;
                return a == cacheKey.a;
            }


            public int hashCode() {
                int result = a.hashCode();
                result = 31 * result + len;
                return result;
            }

        }

        static class InvBitsCache {
            int[][] cache = new int[0][];
            static FastFourierTransformModulo.InvBitsCache INSTANCE = new FastFourierTransformModulo.InvBitsCache();

            private InvBitsCache() {
            }

            synchronized int[] getInvBits(int size) {
                int logsize = MathUtils.log2(size);
                if (logsize >= cache.length) {
                    cache = Arrays.copyOf(cache, logsize + 1);
                }
                if (cache[logsize] == null) {
                    cache[logsize] = new int[size];
                    for (int i = 0; i < size; ++i) cache[logsize][i] = calcInvBits(i, size);
                }
                return cache[logsize];
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
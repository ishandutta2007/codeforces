import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        static final int MODULO = (int) 1e9 + 7;

        Desc factor(int x, int[] globalPrimes) {
            Desc res = new Desc();
            res.pows = new int[globalPrimes.length];
            for (int i = 0; i < globalPrimes.length; ++i) {
                while (x % globalPrimes[i] == 0) {
                    x /= globalPrimes[i];
                    ++res.pows[i];
                }
            }
            int[] primes = new int[100];
            int[] ppow = new int[100];
            int nprimes = 0;
            int tmp = x;
            for (int i = 2; i * i <= tmp; ++i)
                if (tmp % i == 0) {
                    primes[nprimes++] = i;
                    while (tmp % i == 0) {
                        tmp /= i;
                        ++ppow[nprimes - 1];
                    }
                }
            if (tmp > 1) {
                primes[nprimes++] = tmp;
                ++ppow[nprimes - 1];
            }
            res.extraPrimes = Arrays.copyOf(primes, nprimes);
            res.extraPrimePow = Arrays.copyOf(ppow, nprimes);
            return res;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
            }

            for (int i = 0; i < n; ++i)
                if (b[i] == 1) {
                    out.println(checkOne(n, a, b, i, 0));
                    return;
                }

            int[] primes = new int[100];
            int nprimes = 0;
            int tmp = b[0];
            for (int i = 2; i * i <= tmp; ++i)
                if (tmp % i == 0) {
                    primes[nprimes++] = i;
                    while (tmp % i == 0) tmp /= i;
                }
            if (tmp > 1) {
                primes[nprimes++] = tmp;
            }
            primes = Arrays.copyOf(primes, nprimes);

            Desc basic = factor(b[0], primes);
            Desc ba = factor(a[0], primes);

            int[] start = new int[n];
            int[] step = new int[n];
            start[0] = ba.pows[0];
            step[0] = basic.pows[0];

            for (int i = 1; i < n; ++i) {
                Desc other = factor(b[i], primes);
                if (other.extraPrimes.length > 0) {
                    int p = other.extraPrimes[0];
                    tmp = a[0];
                    int needPow = 0;
                    while (tmp % p == 0) {
                        tmp /= p;
                        ++needPow;
                    }
                    tmp = a[i];
                    while (tmp % p == 0) {
                        tmp /= p;
                        --needPow;
                    }
                    if (needPow < 0 || needPow % other.extraPrimePow[0] != 0) {
                        out.println(-1);
                        return;
                    }
                    int times = needPow / other.extraPrimePow[0];
                    out.println(checkOne(n, a, b, i, times));
                    return;
                }

                int nonzero = 0;
                while (other.pows[nonzero] == 0) ++nonzero;
                int p = other.pows[nonzero];
                int q = basic.pows[nonzero];
                int nonpropindex = -1;
                for (int j = 0; j < primes.length; ++j) {
                    if (p * basic.pows[j] != q * other.pows[j]) {
                        nonpropindex = j;
                        break;
                    }
                }

                Desc bo = factor(a[i], primes);

                if (nonpropindex >= 0) {
                    if (nonpropindex == nonzero) throw new RuntimeException();
                    int s1 = ba.pows[nonzero];
                    int s2 = ba.pows[nonpropindex];
                    int sv1 = basic.pows[nonzero];
                    int sv2 = basic.pows[nonpropindex];
                    int t1 = bo.pows[nonzero];
                    int t2 = bo.pows[nonpropindex];
                    int tv1 = other.pows[nonzero];
                    int tv2 = other.pows[nonpropindex];
                    int needDiff = sv2 * s1 - sv1 * s2 - (sv2 * t1 - sv1 * t2);
                    int each = sv2 * tv1 - sv1 * tv2;
                    if (each == 0) throw new RuntimeException();
                    if (each < 0) {
                        needDiff = -needDiff;
                        each = -each;
                    }
                    if (needDiff < 0 || needDiff % each != 0) {
                        out.println(-1);
                        return;
                    }
                    out.println(checkOne(n, a, b, i, needDiff / each));
                    return;
                }

                if (bo.extraPrimes.length != ba.extraPrimes.length) {
                    out.println(-1);
                    return;
                }

                for (int j = 0; j < bo.extraPrimes.length; ++j) {
                    if (bo.extraPrimes[j] != ba.extraPrimes[j] || bo.extraPrimePow[j] != ba.extraPrimePow[j]) {
                        out.println(-1);
                        return;
                    }
                }

                int[] delta = new int[primes.length];
                for (int j = 0; j < primes.length; ++j) delta[j] = bo.pows[j] - ba.pows[j];
                for (int j = 0; j < primes.length; ++j) {
                    if (delta[j] * basic.pows[0] != delta[0] * basic.pows[j]) {
                        out.println(-1);
                        return;
                    }
                }

                start[i] = bo.pows[0];
                step[i] = other.pows[0];
            }

            int maxStart = start[0];
            for (int x : start) maxStart = Math.max(maxStart, x);
            long lcm = 1;
            long rem = 0;
            for (int i = 0; i < n; ++i) {
                int needRem = (((start[i] - maxStart) % step[i]) + step[i]) % step[i];
                int needBy = step[i];
                long g = gcd(needBy, lcm);
                if (rem % g != needRem % g) {
                    out.println(-1);
                    return;
                }
                long rg = rem % g;
                rem /= g;
                lcm /= g;
                needBy /= g;
                needRem /= g;
                if (needBy == 1) {

                } else if (lcm == 1) {
                    lcm = needBy;
                    rem = needRem;
                } else {
                    long oneForFirst = needBy * BigInteger.valueOf(needBy % lcm).modInverse(BigInteger.valueOf(lcm)).longValue();
                    long oneForSecond = lcm * BigInteger.valueOf(lcm % needBy).modInverse(BigInteger.valueOf(needBy)).longValue();
                    lcm = lcm * needBy;
                    rem = (BigInteger.valueOf(rem).multiply(BigInteger.valueOf(oneForFirst)).mod(BigInteger.valueOf(lcm)).longValue() + needRem * oneForSecond) % lcm;
                }
                lcm *= g;
                rem = rem * g + rg;
            }

            if ((rem + (maxStart - start[0])) % step[0] != 0) throw new RuntimeException();
            long times = (rem + (maxStart - start[0])) / step[0];

            out.println(getRes(a[0], b[0], times));
        }

        private long getRes(long a, long b, long times) {
            if (times == 0) return a % MODULO;
            if (times % 2 == 0) {
                return getRes(a, b * b % MODULO, times / 2);
            }
            return getRes(a, b, times - 1) * b % MODULO;
        }

        private long gcd(long a, long b) {
            while (b > 0) {
                long t = a % b;
                a = b;
                b = t;
            }
            return a;
        }

        private int checkOne(int n, int[] a, int[] b, int i, int times) {
            Desc fa = factor(a[i], new int[0]);
            Desc fb = factor(b[i], fa.extraPrimes);
            int[] primes = new int[fa.extraPrimes.length + fb.extraPrimes.length];
            System.arraycopy(fa.extraPrimes, 0, primes, 0, fa.extraPrimes.length);
            System.arraycopy(fb.extraPrimes, 0, primes, fa.extraPrimes.length, fb.extraPrimes.length);
            int[] pows = new int[primes.length];
            fb = factor(b[i], primes);
            if (fb.extraPrimes.length != 0) throw new RuntimeException();
            for (int j = 0; j < primes.length; ++j) pows[j] += times * fb.pows[j];
            fa = factor(a[i], primes);
            if (fa.extraPrimes.length != 0) throw new RuntimeException();
            for (int j = 0; j < primes.length; ++j) pows[j] += fa.pows[j];
            for (int k = 0; k < n; ++k) {
                fa = factor(a[k], primes);
                if (fa.extraPrimes.length != 0) return -1;
                fb = factor(b[k], primes);
                int reps = -1;
                for (int j = 0; j < primes.length; ++j) {
                    if (fa.pows[j] > pows[j]) return -1;
                    if (fb.pows[j] == 0) {
                        if (fa.pows[j] != pows[j]) return -1;
                        continue;
                    }
                    if ((pows[j] - fa.pows[j]) % fb.pows[j] != 0) return -1;
                    int creps = (pows[j] - fa.pows[j]) / fb.pows[j];
                    if (reps < 0 || reps == creps) {
                        reps = creps;
                    } else {
                        return -1;
                    }
                }
                if (reps > 0 && fb.extraPrimes.length != 0) return -1;
            }
            return (int) getRes(a[i], b[i], times);
        }

        static class Desc {
            int[] pows;
            int[] extraPrimes;
            int[] extraPrimePow;

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
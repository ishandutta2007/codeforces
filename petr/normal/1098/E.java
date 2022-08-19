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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int[] smallestDivisor;

        TaskE.Factorization factorize(int x) {
            int cnt = 0;
            int tmp = x;
            while (tmp > 1) {
                int cur = smallestDivisor[tmp];
                while (tmp % cur == 0) {
                    tmp /= cur;
                }
                ++cnt;
            }
            TaskE.Factorization f = new TaskE.Factorization(cnt);
            tmp = x;
            cnt = 0;
            while (tmp > 1) {
                int cur = smallestDivisor[tmp];
                f.p[cnt] = cur;
                while (tmp % cur == 0) {
                    tmp /= cur;
                    ++f.k[cnt];
                }
                if (f.k[cnt] == 0) throw new RuntimeException();
                ++cnt;
            }
            return f;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt();
            int maxa = 2;
            for (int x : a) maxa = Math.max(maxa, x);
            ++maxa;

            TaskE.Factorization[] fs = factorizeAll(n, a, maxa);

            long[] bCounts = buildB(n, maxa, fs);

            long bTotal = 0;
            long bSize = 0;
            for (int i = 0; i < bCounts.length; ++i) {
                bTotal += i * bCounts[i];
                bSize += bCounts[i];
            }

            long position = ((bSize * (bSize + 1) / 2) - 1) / 2;

            long left = -1;
            long right = bTotal;
            while (right - left > 1) {
                long middle = (left + right) / 2;
                if (howManyLessOrEqual(bCounts, middle) <= position) {
                    left = middle;
                } else {
                    right = middle;
                }
            }

            out.println(right);
        }

        private long howManyLessOrEqual(long[] bCounts, long bound) {
            long res = 0;
            int right = 0;
            long rightAt = 0;
            long rightTotal = bCounts[0];
            long beforeRight = 0;
            long countBeforeRight = 0;
            long beforeLeft = 0;
            long countBeforeLeft = 0;
            for (int left = 0; left < bCounts.length; ++left) {
                long leftAt = 0;
                long leftTotal = bCounts[left];
                while (leftAt < leftTotal) {
                    while (right < bCounts.length && beforeRight + (rightTotal - rightAt) * right <= beforeLeft + bound) {
                        beforeRight += (rightTotal - rightAt) * right;
                        countBeforeRight += (rightTotal - rightAt);
                        ++right;
                        if (right < bCounts.length) {
                            rightAt = 0;
                            rightTotal = bCounts[right];
                        } else {
                            rightAt = -1;
                            rightTotal = -1;
                        }
                    }
                    if (right == bCounts.length) {
                        long by = leftTotal - leftAt;
                        res += ((countBeforeRight - countBeforeLeft) + (countBeforeRight - countBeforeLeft - by + 1)) * by / 2;
                        leftAt += by;
                        countBeforeLeft += by;
                        beforeLeft += by * left;
                    } else {
                        long maxRight = beforeRight + (rightTotal - rightAt) * right;
                        long by = leftTotal - leftAt;
                        by = Math.min(by, (maxRight - beforeLeft - bound + left - 1) / left);
                        if (by == 0) {
                            throw new RuntimeException();
                        }

                        res += countBeforeRight * by + sumIntPart(left, beforeLeft + bound - beforeRight, right, by);
                        res -= (countBeforeLeft + countBeforeLeft + by - 1) * by / 2;

                        leftAt += by;
                        countBeforeLeft += by;
                        beforeLeft += by * left;
                    }
                }
            }
            return res;
        }

        private long intPartSum(long mult, long modulo, long cnt, long add) {
            if (cnt == 0)
                return 0;
            if (add >= modulo)
                return intPartSum(mult, modulo, cnt, add % modulo) + cnt * (long) (add / modulo);
            if (add < 0)
                return intPartSum(mult, modulo, cnt, add % modulo + modulo) + cnt * (long) (add / modulo - 1);
            if (mult >= modulo)
                return intPartSum(mult % modulo, modulo, cnt, add) + (mult / modulo) * (long) cnt * (long) (cnt + 1) / 2;
            if (mult == 0) {
                return 0;
            }
            int max = (int) ((mult * (long) cnt + add) / modulo);
            return max * (long) cnt - intPartSum(modulo, mult, max, -add - 1);
        }

        private long sumIntPart(long a, long b, long c, long count) {
            if (count == 0) return 0;
            long got = b / c + intPartSum(a, c, count - 1, b);
        /*long expected = 0;
        for (int i = 0; i < count; ++i) {
            expected += (a * i + b) / c;
        }
        if (got != expected) {
            throw new RuntimeException();
        }*/
            return got;
        }

        private long[] buildB(int n, int maxa, TaskE.Factorization[] fs) {
            long[] bCounts = new long[maxa];
            for (int left = 0; left < n; ++left) {
                TaskE.Factorization f = fs[left];
                int[] primes = f.p;
                int[] pow = f.k.clone();
                int[] decrease = f.nextDecrease.clone();
                int at = left;
                while (at < n) {
                    int prod = 1;
                    for (int i = 0; i < primes.length; ++i) {
                        for (int j = 0; j < pow[i]; ++j) {
                            prod *= primes[i];
                        }
                    }
                    int dest = n;
                    for (int i = 0; i < primes.length; ++i) {
                        dest = Math.min(dest, decrease[i]);
                    }
                    bCounts[prod] += dest - at;
                    at = dest;
                    if (at < n) {
                        TaskE.Factorization cur = fs[at];
                        for (int i = 0; i < primes.length; ++i)
                            if (decrease[i] == at) {
                                int pos = Arrays.binarySearch(cur.p, primes[i]);
                                if (pos >= 0) {
                                    pow[i] = cur.k[pos];
                                    decrease[i] = cur.nextDecrease[pos];
                                } else {
                                    pow[i] = 0;
                                    decrease[i] = n;
                                }
                            }
                    }
                }
            }
            return bCounts;
        }

        private TaskE.Factorization[] factorizeAll(int n, int[] a, int maxa) {
            smallestDivisor = new int[maxa];
            for (int i = 2; i < maxa; ++i) {
                smallestDivisor[i] = i;
            }
            for (int i = 2; i * i < maxa; ++i)
                if (smallestDivisor[i] == i) {
                    for (int j = i * i; j < maxa; j += i) if (smallestDivisor[j] == j) smallestDivisor[j] = i;
                }

            TaskE.Factorization[] fs = new TaskE.Factorization[n];
            for (int i = 0; i < n; ++i) fs[i] = factorize(a[i]);

            int[] stackTop = new int[maxa];
            int[] stackTopPos = new int[maxa];

            Arrays.fill(stackTop, n);
            Arrays.fill(stackTopPos, -1);

            for (int i = n - 1; i >= 0; --i) {
                TaskE.Factorization f = fs[i];
                for (int j = 0; j < f.p.length; ++j) {
                    int what = f.p[j];
                    int deg = f.k[j];
                    if (stackTop[what] != i + 1) {
                        stackTop[what] = i + 1;
                        stackTopPos[what] = -1;
                    }
                    while (stackTopPos[what] >= 0 && fs[stackTop[what]].k[stackTopPos[what]] >= deg) {
                        int next = fs[stackTop[what]].nextInStackIndex[stackTopPos[what]];
                        int nextPos = fs[stackTop[what]].nextInStackPos[stackTopPos[what]];
                        stackTop[what] = next;
                        stackTopPos[what] = nextPos;
                    }
                    f.nextDecrease[j] = stackTop[what];
                    f.nextInStackIndex[j] = stackTop[what];
                    f.nextInStackPos[j] = stackTopPos[what];
                    stackTop[what] = i;
                    stackTopPos[what] = j;
                }
            }
            return fs;
        }

        static class Factorization {
            int[] p;
            int[] k;
            int[] nextDecrease;
            int[] nextInStackIndex;
            int[] nextInStackPos;

            public Factorization(int len) {
                p = new int[len];
                k = new int[len];
                nextDecrease = new int[len];
                nextInStackIndex = new int[len];
                nextInStackPos = new int[len];
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
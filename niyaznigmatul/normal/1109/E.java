import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Niyaz Nigmatullin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int MOD;

        int mul(int a, int b) {
            return (int) ((long) a * b % MOD);
        }

        int add(int a, int b) {
            a += b;
            if (a >= MOD) a -= MOD;
            return a;
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            MOD = in.nextInt();
            int phi = MOD;
            Factor[] f = MathUtils.factorize(MOD);
            for (Factor e : f) phi -= phi / e.prime;
            FenwickRev[] fs = new FenwickRev[f.length];
            for (int i = 0; i < fs.length; i++) {
                fs[i] = new FenwickRev(n);
            }
            SegmentTree tree = new SegmentTree(n);
            SegmentTree coprime = new SegmentTree(n);
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                tree.set(i, a[i] % MOD);
                for (int j = 0; j < f.length; j++) {
                    int prime = (int) f[j].prime;
                    while (a[i] % prime == 0) {
                        fs[j].add(i, i + 1, 1);
                        a[i] /= prime;
                    }
                }
                coprime.set(i, a[i]);
            }
            int q = in.nextInt();
            for (int cq = 0; cq < q; cq++) {
                int op = in.nextInt();
                if (op == 1) {
                    int left = in.nextInt() - 1;
                    int right = in.nextInt();
                    int val = in.nextInt();
                    tree.makeMul(left, right, val % MOD);
                    for (int j = 0; j < f.length; j++) {
                        int prime = (int) f[j].prime;
                        while (val % prime == 0) {
                            fs[j].add(left, right, 1);
                            val /= prime;
                        }
                    }
                    coprime.makeMul(left, right, val % MOD);
                } else if (op == 2) {
                    int pos = in.nextInt() - 1;
                    int val = in.nextInt();
                    for (int j = 0; j < f.length; j++) {
                        int prime = (int) f[j].prime;
                        while (val % prime == 0) {
                            fs[j].add(pos, pos + 1, -1);
                            val /= prime;
                        }
                    }
                    int newVal = coprime.getSum(pos, pos + 1);
                    newVal = mul(newVal, MathUtils.modPow(val, phi - 1, MOD));
                    coprime.set(pos, newVal);
                    for (int j = 0; j < f.length; j++) {
                        newVal = mul(newVal, MathUtils.modPow((int) f[j].prime, fs[j].getElement(pos), MOD));
                    }
                    tree.set(pos, newVal);
                } else {
                    int left = in.nextInt() - 1;
                    int right = in.nextInt();
                    out.println(tree.getSum(left, right));
                }
            }
        }

        class SegmentTree {
            int[] sum;
            int[] coef;
            int n;

            SegmentTree(int size) {
                n = 1;
                while (n < size) n *= 2;
                sum = new int[2 * n];
                coef = new int[2 * n];
                Arrays.fill(coef, 1);
            }

            void set(int v, int x) {
                set(1, 0, n, v, x);
            }

            int getSum(int left, int right) {
                return getSum(1, 0, n, left, right);
            }

            void relax(int v) {
                if (coef[v] == 1) return;
                sum[v] = getSumVertex(v);
                coef[2 * v] = mul(coef[2 * v], coef[v]);
                coef[2 * v + 1] = mul(coef[2 * v + 1], coef[v]);
                coef[v] = 1;
            }

            int getSum(int v, int left, int right, int L, int R) {
                if (right <= L || R <= left) return 0;
                if (L <= left && right <= R) {
                    return getSumVertex(v);
                }
                relax(v);
                int mid = (left + right) >> 1;
                return add(getSum(v * 2, left, mid, L, R), getSum(v * 2 + 1, mid, right, L, R));
            }

            void set(int v, int left, int right, int pos, int val) {
                if (left == right - 1) {
                    sum[v] = val;
                    coef[v] = 1;
                    return;
                }
                relax(v);
                int mid = (left + right) >> 1;
                if (pos < mid) {
                    set(v * 2, left, mid, pos, val);
                } else {
                    set(v * 2 + 1, mid, right, pos, val);
                }
                sum[v] = add(getSumVertex(2 * v), getSumVertex(2 * v + 1));
            }

            void makeMul(int left, int right, int val) {
                makeMul(1, 0, n, left, right, val);
            }

            void makeMul(int v, int left, int right, int L, int R, int val) {
                if (right <= L || R <= left) return;
                if (L <= left && right <= R) {
                    coef[v] = mul(coef[v], val);
                    return;
                }
                relax(v);
                int mid = (left + right) >> 1;
                makeMul(v * 2, left, mid, L, R, val);
                makeMul(v * 2 + 1, mid, right, L, R, val);
                sum[v] = add(getSumVertex(2 * v), getSumVertex(2 * v + 1));
            }

            int getSumVertex(int v) {
                return mul(sum[v], coef[v]);
            }

        }

    }

    static class FastScanner extends BufferedReader {
        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }

        public int read() {
            try {
                int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
                return ret;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

        static boolean isWhiteSpace(int c) {
            return c >= 0 && c <= 32;
        }

        public int nextInt() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int ret = 0;
            while (c >= 0 && !isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                ret = ret * 10 + c - '0';
                c = read();
            }
            return ret * sgn;
        }

        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                return null;
            }
        }

    }

    static class Factor {
        public long prime;
        public int pow;

        public Factor(long prime, int pow) {
            this.prime = prime;
            this.pow = pow;
        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }

    static class MathUtils {
        public static Factor[] factorize(long n) {
            List<Factor> ret = new ArrayList<Factor>();
            for (long i = 2; i * i <= n; i++) {
                if (n % i != 0) {
                    continue;
                }
                int count = 0;
                while (n % i == 0) {
                    n /= i;
                    count++;
                }
                ret.add(new Factor(i, count));
            }
            if (n > 1) {
                ret.add(new Factor(n, 1));
            }
            return ret.toArray(new Factor[ret.size()]);
        }

        public static int modPow(int a, int b, int mod) {
            int ret = 1;
            a = (a % mod + mod) % mod;
            while (b > 0) {
                if ((b & 1) == 1) {
                    ret = (int) ((long) ret * a % mod);
                }
                a = (int) ((long) a * a % mod);
                b >>= 1;
            }
            return ret % mod;
        }

        public static int modPow(int a, long b, int mod) {
            int ret = 1;
            a = (a % mod + mod) % mod;
            while (b > 0) {
                if ((b & 1) == 1) {
                    ret = (int) ((long) ret * a % mod);
                }
                a = (int) ((long) a * a % mod);
                b >>= 1;
            }
            return ret;
        }

    }

    static class FenwickRev {
        long[] a;

        public FenwickRev(int n) {
            a = new long[n];
        }

        public void add(int x, long y) {
            for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
                a[i] += y;
            }
        }

        public long getElement(int x) {
            long ret = 0;
            for (int i = x; i < a.length; i |= i + 1) {
                ret += a[i];
            }
            return ret;
        }

        public void add(int left, int right, int y) {
            add(left - 1, -y);
            add(right - 1, y);
        }

    }
}
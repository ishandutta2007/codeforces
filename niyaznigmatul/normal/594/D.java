import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final int MOD = 1_000_000_007;

        static int mul(int a, int b) {
            return (int) ((long) a * b % MOD);
        }

        static int modInverse(int x) {
            return MathUtils.modPow(x, MOD - 2, MOD);
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);
            int m = in.nextInt();
            int[] ql = new int[m];
            int[] qr = new int[m];
            int[] headQ = new int[n];
            Arrays.fill(headQ, -1);
            int[] nextQ = new int[m];
            for (int i = 0; i < m; i++) {
                ql[i] = in.nextInt() - 1;
                qr[i] = in.nextInt() - 1;
                nextQ[i] = headQ[qr[i]];
                headQ[qr[i]] = i;
            }
            int maxA = 0;
            for (int i : a) maxA = Math.max(maxA, i);
            maxA++;
            int[] p = MathUtils.getFactoringSieve(maxA);
            int[] lastPrime = new int[maxA];
            Arrays.fill(lastPrime, -1);
            Tree tree = new Tree(n);
            int[] answer = new int[m];
            for (int i = 0; i < n; i++) {
                int x = a[i];
                while (x > 1) {
                    int cp = p[x];
                    if (lastPrime[cp] < i) {
                        int id = lastPrime[cp];
                        if (id >= 0) {
                            tree.makeMul(id, mul(cp, modInverse(cp - 1)));
                        }
                        lastPrime[cp] = i;
                        tree.makeMul(i, cp - 1);
                    } else {
                        tree.makeMul(i, cp);
                    }
                    x /= cp;
                }
                for (int e = headQ[i]; e >= 0; e = nextQ[e]) {
                    answer[e] = tree.get(ql[e], qr[e]);
                }
            }
            for (int i : answer) {
                out.println(i);
            }
        }

        static class Tree {
            int[] a;
            int n;

            Tree(int size) {
                n = Integer.highestOneBit(size) * 2;
                a = new int[2 * n];
                Arrays.fill(a, 1);
            }

            void makeMul(int x, int y) {
                x += n;
                while (x > 0) {
                    a[x] = mul(a[x], y);
                    x >>= 1;
                }
            }

            int get(int l, int r) {
                l += n;
                r += n;
                int ret = 1;
                while (l <= r) {
                    if ((l & 1) == 1) {
                        ret = mul(ret, a[l++]);
                    }
                    if ((r & 1) == 0) {
                        ret = mul(ret, a[r--]);
                    }
                    l >>= 1;
                    r >>= 1;
                }
                return ret;
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

        public int[] readIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }

    static class MathUtils {
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

        public static int[] getFactoringSieve(int n) {
            int[] p = new int[n];
            for (int i = 2; i < n; i++) {
                if (p[i] > 0) {
                    continue;
                }
                for (int j = i; j < n; j += i) {
                    p[j] = i;
                }
            }
            return p;

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
}
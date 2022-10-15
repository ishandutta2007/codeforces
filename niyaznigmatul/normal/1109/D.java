import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.Writer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        static final int MOD = 1000000007;

        static int mul(int a, int b) {
            return (int) ((long) a * b % MOD);
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] FACT = new int[m + n];
            int[] INV = new int[m + n];
            int[] INVFACT = new int[m + n];
            INV[1] = 1;
            for (int i = 2; i < INV.length; i++) {
                INV[i] = mul(INV[MOD % i], MOD - MOD / i);
            }
            FACT[0] = 1;
            INVFACT[0] = 1;
            for (int i = 1; i < FACT.length; i++) {
                FACT[i] = mul(FACT[i - 1], i);
                INVFACT[i] = mul(INVFACT[i - 1], INV[i]);
            }
            int ans = 0;
            for (int i = 2; i <= n; i++) {
                int edges = i - 1;
                int left = m - edges;
                if (left >= 0) {
                    int from = left + edges - 1;
                    int choose = edges - 1;
                    int ways = choose(FACT, INVFACT, from, choose);
                    ways = mul(ways, choose(FACT, INVFACT, n - 2, i - 2));
                    ways = mul(ways, FACT[i - 2]);
                    if (i < n) {
                        ways = mul(ways, MathUtils.modPow(n, n - i - 1, MOD));
                        ways = mul(ways, i);
                        ways = mul(ways, MathUtils.modPow(m, n - i, MOD));
                    }
                    ans += ways;
                    if (ans >= MOD) ans -= MOD;
                }
            }
            out.println(ans);
        }

        static int choose(int[] FACT, int[] INVFACT, int from, int choose) {
            return mul(FACT[from], mul(INVFACT[choose], INVFACT[from - choose]));
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

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }
}
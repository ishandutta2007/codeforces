import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.math.BigInteger;
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
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            n++;
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                String s = in.next();
                if (s.equals("?")) {
                    a[i] = Integer.MIN_VALUE;
                } else {
                    a[i] = Integer.parseInt(s);
                }
            }
            int who = 0;
            int no = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != Integer.MIN_VALUE) {
                    who ^= 1;
                } else no++;
            }
            if (k == 0) {
                if (a[0] == 0) {
                    out.println("Yes");
                } else if (a[0] != Integer.MIN_VALUE) {
                    out.println("No");
                } else {
                    if (who == 0) {
                        out.println("No");
                    } else {
                        out.println("Yes");
                    }
                }
                return;
            }
            if (no == 0) {
                long z = 0;
                int MOD = BigInteger.probablePrime(30, new Random(System.nanoTime())).intValue();
                for (int i = n - 1; i >= 0; i--) {
                    z = z * k + a[i];
                    z %= MOD;
                    if (z < 0) z += MOD;
                }
                if (z == 0) {
                    out.println("Yes");
                } else {
                    out.println("No");
                }
                return;
            }
            if (n % 2 == 1) {
                out.println("No");
            } else {
                out.println("Yes");
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

        public String next() {
            StringBuilder sb = new StringBuilder();
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            if (c < 0) {
                return null;
            }
            while (c >= 0 && !isWhiteSpace(c)) {
                sb.appendCodePoint(c);
                c = read();
            }
            return sb.toString();
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
}
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.HashMap;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.Map;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);
            int[] b = in.readIntArray(n);
            Map<Rational, Integer> set = new HashMap<>();
            int cc = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) {
                    if (b[i] == 0) {
                        cc++;
                    }
                    continue;
                }
                Rational e = Rational.valueOf(-b[i], a[i]);
                Integer g = set.get(e);
                if (g == null) {
                    g = 1;
                } else {
                    g += 1;
                }
                set.put(e, g);
            }
            int ans = 0;
            for (int e : set.values()) {
                ans = Math.max(ans, e);
            }
            out.println(ans + cc);
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

    static class Rational implements Comparable<Rational> {
        BigInteger num;
        BigInteger den;

        public Rational(long a) {
            num = BigInteger.valueOf(a);
            den = BigInteger.ONE;
            norm();
        }

        public Rational(long a, long b) {
            if (b == 0) {
                throw new Error("b == 0");
            }
            num = BigInteger.valueOf(a);
            den = BigInteger.valueOf(b);
            norm();
        }

        public Rational(BigInteger a) {
            if (a == null) {
                throw new NullPointerException();
            }
            num = a;
            den = BigInteger.ONE;
            norm();
        }

        public Rational(BigInteger num, BigInteger den) {
            if (num == null || den == null) {
                throw new NullPointerException();
            }
            if (den.equals(BigInteger.ZERO)) {
                throw new Error("den == 0");
            }
            this.num = num;
            this.den = den;
            norm();
        }

        private void norm() {
            if (den.compareTo(BigInteger.ZERO) < 0) {
                den = den.negate();
                num = num.negate();
            }
            BigInteger g = num.gcd(den);
            if (g.compareTo(BigInteger.ONE) > 0) {
                num = num.divide(g);
                den = den.divide(g);
            }
        }

        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + ((den == null) ? 0 : den.hashCode());
            result = prime * result + ((num == null) ? 0 : num.hashCode());
            return result;
        }

        public boolean equals(Object obj) {
            Rational other = (Rational) obj;
            if (den == null) {
                if (other.den != null)
                    return false;
            } else if (!den.equals(other.den))
                return false;
            if (num == null) {
                if (other.num != null)
                    return false;
            } else if (!num.equals(other.num))
                return false;
            return true;
        }

        public static Rational valueOf(long a, long b) {
            return new Rational(a, b);
        }

        public String toString() {
            return num.toString()
                    + (den.equals(BigInteger.ONE) ? "" : "/" + den.toString());
        }

        public int compareTo(Rational o) {
            return num.multiply(o.den).compareTo(den.multiply(o.num));
        }

    }
}
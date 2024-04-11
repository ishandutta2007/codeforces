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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int t = in.nextInt();
            t = Math.min(t, 1500);
            Rational[][] a = new Rational[n][];
            for (int i = 0; i < n; i++) {
                a[i] = new Rational[i + 1];
                Arrays.fill(a[i], Rational.ZERO);
            }
            for (int i = 0; i < t; i++) {
                a[0][0] = a[0][0].add(Rational.ONE);
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y <= x; y++) {
                        Rational add = a[x][y].compareTo(Rational.ONE) > 0 ? a[x][y].subtract(Rational.ONE) : Rational.ZERO;
                        a[x][y] = a[x][y].subtract(add);
                        add = add.divide(Rational.valueOf(2));
                        if (x + 1 < n) {
                            a[x + 1][y] = a[x + 1][y].add(add);
                            a[x + 1][y + 1] = a[x + 1][y + 1].add(add);
                        }
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (Rational z : a[i]) {
                    if (z.equals(Rational.ONE)) {
                        ans++;
                    }
                }
            }
            out.println(ans);
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

    }

    static class Rational implements Comparable<Rational> {
        BigInteger num;
        BigInteger den;
        public static Rational ZERO = new Rational(BigInteger.ZERO);
        public static Rational ONE = new Rational(BigInteger.ONE);

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

        public Rational add(Rational r) {
            BigInteger a = num.multiply(r.den).add(r.num.multiply(den));
            BigInteger b = den.multiply(r.den);
            return new Rational(a, b);
        }

        public Rational subtract(Rational r) {
            BigInteger a = num.multiply(r.den).subtract(r.num.multiply(den));
            BigInteger b = den.multiply(r.den);
            return new Rational(a, b);
        }

        public Rational divide(Rational r) {
            return new Rational(num.multiply(r.den), den.multiply(r.num));
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

        public static Rational valueOf(long a) {
            return new Rational(a);
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
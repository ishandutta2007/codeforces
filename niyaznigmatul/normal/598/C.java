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
import java.util.Comparator;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            Integer[] id = new Integer[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
                id[i] = i;
            }
            Arrays.sort(id, new Comparator<Integer>() {

                int get(int x, int y) {
                    if (x > 0) {
                        return y > 0 ? 2 : y < 0 ? 8 : 1;
                    } else if (x == 0) {
                        return y > 0 ? 3 : y < 0 ? 7 : 0;
                    } else {
                        return y > 0 ? 4 : y < 0 ? 6 : 5;
                    }
                }


                public int compare(Integer o1, Integer o2) {
                    int c = get(x[o1], y[o1]) - get(x[o2], y[o2]);
                    if (c != 0) return c;
                    return -Integer.signum(x[o1] * y[o2] - x[o2] * y[o1]);
                }
            });
            Rational angle = null;
            int ansi = 0;
            int ansj = 1;
            for (int it = 0; it < n; it++) {
                int i = id[it];
                int j = id[(it + 1) % n];
                int vmul = x[i] * y[j] - y[i] * x[j];
                int smul = x[i] * x[j] + y[i] * y[j];
                if (vmul <= 0) continue;
                int leni = x[i] * x[i] + y[i] * y[i];
                int lenj = x[j] * x[j] + y[j] * y[j];
                Rational z = new Rational((long) vmul * vmul, (long) leni * lenj);
                if (smul < 0) {
                    z = Rational.ONE.add(Rational.ONE).subtract(z);
                }
                if (angle == null || angle.compareTo(z) > 0) {
                    angle = z;
                    ansi = i;
                    ansj = j;
                }
            }
            out.println((1 + ansi) + " " + (1 + ansj));
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

    static class Rational implements Comparable<Rational> {
        BigInteger num;
        BigInteger den;
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


        public String toString() {
            return num.toString()
                    + (den.equals(BigInteger.ONE) ? "" : "/" + den.toString());
        }

        public int compareTo(Rational o) {
            return num.multiply(o.den).compareTo(den.multiply(o.num));
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
}
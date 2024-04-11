import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Reader;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            sum += a[i];
        }
        ArrayUtils.sort(a);
//        Rational ans = new Rational(sum, n);
        Rational ans = Rational.ZERO;
        for (int i = 0; i < n; i++) {
            long n1 = (long) a[i] * (i - (n - i - 1));
            long d1 = n;
            ans = ans.add(new Rational(n1, d1));
        }
        ans = ans.multiply(new Rational(2));
        ans = ans.add(new Rational(sum, n));
        out.println(ans.getNum() + " " + ans.getDen());
    }
}

class FastScanner extends BufferedReader {

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

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

class ArrayUtils {


    static final long seed = System.nanoTime();

    static final Random rand = new Random(seed);

    public static void sort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    public static void shuffle(int[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }


    }

class Rational implements Comparable<Rational> {
	BigInteger num;
	BigInteger den;
    public static Rational ZERO = new Rational(BigInteger.ZERO);

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

    public BigInteger getNum() {
        return num;
    }

    public BigInteger getDen() {
        return den;
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

	public Rational multiply(Rational r) {
		return new Rational(num.multiply(r.num), den.multiply(r.den));
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
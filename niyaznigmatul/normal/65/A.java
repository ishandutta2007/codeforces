import java.io.*;
import java.util.*;
import java.math.*;
import static java.math.BigInteger.*;

public class A implements Runnable {

	void solve() {
		int a = nextInt();
		int b = nextInt();
		int c = nextInt();
		int d = nextInt();
		int e = nextInt();
		int f = nextInt();
		if (a != 0 && c != 0 && e != 0) {
			out.println(a * c * e < b * d * f ? "Ron" : "Hermione");
			return;
		}
		if ((c == 0 && d > 0) || (a == 0 && b > 0 && d > 0)
				|| (e == 0 && f > 0 && b > 0 && d > 0)) {
			out.println("Ron");
			return;
		} else {
			out.println("Hermione");
			return;
		}
	}

	void solve2() {
		BigInteger a = valueOf(nextInt());
		BigInteger b = valueOf(nextInt());
		BigInteger c = valueOf(nextInt());
		BigInteger d = valueOf(nextInt());
		BigInteger e = valueOf(nextInt());
		BigInteger f = valueOf(nextInt());
		BigInteger first = ONE
				.shiftLeft(100)
				.multiply(
						(a.equals(ZERO) ? ONE : a).multiply((c.equals(ZERO) ? ONE
								: c).multiply(e.equals(ZERO) ? ONE : e)))
				.multiply(b.equals(ZERO) ? ONE : b)
				.multiply(d.equals(ZERO) ? ONE : d)
				.multiply(f.equals(ZERO) ? ONE : f);
		BigInteger current = first;
		if (a.equals(ZERO)) {
			current = b.equals(ZERO) ? ZERO : ONE.shiftLeft(1000);
		} else {
			current = current.divide(a).multiply(b);
		}
		if (c.equals(ZERO)) {
			current = d.equals(ZERO) ? ZERO : ONE.shiftLeft(1000);
		} else {
			current = current.divide(c).multiply(d);
		}
		if (e.equals(ZERO)) {
			current = f.equals(ZERO) ? ZERO : ONE.shiftLeft(1000);
		} else
			current = current.divide(e).multiply(f);
		if (current.compareTo(first) > 0) {
			out.println("Ron");
			return;
		}
		out.println("Hermione");
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}
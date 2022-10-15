import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A implements Runnable {

	void solve() {
		int n = nextInt();
		int m = nextInt();
		for (int i = 0; i < n; i++) {
			int s = nextInt() - 1;
			int f = nextInt() - 1;
			int t = nextInt();
			if (s == f) {
				out.println(t);
				continue;
			}
			int mod = t % (2 * (m - 1));
			if (mod <= s) {
				if (f >= s) {
					out.println(f - s + (t - mod + s));
				} else {
					out.println((m - 1 - f) + (m - 1 - s) + (t - mod + s));
				}
			} else if (mod > 2 * (m - 1) - s) {				
				if (f >= s) {
					out.println(f - s + (t - mod + 2 * (m - 1) + s));
				} else {
					out.println((m - 1 - f) + (m - 1 - s) + (t - mod + 2 * (m - 1) + s));
				}
			} else {
				if (f <= s) {
					out.println(s - f + (t - mod + 2 * (m - 1) - s));
				} else {
					out.println(s + f + (t - mod + 2 * (m - 1) - s));
				}
			}
		}
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
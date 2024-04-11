import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

	void solve() {
		int n = nextInt();
		int x1 = nextInt();
		int y1 = nextInt();
		int x2 = nextInt();
		int y2 = nextInt();
		int ans = 0;
		if (x1 == x2 && (x1 == n || x1 == 0)) {
			ans = Math.abs(y2 - y1);
		} else if (y1 == y2 && (y1 == n || y1 == 0)) {
			ans = Math.abs(x1 - x2);
		} else if (x1 == 0 && x2 == n || x1 == n && x2 == 0) {
			ans = Math.min(3 * n - y1 - y2, y1 + y2 + n);
		} else if (y1 == 0 && y2 == n || y1 == n && y2 == 0) {
			ans = Math.min(3 * n - x1 - x2, x1 + x2 + n);
		} else if (x1 == 0 && y2 == 0) {
			ans = x2 + y1;
		} else if (x1 == n && y2 == n) {
			ans = 2 * n - x2 - y1;
		} else if (x1 == 0 && y2 == n) {
			ans = x2 + n - y1;
		} else if (x1 == n && y2 == 0) {
			ans = n - x2 + y1;
		} else if (x2 == 0 && y1 == 0) {
			ans = x1 + y2;
		} else if (x2 == n && y1 == n) {
			ans = 2 * n - x1 - y2;
		} else if (x2 == 0 && y1 == n) {
			ans = x1 + n - y2;
		} else if (x2 == n && y1 == 0) {
			ans = n - x1 + y2;
		}
		out.println(ans);
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
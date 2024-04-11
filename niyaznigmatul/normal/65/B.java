import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	void solve() {
		int n = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < c.length; i++) {
			c[i] = nextToken().toCharArray();
		}
		int last = 1000;
		for (int i = 0; i < n; i++) {
			boolean found = false;
			if (Integer.parseInt(new String(c[i])) < last) {
				for (int j = 3; j >= 0; j--) {
					int ch = c[i][j] - '0';
					boolean ok = false;
					for (int k = ch + 1; k < 10; k++) {
						System.err.println(i + " " + j + " " + k);
						c[i][j] = (char) (k + '0');
						if (j == 0 && k == 0) {
							continue;
						}
						int x = Integer.parseInt(new String(c[i]));
						if (x < last) {
							continue;
						}
						ok = true;
						break;
					}
					if (ok) {
						found = true;
						break;
					} else {
						c[i][j] = (char) (ch + '0');
					}
				}
				if (!found && Integer.parseInt(new String(c[i])) < last) {
					out.println("No solution");
					return;
				}
			} else {
				for (int j = 0; j < 4; j++) {
					int ch = c[i][j] - '0';
					boolean ok = false;
					for (int k = 0; k < ch; k++) {
						c[i][j] = (char) (k + '0');
						if (j == 0 && k == 0) {
							continue;
						}
						int x = Integer.parseInt(new String(c[i]));
						if (x < last) {
							continue;
						}
						ok = true;
						break;
					}
					if (ok) {
						found = true;
						break;
					} else {
						c[i][j] = (char) (ch + '0');
					}
				}
				if (!found && Integer.parseInt(new String(c[i])) < last) {
					out.println("No solution");
					return;
				}
			}
			last = Integer.parseInt(new String(c[i]));
		}
		for (int i = 0; i < n; i++) {
			if (Integer.parseInt(new String(c[i])) > 2011) {
				out.println("No solution");
				return;
			}
		}
		for (char[] cc : c) {
			out.println(new String(cc));
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
		new B().run();
	}
}
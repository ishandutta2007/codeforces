import java.io.*;
import java.util.*;
import java.math.*;

public class F implements Runnable {

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		if (n < 3 || m < 3) {
			out.println(0);
			return;
		}
		char[][] c = new char[n][];
		for (int i = 0; i < n; i++) {
			c[i] = nextToken().toCharArray();
		}
		int[][] isGood = new int[n - 2][m - 2];
		for (int i = 0; i < n - 2; i++) {
			for (int j = 0; j < m - 2; j++) {
				if (c[i][j + 1] == '1' && c[i + 1][j] == '1'
						&& c[i + 1][j + 1] == '1' && c[i + 1][j + 2] == '1'
						&& c[i + 2][j + 1] == '1') {
					isGood[i][j] = 1;
				}
			}
		}
		n -= 2;
		m -= 2;
		int[][] b = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i > 0) {
					b[i][j] += b[i - 1][j];
				}
				if (j > 0) {
					b[i][j] += b[i][j - 1];
				}
				if (i > 0 && j > 0) {
					b[i][j] -= b[i - 1][j - 1];
				}
				b[i][j] += isGood[i][j];
			}
		}
		long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int cur = 0;
				for (int t = 0; t < m; t++) {
					while (cur < m && sum(b, i, t, j, cur) < k) {
						cur++;
					}
					ans += m - cur;
				}
			}
		}
		out.println(ans);
	}

	static int sum(int[][] a, int x1, int y1, int x2, int y2) {
		int ret = a[x2][y2];
		if (x1 > 0) {
			ret -= a[x1 - 1][y2];
		}
		if (y1 > 0) {
			ret -= a[x2][y1 - 1];
		}
		if (x1 > 0 && y1 > 0) {
			ret += a[x1 - 1][y1 - 1];
		}
		return ret;
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
		new F().run();
	}
}
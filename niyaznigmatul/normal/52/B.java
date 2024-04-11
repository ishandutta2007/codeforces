import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	void solve() {
		int n = nextInt();
		int m = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < c.length; i++) {
			c[i] = nextToken().toCharArray();
		}
		long ans = get(c);
		for (int i = 0; i < c.length - i - 1; i++) {
			char[] t = c[i];
			c[i] = c[c.length - 1 - i];
			c[c.length - 1 - i] = t;
		}
		ans += get(c);
		out.println(ans);
	}

	long get(char[][] c) {
		int n = c.length;
		int m = c[0].length;
		int[][] up = new int[n][m];
		for (int i = 0; i < m; i++) {
			if (c[0][i] == '*') {
				up[0][i] = 1;
			}
		}
		long ans = 0;
		for (int i = 1; i < n; i++) {
			int sum = 0;
			int count = 0;
			for (int j = 0; j < m; j++) {
				if (c[i][j] == '*') {
					up[i][j] = up[i - 1][j] + 1;
					ans += sum;
					ans += (up[i][j] - 1) * count;
					count++;
					sum += up[i][j] - 1;
				} else {
					up[i][j] = up[i - 1][j];
				}
			}
		}
		return ans;
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
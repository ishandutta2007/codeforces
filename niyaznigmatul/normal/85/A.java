import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

	static char[][] answer;
	static final int[] DX = { 1, 0, -1, 0 };
	static final int[] DY = { 0, 1, 0, -1 };
	static boolean[] has = new boolean[26];

	static void put(char[][] c, int x1, int y1, int x2, int y2) {
		Arrays.fill(has, false);
		for (int i = 0; i < DX.length; i++) {
			int x = x1 + DX[i];
			int y = y1 + DY[i];
			if (x < 0 || y < 0 || x >= c.length || y >= c[x].length) {
				continue;
			}
			if (c[x][y] == 0) {
				continue;
			}
			has[c[x][y] - 'a'] = true;
		}
		for (int i = 0; i < DX.length; i++) {
			int x = x2 + DX[i];
			int y = y2 + DY[i];
			if (x < 0 || y < 0 || x >= c.length || y >= c[x].length) {
				continue;
			}
			if (c[x][y] == 0) {
				continue;
			}
			has[c[x][y] - 'a'] = true;
		}
		for (int i = 0; i < has.length; i++) {
			if (!has[i]) {
				c[x2][y2] = c[x1][y1] = (char) ('a' + i);
				return;
			}
		}
		throw new AssertionError();
	}

	void solve() {
		int n = 4;
		int m = nextInt();
		answer = new char[n][m];
		if ((m & 1) == 0) {
			for (int i = 0; i < m; i += 2) {
				put(answer, 0, i, 0, i + 1);
				put(answer, 3, i, 3, i + 1);
			}
			for (int i = 1; i + 1 < m; i += 2) {
				put(answer, 1, i, 1, i + 1);
				put(answer, 2, i, 2, i + 1);
			}
			put(answer, 1, 0, 2, 0);
			put(answer, 1, m - 1, 2, m - 1);
		} else {
			for (int i = 0; i + 1 < m; i += 2) {
				put(answer, 0, i, 0, i + 1);
				put(answer, 1, i, 1, i + 1);
			}
			for (int i = 1; i + 1 < m; i += 2) {
				put(answer, 2, i, 2, i + 1);
				put(answer, 3, i, 3, i + 1);
			}
			put(answer, 0, m - 1, 1, m - 1);
			put(answer, 2, 0, 3, 0);
		}
		for (char[] c : answer) {
			out.println(new String(c));
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
import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	void solve() {
		int n = nextInt();
		int[] p = new int[3 * n];
		for (int i = 0; i < p.length; i++) {
			p[i] = nextInt() - 1;
		}
		int[] ans = solve2(n, p);
		for (int i : ans) {
			out.print(1 + i + " ");
		}
	}

	int[] solve2(int n, int[] p) {
		int[] rp = new int[3 * n];
		for (int i = 0; i < 3 * n; i++) {
			rp[p[i]] = i;
		}
		int[][] team = new int[n][3];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				team[i][j] = nextInt() - 1;
			}
			for (int j = 0; j < 3; j++) {
				for (int k = j + 1; k < 3; k++) {
					if (rp[team[i][j]] > rp[team[i][k]]) {
						int t = team[i][j];
						team[i][j] = team[i][k];
						team[i][k] = t;
					}
				}
			}
		}
		int ask = nextInt() - 1;
		int found = -1;
		int f1 = -1;
		int f2 = -1;
		for (int i = 0; i < n; i++) {
			if (team[i][0] == ask) {
				found = i;
				f1 = team[i][1];
				f2 = team[i][2];
				break;
			}
		}
		if (found == -1) {
			int[] ret = new int[3 * n - 1];
			for (int i = 0, cur = 0; i < 3 * n; i++) {
				if (i != ask) {
					ret[cur++] = i;
				}
			}
			return ret;
		}
		int[] first = new int[found * 3 + 2];
		int[] second = new int[3 * n - first.length - 1];
		for (int i = 0, cur = 0; i <= found; i++) {
			for (int j = 0; j < 3; j++) {
				if (team[i][j] != ask) {
					first[cur++] = team[i][j];
				}
			}
		}
		for (int i = found + 1, cur = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				second[cur++] = team[i][j];
			}
		}
		Arrays.sort(first);
		Arrays.sort(second);
		int[] ret = new int[first.length + second.length];
		System.arraycopy(first, 0, ret, 0, first.length);
		System.arraycopy(second, 0, ret, first.length, second.length);
		found = -1;
		for (int i = 0; i < 3 * n - 1; i++) {
			if (ret[i] == f1 || ret[i] == f2) {
				found = i;
			}
		}
		Arrays.sort(ret, found + 1, ret.length);
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
		new D().run();
	}
}
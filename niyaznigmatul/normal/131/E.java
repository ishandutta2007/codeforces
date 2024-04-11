import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int[] x = new int[m];
		int[] y = new int[m];
		int[] minX = new int[n];
		int[] maxX = new int[n];
		int[] minY = new int[n];
		int[] maxY = new int[n];
		int[] minS = new int[n + n];
		int[] maxS = new int[n + n];
		int[] minD = new int[n + n];
		int[] maxD = new int[n + n];
		fill(minX, Integer.MAX_VALUE);
		fill(minY, Integer.MAX_VALUE);
		fill(minS, Integer.MAX_VALUE);
		fill(minD, Integer.MAX_VALUE);
		fill(maxX, Integer.MIN_VALUE);
		fill(maxY, Integer.MIN_VALUE);
		fill(maxS, Integer.MIN_VALUE);
		fill(maxD, Integer.MIN_VALUE);
		for (int i = 0; i < m; i++) {
			x[i] = nextInt() - 1;
			y[i] = nextInt() - 1;
			int s = x[i] + y[i];
			int d = (n - 1) + x[i] - y[i];
			minX[y[i]] = min(minX[y[i]], x[i]);
			maxX[y[i]] = max(maxX[y[i]], x[i]);
			minY[x[i]] = min(minY[x[i]], y[i]);
			maxY[x[i]] = max(maxY[x[i]], y[i]);
			minS[s] = min(minS[s], x[i]);
			maxS[s] = max(maxS[s], x[i]);
			minD[d] = min(minD[d], x[i]);
			maxD[d] = max(maxD[d], x[i]);
		}
		int[] ans = new int[9];
		for (int i = 0; i < m; i++) {
			int s = x[i] + y[i];
			int d = (n - 1) + x[i] - y[i];
			int count = 0;
			if (x[i] > minX[y[i]]) {
				count++;
			}
			if (x[i] < maxX[y[i]]) {
				count++;
			}
			if (y[i] > minY[x[i]]) {
				count++;
			}
			if (y[i] < maxY[x[i]]) {
				count++;
			}
			if (x[i] > minS[s]) {
				count++;
			}
			if (x[i] < maxS[s]) {
				count++;
			}
			if (x[i] > minD[d]) {
				count++;
			}
			if (x[i] < maxD[d]) {
				count++;
			}
			ans[count]++;
		}
		for (int i : ans) {
			out.print(i + " ");
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
		new E().run();
	}
}
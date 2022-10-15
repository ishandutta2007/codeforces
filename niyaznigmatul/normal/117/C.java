import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	void solve() {
		int n = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < n; i++) {
			c[i] = sc.nextToken().toCharArray();
		}
		// BitSet[] from = new BitSet[n];
		// BitSet[] to = new BitSet[n];
		// for (int i = 0; i < n; i++) {
		// from[i] = new BitSet(n);
		// to[i] = new BitSet(n);
		// }
		// for (int i = 0; i < n; i++) {
		// for (int j = 0; j < n; j++) {
		// if (c[i][j] == '1') {
		// from[i].set(j);
		// to[j].set(i);
		// }
		// }
		// }
		// BitSet tmp = new BitSet(n);
		// for (int i = 0; i < n; i++) {
		// tmp.clear();
		// for (int j = from[i].nextSetBit(0); j >= 0; j = from[i]
		// .nextSetBit(j + 1)) {
		// tmp.or(from[j]);
		// }
		// tmp.andNot(from[i]);
		// tmp.and(to[i]);
		// if (tmp.cardinality() > 0) {
		// int got = tmp.nextSetBit(0);
		// for (int j = from[i].nextSetBit(0); j >= 0; j = from[i]
		// .nextSetBit(j + 1)) {
		// if (from[j].get(got)) {
		// out.println((1 + i) + " " + (1 + j) + " " + (1 + got));
		// return;
		// }
		// }
		// }
		// }
		// out.println(-1);
		int[] count = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[i][j] == '1') {
					count[i]++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[i][j] == '1') {
					if (count[j] >= count[i]) {
						for (int k = 0; k < n; k++) {
							if (k == i || k == j) {
								continue;
							}
							if (c[j][k] == '1' && c[k][i] == '1') {
								out.println((1 + i) + " " + (1 + j) + " "
										+ (1 + k));
								return;
							}
						}
					}
				}
			}
		}
		out.println(-1);
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
		new C().run();
	}
}
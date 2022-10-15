import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	int ans;
	int mX;
	int mY;

	void solve() {
		int n = nextInt();
		int m = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < c.length; i++) {
			c[i] = nextToken().toCharArray();
		}
		ans = 0;
		mX = 1000;
		mY = 1000;
		for (int i = 1; i * i <= n; i++) {
			if (n % i != 0) {
				continue;
			}
			for (int j = 1; j * j <= m; j++) {
				if (m % j != 0) {
					continue;
				}
				check(n, m, c, i, j);
				if (i != n / i) {
					check(n, m, c, n / i, j);
				}
				if (j != m / j) {
					check(n, m, c, i, m / j);
				}
				if (i != n / i && j != m / j) {
					check(n, m, c, n / i, m / j);
				}
			}
		}
		out.println(ans);
		out.println(mX + " " + mY);
	}

	void check(int n, int m, char[][] c, int d1, int d2) {
		HashSet<State> hs = new HashSet<State>();
		int k1 = n / d1;
		int k2 = m / d2;
		StringBuilder sb = new StringBuilder();
//		System.err.println("START");
		for (int i = 0; i < k1; i++) {
			for (int j = 0; j < k2; j++) {
				State state1;
				State state2;
				State state3;
				State state4;
				{
					String[] r = new String[d1];
					for (int k = 0; k < d1; k++) {
						sb.setLength(0);
						for (int t = 0; t < d2; t++) {
							int x = i * d1 + k;
							int y = j * d2 + t;
							sb.append(c[x][y]);
						}
						r[k] = sb.toString();
					}
					state1 = new State(r);
				}
				{
					String[] r = new String[d1];
					for (int k = 0; k < d1; k++) {
						sb.setLength(0);
						for (int t = 0; t < d2; t++) {
							int x = i * d1 + (d1 - k - 1);
							int y = j * d2 + (d2 - t - 1);
							sb.append(c[x][y]);
						}
						r[k] = sb.toString();
					}
					state2 = new State(r);
				}
				{
					String[] r = new String[d2];
					for (int k = 0; k < d2; k++) {
						sb.setLength(0);
						for (int t = 0; t < d1; t++) {
							int x = i * d1 + (d1 - t - 1);
							int y = j * d2 + k;
							sb.append(c[x][y]);
						}
						r[k] = sb.toString();
					}
					state3 = new State(r);
				}
				{
					String[] r = new String[d2];
					for (int k = 0; k < d2; k++) {
						sb.setLength(0);
						for (int t = 0; t < d1; t++) {
							int x = i * d1 + t;
							int y = j * d2 + (d2 - k - 1);
							sb.append(c[x][y]);
						}
						r[k] = sb.toString();
					}
					state4 = new State(r);
				}
				if (hs.contains(state1) || hs.contains(state2)
						|| hs.contains(state3) || hs.contains(state4)) {
					return;
				}
				hs.add(state1);
				hs.add(state2);
				hs.add(state3);
				hs.add(state4);
//				System.err.println(state1);
//				System.err.println(state2);
//				System.err.println(state3);
//				System.err.println(state4);
//				System.err.println("next");
			}
		}
		ans++;
		if (mX * mY > d1 * d2 || (mX * mY == d1 * d2 && d1 < mX)) {
			mX = d1;
			mY = d2;
		}
	}

	class State {
		String[] s;

		public State(String[] s) {
			super();
			this.s = s;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(s);
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (!Arrays.equals(s, other.s))
				return false;
			return true;
		}

		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < s.length; i++) {
				sb.append(s[i]).append("\n");
			}
			return sb.toString();
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
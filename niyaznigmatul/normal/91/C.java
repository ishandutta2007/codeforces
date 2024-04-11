import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	static class DSU {
		int[] p;
		int[] r;
		int n;

		public DSU(int n) {
			this.n = n;
			p = new int[n];
			r = new int[n];
			for (int i = 0; i < p.length; i++) {
				p[i] = i;
			}
		}

		int get(int x) {
			return x == p[x] ? x : (p[x] = get(p[x]));
		}

		void union(int x, int y) {
			x = get(x);
			y = get(y);
			if (x == y) {
				return;
			}
			if (r[x] >= r[y]) {
				if (r[x] == r[y]) {
					r[x]++;
				}
				p[y] = x;
			} else {
				p[x] = y;
			}
		}

		void clear() {
			for (int i = 0; i < n; i++) {
				p[i] = i;
				r[i] = 0;
			}
		}
	}

	static final int MOD = 1000000009;

	void solve() {
		int n = nextInt();
		int m = nextInt();
		DSU dsu = new DSU(n);
		int ans = 1;
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			if (dsu.get(x) != dsu.get(y)) {
				dsu.union(x, y);
			} else {
				ans = ans * 2 % MOD;
			}
			out.println((ans + MOD - 1) % MOD);
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
		new C().run();
	}
}
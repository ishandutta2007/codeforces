import java.io.*;
import java.util.*;
import java.math.*;

public class C {

	void solve() {
		int n = nextInt();
		SegmentTree tree = new SegmentTree(n);
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			tree.inc(i, i + 1, x);
		}
		int m = nextInt();
		for (int i = 0; i < m; i++) {
			String[] s = sc.nextLine().split(" ");
			if (s.length == 3) {
				int l = Integer.parseInt(s[0]);
				int r = Integer.parseInt(s[1]) + 1;
				int v = Integer.parseInt(s[2]);
				if (l >= r) {
					tree.inc(l, n, v);
					tree.inc(0, r, v);
				} else {
					tree.inc(l, r, v);
				}
			} else {
				int l = Integer.parseInt(s[0]);
				int r = Integer.parseInt(s[1]) + 1;
				long ans;
				if (l >= r) {
					ans = Math.min(tree.getMin(l, n), tree.getMin(0, r));
				} else {
					ans = tree.getMin(l, r);
				}
				out.println(ans);
			}
		}
	}

	class SegmentTree {
		int n;
		int h;
		long[] min;
		long[] inc;

		public SegmentTree(int n) {
			this.n = Integer.highestOneBit(n) << 1;
			h = Integer.numberOfTrailingZeros(this.n);
			min = new long[this.n << 1];
			inc = new long[this.n << 1];
		}

		long get(int node) {
			return min[node] + inc[node];
		}

		void set(int node, long y) {
			inc[node] += y;
		}

		void relax(int node) {
			if (inc[node] != 0) {
				set(node * 2 + 1, inc[node]);
				set(node * 2 + 2, inc[node]);
				min[node] = get(node);
				inc[node] = 0;
			}
		}

		void inc(int node, int l, int r, int left, int right, long y) {
			if (right <= l || r <= left) {
				return;
			}
			if (left <= l && r <= right) {
				set(node, y);
				return;
			}
			relax(node);
			int m = (l + r) >> 1;
			inc(node * 2 + 1, l, m, left, right, y);
			inc(node * 2 + 2, m, r, left, right, y);
			min[node] = Math.min(get(node * 2 + 1), get(node * 2 + 2));
		}

		void inc(int l, int r, long y) {
			inc(0, 0, n, l, r, y);
		}

		long getMin(int node, int l, int r, int left, int right) {
			if (right <= l || r <= left) {
				return Long.MAX_VALUE;
			}
			if (left <= l && r <= right) {
				return get(node);
			}
			relax(node);
			int m = (l + r) >> 1;
			return Math.min(getMin(node * 2 + 1, l, m, left, right),
					getMin(node * 2 + 2, m, r, left, right));
		}

		long getMin(int l, int r) {
			return getMin(0, 0, n, l, r);
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
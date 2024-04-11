import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {

	class Domino {
		int x;
		int h;
		int num;

		public Domino(int x, int h, int num) {
			super();
			this.x = x;
			this.h = h;
			this.num = num;
		}

	}

	void solve() {
		int n = nextInt();
		Domino[] d = new Domino[n];
		for (int i = 0; i < n; i++) {
			d[i] = new Domino(nextInt(), nextInt(), i);
		}
		Arrays.sort(d, new Comparator<Domino>() {
			@Override
			public int compare(Domino o1, Domino o2) {
				return o1.x - o2.x;
			}
		});
		int[] x = new int[n];
		int[] h = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = d[i].x;
			h[i] = d[i].h;
		}
		SegmentTree tree = new SegmentTree(n);
		for (int i = 0; i < n; i++) {
			tree.update(i, x[i] + h[i]);
		}
		int[] dp = new int[n];
		dp[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			int l = i;
			int r = n;
			int right = x[i] + h[i] - 1;
			while (l < r - 1) {
				int mid = (l + r) >> 1;
				if (x[mid] <= right) {
					l = mid;
				} else {
					r = mid;
				}
			}
			int gotMax = tree.getMax(i + 1, l);
			if (gotMax == -1) {
				dp[i] = 1;
			} else {
				dp[i] = dp[gotMax] + gotMax - i;
			}
		}
		int[] ans = new int[n];
		for (int i = 0; i < n; i++) {
			ans[d[i].num] = dp[i];
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(" ");
			}
			out.print(ans[i]);
		}
	}

	class SegmentTree {
		int[] max;
		int[] a;
		int n;

		public SegmentTree(int n) {
			this.n = Integer.highestOneBit(n) << 1;
			max = new int[this.n << 1];
			a = new int[max.length];
		}

		void update(int x, int y) {
			x += n;
			a[x - n] = y;
			max[x] = x - n;
			while (x > 1) {
				x >>= 1;
				if (a[max[x * 2]] > a[max[x * 2 + 1]]) {
					max[x] = max[x * 2];
				} else {
					max[x] = max[x * 2 + 1];
				}
			}
		}

		int getMax(int l, int r) {
			l += n;
			r += n;
			int ret = -1;
			while (l <= r) {
				if ((l & 1) == 1) {
					if (ret == -1 || a[ret] < a[max[l]]) {
						ret = max[l];
					}
					l++;
				}
				if ((r & 1) == 0) {
					if (ret == -1 || a[ret] < a[max[r]]) {
						ret = max[r];
					}
					r--;
				}
				l >>= 1;
				r >>= 1;
			}
			return ret;
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
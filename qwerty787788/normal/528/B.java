import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class O implements Comparable<O> {
		int pos, w;

		public O(int pos, int w) {
			super();
			this.pos = pos;
			this.w = w;
		}

		@Override
		public int compareTo(O o) {
			return Integer.compare(pos, o.pos);
		}

	}

	class SegmentTree {
		int[] max;
		int[] add;

		public SegmentTree(int n) {
			max = new int[n * 4];
			add = new int[n * 4];
		}

		int get(int v, int l, int r, int needL, int needR) {
			if (needR < needL) {
				return 0;
			}
			if (needL == l && needR == r) {
				return max[v];
			}
			int m = (l + r) >>> 1;
			int res = get(v * 2 + 1, l, m, needL, Math.min(needR, m));
			res = Math.max(res,
					get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR));
			return res + add[v];
		}

		void set(int v, int l, int r, int need, int value) {
			if (l == r) {
				max[v] = Math.max(max[v], value);
			} else {
				int m = (l + r) >>> 1;
				if (m >= need) {
					set(v * 2 + 1, l, m, need, value - add[v]);
				} else {
					set(v * 2 + 2, m + 1, r, need, value - add[v]);
				}
				max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]) + add[v];
			}
		}
	}

	int lower(ArrayList<Integer> x, int need) {
		int l = -1, r = x.size();
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (x.get(m) >= need) {
				r = m;
			} else {
				l = m;
			}
		}
		return r;
	}

	int st(int[] x, int[] w) {
		int res = 1;
		int n = x.length;
		for (int st = 0; st < 1 << n; st++) {
			boolean ok = true;
			for (int i = 0; i < n; i++)
				if (((1 << i) & st) != 0)
					for (int j = i + 1; j < n; j++)
						if (((1 << j) & st) != 0) {
							if (Math.abs(x[i] - x[j]) < w[i] + w[j]) {
								ok = false;
							}
						}
			if (ok) {
				res = Math.max(res, Integer.bitCount(st));
			}
		}
		return res;
	}

	void solve213() {
		Random rnd = new Random(123);
		final int MAX = 10;
		for (int it = 0; it < 123123; it++) {
			System.err.println("ITER = " + it);
			int n = 1 + rnd.nextInt(MAX);
			int[] x = new int[n];
			int[] w = new int[n];
			for (int i = 0; i < n; i++) {
				x[i] = rnd.nextInt(MAX);
				w[i] = rnd.nextInt(MAX);
				boolean ok = true;
				for (int j = 0; j < i; j++) {
					if (x[j] == x[i]) {
						ok = false;
					}
				}
				if (!ok) {
					i--;
				}
			}
			// Arrays.sort(x);
			int cor = st(x, w);
			int my = solve(x, w);
			if (my != cor) {
				System.err.println(Arrays.toString(x));
				System.err.println(Arrays.toString(w));
				System.err.println("my = " + my);
				System.err.println("corr = " + cor);
				throw new AssertionError();
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int[] x = new int[n];
		int[] w = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			w[i] = in.nextInt();
		}
		out.println(solve(x, w));
	}

	int solve(int[] x, int[] w) {
		int n = x.length;
		O[] a = new O[n];
		ArrayList<Integer> allX = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			a[i] = new O(x[i], w[i]);
			allX.add(a[i].pos + a[i].w);
		}
		Collections.sort(allX);
		SegmentTree st = new SegmentTree(n);
		Arrays.sort(a);
		int res = 1;
		for (O o : a) {
			int from = lower(allX, o.pos - o.w + 1);
			int value = 1 + st.get(0, 0, n - 1, 0, from - 1);
			res = Math.max(res, value);
			st.set(0, 0, n - 1, lower(allX, o.pos + o.w), res);
		}
		return res;
		// out.println(res);
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
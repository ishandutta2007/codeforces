import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Segment implements Comparable<Segment> {
		int fr, to;
		int val;

		public Segment(int fr, int to, int val) {
			super();
			this.fr = fr;
			this.to = to;
			this.val = val;
		}

		@Override
		public int compareTo(Segment o) {
			return Integer.compare(fr, o.fr);
		}

		@Override
		public String toString() {
			return "Segment [fr=" + fr + ", to=" + to + ", val=" + val + "]";
		}

	}

	class ST2 {
		long[] a;
		long[] s;
		int n;

		ST2(int n) {
			this.n = n;
			a = new long[n * 4];
			s = new long[n * 4];
		}

		long get(int v, int l, int r, int needL, int needR) {
			if (needR < needL)
				return 0;
			if (l == needL && r == needR)
				return s[v];
			int m = (l + r) >> 1;
			return a[v] * 1L * (needR - needL + 1)
					+ get(v * 2 + 1, l, m, needL, Math.min(needR, m))
					+ get(v * 2 + 2, m + 1, r, Math.max(m + 1, needL), needR);
		}

		void add(int v, int l, int r, int needL, int needR, int val) {
			if (needR < needL)
				return;
			if (l == needL && r == needR) {
				a[v] += val;
				s[v] += (r - l + 1) * 1L * val;
				return;
			}
			int m = (l + r) >> 1;
			add(v * 2 + 1, l, m, needL, Math.min(needR, m), val);
			add(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, val);
			s[v] = s[v * 2 + 1] + s[v * 2 + 2] + a[v] * (r - l + 1);
		}
	}

	class ST {
		long[] a;
		int n;

		ST(int n) {
			this.n = n;
			a = new long[n * 4];
		}

		long get(int v, int l, int r, int needL, int needR) {
			long res = 0;
			for (int i = needL; i <= needR; i++)
				res += a[i];
			return res;
		}

		void add(int v, int l, int r, int needL, int needR, int val) {
			for (int i = needL; i <= needR; i++)
				a[i] += val;
		}
	}

	void solv3e() {
		Random rnd = new Random(123);
		for (int it = 0; it < 10000; it++) {
			System.err.println(it);
			int n = 1 + rnd.nextInt(100);
			ST a = new ST(n);
			ST2 b = new ST2(n);
			int m = 1 + rnd.nextInt(100);
			for (int i = 0; i < m; i++) {
				if (rnd.nextBoolean()) {
					int fr = rnd.nextInt(n), to = rnd.nextInt(n);
					if (to < fr) {
						int tmp = fr;
						fr = to;
						to = tmp;
					}
					int val = rnd.nextInt(100);
					a.add(0, 0, n - 1, fr, to, val);
					b.add(0, 0, n - 1, fr, to, val);
				} else {
					int fr = rnd.nextInt(n), to = rnd.nextInt(n);
					if (to < fr) {
						int tmp = fr;
						fr = to;
						to = tmp;
					}
					long v1 = a.get(0, 0, n - 1, fr, to);
					long v2 = b.get(0, 0, n - 1, fr, to);
					if (v1 != v2) {
						System.err.println(v1 + " " + v2);
						throw new AssertionError();
					}
				}
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		TreeSet<Segment> ts = new TreeSet<>();
		for (int i = 1; i <= n; i++) {
			ts.add(new Segment(i - 1, i - 1, i));
		}
		ST2 st = new ST2(n);
		for (int i = 0; i < m; i++) {
			if (in.nextInt() == 1) {
				int fr = in.nextInt() - 1;
				int to = in.nextInt() - 1;
				int val = in.nextInt();
				Segment x = new Segment(fr, to, val);
				{
					Segment y = ts.lower(x);
					if (y != null) {
						if (y.to >= x.fr) {
							ts.remove(y);
							ts.add(new Segment(y.fr, x.fr - 1, y.val));
							ts.add(new Segment(x.fr, y.to, y.val));
						}
					}
				}
				while (true) {
					Segment y = ts.ceiling(x);
					if (y == null)
						break;
					if (y.fr > x.to)
						break;
					ts.remove(y);
					if (y.to > x.to) {
						ts.add(new Segment(x.to + 1, y.to, y.val));
						y.to = x.to;
					}
					st.add(0, 0, n - 1, y.fr, y.to, Math.abs(y.val - x.val));
				}
				ts.add(x);
			} else {
				int fr = in.nextInt() - 1;
				int to = in.nextInt() - 1;
				out.println(st.get(0, 0, n - 1, fr, to));
			}
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
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
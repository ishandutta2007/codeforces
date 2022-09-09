import java.io.*;
import java.util.*;

public class CFB {
	FastScanner in;
	PrintWriter out;

	class Vod implements Comparable<Vod> {
		int h, l, r;

		public Vod(int h, int l, int r) {
			super();
			this.h = h;
			this.l = l;
			this.r = r;
		}

		@Override
		public int compareTo(Vod o) {
			if (h != o.h)
				return o.h - h;
			return l - o.l;
		}

		@Override
		public String toString() {
			return "Vod [h=" + h + ", l=" + l + ", r=" + r + "]";
		}

	}

	class StupidSolution {
		Vod[] a;
		boolean[][] can;
		int n;

		class MyObj implements Comparable<MyObj> {
			int id, h;

			public MyObj(int id, int h) {
				super();
				this.id = id;
				this.h = h;
			}

			@Override
			public int compareTo(MyObj arg0) {
				return arg0.h - h;
			}

		}

		public StupidSolution(Vod[] b) {
			a = b.clone();
		}

		int solve() {
			int res = 0;
			n = a.length;
			can = new boolean[n][n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (i != j)
						if (a[j].h < a[i].h)
							if (Math.max(a[i].l, a[j].l) < Math.min(a[i].r,
									a[j].r))
								can[i][j] = true;
			boolean[][] cannot = new boolean[n][n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
						if (i != j && j != k && i != k)
							if (a[i].h > a[j].h && a[j].h > a[k].h)
								if (can[i][j] && can[j][k])
									cannot[i][k] = true;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (cannot[i][j])
						can[i][j] = false;
			boolean[] free = new boolean[n];
			for (int i = 0; i < n; i++) {
				boolean ok = true;
				for (int j = 0; j < n; j++)
					if (can[j][i])
						ok = false;
				if (ok)
					free[i] = true;
			}
			boolean[] out = new boolean[n];
			for (int i = 0; i < n; i++) {
				boolean ok = true;
				for (int j = 0; j < n; j++) {
					if (can[i][j])
						ok = false;
				}
				if (ok)
					out[i] = true;
			}
			int[] ans = new int[n];
			MyObj[] xx = new MyObj[n];
			for (int i = 0; i < n; i++)
				xx[i] = new MyObj(i, a[i].h);
			Arrays.sort(xx);
			for (int i = 0; i < n; i++)
				if (free[i])
					ans[i] = a[i].r - a[i].l;
			for (int i = 0; i < n; i++) {
				int id = xx[i].id;
				for (int next = 0; next < n; next++)
					if (can[id][next])
						ans[next] = Math.max(
								ans[next],
								Math.min(ans[id], Math.min(a[id].r, a[next].r)
										- Math.max(a[id].l, a[next].l)));
			}
			for (int i = 0; i < n; i++) {
				// System.err.println(i + ": " + ans[i]);
				if (out[i])
					res = Math.max(res, ans[i]);
			}
			return res;
		}
	}

	class Segment implements Comparable<Segment> {
		int l, r;
		int cost;
		boolean canRight, canLeft;

		public Segment(int l, int r, int cost) {
			super();
			this.l = l;
			this.r = r;
			this.cost = cost;
			canRight = true;
			canLeft = true;
		}

		@Override
		public int compareTo(Segment o) {
			return l - o.l;
		}

		@Override
		public String toString() {
			return "Segment [l=" + l + ", r=" + r + ", cost=" + cost
					+ ", canRight=" + canRight + ", canLeft=" + canLeft + "]";
		}

	}

	class SmartSolution {
		Vod[] a;

		SmartSolution(Vod[] b) {
			a = b.clone();
		}

		int solve() {
			Arrays.sort(a);
			TreeSet<Segment> ts = new TreeSet<CFB.Segment>();
			for (int i = 0; i < a.length; i++) {
				Segment x = new Segment(a[i].l, a[i].r, a[i].r - a[i].l);
				int curAns = Integer.MIN_VALUE;
				while (true) {
					Segment less = ts.floor(x);
					if (less == null || less.r <= x.l)
						break;
					ts.remove(less);
					if (less.l < x.l) {
						Segment tmp = new Segment(less.l, x.l, Math.min(x.l
								- less.l, less.cost));
						tmp.canRight = false;
						tmp.canLeft = less.canLeft;
						ts.add(tmp);
					}
					if (less.r > x.r) {
						Segment tmp = new Segment(x.r, less.r, Math.min(less.r
								- x.r, less.cost));
						tmp.canLeft = false;
						tmp.canRight = less.canRight;
						ts.add(tmp);
					}
					if (less.canRight || (less.r >= x.r)) {
						curAns = Math.max(curAns, Math.min(
								Math.min(less.r, x.r) - x.l, less.cost));
					} else {
						curAns = Math.max(curAns, 0);
					}
				}

				while (true) {
					Segment bigg = ts.higher(x);
					if (bigg == null || bigg.l >= x.r)
						break;
					ts.remove(bigg);
					if (bigg.r > x.r) {
						Segment tmp = new Segment(x.r, bigg.r, Math.min(bigg.r
								- x.r, bigg.cost));
						tmp.canLeft = false;
						tmp.canRight = bigg.canRight;
						ts.add(tmp);
					}
					if (bigg.canLeft && (bigg.canRight || bigg.r >= x.r)) {
						curAns = Math.max(curAns,
								Math.min(x.r - bigg.l, bigg.cost));
					} else {
						curAns = Math.max(curAns, 0);
					}
				}

				if (curAns != Integer.MIN_VALUE)
					x.cost = curAns;
				ts.add(x);
			}
			int ans = 0;
			for (Segment s : ts) {
				if (s.canLeft && s.canRight)
					ans = Math.max(ans, s.cost);
			}
			return ans;
		}
	}

	Random rnd = new Random(123);

	Vod[] generateSample(int n, int max_h, int max_x) {
		int curN = 0;
		Vod[] res = new Vod[n];
		while (curN != n) {
			int h = rnd.nextInt(max_h);
			int l = rnd.nextInt(max_x);
			int r = rnd.nextInt(max_x);
			if (r < l) {
				int tmp = l;
				l = r;
				r = tmp;
			}
			r++;
			boolean ok = true;
			for (int i = 0; i < curN; i++)
				if (res[i].h == h)
					if (Math.max(res[i].l, l) < Math.min(res[i].r, r))
						ok = false;
			if (ok) {
				res[curN++] = new Vod(h, l, r);
			}
		}
		return res;
	}

	void solve() {
		boolean isStress = false;
		if (!isStress) {
			int n = in.nextInt();
			int tmp = in.nextInt();
			Vod[] a = new Vod[n];
			for (int i = 0; i < n; i++) {
				a[i] = new Vod(in.nextInt(), in.nextInt(), in.nextInt());
			}
			out.println(new SmartSolution(a).solve());
		} else {
			int testN = 0;
			int n = 10;
			while (true) {
				System.err.println("testN " + testN++);
				// if (testN == 24) {
				// System.err.println("123");
				// }
				Vod[] a = generateSample(n, 7, 7);
				// System.err.println("xxx");
				int stupid = new StupidSolution(a).solve();
				// System.err.println("stupid");
				int smart = new SmartSolution(a).solve();
				// System.err.println("smart");
				if (smart == stupid) {
					System.err.println("ok");
				} else {
					System.err.println("found bug.");
					System.err.println(Arrays.toString(a));
					System.err.println("stupid ans: " + stupid);
					System.err.println("smart ans:" + smart);
					System.err.println(n + " " + 10000);
					for (int i = 0; i < n; i++)
						System.err
								.println(a[i].h + " " + a[i].l + " " + a[i].r);
					throw new AssertionError();
				}
			}
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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
	}

	public static void main(String[] args) {
		new CFB().runIO();
	}
}
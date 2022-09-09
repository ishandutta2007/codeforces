import java.io.*;
import java.util.*;

public class CF {

	ArrayList<Integer>[] g;
	int it;
	int[] inn;
	int[] outt;
	int[] h;
	int[] par;

	void go(int v, int p, int hh) {
		h[v] = hh;
		par[v] = p;
		inn[v] = it++;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to != p)
				go(to, v, hh + 1);
		}
		outt[v] = it - 1;
	}

	class SegmentTree {
		int n;
		int[] a;

		SegmentTree(int n) {
			this.n = n;
			a = new int[4 * n];
		}

		void add(int v, int l, int r, int needL, int needR, int addV) {
			if (needL > needR)
				return;
			if (l == needL && r == needR) {
				a[v] += addV;
				return;
			}
			int m = (l + r) >> 1;
			add(v * 2 + 1, l, m, needL, Math.min(needR, m), addV);
			add(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, addV);
		}

		void add(int l, int r, int val) {
			add(0, 0, n - 1, l, r, val);
		}

		int get(int v, int l, int r, int need) {
			if (l == r)
				return a[v];
			int m = (l + r) >> 1;
			if (m >= need)
				return a[v] + get(v * 2 + 1, l, m, need);
			return a[v] + get(v * 2 + 2, m + 1, r, need);
		}

		int get(int v) {
			return get(0, 0, n - 1, v);
		}
	}

	int[] real;

	void add(int v, int addV) {
		real[v] += addV;
		for (int i = 0; i < g[v].size(); i++) {
			if (g[v].get(i) != par[v])
				add(g[v].get(i), -addV);
		}
	}

	void solve2() {
		Random rnd = new Random(123);
		for (int it1 = 0; it1 < 10000; it1++) {
			if (it1 == 106)
				System.err.println("?");
			System.err.println("!!!" + it1);
			it = 0;
			int n = 3 + rnd.nextInt(100);
			int m = 2 + rnd.nextInt(100);
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = 0;
			g = new ArrayList[n];
			for (int i = 0; i < n; i++)
				g[i] = new ArrayList<>();
			for (int i = 0; i < n - 1; i++) {
				int fr = i + 1;
				int to = rnd.nextInt(i + 1);
				g[fr].add(to);
				g[to].add(fr);
				System.err.println(fr +" "  + to);
			}
			par = new int[n];
			inn = new int[n];
			outt = new int[n];
			h = new int[n];
			go(0, -1, 0);
			real = new int[n];
			for (int i = 0; i < n; i++)
				real[i] = a[i];
			SegmentTree stEven = new SegmentTree(it + 1);
			SegmentTree stOdd = new SegmentTree(it + 1);
			for (int i = 0; i < m; i++) {
				int type = rnd.nextInt(2) + 1;
				if (type == 1) {
					int v = rnd.nextInt(n);
					int addV = rnd.nextInt(100);
					add(v, addV);
					System.err.println("+ " + v + " " + addV);
					if (h[v] % 2 == 0) {
						stEven.add(inn[v], outt[v], addV);
						stOdd.add(inn[v], outt[v], -addV);
					} else {
						stEven.add(inn[v], outt[v], -addV);
						stOdd.add(inn[v], outt[v], addV);
					}
				} else {
					int v = rnd.nextInt(n);
					System.err.println("? " + v);
					int res = a[v];
					if (h[v] % 2 == 0) {
						res += stEven.get(inn[v]);
					} else {
						res += stOdd.get(inn[v]);
					}
					System.err.println(res + " " + real[v]);
					if (res != real[v])
						throw new AssertionError();
//					out.println(res);
				}
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		par = new int[n];
		inn = new int[n];
		outt = new int[n];
		h = new int[n];
		go(0, -1, 0);
		real = new int[n];
		for (int i = 0; i < n; i++)
			real[i] = a[i];
		SegmentTree stEven = new SegmentTree(it + 1);
		SegmentTree stOdd = new SegmentTree(it + 1);
		for (int i = 0; i < m; i++) {
			int type = in.nextInt();
			if (type == 1) {
				int v = in.nextInt() - 1;
				int addV = in.nextInt();
				if (h[v] % 2 == 0) {
					stEven.add(inn[v], outt[v], addV);
					stOdd.add(inn[v], outt[v], -addV);
				} else {
					stEven.add(inn[v], outt[v], -addV);
					stOdd.add(inn[v], outt[v], addV);
				}
			} else {
				int v = in.nextInt() - 1;
				int res = a[v];
				if (h[v] % 2 == 0) {
					res += stEven.get(inn[v]);
				} else {
					res += stOdd.get(inn[v]);
				}
				out.println(res);
			}
		}
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
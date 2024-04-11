import java.io.*;
import java.util.*;

public class Sol {
	FastScanner in;
	PrintWriter out;

	class SegmentTree {
		int n;
		int[] t;

		SegmentTree(int n) {
			this.n = n;
			t = new int[4 * n];
		}

		void add(int v, int tl, int tr, int l, int r, int add2) {
			if (l > r)
				return;
			if (l == tl && tr == r)
				t[v] += add2;
			else {
				int tm = (tl + tr) / 2;
				add(v * 2, tl, tm, l, Math.min(r, tm), add2);
				add(v * 2 + 1, tm + 1, tr, Math.max(l, tm + 1), r, add2);
			}
		}

		int get(int v, int tl, int tr, int pos) {
			if (tl == tr)
				return t[v];
			int tm = (tl + tr) / 2;
			if (pos <= tm)
				return t[v] + get(v * 2, tl, tm, pos);
			else
				return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
		}

		void add(int l, int r, int cnt) {
			if (r >= n)
				r = n - 1;
			add(1, 1, n, l + 1, r + 1, cnt);
		}

		int get(int need) {
			return get(1, 1, n, need + 1);
		}

	}

	boolean[] was;
	int[] treeId;
	int[] pos;
	int[] maxId;

	ArrayList<Integer>[] g;
	int totalTrees = 0;

	void dfs(int v, int posNow, int treeIdNow) {
		was[v] = true;
		treeId[v] = treeIdNow;
		pos[v] = posNow;
		for (int to : g[v])
			if (!was[to])
				dfs(to, posNow + 1, treeIdNow);
	}

	void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
		for (int i = 0; i < n - 1; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		was = new boolean[n];
		was[0] = true;
		treeId = new int[n];
		pos = new int[n];
		totalTrees = g[0].size();
		maxId = new int[totalTrees];
		int x2 = 0;
		for (int to : g[0]) {
			dfs(to, 1, x2);
			x2++;
		}
		for (int i = 1; i < n; i++)
			maxId[treeId[i]] = Math.max(maxId[treeId[i]], pos[i]);
		SegmentTree[] st = new SegmentTree[totalTrees];
		SegmentTree main = new SegmentTree(n + 3);
		for (int i = 0; i < st.length; i++)
			st[i] = new SegmentTree(maxId[i] + 3);
		for (int i = 0; i < q; i++) {
			int type = in.nextInt();
			if (type == 0) {
				int v = in.nextInt() - 1;
				int x = in.nextInt();
				int d = in.nextInt();
				if (v == 0) {
					main.add(0, d, x);
				} else {
					int p = pos[v];
					if (p > d) {
						st[treeId[v]].add(p - d, p + d, x);
					} else {
						int z = d - p;
						main.add(0, z, x);
						int left = z + 1;
						st[treeId[v]].add(left, p + d, x);
					}
				}
			} else {
				int v = in.nextInt() - 1;
				if (v == 0) {
					out.println(main.get(0));
				} else {
					out.println(main.get(pos[v]) + st[treeId[v]].get(pos[v]));
				}
			}
		}
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
		new Sol().runIO();
	}
}
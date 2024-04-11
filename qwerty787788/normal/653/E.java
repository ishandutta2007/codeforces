import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] p;

	int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}

	void unite(int x, int y) {
		p[get(x)] = get(y);
	}

	class SegmentTree {
		int[] ids;

		SegmentTree(int n) {
			ids = new int[n * 4];
			Arrays.fill(ids, -1);
		}

		void set(int v, int l, int r, int needL, int needR, int val) {
			if (needL > needR) {
				return;
			}
			if (needL == l && needR == r) {
				if (ids[v] == -1) {
					ids[v] = val;
				} else {
					unite(ids[v], val);
				}
			} else {
				int m = (l + r) >> 1;
				set(v * 2 + 1, l, m, needL, Math.min(needR, m), val);
				set(v * 2 + 2, m + 1, r, Math.max(m + 1, needL), needR, val);
			}
		}

		void go(int v, int l, int r) {
			if (l == r) {
				return;
			}
			if (ids[v] != -1) {
				if (ids[v * 2 + 1] == -1) {
					ids[v * 2 + 1] = ids[v];
				} else {
					unite(ids[v], ids[v * 2 + 1]);
				}
				if (ids[v * 2 + 2] == -1) {
					ids[v * 2 + 2] = ids[v];
				} else {
					unite(ids[v], ids[v * 2 + 2]);
				}
			}
			int m = (l + r) >> 1;
			go(v * 2 + 1, l, m);
			go(v * 2 + 2, m + 1, r);
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		ArrayList<Integer>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		for (int i = 1; i < n; i++) {
			g[i].add(-1);
			g[i].add(n);
			Collections.sort(g[i]);
		}
		p = new int[n];
		for (int i = 0; i < p.length; i++) {
			p[i] = i;
		}
		SegmentTree st = new SegmentTree(n);
		for (int i = 0; i < n; i++) {
			st.set(0, 0, n - 1, i, i, i);
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j + 1 < g[i].size(); j++) {
				int fr = g[i].get(j) + 1;
				fr = Math.max(fr, 1);
				int to = g[i].get(j + 1) - 1;
				if (fr <= to) {
					st.set(0, 0, n - 1, fr, to, i);
				}
			}
		}
		st.go(0, 0, n - 1);
		ArrayList<Integer>[] all = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			all[i] = new ArrayList<>();
		}
		for (int i = 1; i < n; i++) {
			all[get(i)].add(i);
		}
		int groups = 0;
		boolean[] canFirst = new boolean[n];
		Arrays.fill(canFirst, true);
		for (int to : g[0]) {
			canFirst[to] = false;
		}
		for (int i = 0; i < n; i++) {
			if (all[i].size() == 0) {
				continue;
			}
			boolean can = false;
			for (int v : all[i]) {
				if (canFirst[v]) {
					can = true;
				}
			}
			if (!can) {
				out.println("impossible");
				return;
			}
			groups++;
		}
		out.println(groups <= k && (n - 1 - g[0].size() >= k) ? "possible"
				: "impossible");
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test2.out"));

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
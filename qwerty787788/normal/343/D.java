import java.io.*;
import java.util.*;

public class CF {

	ArrayList<Integer>[] g;
	int it = 0;
	int[] from;
	int[] to;

	void go(int v, int p) {
		from[v] = it++;
		for (int i = 0; i < g[v].size(); i++) {
			int next = g[v].get(i);
			if (next == p)
				continue;
			go(next, v);
		}
		to[v] = it - 1;
	}

	class SegmentTree {
		int n;
		int[] val;

		SegmentTree(int n) {
			this.n = n;
			val = new int[4 * n];
			Arrays.fill(val, -1);
		}

		void push(int v, int l, int r) {
			if (l == r)
				return;
			val[v * 2 + 1] = Math.max(val[v * 2 + 1], val[v]);
			val[v * 2 + 2] = Math.max(val[v * 2 + 2], val[v]);
		}

		int get(int v, int l, int r, int need) {
			push(v, l, r);
			if (l == r)
				return val[v];
			int m = (l + r) >> 1;
			if (need <= m)
				return get(v * 2 + 1, l, m, need);
			return get(v * 2 + 2, m + 1, r, need);
		}

		int get(int need) {
			return get(0, 0, n - 1, need);
		}

		void update(int v, int l, int r, int needL, int needR, int newVal) {
			if (needL > needR)
				return;
			if (l == needL && r == needR) {
				val[v] = Math.max(newVal, val[v]);
				return;
			}
			push(v, l, r);
			int m = (l + r) >> 1;
			update(v * 2 + 1, l, m, needL, Math.min(needR, m), newVal);
			update(v * 2 + 2, m + 1, r, Math.max(m + 1, needL), needR, newVal);
		}

		void update(int l, int r, int newVal) {
			update(0, 0, n - 1, l, r, newVal);
		}
	}

	class SegmentTree2 {
		int n;
		int[] val;

		SegmentTree2(int n) {
			this.n = n;
			val = new int[4 * n];
			Arrays.fill(val, -1);
		}

		int get(int v, int l, int r, int needL, int needR) {
			if (needL > needR)
				return -1;
			if (l == needL && r == needR)
				return val[v];
			int m = (l + r) >> 1;
			return Math.max(get(v * 2 + 1, l, m, needL, Math.min(needR, m)),
					get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR));
		}

		int get(int needL, int needR) {
			return get(0, 0, n - 1, needL, needR);
		}

		void update(int v, int l, int r, int need, int newVal) {
			if (l == r) {
				val[v] = Math.max(newVal, val[v]);
				return;
			}
			int m = (l + r) >> 1;
			if (need <= m)
				update(v * 2 + 1, l, m, need, newVal);
			else
				update(v * 2 + 2, m + 1, r, need, newVal);
			val[v] = Math.max(val[v * 2 + 1], val[v * 2 + 2]);
		}

		void update(int need, int newVal) {
			update(0, 0, n - 1, need, newVal);
		}
	}

	void solve() {
		int n = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		from = new int[n];
		to = new int[n];
		go(0, -1);
		SegmentTree st = new SegmentTree(it);
		SegmentTree2 st2 = new SegmentTree2(it);
		int m = in.nextInt();
		for (int i = 0; i < m; i++) {
			int type = in.nextInt();
			int v = in.nextInt() - 1;
			if (type == 1) {
				st.update(from[v], to[v], i + 1);
			} else {
				if (type == 2) {
					st2.update(from[v], i + 1);
				} else {
					int timeGo = st.get(from[v]);
					int timeNo = st2.get(from[v], to[v]);
					if (timeNo >= timeGo)
						out.println(0);
					else
						out.println(1);
				}
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
import java.io.*;
import java.util.*;

public class CF157DIV1 {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	int[] first, last;
	boolean[] was;
	int it;

	void go(int v) {
		was[v] = true;
		first[v] = it++;
		for (int to = 0; to < g[v].size(); to++)
			if (!was[g[v].get(to)])
				go(g[v].get(to));
		last[v] = it++;
	}

	class SegmentTree {
		int n;
		int[] sum;
		int[] addSongs;

		public SegmentTree(int n) {
			this.n = n;
			sum = new int[4 * n];
			addSongs = new int[4 * n];
		}

		void add(int v, int left, int right, int needL, int needR, int add) {
			if (needL > needR)
				return;
			if (left == needL && right == needR) {
				addSongs[v] += add;
			} else {
				int m = (left + right) / 2;
				add(v * 2 + 1, left, m, needL, Math.min(needR, m), add);
				add(v * 2 + 2, m + 1, right, Math.max(needL, m + 1), needR, add);
			}
			updateSum(v, left, right);
		}

		int get(int v, int left, int right, int needL, int needR) {
			if (needL > needR)
				return 0;
			if (left == needL && right == needR)
				return sum[v];
			if (addSongs[v] > 0)
				return (needR - needL + 1);
			int m = (left + right) / 2;
			return get(v * 2 + 1, left, m, needL, Math.min(needR, m))
					+ get(v * 2 + 2, m + 1, right, Math.max(needL, m + 1),
							needR);
		}

		void updateSum(int v, int l, int r) {
			if (addSongs[v] > 0) {
				sum[v] = r - l + 1;
			} else {
				if (r != l) {
					sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
				} else {
					sum[v] = 0;
				}
			}
		}
	}

	ArrayList<Integer>[] another;
	SegmentTree st;
	int[] ans;

	void go2(int v) {
		was[v] = true;
		for (int i = 0; i < another[v].size(); i++) {
			int to = another[v].get(i);
			st.add(0, 0, it - 1, first[to], last[to], 1);
		}
		ans[v] += st.get(0, 0, it - 1, 0, it - 1) / 2 - st.get(0, 0, it - 1, first[v], first[v]);
		for (int i = 0; i < g[v].size(); i++) {
			if (!was[g[v].get(i)])
				go2(g[v].get(i));
		}
		for (int i = 0; i < another[v].size(); i++) {
			int to = another[v].get(i);
			st.add(0, 0, it - 1, first[to], last[to], -1);
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
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
		first = new int[n];
		last = new int[n];
		go(0);
		st = new SegmentTree(it);
		another = new ArrayList[n];
		for (int i = 0; i < n; i++)
			another[i] = new ArrayList<Integer>();
		for (int i = 0; i < m; i++) {
			int ai = in.nextInt() - 1;
			int bi = in.nextInt() - 1;
			another[ai].add(bi);
			another[bi].add(ai);
			another[ai].add(ai);
			another[bi].add(bi);
		}
		ans = new int[n];
		Arrays.fill(was, false);
		go2(0);
		for (int i = 0; i < n; i++)
			out.print(ans[i] + " ");
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
		new CF157DIV1().runIO();
	}
}
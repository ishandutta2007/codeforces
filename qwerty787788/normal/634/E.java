import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	int[] a;
	int[] sz;
	int[] ans;
	int[] szUp;
	int[] ansUp;

	void dfs(int v, int p) {
		sz[v] = 1;
		ans[v] = 1;
		int ma = 0;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to != p) {
				dfs(to, v);
				sz[v] += sz[to];
				if (ans[to] == sz[to]) {
					ans[v] += ans[to];
				} else {
					ma = Math.max(ma, ans[to]);
				}
			}
		}
		ans[v] += ma;
		if (a[v] < value) {
			ans[v] = 0;
		}
		szUp[v] = n - sz[v];
	}

	boolean dfs2(int v, int p, int rAnsUp) {
		if (sufSum[v] == null) {
			sufSum[v] = new int[g[v].size() + 1];
			sufMax[v] = new int[g[v].size() + 1];
		}
		ansUp[v] = rAnsUp;
		if (szUp[v] == ansUp[v]) {
			sufSum[v][0] = ansUp[v];
			sufMax[v][0] = 0;
		} else {
			sufSum[v][0] = 0;
			sufMax[v][0] = ansUp[v];
		}
		for (int i = 0; i < g[v].size(); i++) {
			sufMax[v][i + 1] = sufMax[v][i];
			sufSum[v][i + 1] = sufSum[v][i];
			int to = g[v].get(g[v].size() - i - 1);
			if (to != p) {
				if (sz[to] == ans[to]) {
					sufSum[v][i + 1] += ans[to];
				} else {
					sufMax[v][i + 1] = Math.max(sufMax[v][i + 1], ans[to]);
				}
			}
		}
		if (a[v] >= value) {
			if (sufSum[v][sufSum[v].length - 1] + sufMax[v][sufMax[v].length - 1] + 1 >= k) {
				return true;
			}
		}
		int prefSum = 0, prefMax = 0;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to != p) {
				int mySum = prefSum + sufSum[v][g[v].size() - i -  1];
				int myMax = Math.max(prefMax, sufMax[v][g[v].size() - i - 1]);
				int go = 1 + mySum + myMax;
				if (dfs2(to, v, (a[v] < value ? 0 : go))) {
					return true;
				}
				if (ans[to] == sz[to]) {
					prefSum += ans[to];
				} else {
					prefMax = Math.max(prefMax, ans[to]);
				}
			}
		}
		return false;
	}

	int value, n, k;
	int[][] sufSum;
	int[][] sufMax;

	boolean can(int value) {
		this.value = value;
		dfs(0, -1);
		return dfs2(0, -1, 0);
	}

	void solve() {
		n = in.nextInt();
		k = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i + 1 < n; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		sz = new int[n];
		ans = new int[n];
		szUp = new int[n];
		ansUp = new int[n];
		sufSum = new int[n][];
		sufMax = new int[n][];
		int left = 0, right = (int) 1e6 + 10;
		while (right - left > 1) {
			int mid = (left + right) >> 1;
			if (can(mid)) {
				left = mid;
			} else {
				right = mid;
			}
		}
		out.println(left);
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
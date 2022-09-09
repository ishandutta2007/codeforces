import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	final int mod = (int) 1e9 + 7;

	int[] parent;
	int[] dp;
	int[] dpParentAns;
	int[][] prefMul, sufMul;

	void go(int v, int p) {
		dp[v] = 1;
		int cnt = g[v].size();
		if (p != -1) {
			cnt--;
		}
		prefMul[v] = new int[cnt + 1];
		sufMul[v] = new int[cnt + 1];
		int it = 0;
		prefMul[v][0] = 1;
		sufMul[v][sufMul[v].length - 1] = 1;
		for (int to : g[v]) {
			if (to != p) {
				go(to, v);
				dp[v] = (int) ((dp[v] * 1L * (dp[to] + 1)) % mod);
				it++;
				prefMul[v][it] = (int) ((prefMul[v][it - 1] * 1L * (dp[to] + 1)) % mod);
			}
		}
		it = sufMul[v].length - 1;
		for (int i = g[v].size() - 1; i >= 0; i--) {
			int to = g[v].get(i);
			if (to != p) {
				it--;
				sufMul[v][it] = (int) ((sufMul[v][it + 1] * 1L * (dp[to] + 1)) % mod);
			}
		}
	}

	void go2(int v, int p) {
		int it = 0;
		for (int to : g[v]) {
			if (to != p) {
				dpParentAns[to] = (int) ((1 + dpParentAns[v]) * 1L
						* prefMul[v][it] % mod * 1L * sufMul[v][it + 1] % mod);
				go2(to, v);
				it++;
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int to = in.nextInt() - 1;
			int fr = i + 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		dp = new int[n];
		prefMul = new int[n][];
		sufMul = new int[n][];
		go(0, -1);
		dpParentAns = new int[n];
		go2(0, -1);
		for (int v = 0; v < n; v++) {
			int ans = (int) ((1 + dpParentAns[v]) * 1L * dp	[v] % mod);
			out.print(ans + " ");
		}
		out.println();
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
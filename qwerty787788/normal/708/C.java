import java.io.*;
import java.util.*;

public class CF_Cr {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;

	int[] sz;
	int maxSize;
	int[] maxRes;

	void go(int v, int p) {
		sz[v] = 1;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}
			go(to, v);
			sz[v] += sz[to];
			maxRes[v] = Math.max(maxRes[v], maxRes[to]);
		}
		if (sz[v] <= maxSize) {
			maxRes[v] = sz[v];
		}
	}

	int n;

	boolean[] ans;

	void go2(int v, int p, int nowMax) {
		int all = n - sz[v];
		if (all <= maxSize) {
			nowMax = Math.max(nowMax, all);
		}
		int[] pref = new int[1 + g[v].size() - (p == -1 ? 0 : 1)];
		int it = 0;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}
			pref[it + 1] = Math.max(pref[it], maxRes[to]);
			it++;
		}
		int nowSuf = nowMax;
		for (int i = g[v].size() - 1; i >= 0; i--) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}
			it--;
			go2(to, v, Math.max(pref[it], nowSuf));
			nowSuf = Math.max(nowSuf, maxRes[to]);
		}
		ans[v] = true;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}
			if (sz[to] - maxRes[to] > maxSize) {
				ans[v] = false;
				break;
			}
		}
		if (n - sz[v] - nowMax > maxSize) {
			ans[v] = false;
		}
	}

	void solve() {
		n = in.nextInt();
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
		maxSize = n / 2;
		maxRes = new int[n];
		ans = new boolean[n];
		sz = new int[n];
		go(0, -1);
		go2(0, -1, 0);
		for (int i = 0; i < n; i++) {
			out.print(ans[i] ? 1 : 0);
			out.print(" ");
		}
		out.println();
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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new Thread(null, new Runnable() {
			
			@Override
			public void run() {

				new CF_Cr().runIO();	
			}
		}, "12312", 1 << 28).start();
	}
}
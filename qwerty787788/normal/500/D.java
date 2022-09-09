import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] sz;

	int go(int v, int p, ArrayList<Integer>[] g) {
		sz[v] = 1;
		for (int to : g[v]) {
			if (to != p) {
				sz[v] += go(to, v, g);
			}
		}
		return sz[v];
	}

	void solve() {
		int n = in.nextInt();
		int[] fr = new int[n - 1];
		int[] to = new int[n - 1];
		ArrayList<Integer>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		int[] cost = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			fr[i] = in.nextInt() - 1;
			to[i] = in.nextInt() - 1;
			g[fr[i]].add(to[i]);
			g[to[i]].add(fr[i]);
			cost[i] = in.nextInt();
		}
		sz = new int[n];
		go(0, 0, g);
		long curAns = 0;
		for (int i = 0; i < n - 1; i++) {
			int cnt = Math.min(sz[fr[i]], sz[to[i]]);
			curAns += cnt * 1L * (n - cnt) * 1L * cost[i];
		}
		int qq = in.nextInt();
		long denom = n * 1L * (n - 1) / 2;
		for (int q = 0; q < qq; q++) {
			int id = in.nextInt() - 1;
			int nCost = in.nextInt();
			int cnt = Math.min(sz[fr[id]], sz[to[id]]);
			curAns -= cnt * 1L * (n - cnt) * 1L * cost[id];
			cost[id] = nCost;
			curAns += cnt * 1L * (n - cnt) * 1L * cost[id];
			out.println(3.0 * curAns / 1.0 / denom);
		}
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
import java.io.*;
import java.util.*;

public class CF {

	class W implements Comparable<W> {
		int id, sz;

		W(int id, int sz) {
			this.id = id;
			this.sz = sz;
		}

		@Override
		public int compareTo(W o) {
			return -Integer.compare(sz, o.sz);
		}
	}

	int[] left;
	int center;
	boolean[] used;

	boolean go(int v) {
		if (used[v])
			return false;
		used[v] = true;
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v].get(i);
			if (to == center)
				continue;
			if (left[to] == -1 || go(left[to])) {
				left[to] = v;
				return true;
			}
		}
		return false;
	}

	ArrayList<Integer>[] g;

	void solve() {
		
		int n = in.nextInt();
		int m = in.nextInt();
		used = new boolean[n];
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			g[in.nextInt() - 1].add(in.nextInt() - 1);
		}
		long st = System.currentTimeMillis();
		int ans = Integer.MAX_VALUE;
		W[] a = new W[n];
		for (int i = 0; i < n; i++) {
			a[i] = new W(i, g[i].size());
		}
		left = new int[n];
		Arrays.sort(a);
		for (int centerId = 0; centerId < n; centerId++) {
			center = a[centerId].id;
			if (System.currentTimeMillis() - st > 800)
				break;
			int cost = n - g[center].size();
			Arrays.fill(left, -1);
			for (int i = 0; i < n; i++)
				if (i != center) {
					boolean has = false;
					for (int j = 0; j < g[i].size(); j++) {
						if (g[i].get(j) == center)
							has = true;
					}
					Arrays.fill(used, false);
					if (!go(i)) {
						if (has) {
							cost += g[i].size();
						} else {
							cost += g[i].size() + 2;
						}
					} else {
						if (has) {
							cost += g[i].size() - 2;
						} else {
							cost += g[i].size();
						}
					}
				}
			ans = Math.min(ans, cost);
		}
		out.println(ans);
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
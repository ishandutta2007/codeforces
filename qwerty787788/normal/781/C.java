import java.io.*;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	int[] p;

	int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}

	void unite(int x, int y) {
		p[get(x)] = get(y);
	}

	ArrayList<Integer>[] g;

	ArrayList<Integer> result = new ArrayList<Integer>();

	void go(int v, int p) {
		result.add(v);
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}
			go(to, v);
			result.add(v);
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		p = new int[n];
		g = new ArrayList[n];
		int k = in.nextInt();
		for (int i = 0; i < n; i++) {
			p[i] = i;
			g[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			if (get(fr) == get(to)) {
				continue;
			}
			unite(fr, to);
			g[fr].add(to);
			g[to].add(fr);
		}
		go(0, 0);
		int canUse = 1 + (2 * n - 1) / k;
		int from = 0;
		for (int i = 0; i < k; i++) {
			int use = Math.min(canUse, result.size() - from);
			if (use == 0) {
				out.println("1 1");
				continue;
			}
			out.print(use);
			for (int j = 0; j < use; j++) {
				out.print(" " + (1 + result.get(j + from)));
			}
			out.println();
			from += use;
		}
		if (from != result.size()) {
			throw new AssertionError();
		}
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
		new C().runIO();
	}
}
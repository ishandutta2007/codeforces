import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] p;
	int[] sz;

	int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}

	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) {
			return;
		}
		p[x] = y;
		sz[y] += sz[x];
	}

	class O implements Comparable<O> {
		int id;
		int val;

		public O(int id, int val) {
			super();
			this.id = id;
			this.val = val;
		}

		@Override
		public int compareTo(O o) {
			return Integer.compare(o.val, val);
		}

	}

	void solve() {
		int n = in.nextInt();
		p = new int[n];
		sz = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
			sz[i] = 1;
		}
		O[] a = new O[n];
		for (int i = 0; i < n; i++) {
			a[i] = new O(i, in.nextInt());
		}
		Arrays.sort(a);
		int[] ans = new int[n + 1];
		boolean[] alive = new boolean[n];
		for (O o : a) {
			alive[o.id] = true;
			if (o.id > 0 && alive[o.id - 1]) {
				unite(o.id, o.id - 1);
			}
			if (o.id + 1 < n && alive[o.id + 1]) {
				unite(o.id, o.id + 1);
			}
			ans[sz[get(o.id)]] = Math.max(ans[sz[get(o.id)]], o.val);
		}
		for (int i = n; i > 0; i--) {
			ans[i - 1] = Math.max(ans[i - 1], ans[i]);
		}
		for (int i = 1; i <= n; i++) {
			out.print(ans[i] + " ");
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
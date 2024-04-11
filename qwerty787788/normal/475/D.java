import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int gcd(int x, int y) {
		return x == 0 ? y : gcd(y % x, x);
	}

	class Query implements Comparable<Query> {
		int pos, value;

		public Query(int pos, int value) {
			super();
			this.pos = pos;
			this.value = value;
		}

		@Override
		public int compareTo(Query o) {
			return Integer.compare(value, o.value);
		}

	}

	Query[] all;
	long[] sum;

	void add(int gcd, int len) {
		int l = -1, r = all.length;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (all[m].value >= gcd) {
				r = m;
			} else {
				l = m;
			}
		}
if (r == all.length || all[r].value != gcd)
			return;
		sum[r] += len;
		l = 0;
		r = all.length;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (all[m].value <= gcd) {
				l = m;
			} else {
				r = m;
			}
		}
		sum[l + 1] -= len;
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		final int MAX = 20;
		int[][] g = new int[MAX][n];
		for (int i = 0; i < n; i++) {
			g[0][i] = a[i];
		}
		for (int i = 1; i < MAX; i++) {
			for (int j = 0; j < n; j++) {
				int next = j + (1 << (i - 1));
				if (next >= n) {
					g[i][j] = g[i - 1][j];
				} else {
					g[i][j] = gcd(g[i - 1][j], g[i - 1][next]);
				}
			}
		}
		int qq = in.nextInt();
		all = new Query[qq];
		for (int q = 0; q < qq; q++) {
			all[q] = new Query(q, in.nextInt());
		}
		sum = new long[qq + 1];
		Arrays.sort(all);
		for (int start = 0; start < n; start++) {
			int curGCD = a[start];
			int from = start;
			while (true) {
				int len = 0;
				for (int i = MAX - 1; i >= 0; i--) {
					if (from != n && g[i][from] % curGCD == 0) {
						int add = Math.min(1 << i, n - from);
						from += add;
						len += add;
					}
				}
				add(curGCD, len);
				if (from == n)
					break;
				curGCD = gcd(curGCD, a[from]);
			}
		}
		long[] answer = new long[qq];
		long tmp = 0;
		for (int i = 0; i < all.length; i++) {
			tmp += sum[i];
			answer[all[i].pos] = tmp;
		}
		for (int i = 0; i < qq; i++) {
			out.println(answer[i]);
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
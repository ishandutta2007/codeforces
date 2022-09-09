import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Ans implements Comparable<Ans> {
		int s, t;

		public Ans(int s, int t) {
			super();
			this.s = s;
			this.t = t;
		}

		@Override
		public int compareTo(Ans o) {
			if (s == o.s)
				return Integer.compare(t, o.t);
			return Integer.compare(s, o.s);
		}

	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt() - 1;
		}
		int[][] pr = new int[2][n + 1];
		for (int i = 0; i < n; i++) {
			pr[0][i + 1] = pr[0][i];
			pr[1][i + 1] = pr[1][i];
			pr[a[i]][i + 1]++;
		}
		final int SQRT = 700;
		ArrayList<Ans> ans = new ArrayList<>();
		int[] c = new int[2];
		int[] s = new int[2];
		for (int t = 1; t <= n; t++) {
			if (t <= SQRT) {
				int last = -1;
				int pos = 0;
				boolean ok = true;
				c[0] = c[1] = 0;
				while (pos != n) {
					s[0] = s[1] = 0;
					while (s[0] != t && s[1] != t && pos != n) {
						s[a[pos]]++;
						pos++;
					}
					if (s[0] != t && s[1] != t) {
						ok = false;
					} else {
						if (s[0] == t) {
							c[0]++;
							last =0;
						} else {
							c[1]++;
							last = 1;
						}
					}
				}
				if (ok && c[0] != c[1] && Math.max(c[0], c[1]) == c[last]) {
					ans.add(new Ans(Math.max(c[0], c[1]), t));
				}
			} else {
				int pos = 0;
				boolean ok = true;
				c[0] = c[1] = 0;
				int last = -1;
				while (pos != n) {
					int a0 = pr[0][n] - pr[0][pos];
					int a1 = pr[1][n] - pr[1][pos];
					if (a0 < t && a1 < t) {
						ok = false;
						break;
					}
					int l = pos, r = n;
					while (r - l > 1) {
						int mid = (l + r) >>> 1;
						int a00 = pr[0][mid] - pr[0][pos];
						int a10 = pr[1][mid] - pr[1][pos];
						if (a00 >= t || a10 >= t) {
							r = mid;
						} else {
							l = mid;
						}
					}
					if (pr[0][r] - pr[0][pos] == t) {
						c[0]++;
						last = 0;
					} else {
						c[1]++;
						last = 1;
					}
					pos = r;
				}
				if (ok && c[0] != c[1] && Math.max(c[0], c[1]) == c[last]) {
					ans.add(new Ans(Math.max(c[0], c[1]), t));
				}
			}
		}
		Collections.sort(ans);
		out.println(ans.size());
		for (Ans an : ans) {
			out.println(an.s + " " + an.t);
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
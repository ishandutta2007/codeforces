import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final int TIMELIMIT = 6000;

	void solve() {
		long START = System.currentTimeMillis();
		int n = in.nextInt();
		int m = in.nextInt();
		final int[][] d = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(d[i], Integer.MAX_VALUE / 3);
			d[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			d[fr][to] = d[to][fr] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					d[j][k] = Math.min(d[j][k], d[j][i] + d[i][k]);
				}
			}
		}
		Integer[][] g = new Integer[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = j;
			}
			final int start = i;
			Arrays.sort(g[i], new Comparator<Integer>() {

				@Override
				public int compare(Integer o1, Integer o2) {
					return Integer.compare(d[start][o1], d[start][o2]);
				}
			});
		}
		double res = 0;
		double[] pr = new double[n];
		double p = 1. / n;
		int[] sz = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] == 1) {
					sz[i]++;
				}
			}
		}

		O[] a = new O[n];

		for (int start = 0; start < n; start++) {
			int val = 0;
			for (int posi = 0; posi < n;) {
				Arrays.fill(pr, 0);
				int posj = posi;
				while (posj != n
						&& d[start][g[start][posi]] == d[start][g[start][posj]]) {
					posj++;
				}
				val += (posj - posi) * (posj - posi);
				posi = posj;
			}
			a[start] = new O(start, val);
		}

		Arrays.sort(a);
		boolean[] was = new boolean[n];
		double[] maxForDist = new double[n + 1];
		for (O o : a) {
			if (System.currentTimeMillis() - START > TIMELIMIT) {
				break;
			}
			int start = o.id;
			double cur = 0;
			
			for (int posi = 0; posi < n;) {
				Arrays.fill(pr, 0);
				int posj = posi;
				while (posj != n
						&& d[start][g[start][posi]] == d[start][g[start][posj]]) {
					posj++;
				}
				if (cur + p * (n - posi) < res) {
					break;
				}
				if (posj - posi == 1) {
					cur += p;
				} else {
					ArrayList<Integer> check = new ArrayList<>();
					Arrays.fill(was, false);
					for (int ii = posi; ii < posj; ii++) {
						int v = g[start][ii];
						double add = p / sz[v];
						for (int j = 0; j < n; j++) {
							if (d[v][j] == 1) {
								pr[j] += add;
								if (!was[j]) {
									was[j] = true;
									check.add(j);
								}
							}
						}
					}
					double tryThis = p;
					Arrays.fill(maxForDist, 0);
					for (O o2 : a) {
						int second = o2.id;
						for (int u : check) {
							maxForDist[d[second][u]] = Math.max(maxForDist[d[second][u]], pr[u]);
						}
						double myAns = 0;
						for (int u : check) {
							myAns += maxForDist[d[second][u]];
							maxForDist[d[second][u]] = 0;
						}
						tryThis = Math.max(tryThis, myAns);
					}
					cur += tryThis;
				}
				posi = posj;
			}
			res = Math.max(res, cur);
		}
		out.println(res);
	}

	class O implements Comparable<O> {
		int id, val;

		public O(int id, int val) {
			super();
			this.id = id;
			this.val = val;
		}

		@Override
		public int compareTo(O o) {
			return Integer.compare(val, o.val);
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
		new CF().runIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class SegmentTree {
		int[][] vals;
		boolean[] swap;
		int n;

		SegmentTree(String s) {
			n = s.length();
			vals = new int[4][n * 4];
			swap = new boolean[n * 4];
			build(0, 0, n - 1, s);
		}

		void build(int v, int l, int r, String s) {
			if (l == r) {
				if (s.charAt(l) == '4') {
					vals[0][v] = vals[2][v] = vals[3][v] = 1;
				} else {
					vals[1][v] = vals[2][v] = vals[3][v] = 1;
				}
			} else {
				int m = (l + r) >>> 1;
				build(v * 2 + 1, l, m, s);
				build(v * 2 + 2, m + 1, r, s);
				upd(v);
			}
		}

		void doSwap(int v) {
			{
				int tmp = vals[0][v];
				vals[0][v] = vals[1][v];
				vals[1][v] = tmp;
			}
			{
				int tmp = vals[2][v];
				vals[2][v] = vals[3][v];
				vals[3][v] = tmp;
			}
		}

		void upd(int v) {
			vals[0][v] = vals[0][v * 2 + 1] + vals[0][v * 2 + 2];
			vals[1][v] = vals[1][v * 2 + 1] + vals[1][v * 2 + 2];
			vals[2][v] = Math.max(vals[0][v * 2 + 1] + vals[2][v * 2 + 2],
					vals[2][v * 2 + 1] + vals[1][v * 2 + 2]);
			vals[3][v] = Math.max(vals[1][v * 2 + 1] + vals[3][v * 2 + 2],
					vals[3][v * 2 + 1] + vals[0][v * 2 + 2]);
			if (swap[v]) {
				doSwap(v);
			}
		}

		void update(int v, int l, int r, int needL, int needR) {
			if (needL > r || needR < l) {
				return;
			}
			if (needL <= l && needR >= r) {
				swap[v] = !swap[v];
				doSwap(v);
				return;
			}
			int m = (l + r) >>> 1;
			update(v * 2 + 1, l, m, needL, needR);
			update(v * 2 + 2, m + 1, r, needL, needR);
			upd(v);
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		String s = in.next();
		SegmentTree st = new SegmentTree(s);
		for (int i = 0; i < m; i++) {
			if (in.next().equals("count")) {
				out.println(st.vals[2][0]);
			} else {
				int from = in.nextInt() - 1, to = in.nextInt() - 1;
				st.update(0, 0, n - 1, from, to);
			}
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
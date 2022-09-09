import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	MyScanner in;
	PrintWriter out;

	class SegmentTree {
		int n;
		int[] max;

		public SegmentTree(int n) {
			this.n = n;
			max = new int[4 * n];
		}

		void upd(int v, int l, int r, int need, int val) {
			if (l == r) {
				max[v] = val;
			} else {
				int m = (l + r) / 2;
				if (need <= m) {
					upd(v * 2 + 1, l, m, need, val);
				} else {
					upd(v * 2 + 2, m + 1, r, need, val);
				}
				max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
			}
		}

		int get(int v, int l, int r, int needL, int needR) {
			if (needR < needL)
				return 0;
			if (needL == l && needR == r)
				return max[v];
			int m = (l + r) / 2;
			return Math.max(get(v * 2 + 1, l, m, needL, Math.min(needR, m)), get(v * 2 + 2, m + 1, r, Math.max(m + 1, needL), needR));
		}
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		SegmentTree st = new SegmentTree(n + 1);
		int res = 0;
		for (int i = 0; i < n; i++) {
			int max = st.get(0, 0, n, 0, a[i] - 1);
			st.upd(0, 0, n, a[i], max + 1);
			res = Math.max(res, max + 1);
		}
		out.println(res);
	}

	void run() {
		try {
			in = new MyScanner();
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class MyScanner {
		BufferedReader in;
		StringTokenizer st;

		public MyScanner() {
			in = new BufferedReader(new InputStreamReader(System.in));

		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(in.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new CF().run();
	}
}
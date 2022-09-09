import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] start;
	int[] left, right;

	String ask = "2016";

	void go(int l, int r) {
		if (l == r) {
			return;
		}
		int m = (l + r + 1) >> 1;
		go(l, m - 1);
		go(m, r);
		int prevId = n;
		for (int pos = m; pos <= r; pos++) {
			for (int i = 0; i < 4; i++) {
				for (int j = i; j < 4; j++) {
					dpRight[i][j][pos] = Integer.MAX_VALUE;
					if (s[pos] != ask.charAt(j)) {
						dpRight[i][j][pos] = dpRight[i][j][prevId];
					} else {
						if (dpRight[i][j][prevId] != Integer.MAX_VALUE) {
							dpRight[i][j][pos] = dpRight[i][j][prevId] + 1;
						}
					}
					if (i != j
							&& dpRight[i][j - 1][prevId] != Integer.MAX_VALUE) {
						if (ask.charAt(j - 1) == s[pos]) {
							dpRight[i][j][pos] = Math.min(dpRight[i][j][pos],
									dpRight[i][j - 1][prevId]);
						}
					}
				}
			}
			prevId = pos;
		}
		prevId = n;
		for (int pos = m - 1; pos >= l; pos--) {
			for (int i = 0; i < 4; i++) {
				for (int j = i; j < 4; j++) {
					dpLeft[i][j][pos] = Integer.MAX_VALUE;
					if (s[pos] != ask.charAt(i)) {
						dpLeft[i][j][pos] = dpLeft[i][j][prevId];
					} else {
						if (dpLeft[i][j][prevId] != Integer.MAX_VALUE) {
							dpLeft[i][j][pos] = dpLeft[i][j][prevId] + 1;
						}
						if (i != j
								&& dpLeft[i + 1][j][prevId] != Integer.MAX_VALUE) {
							dpLeft[i][j][pos] = Math.min(dpLeft[i][j][pos],
									dpLeft[i + 1][j][prevId]);
						}
					}
				}
			}
			for (int id : start[pos]) {
				int ri = right[id];
				if (ri >= m && ri <= r) {
					int best = Integer.MAX_VALUE;
					for (int inter = 0; inter < 4; inter++) {
						if (dpLeft[0][inter][pos] != Integer.MAX_VALUE) {
							if (dpRight[inter][3][ri] != Integer.MAX_VALUE) {
								best = Math.min(best, dpLeft[0][inter][pos]
										+ dpRight[inter][3][ri]);
							}
						}
					}
					if (best == Integer.MAX_VALUE) {
						ans[id] = -1;
					} else {
						ans[id] += best;
					}
				}
			}
			prevId = pos;
		}
	}

	char[] s;
	int n;

	int[][][] dpLeft;
	int[][][] dpRight;

	int[] ans;

	void solve() {
		n = in.nextInt();
		int q = in.nextInt();
		s = in.next().toCharArray();
		dpLeft = new int[4][4][n + 1];
		dpRight = new int[4][4][n + 1];
		left = new int[q];
		right = new int[q];
		start = new ArrayList[n];
		int[] last7 = new int[n];
		int[] cnt6 = new int[n + 1];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dpRight[i][j][n] = i == j ? 0 : Integer.MAX_VALUE;
				dpLeft[i][j][n] = i == j ? 0 : Integer.MAX_VALUE;
			}
		}
		for (int i = 0; i < n; i++) {
			cnt6[i + 1] = cnt6[i];
			if (s[i] == '6') {
				cnt6[i + 1]++;
			}
			if (s[i] == '7') {
				last7[i] = i;
			} else {
				last7[i] = i == 0 ? -1 : (last7[i - 1]);
			}
		}
		ans = new int[q];
		for (int i = 0; i < n; i++) {
			start[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < q; i++) {
			left[i] = in.nextInt() - 1;
			right[i] = in.nextInt() - 1;
			int pr = last7[right[i]];
			if (pr <= left[i]) {
				ans[i] = -1;
			} else {
				ans[i] = cnt6[right[i] + 1] - cnt6[pr];
				right[i] = pr;
				start[left[i]].add(i);
			}
		}
		go(0, n - 1);
		for (int x : ans) {
			out.println(x);
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
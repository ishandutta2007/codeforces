import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		int[][] cost = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cost[i][j] = in.nextInt();
			}
		}
		int[] dp = new int[1 << n];
		Arrays.fill(dp, Integer.MAX_VALUE / 2);
		int curMask = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				for (int k = 0; k < n; k++) {
					if (a[k][j] == a[i][j]) {
						cnt++;
					}
				}
				if (cnt == 1) {
					curMask |= 1 << i;
				}
			}
		}
		dp[curMask] = 0;
		ArrayList<Integer> masks = new ArrayList<>();
		ArrayList<Integer> costs = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			masks.add(1 << i);
			int curCost = Integer.MAX_VALUE;
			for (int j = 0; j < m; j++) {
				curCost = Math.min(curCost, cost[i][j]);
			}
			costs.add(curCost);
		}
		ArrayList<Integer> price = new ArrayList<>();
		for (int col = 0; col < m; col++) {
			for (int row = 0; row < n; row++) {
				boolean ok = true;
				int nowMask = 0;
				price.clear();
				for (int row2 = 0; row2 < n; row2++) {
					if (a[row2][col] == a[row][col]) {
						if (row2 < row) {
							ok = false;
						}
						nowMask |= 1 << row2;
						price.add(cost[row2][col]);
					}
				}
				if (!ok) {
					continue;
				}
				Collections.sort(price);
				if (price.size() == 1) {
					continue;
				}
				masks.add(nowMask);
				int sum = 0;
				for (int i = 0; i + 1 < price.size(); i++) {
					sum += price.get(i);
				}
				costs.add(sum);
			}
		}
		int sz = costs.size();
		int[] addM = new int[sz];
		int[] addC = new int[sz];
		for (int i = 0; i < sz; i++) {
			addM[i] = masks.get(i);
			addC[i] = costs.get(i);
		}
		for (int mask = 0; mask < 1 << n; mask++) {
			int cur = dp[mask];
			if (cur >= Integer.MAX_VALUE / 2) {
				continue;
			}
			for (int i = 0; i < sz; i++) {
				int nmask = mask | addM[i];
				int ncost = cur + addC[i];
				if (dp[nmask] > ncost) {
					dp[nmask] = ncost;
				}
			}
		}
		out.println(dp[dp.length - 1]);
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
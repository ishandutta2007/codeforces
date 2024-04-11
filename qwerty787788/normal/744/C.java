import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		boolean[] isRed = new boolean[n];
		int[] rCost = new int[n];
		int[] bCost = new int[n];
		long needR = 0, needB = 0;
		for (int i = 0; i < n; i++) {
			isRed[i] = in.next().equals("R");
			rCost[i] = in.nextInt();
			needR += rCost[i];
			bCost[i] = in.nextInt();
			needB += bCost[i];
		}
		final int max = n * (n - 1) / 2 + 1;
		int[][] dp = new int[max][1 << n];
		for (int i = 0; i < max; i++) {
			Arrays.fill(dp[i], -1);
		}
		dp[0][0] = 0;
		for (int mask = 0; mask < 1 << n; mask++) {
			int cntRed = 0;
			int cntBlue = 0;
			for (int i = 0; i < n; i++) {
				if (((1 << i) & mask) != 0) {
					if (isRed[i]) {
						cntRed++;
					} else {
						cntBlue++;
					}
				}
			}
			for (int red = 0; red < max; red++) {
				if (dp[red][mask] == -1) {
					continue;
				}
				for (int next = 0; next < n; next++) {
					if (((1 << next) & mask) == 0) {
						int nred = red + Math.min(rCost[next], cntRed);
						int nblue = dp[red][mask]
								+ Math.min(bCost[next], cntBlue);
						int nmask = mask | (1 << next);
						dp[nred][nmask] = Math.max(dp[nred][nmask], nblue);
					}
				}
			}
		}
		long result = Long.MAX_VALUE;
		for (int r = 0; r < max; r++) {
			int b = dp[r][(1 << n) - 1];
			if (b == -1) {
				continue;
			}
			long curRes = Math.max(needR - r, needB - b);
			result = Math.min(result, curRes);
		}
		out.println(result + n);
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
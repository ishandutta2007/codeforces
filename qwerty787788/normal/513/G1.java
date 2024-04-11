import java.io.*;
import java.util.*;

public class CFG {
	FastScanner in;
	PrintWriter out;

	int reflect(int pos, int left, int right) {
		if (pos < left || pos > right) {
			return pos;
		}
		return right + left - pos;
	}

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		double[][] dp = new double[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[i] < a[j]) {
					dp[i][j]++;
				}
		int total = n * (n + 1) / 2;
		for (int move = 0; move < k; move++) {
			double[][] newDp = new double[n][n];
			for (int pos1 = 0; pos1 < n; pos1++)
				for (int pos2 = 0; pos2 < n; pos2++) {
					for (int left = 0; left < n; left++)
						for (int right = left; right < n; right++) {
							newDp[reflect(pos1, left, right)][reflect(pos2,
									left, right)] += dp[pos1][pos2] / total;
						}
				}
			dp = newDp;
		}
		double result = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				result += dp[i][j];
		out.println(result);
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
		new CFG().runIO();
	}
}
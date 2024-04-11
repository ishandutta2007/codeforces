import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	long[] solveOneDTask(int[][] a, int k, int p) {
		int n = a.length;
		PriorityQueue<Long> pq = new PriorityQueue<>();
		long[] ans = new long[k + 1];
		ans[0] = 0;
		int m = a[0].length;
		for (int i = 0; i < n; i++) {
			long sum = 0;
			for (int j = 0; j < m; j++)
				sum += a[i][j];
			pq.add(-sum);
		}
		for (int moves = 1; moves <= k; moves++) {
			long curBest = pq.poll();
			ans[moves] = ans[moves - 1] - curBest;
			pq.add(curBest + m * 1L * p);
		}
		return ans;
	}

	int[][] reverse(int[][] a) {
		int[][] b = new int[a[0].length][a.length];
		for (int i = 0; i < a.length; i++)
			for (int j = 0; j < a[i].length; j++)
				b[j][i] = a[i][j];
		return b;
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		int p = in.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = in.nextInt();
			}
		}
		long[] ans1 = solveOneDTask(a, k, p);
		long[] ans2 = solveOneDTask(reverse(a), k, p);
		long best = Long.MIN_VALUE;
		for (int f = 0; f <= k; f++) {
			int s = k - f;
			long cost = ans1[f] + ans2[s] - p * 1L * f * s;
			best = Math.max(best, cost);
		}
		out.println(best);
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

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
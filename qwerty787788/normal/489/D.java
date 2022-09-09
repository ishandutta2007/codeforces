import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	boolean can(int len, int sum) {
		return sum >= 0 && sum <= 9 * len;
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		boolean[][] has = new boolean[n][n];
		ArrayList<Integer>[] g = new ArrayList[n];
		ArrayList<Integer>[] gRev = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
			gRev[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			gRev[to].add(fr);
			has[fr][to] = true;
		}
		long res = 0;
		int[][] cntIn = new int[n][n];
		int[][] cntOut = new int[n][n];
		for (int i = 0; i < n; i++) {
			int sz = g[i].size();
			for (int j = 0; j < sz; j++)
				for (int k = j + 1; k < sz; k++) {
					int to1 = g[i].get(j), to2 = g[i].get(k);
					if (to1 > to2) {
						int tmp = to1;
						to1 = to2;
						to2 = tmp;
					}
					cntIn[to1][to2]++;
					if (has[to1][i] && has[to2][i]) {
						res--;
					}
				}
		}
		for (int i = 0; i < n; i++) {
			int sz = gRev[i].size();
			for (int j = 0; j < sz; j++)
				for (int k = j + 1; k < sz; k++) {
					int to1 = gRev[i].get(j), to2 = gRev[i].get(k);
					if (to1 > to2) {
						int tmp = to1;
						to1 = to2;
						to2 = tmp;
					}
					cntOut[to1][to2]++;
				}
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				res += cntIn[i][j] * cntOut[i][j];
			}
		out.println(res);
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
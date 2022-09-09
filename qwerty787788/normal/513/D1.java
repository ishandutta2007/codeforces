import java.io.*;
import java.util.*;

public class CFD {
	FastScanner in;
	PrintWriter out;

	final String imp = "IMPOSSIBLE";

	void go(int left, int right, int[][] sz) {
		if (left == right) {
			return;
		}
		if (right == left + 1) {
			out.print(left + 1);
			out.print(" ");
			return;
		}
		go(left + 1, left + 1 + sz[left][right], sz);
		out.print(left + 1);
		out.print(" ");
		go(left + 1 + sz[left][right], right, sz);
	}

	void solve() {
		int n = in.nextInt();
		int c = in.nextInt();
		int[][] g = new int[n][n];
		for (int i = 0; i < c; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			if (x >= y) {
				out.println(imp);
				return;
			}
			if (in.next().equals("LEFT")) {
				if (g[x][y] == 2) {
					out.println(imp);
					return;
				}
				g[x][y] = 1;
			} else {
				if (g[x][y] == 1) {
					out.println(imp);
					return;
				}
				g[x][y] = 2;
			}
		}
		boolean[][] can = new boolean[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			can[i][i] = true;
		}
		int[][] sz = new int[n + 1][n + 1];
		for (int len = 1; len <= n; len++)
			for (int fr = 0; fr + len <= n; fr++) {
				int to = fr + len - 1;
				for (int firstPart = 0; firstPart < len; firstPart++) {
					int secondPart = len - 1 - firstPart;
					boolean ok = true;
					int from1 = fr + 1, to1 = from1 + firstPart;
					int from2 = to1, to2 = from2 + secondPart;
					for (int j = fr + 1; j < n; j++)
						if (g[fr][j] != 0) {
							if (g[fr][j] == 1 && (j < from1 || j >= to1)) {
								ok = false;
							}
							if (g[fr][j] == 2 && (j < from2 || j >= to2)) {
								ok = false;
							}
						}
					if (ok && can[from1][to1] && can[from2][to2]) {
						can[fr][to + 1] = true;
						sz[fr][to + 1] = firstPart;
					}
				}
			}
		if (!can[0][n]) {
			out.println(imp);
			return;
		}
		go(0, n, sz);
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
		new CFD().runIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	boolean[][][] canGoUpDownLeftRight(char[][] a) {
		int n = a.length, m = a[0].length;
		boolean[][][] res = new boolean[4][n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				res[0][i][j] = a[i][j] != '#';
				res[2][i][j] = a[i][j] != '#';
				if (i > 0) {
					res[0][i][j] &= res[0][i - 1][j];
				}
				if (j > 0) {
					res[2][i][j] &= res[2][i][j - 1];
				}
			}
		for (int i = n - 1; i >= 0; i--)
			for (int j = m - 1; j >= 0; j--) {
				res[1][i][j] = a[i][j] != '#';
				res[3][i][j] = a[i][j] != '#';
				if (i != n - 1) {
					res[1][i][j] &= res[1][i + 1][j];
				}
				if (j != m - 1) {
					res[3][i][j] &= res[3][i][j + 1];
				}
			}
		return res;
	}

	long solve(char[][] a) {
		boolean[][][] udlr = canGoUpDownLeftRight(a);
		long res = 0;
		int n = a.length, m = a[0].length;
		for (int i = 1; i + 1 < n; i++) {
			if (udlr[3][i][0]) {
				res++;
			}
		}
		for (int i = 1; i + 1 < m; i++) {
			if (udlr[1][0][i]) {
				res++;
			}
		}
		for (int i = 1; i + 1 < n; i++)
			for (int j = 1; j + 1 < m; j++) {
				for (int k = 0; k < 2; k++) {
					res += (udlr[k][i][j] && udlr[2][i][j]) ? 1 : 0;
					res += (udlr[k][i][j] && udlr[3][i][j]) ? 1 : 0;
				}
			}
		for (int i = 1; i + 1 < n; i++) {
			int tmp = 0;
			for (int j = 1; j + 1 < m; j++) {
				if (a[i][j] == '#') {
					tmp = 0;
				} else {
					if (udlr[0][i][j]) {
						res += tmp;
						if (j > 1 && udlr[0][i][j - 1]) {
							res--;
						}
					}
					if (udlr[1][i][j]) {
						res += tmp;
						if (j > 1 && udlr[1][i][j - 1]) {
							res--;
						}
					}
					if (udlr[0][i][j]) {
						tmp++;
					}
					if (udlr[1][i][j]) {
						tmp++;
					}
				}
			}
		}

		for (int j = 1; j + 1 < m; j++) {
			int tmp = 0;
			for (int i = 1; i + 1 < n; i++) {
				if (a[i][j] == '#') {
					tmp = 0;
				} else {
					if (udlr[2][i][j]) {
						res += tmp;
						if (i > 1 && udlr[2][i - 1][j]) {
							res--;
						}
					}
					if (udlr[3][i][j]) {
						res += tmp;
						if (i > 1 && udlr[3][i - 1][j]) {
							res--;
						}
					}
					if (udlr[2][i][j]) {
						tmp++;
					}
					if (udlr[3][i][j]) {
						tmp++;
					}
				}
			}
		}
		return res;
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		long res = 0;
		res = solve(a);
		out.println(res);
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
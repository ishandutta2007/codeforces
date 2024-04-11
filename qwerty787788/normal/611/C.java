import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[][] sum1, sum2;

	int getR(int r, int c) {
		if (r == 0 || c == 0) {
			return 0;
		}
		return (r > 1 ? sum1[r - 2][c - 1] : 0);
	}

	int getC(int r, int c) {
		if (r == 0 || c == 0) {
			return 0;
		}
		return (c > 1 ? sum2[r - 1][c - 2] : 0);
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		sum1 = new int[n - 1][m];
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				sum1[i][j] = (a[i][j] == '.' && a[i + 1][j] == '.') ? 1 : 0;
				if (i > 0) {
					sum1[i][j] += sum1[i - 1][j];
				}
				if (j > 0) {
					sum1[i][j] += sum1[i][j - 1];
				}
				if (i > 0 && j > 0) {
					sum1[i][j] -= sum1[i - 1][j - 1];
				}
			}
		}
		sum2 = new int[n][m - 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				sum2[i][j] = (a[i][j] == '.' && a[i][j + 1] == '.') ? 1 : 0;
				if (i > 0) {
					sum2[i][j] += sum2[i - 1][j];
				}
				if (j > 0) {
					sum2[i][j] += sum2[i][j - 1];
				}
				if (i > 0 && j > 0) {
					sum2[i][j] -= sum2[i - 1][j - 1];
				}
			}
		}
		int qq = in.nextInt();
		for (int q = 0; q < qq; q++) {
			int r1 = in.nextInt();
			int c1 = in.nextInt();
			int r2 = in.nextInt();
			int c2 = in.nextInt();
			int res = getC(r2, c2) - getC(r1 - 1, c2) - getC(r2, c1)
					+ getC(r1 - 1, c1);
			res += getR(r2, c2) - getR(r1, c2) - getR(r2, c1 - 1)
					+ getR(r1, c1 - 1);
			out.println(res);
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
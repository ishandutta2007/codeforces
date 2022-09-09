import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int solve(char[][] a) {
		int n = a.length;
		int m = a[0].length;
		int[][] right = new int[n][m];
		int[][] down = new int[n][m];
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (a[i][j] == '.') {
					right[i][j] = j;
					if (i + 1 == n) {
						down[i][j] = i + 1;
					} else {
						down[i][j] = down[i + 1][j];
					}
				} else {
					down[i][j] = i;
					if (j + 1 == m) {
						right[i][j] = j + 1;
					} else {
						right[i][j] = right[i][j + 1];
					}
				}
			}
		}
		int x1 = -1, y1 = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (x1 != -1)
					break;
				if (a[i][j] == 'X') {
					x1 = i;
					y1 = j;
					break;
				}
			}
		if (x1 == -1)
			return Integer.MAX_VALUE;
		int w = right[x1][y1] - y1;
		int h = 0;
		int tmpX = x1;
		while (tmpX != n && a[tmpX][y1] == 'X') {
			h++;
			tmpX++;
		}
		int tmp = y1;
		y1 += w - 1;
		if (y1 == m - 1 || down[x1][y1 + 1] == n) {
			h = 1;
		} else {
			int cnt = down[x1][y1 + 1] - x1;
			h -= cnt;
		}
		h = Math.max(h, 1);
		w = Math.max(w, 1);
		y1 = tmp;
		int[][] sum = new int[n + 1][m + 1];
		while (true) {
			sum[x1][y1]++;
			sum[x1 + h][y1]--;
			sum[x1][y1 + w]--;
			sum[x1 + h][y1 + w]++;
			if (x1 + h < n && a[x1 + h][y1] == 'X') {
				x1++;
			} else {
				if (y1 + w < m && a[x1][y1 + w] == 'X') {
					y1++;
				} else {
					break;
				}
			}
		}
		for (int i = n; i >= 0; i--)
			for (int j = m; j >= 0; j--) {
				if (i > 0 && j > 0)
					sum[i - 1][j - 1] -= sum[i][j];
				if (i > 0)
					sum[i - 1][j] += sum[i][j];
				if (j > 0)
					sum[i][j - 1] += sum[i][j];
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				boolean need = sum[i + 1][j + 1] > 0;
				if (need != (a[i][j] == 'X'))
					return Integer.MAX_VALUE;
			}
		return w * h;
	}

	void solve2() {
		Random rnd = new Random(13);
		for (int it = 0;; it++) {
			System.err.println("iter = " + it);
			if (it == 3) {
				System.err.println("!");
			}
			int n = 1 + rnd.nextInt(10);
			int m = 1 + rnd.nextInt(10);
			char[][] c = new char[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					c[i][j] = rnd.nextBoolean() ? 'X' : '.';
			solve(c);
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		int ans = solve(a);
		char[][] b = new char[m][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				b[j][i] = a[i][j];
		ans = Math.min(ans, solve(b));
		out.println(ans == Integer.MAX_VALUE ? -1 : ans);
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
import java.io.*;
import java.util.*;

public class A implements Runnable {
	public static void main(String[] args) {
		new A().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			char[] c = nextToken().toCharArray();
			for (int j = 0; j < m; j++) {
				a[i][j] = c[j] - '0';
			}
		}
		int[][] b = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				b[i][j] += a[i][j];
				if (i > 0) {
					b[i][j] += b[i - 1][j];
				}
				if (j > 0) {
					b[i][j] += b[i][j - 1];
				}
				if (i > 0 && j > 0) {
					b[i][j] -= b[i - 1][j - 1];
				}
			}
		}
		int ans = 0;
		for (int x1 = 0; x1 < n; x1++) {
			for (int y1 = 0; y1 < m; y1++) {
				for (int x2 = x1; x2 < n; x2++) {
					for (int y2 = y1; y2 < m; y2++) {
						int r = b[x2][y2];
						if (x1 > 0) {
							r -= b[x1 - 1][y2];
						}
						if (y1 > 0) {
							r -= b[x2][y1 - 1];
						}
						if (x1 > 0 && y1 > 0) {
							r += b[x1 - 1][y1 - 1];
						}
						if (r != 0) {
							continue;
						}
						ans = Math.max(ans, 2 * (x2 - x1 + y2 - y1 + 2));
					}
				}
			}
		}
		out.println(ans);
	}
}
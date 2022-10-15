import java.io.*;
import java.util.*;
import java.math.*;

public class J implements Runnable {
	public static void main(String[] args) {
		new J().run();
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

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
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

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	void solve() {
		int n = nextInt();
		int m = nextInt();
		if (n == 1 && m == 1) {
			out.println(1);
			return;
		}
		if (n <= 2 && m <= 2 || (n == 1 && m == 3) || (n == 3 && m == 1)) {
			out.println(-1);
			return;
		}
		int iter = 100000 / n / m;
		loop: for (int it = 0; it < iter; it++) {
			TreeSet<Integer> ts = new TreeSet<Integer>();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					ts.add(i * m + j);
				}
			}
			int[][] ans = new int[n][m];
			for (int i = 0; i < ans.length; i++) {
				Arrays.fill(ans[i], -5);
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					Integer e;
					int cnt = 0;
					do {
						e = rand.nextBoolean() ? ts
								.ceiling(rand.nextInt(n * m)) : ts.floor(rand
								.nextInt(n * m));
						++cnt;
						if (e != null) {
							ans[i][j] = e;
						}
					} while (cnt < 105 && (e == null || !check(ans, i, j)));
					if (cnt == 105) {
						continue loop;
					}
					ts.remove(e);
					ans[i][j] = e;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (!check(ans, i, j)) {
						continue loop;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					out.print(1 + ans[i][j] + " ");
				}
				out.println();
			}
			return;
		}		
	}

	final int[] DX = { 1, 0, -1, 0 };
	final int[] DY = { 0, 1, 0, -1 };

	boolean check(int[][] a, int x, int y) {
		for (int dir = 0; dir < 4; dir++) {
			int xx = x + DX[dir];
			int yy = y + DY[dir];
			if (xx < 0 || yy < 0 || xx >= a.length || yy >= a[xx].length) {
				continue;
			}
			if (Math.abs(a[xx][yy] - a[x][y]) <= 1) {
				return false;
			}
		}
		return true;
	}

	final Random rand = new Random(this.hashCode());
}
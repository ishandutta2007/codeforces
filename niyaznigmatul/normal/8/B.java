import java.io.*;
import java.math.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
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

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	final int[] DX = { 0, 1, 0, -1 };
	final int[] DY = { 1, 0, -1, 0 };

	void solve() {
		char[] s = nextToken().toCharArray();
		int[][] a = new int[401][401];
		int x = 200, y = 200, cur = 1;
		a[x][y] = cur++;
		for (char c : s) {
			if (c == 'L') {
				--x;
			} else if (c == 'R') {
				++x;
			} else if (c == 'U') {
				++y;
			} else {
				--y;
			}
			if (a[x][y] != 0) {
				out.println("BUG");
				return;
			}
			a[x][y] = cur++;
			for (int dir = 0; dir < 4; dir++) {
				if (a[x + DX[dir]][y + DY[dir]] != 0
						&& Math.abs(a[x][y] - a[x + DX[dir]][y + DY[dir]]) > 1) {
					out.println("BUG");
					return;
				}
			}
		}
		out.println("OK");
	}
}
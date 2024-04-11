import java.io.*;
import java.util.*;

public class B implements Runnable {
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
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			// solve2();
			// int n = rand.nextInt(10) + 1;
			// int m = rand.nextInt(10) + 1;
			// int x1 = rand.nextInt((int) n) + 1;
			// int x2 = rand.nextInt() % 5 == 0 ? x1 : rand.nextInt((int) n) +
			// 1;
			// int y1 = rand.nextInt((int) m) + 1;
			// int y2 = rand.nextInt() % 5 == 1 ? y1 : rand.nextInt((int) m) +
			// 1;
			// if (solve2(n, m, x1, y1, x2, y2) != solve3(n, m, x1, y1, x2, y2))
			// {
			// throw new AssertionError(n + " " + m + " " + x1 + " " + y1
			// + " " + x2 + " " + y2 + " "
			// + solve2(n, m, x1, y1, x2, y2) + " "
			// + solve3(n, m, x1, y1, x2, y2));
			// }
			int n = nextInt();
			int m = nextInt();
			int x1 = nextInt();
			int y1 = nextInt();
			int x2 = nextInt();
			int y2 = nextInt();
			out.println(solve2(n, m, x1, y1, x2, y2));
		}

	}

	Random rand = new Random();

	boolean check(long x, long y, long n, long m) {
		return 1 <= x && x <= n && 1 <= y && y <= m;
	}

	long solve3(long n, long m, long x1, long y1, long x2, long y2) {
		long dx = x1 - x2;
		long dy = y1 - y2;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!(check(i + dx, j + dy, n, m) || check(i - dx, j - dy, n, m))) {
					++ans;
				}
			}
		}
		return ans;
	}

	long solve2(long n, long m, long x1, long y1, long x2, long y2) {
		// long n = nextInt();
		// long m = nextInt();
		// long x1 = nextInt();
		// long y1 = nextInt();
		// long x2 = nextInt();
		// long y2 = nextInt();
		if (x1 == x2) {
			long h = Math.abs(y2 - y1) + 1;
			long w = m;
			if (2 * h > m + 1) {
				w = 2 * (m - h + 1);
			}
			long ans = n * m - w * n;
			// out.println(n * m - w * n);
			return ans;
		}
		if (y1 == y2) {
			long h = Math.abs(x2 - x1) + 1;
			long w = n;
			if (2 * h > n + 1) {
				w = 2 * (n - h + 1);
			}
			long ans = n * m - w * m;
			// out.println(n * m - w * m);
			return ans;
		}
		long width = Math.abs(x1 - x2);
		long height = Math.abs(y2 - y1);
		long ans = 2 * width * height;
		if (width * 2 > n && height * 2 > m) {
			ans -= (width * 2 - n) * (height * 2 - m);
		}
		if (2 * width + 1 > n) {
			long e = width - n + width;
			ans += e * Math.max(0, m - 2 * height);
		}
		if (2 * height + 1 > m) {
			long e = height - m + height;
			ans += e * Math.max(0, n - 2 * width);
		}
		// out.println(ans);
		return ans;
	}
}
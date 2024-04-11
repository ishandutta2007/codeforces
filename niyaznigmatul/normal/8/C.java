import java.io.*;
import java.math.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
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

	static class Point {
		int x, y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		int dist(Point p) {
			return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
		}
	}

	void solve() {
		Point p0 = new Point(nextInt(), nextInt());
		int n = nextInt();
		Point[] p = new Point[n];
		for (int i = 0; i < n; i++) {
			p[i] = new Point(nextInt(), nextInt());
		}
		int[][] d = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = p[i].dist(p[j]);
			}
		}
		int[] d0 = new int[n];
		for (int i = 0; i < n; i++) {
			d0[i] = p0.dist(p[i]);
		}
		int[] dp = new int[1 << n];
		Arrays.fill(dp, 1 << 30);
		dp[0] = 0;
		int[] from = new int[1 << n];
		for (int i = 0; i + 1 < 1 << n; i++) {
			int j = Integer.numberOfTrailingZeros(Integer.lowestOneBit(~i));
			int cnt = dp[i] + 2 * d0[j];
			if (dp[i ^ (1 << j)] > cnt) {
				dp[i ^ (1 << j)] = cnt;
				from[i ^ (1 << j)] = i;
			}
			for (int k = j + 1; k < n; k++) {
				if (((i >> k) & 1) == 0) {
					cnt = dp[i] + d0[j] + d0[k] + d[j][k];
					if (dp[i ^ (1 << j) ^ (1 << k)] > cnt) {
						dp[i ^ (1 << j) ^ (1 << k)] = cnt;
						from[i ^ (1 << j) ^ (1 << k)] = i;
					}
				}
			}
		}
		ArrayList<Integer> ans = new ArrayList<Integer>();
		ans.add(0);
		int mask = (1 << n) - 1;
		while (mask > 0) {
			int xor = mask ^ from[mask];
			while (xor > 0) {
				ans.add(Integer
						.numberOfTrailingZeros(Integer.lowestOneBit(xor)) + 1);
				xor = xor & (xor - 1);
			}
			ans.add(0);
			mask = from[mask];
		}
		out.println(dp[(1 << n) - 1]);
		for (int i : ans) {
			out.print(i + " ");
		}
	}
}
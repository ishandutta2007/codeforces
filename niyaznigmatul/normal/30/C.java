import java.io.*;
import java.util.*;

public class C implements Runnable {
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

	class Point implements Comparable<Point> {
		int x, y, t;
		double p;

		public Point(int x, int y, int t, double p) {
			this.x = x;
			this.y = y;
			this.t = t;
			this.p = p;
		}

		long dist(Point p) {
			long dx = x - p.x;
			long dy = y - p.y;
			return (dx * dx + dy * dy);
		}

		@Override
		public int compareTo(Point o) {
			return t < o.t ? -1 : t > o.t ? 1 : 0;
		}
	}

	void solve() {
		int n = nextInt();
		Point[] p = new Point[n];
		for (int i = 0; i < n; i++) {
			p[i] = new Point(nextInt(), nextInt(), nextInt(), nextDouble());
		}
		Arrays.sort(p);
		double[] dp = new double[n + 1];
		dp[0] = 0;
		double ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				long dist = (j == 0) ? 0 : (p[i - 1].dist(p[j - 1]));
				long t = (j == 0) ? 0 : (p[i - 1].t - p[j - 1].t);
				if (dist <= t * t) {
					dp[i] = Math.max(dp[i], dp[j] + p[i - 1].p);
				}
			}
			ans = Math.max(ans, dp[i]);
		}
		out.println(ans);
	}
}
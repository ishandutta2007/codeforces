import java.util.*;
import java.math.*;
import java.io.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new B().run();
	}

	StringTokenizer st;
	PrintWriter out;
	BufferedReader br;
	boolean eof = false, in_out = false, std = false;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextLine() {
		String ret = "";
		try {
			ret = br.readLine();
		} catch (Exception e) {
			ret = "";
		}
		if (ret == null) {
			eof = true;
			return "$";
		}
		return ret;
	}

	String nextString() {
		return nextToken();
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

	public void run() {
		// long time = System.currentTimeMillis();
		try {
			br = new BufferedReader(new InputStreamReader(System.in), 5000);
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(111);
		}
		// System.err.println(System.currentTimeMillis() - time);
	}

	void solve() {
		int n = nextInt();
		int m = n;
		int[][] dp1 = new int[n][m];
		int[][] dp2 = new int[n][m];
		int[][] p1 = new int[n][m];
		int[][] p2 = new int[n][m];
		int id = -1, jd = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x = nextInt();
				if (x == 0) {
					id = i;
					jd = j;
				}
				if (i != 0 || j != 0) {
					dp1[i][j] = dp2[i][j] = Integer.MAX_VALUE;
				}
				if (i > 0) {
					dp1[i][j] = Math.min(dp1[i][j], dp1[i - 1][j]);
					dp2[i][j] = Math.min(dp2[i][j], dp2[i - 1][j]);
				}
				if (j > 0) {
					dp1[i][j] = Math.min(dp1[i][j], dp1[i][j - 1]);
					dp2[i][j] = Math.min(dp2[i][j], dp2[i][j - 1]);
				}
				{
					int p = x;
					if (p == 0) {
						dp1[i][j] = Integer.MAX_VALUE;
						p1[i][j] = Integer.MAX_VALUE;
					} else
						while (p % 2 == 0) {
							p1[i][j]++;
							p /= 2;
						}
				}
				{
					int p = x;
					if (p == 0) {
						dp2[i][j] = Integer.MAX_VALUE;
						p2[i][j] = Integer.MAX_VALUE;
					} else
						while (p % 5 == 0) {
							p2[i][j]++;
							p /= 5;
						}
				}
				if (p1[i][j] != Integer.MAX_VALUE) {
					dp1[i][j] += p1[i][j];
					dp2[i][j] += p2[i][j];
				}
			}
		}
		long ans = Math.min(dp1[n - 1][m - 1], dp2[n - 1][m - 1]);
		if (ans > 1 && id != -1) {
			int i = id;
			int j = jd;
			StringBuilder sb = new StringBuilder(n * m + 1000);
			sb.append("1\n");
			for (int x = 0; x < i; x++) {
				sb.append("D");
			}
			for (int x = 0; x < j; x++) {
				sb.append("R");
			}
			for (int x = i; x < n - 1; x++) {
				sb.append("D");
			}
			for (int x = j; x < n - 1; x++) {
				sb.append("R");
			}
			out.println(sb);
			return;
		}
		StringBuilder sb = new StringBuilder(n * m + 5);
		if (ans == dp1[n - 1][m - 1]) {
			for (int x = n - 1, y = m - 1; x > 0 || y > 0;) {
				if (x > 0 && dp1[x - 1][y] == dp1[x][y] - p1[x][y]) {
					x--;
					sb.append("D");
				} else {
					y--;
					sb.append("R");
				}
			}
		} else {
			for (int x = n - 1, y = m - 1; x > 0 || y > 0;) {
				if (x > 0 && dp2[x - 1][y] == dp2[x][y] - p2[x][y]) {
					x--;
					sb.append("D");
				} else {
					y--;
					sb.append("R");
				}
			}
		}
		out.println(ans);
		out.println(sb.reverse());
	}
}
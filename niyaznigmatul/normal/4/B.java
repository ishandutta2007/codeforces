import java.io.*;
import java.util.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new Thread(new B()).start();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

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

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
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

	int[] a, b;
	int d;
	boolean[][] dp, was;

	class E {
		int x, cTime;

		public E(int x, int cTime) {
			super();
			this.x = x;
			this.cTime = cTime;
		}

	}

	boolean go(int x, int cTime) {
		if (cTime < 0) {
			return false;
		}
		if (x == d) {
			return cTime == 0;
		}
		// if (was[x][cTime]) {
		// return dp[x][cTime];
		// }
		// was[x][cTime] = true;
		// boolean ret = false;
		// for (int i = a[x]; i <= b[x]; ++i) {
		// ret |= go(x + 1, cTime - i);
		// }
		return dp[x][cTime];
	}

	ArrayList<Integer> ans;

	void restore(int x, int cTime) {
		if (x == d) {
			return;
		}
		for (int i = a[x]; i <= b[x]; ++i) {
			if (go(x + 1, cTime - i)) {
				ans.add(i);
				restore(x + 1, cTime - i);
				return;
			}
		}
	}

	void solve() {
		d = nextInt();
		int sumTime = nextInt();
		a = new int[d];
		b = new int[d];
		dp = new boolean[d + 1][sumTime + 1];
		// was = new boolean[d][sumTime + 1];
		dp[d][0] = true;
		for (int i = 0; i < d; i++) {
			a[i] = nextInt();
			b[i] = nextInt();
		}
		for (int i = d - 1; i >= 0; i--) {
			for (int j = sumTime; j >= 0; j--) {
				for (int k = a[i]; k <= b[i]; ++k) {
					if (j - k >= 0) {
						dp[i][j] |= dp[i + 1][j - k];
					}
				}
			}
		}
		if (!dp[0][sumTime]) {
			out.println("NO");
			return;
		}
		ans = new ArrayList<Integer>();
		restore(0, sumTime);
		out.println("YES");
		for (int i : ans) {
			out.print(i + " ");
		}
	}
}
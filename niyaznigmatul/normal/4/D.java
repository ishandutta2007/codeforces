import java.io.*;
import java.util.*;

public class D implements Runnable {
	public static void main(String[] args) {
		new Thread(new D()).start();
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

	int[] dp, a, b;

	int dfs(int x) {
		if (dp[x] != -1) {
			return dp[x];
		}
		int ret = 1;
		for (int i = 0; i < a.length; i++) {
			if (a[x] < a[i] && b[x] < b[i]) {
				ret = Math.max(ret, dfs(i) + 1);
			}
		}
		return dp[x] = ret;
	}

	ArrayList<Integer> restored;

	void restore(int x) {
		if (dfs(x) == 1) {
			restored.add(x + 1);
			return;
		}
		int got = dfs(x);
		for (int i = 0; i < a.length; i++) {
			if (a[x] < a[i] && b[x] < b[i]) {
				if (dfs(i) == got - 1) {
					restored.add(x + 1);
					restore(i);
					return;
				}
			}
		}
	}

	void solve() {
		int n = nextInt();
		int w = nextInt();
		int h = nextInt();
		a = new int[n];
		b = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
			b[i] = nextInt();
		}
		dp = new int[n];
		Arrays.fill(dp, -1);
		int ans = 0, ansI = -1;
		for (int i = 0; i < n; ++i) {
			int g = dfs(i);
			if (w < a[i] && h < b[i]) {
				if (g > ans) {
					ans = g;
					ansI = i;
				}
			}
		}
		if (ansI == -1) {
			out.println(0);
			return;
		}
		restored = new ArrayList<Integer>();
		for (int x = ansI;;) {
			restored.add(x + 1);
			if (dp[x] == 1) {
				break;
			}
			for (int i = 0; i < n; i++) {
				if (a[x] < a[i] && b[x] < b[i]) {
					if (dp[i] + 1 == dp[x]) {
						x = i;
						break;
					}
				}
			}
		}
		out.println(ans);
		if (restored.size() != ans) {
			System.exit(1);
		}
		for (int i : restored) {
			out.print(i + " ");
		}
	}
}
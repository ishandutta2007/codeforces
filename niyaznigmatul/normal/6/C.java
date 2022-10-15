import java.io.*;
import java.util.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new Thread(new C()).start();
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

	void solve() {
		int n = nextInt();
		int ans1 = 0, ans2 = 0;
		int t1 = 0, t2 = 0;
		int[] t = new int[n];
		for (int i = 0; i < t.length; i++) {
			t[i] = nextInt();
		}
		int i1 = 0, i2 = n - 1;
		while (i1 < i2) {
			if (t1 <= t2) {
				t1 += t[i1++];
				ans1++;
			} else {
				t2 += t[i2--];
				ans2++;
			}
		}
		if (ans1 + ans2 == n - 1) {
			if (t1 <= t2) {
				ans1++;
			} else {
				ans2++;
			}
		}
		out.println(ans1 + " " + ans2);
	}
}
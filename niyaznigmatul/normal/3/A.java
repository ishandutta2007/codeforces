import java.io.*;
import java.util.*;

public class A implements Runnable {
	public static void main(String[] args) {
		new Thread(new A()).start();
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
		String s1 = nextToken();
		String s2 = nextToken();
		int x1 = s1.charAt(0) - 'a';
		int y1 = s1.charAt(1) - '1';
		int x2 = s2.charAt(0) - 'a';
		int y2 = s2.charAt(1) - '1';
		int g = Math.min(Math.abs(x1 - x2), Math.abs(y1 - y2));
		char c1, c2;
		if (x1 > x2) {
			c1 = 'L';
		} else {
			c1 = 'R';
		}
		if (y1 < y2) {
			c2 = 'U';
		} else {
			c2 = 'D';
		}
		ArrayList<String> ans = new ArrayList<String>();
		for (int i = 0; i < g; i++) {
			ans.add("" + c1 + c2 + "");
		}
		if (g == Math.abs(x1 - x2)) {
			for (int i = 0; i < Math.abs(y1 - y2) - g; i++) {
				ans.add("" + c2);
			}
		} else {
			for (int i = 0; i < Math.abs(x1 - x2) - g; i++) {
				ans.add("" + c1);
			}
		}
		out.println(ans.size());
		for (String s : ans) {
			out.println(s);
		}
	}
}
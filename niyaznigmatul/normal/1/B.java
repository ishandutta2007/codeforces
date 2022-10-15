import java.util.*;
import java.math.*;
import java.io.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new Thread(new B()).start();
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
			br = new BufferedReader(new InputStreamReader(System.in));
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
		for (int i = 0; i < n; i++) {
			solve2();
		}
	}

	void solve2() {
		String s = nextToken();
		boolean wasNum = false, isFirst = false;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
				wasNum = true;
			} else if (wasNum) {
				isFirst = true;
				break;
			}
		}
		if (isFirst) {
			StringTokenizer e = new StringTokenizer(s, "RC");
			int y = Integer.parseInt(e.nextToken());
			int x = Integer.parseInt(e.nextToken()) - 1;
			go1(x, y);
		} else {
			go2(s);
		}
	}

	void go1(int x, int y) {
		long cur = 26;
		int len = 1;
		while (x >= cur) {
			x -= cur;
			cur *= 26;
			len++;
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < len; i++) {
			sb.append((char) ('A' + x % 26));
			x /= 26;
		}
		out.println(sb.reverse().toString() + y);
	}

	void go2(String s) {
		int id = -1;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) <= '9' && s.charAt(i) >= '0') {
				id = i;
				break;
			}
		}
		String s1 = s.substring(0, id);
		String s2 = s.substring(id);
		int x = 0;
		int cur = 26;
		for (int i = 1; i < s1.length(); i++) {
			x += cur;
			cur *= 26;
		}
		int d = 0;
		for (int i = 0; i < s1.length(); i++) {
			d *= 26;
			d += s1.charAt(i) - 'A';
		}
		x += d;
		out.println("R" + s2 + "C" + (x + 1));
	}
}
import java.util.*;
import java.math.*;
import java.io.*;

public class A implements Runnable {
	public static void main(String[] args) {
		new Thread(new A()).start();
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
		HashMap<String, Integer> p = new HashMap<String, Integer>();
		String[] s = new String[n];
		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextToken();
			x[i] = nextInt();
			if (p.containsKey(s[i])) {
				p.put(s[i], p.get(s[i]) + x[i]);
			} else {
				p.put(s[i], x[i]);
			}
		}
		int max = Integer.MIN_VALUE;
		for (String t : p.keySet()) {
			max = Math.max(max, p.get(t));
		}
		HashMap<String, Integer> p2 = new HashMap<String, Integer>();
		for (int i = 0; i < n; i++) {
			if (p2.containsKey(s[i])) {
				int y = p2.get(s[i]) + x[i];
				p2.put(s[i], y);
				if (y >= max && p.get(s[i]) == max) {
					out.println(s[i]);
					return;
				}
			} else {
				int y = x[i];
				p2.put(s[i], y);
				if (y >= max && p.get(s[i]) == max) {
					out.println(s[i]);
					return;
				}
			}
		}
	}
}
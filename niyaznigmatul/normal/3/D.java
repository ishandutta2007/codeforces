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

	class Quest implements Comparable<Quest> {
		int dif, a;

		public Quest(int dif, int a) {
			super();
			this.dif = dif;
			this.a = a;
		}

		@Override
		public int compareTo(Quest e) {
			if (dif < e.dif) {
				return -1;
			}
			if (dif > e.dif) {
				return 1;
			}
			return a - e.a;
		}
	}

	void solve() {
		String s = nextToken();
		long ans = 0;
		TreeSet<Quest> dif = new TreeSet<Quest>();
		int k = 0;
		if (s.length() % 2 != 0) {
			out.println(-1);
			return;
		}
		char[] c = new char[s.length()];
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '?') {
				int a = nextInt();
				int b = nextInt();
				ans += b;
				dif.add(new Quest(a - b, i));
				k--;
				c[i] = ')';
			} else if (s.charAt(i) == '(') {
				k++;
				c[i] = '(';
			} else {
				k--;
				c[i] = ')';
			}
			if (k == -1) {
				if (dif.isEmpty()) {
					out.println(-1);
					return;
				} else {
					k += 2;
					Quest q = dif.pollFirst();
					c[q.a] = '(';
					ans += q.dif;
				}
			}
		}
		if (k != 0) {
			out.println(-1);
		} else {
			out.println(ans);
			out.println(new String(c));
		}
	}
}
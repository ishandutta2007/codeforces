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
		char[][] c = new char[3][];
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < c.length; i++) {
			c[i] = nextToken().toCharArray();
			for (char cc : c[i]) {
				if (cc == 'X') {
					cnt1++;
				} else if (cc == '0') {
					cnt2++;
				}
			}
		}
		if (cnt2 > cnt1 || cnt1 - cnt2 > 1) {
			out.println("illegal");
			return;
		}
		cnt1 = 0;
		for (int i = 0; i < 3; i++) {
			if (c[i][0] == c[i][1] && c[i][0] == c[i][2] && c[i][0] != '.') {
				cnt1++;
			}
		}
		if (cnt1 > 1) {
			out.println("illegal");
			return;
		}
		cnt1 = 0;
		for (int i = 0; i < 3; i++) {
			if (c[0][i] == c[1][i] && c[0][i] == c[2][i] && c[0][i] != '.') {
				cnt1++;
			}
		}
		if (cnt1 > 1) {
			out.println("illegal");
			return;
		}
		cnt1 = 0;
		cnt2 = 0;
		for (int i = 0; i < 3; i++) {
			if (c[0][i] == c[1][i] && c[0][i] == c[2][i]) {
				if (c[0][i] == 'X')
					cnt1++;
				else if (c[0][i] == '0')
					cnt2++;
			}
			if (c[i][0] == c[i][1] && c[i][0] == c[i][2]) {
				if (c[i][0] == 'X')
					cnt1++;
				else if (c[i][0] == '0')
					cnt2++;
			}
		}
		if (c[0][0] == c[1][1] && c[0][0] == c[2][2]) {
			if (c[0][0] == 'X') {
				cnt1++;
			} else if (c[0][0] == '0') {
				cnt2++;
			}
		}
		if (c[0][2] == c[1][1] && c[2][0] == c[1][1]) {
			if (c[1][1] == 'X') {
				cnt1++;
			} else if (c[1][1] == '0') {
				cnt2++;
			}
		}
		if (cnt1 > 0) {
			cnt1 = 0;
			cnt2 = 0;
			for (int i = 0; i < 3; i++) {
				for (char cc : c[i]) {
					if (cc == 'X') {
						cnt1++;
					} else if (cc == '0') {
						cnt2++;
					}
				}
			}
			if (cnt1 == cnt2) {
				out.println("illegal");
				return;
			}
			out.println("the first player won");
			return;
		}
		if (cnt2 > 0) {
			cnt1 = 0;
			cnt2 = 0;
			for (int i = 0; i < 3; i++) {
				for (char cc : c[i]) {
					if (cc == 'X') {
						cnt1++;
					} else if (cc == '0') {
						cnt2++;
					}
				}
			}
			if (cnt1 > cnt2) {
				out.println("illegal");
				return;
			}
			out.println("the second player won");
			return;
		}
		cnt1 = 0;
		cnt2 = 0;
		for (int i = 0; i < 3; i++) {
			for (char cc : c[i]) {
				if (cc == 'X') {
					cnt1++;
				} else if (cc == '0') {
					cnt2++;
				}
			}
		}
		if (9 == cnt1 + cnt2) {
			out.println("draw");
		} else {
			if (cnt1 > cnt2) {
				out.println("second");
			} else {
				out.println("first");
			}
		}
	}
}
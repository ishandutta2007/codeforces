import java.io.*;
import java.util.*;
import java.math.*;

public class B {

	public static void main(String[] args) {
		new B().run();
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
				return "-1";
			}
		}
		return st.nextToken();
	}

	void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			solve();
			out.close();
			br.close();
		} catch (Throwable e) {
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

	BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

	char[][] go(char[][] c, int n, int k) {
		if (k == 1) {
			return c;
		}
		char[][] d = go(c, n, k - 1);
		char[][] ret = new char[d.length * n][d.length * n];
		for (int i = 0; i < c.length; i++) {
			for (int j = 0; j < c.length; j++) {
				if (c[i][j] == '*') {
					for (int i1 = 0; i1 < d.length; i1++) {
						for (int j1 = 0; j1 < d.length; j1++) {
							ret[i * d.length + i1][j * d.length + j1] = '*';
						}
					}
				} else {
					for (int i1 = 0; i1 < d.length; i1++) {
						for (int j1 = 0; j1 < d.length; j1++) {
							ret[i * d.length + i1][j * d.length + j1] = d[i1][j1];
						}
					}
				}
			}
		}
		return ret;
	}

	void solve() {
		int n = nextInt();
		int k = nextInt();

		char[][] c = new char[n][];
		for (int i = 0; i < c.length; i++) {
			c[i] = nextToken().toCharArray();
		}
		char[][] d = go(c, n, k);
		for (int i = 0; i < d.length; i++) {
			out.println(new String(d[i]));
		}
	}
}
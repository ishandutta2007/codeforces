import java.io.*;
import java.util.*;
import java.math.*;

public class D {

	public static void main(String[] args) {
		new D().run();
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
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
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

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int t = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < n; i++) {
			c[i] = nextToken().toCharArray();
		}
		for (int k = 1; k < n || k < m; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (c[i][j] != '*') {
						continue;
					}				
					if (i - k < 0 || i + k >= n || j - k < 0 || j + k >= m)  {
						continue;
					}
					if (c[i - k][j] != '*' || c[i][j - k] != '*' || c[i][j + k] != '*' || c[i + k][j] != '*') {
						continue;
					}
					t--;
					if (t == 0) {
						out.println(1 + i + " " + (1 + j));
						out.println((i - k + 1) + " " + (j + 1));
						out.println((i + k + 1) + " " + (j + 1));
						out.println((i + 1) + " " + (j - k + 1));
						out.println((i + 1) + " " + (j + k + 1));
						return;
					}
				}
			}	
		}
		out.println(-1);
	}
}
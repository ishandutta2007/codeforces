import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new B().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
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

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	final int INF = Integer.MAX_VALUE / 2;

	void solve() {
		char[] c1 = nextToken().toCharArray();
		char[] c2 = nextToken().toCharArray();
		if (c1.length != c2.length) {
			out.println("-1");
			return;
		}
		int n = nextInt();
		int[][] a = new int[26][26];
		for (int i = 0; i < a.length; i++) {
			Arrays.fill(a[i], Integer.MAX_VALUE / 2);
			a[i][i] = 0;
		}
		for (int i = 0; i < n; i++) {
			int x = nextToken().charAt(0) - 'a';
			int y = nextToken().charAt(0) - 'a';
			int z = nextInt();
			a[x][y] = Math.min(a[x][y], z);
		}
		for (int k = 0; k < a.length; k++) {
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a.length; j++) {
					if (a[i][k] != INF && a[k][j] != INF) {
						a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
					}
				}
			}
		}
		int ans = 0;
		char[] s = new char[c1.length];
		for (int i = 0; i < c1.length; i++) {
			int cur = INF;
			int x = c1[i] - 'a';
			int y = c2[i] - 'a';
			for (int j = 0; j < a.length; j++) {
				if (a[x][j] != INF && a[y][j] != INF) {
					if (cur > a[x][j] + a[y][j]) {
						s[i] = (char) (j + 'a');
						cur = a[x][j] + a[y][j];
					}
				}				
			}	
			if (a[x][y] < cur) {
				cur = a[x][y];
				s[i] = c2[i];
			}
			if (a[y][x] < cur) {
				cur = a[y][x];
				s[i] = c1[i];
			}
			if (cur == INF) {
				out.println(-1);
				return;
			}
			ans += cur;
		}
		out.println(ans);
		out.println(new String(s));
	}
}
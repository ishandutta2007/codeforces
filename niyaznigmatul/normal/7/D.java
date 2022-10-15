import java.io.*;
import java.math.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		new D().run();
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
	BufferedReader br;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			// sc = new FastScanner(System.in);
			br = new BufferedReader(new InputStreamReader(System.in));
			// br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(System.out);
			solve();
			br.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	int go(int x, int y) {
		int ret = 0;
		while (x >= 0 && y < n && c[x] == c[y]) {
			x--;
			y++;
			ret++;
		}
		return ret;
	}

	int[] solve1() {
		int[] d = new int[n];
		d[0] = 1;
		int dBlock = 0;
		for (int i = 1; i < n; i++) {
			if (d[dBlock] + dBlock - 1 < i) {
				d[i] = go(i, i);
				dBlock = i;
			} else {
				int k = 2 * dBlock - i;
				if (k - d[k] + 1 <= dBlock - d[dBlock] + 1) {
					d[i] = k
							- dBlock
							+ d[dBlock]
							+ go(i - (k - dBlock + d[dBlock]), i
									+ (k - dBlock + d[dBlock]));
					dBlock = i;
				} else {
					d[i] = d[k];
				}
			}
		}
		return d;
	}

	int[] solve2() {
		int[] d = new int[n];
		d[0] = 0;
		int dBlock = 0;
		for (int i = 1; i < n; i++) {
			if (d[dBlock] + dBlock < i) {
				d[i] = go(i, i + 1);
				dBlock = i;
			} else {
				int k = 2 * dBlock - i + 1;
				System.err.println(k);
				if (k - d[k] <= dBlock - d[dBlock]) {
					d[i] = k
							- dBlock
							+ d[dBlock]
							+ go(i - (k - dBlock + d[dBlock]), i
									+ (k - dBlock + d[dBlock]) + 1);
					dBlock = i;
				} else {
					d[i] = d[k];
				}
			}
		}
		return d;
	}

	char[] c;
	int n;

	static boolean isPalindrome(String s) {
		return reverse(s).equals(s);
	}

	static String reverse(String s) {
		return new StringBuilder(s).reverse().toString();
	}

	void solve() throws IOException {
		String s = br.readLine().trim();
		String t = s + "@" + reverse(s);
		int[] p = new int[t.length()];
		int k = -1;
		p[0] = -1;
		for (int i = 1; i < t.length(); i++) {
			while (k > -1 && t.charAt(k + 1) != t.charAt(i)) {
				k = p[k];
			}
			if (t.charAt(k + 1) == t.charAt(i)) {
				k++;
			}
			p[i] = k;
		}
		boolean[] isPalindrome = new boolean[t.length() + 1];
		for (int i = p[t.length() - 1]; i > -1; i = p[i]) {
			isPalindrome[i + 1] = true;
		}
		int[] f = new int[t.length() + 1];
		f[0] = 0;
		long ans = 0;
		for (int i = 1; i <= t.length(); i++) {
			if (isPalindrome[i]) {
				f[i] = f[i / 2] + 1;
			}
			ans += f[i];
		}
		out.println(ans);
	}
}
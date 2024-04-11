import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new C().run();
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

	void solve() {
		int n = nextInt();
		int[] a = new int[n];
		int sum = 0;
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
			sum += a[i];
		}
		int[] pref = new int[n];
		pref[0] = a[0];
		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1] + a[i];
		}
		int[] suf = new int[n];
		suf[suf.length - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			suf[i] = suf[i + 1] + a[i];
		}
		pref[0] = Math.min(pref[0], 0);
		for (int i = 1; i < n; i++) {
			pref[i] = Math.min(pref[i], pref[i - 1]);
		}
		int ans = sum - 2 * pref[n - 1];
		for (int i = n - 1; i >= 1; i--) {
			if (suf[i] < 0) {
				ans = Math.max(ans, sum - 2 * suf[i] - 2 * pref[i - 1]);
			}
		}
		out.println(ans);
	}
}
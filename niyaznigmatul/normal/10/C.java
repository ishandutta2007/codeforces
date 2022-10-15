import java.io.*;
import java.math.*;
import java.util.*;

public class C {
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

	void solve() {
		long n = nextLong();
		long cur = n;
		long ans = 0;
		for (long i = 1; i <= n; i++) {
			while (i * cur > n) {
				--cur;
			}
			ans -= cur;
		}
		int j = 0;
		long[] a = new long[9];		
		for (int i = 1; i <= n % 9; i++) {
			a[i] = (n / 9 + 1);
		}
		for (int i = (int) (n % 9 + 1); i <= 9; i++) {
			a[i % 9] = n / 9;
		}
		for (long i = 1; i <= n; i++) {
			++j;
			if (j == 9) {
				j = 0;
			}
			for (int k = 0; k < 9; k++) {
				int t = (j * k) % 9;
				ans += a[k] * a[t];
			}
		}
		out.println(ans);
	}
}
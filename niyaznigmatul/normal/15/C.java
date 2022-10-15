import java.io.*;
import java.util.*;

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

	long f(long x) {
		if (x == 0) {
			return 0;
		}
		long ret = ((x + 1) >> 1) & 1;
		for (int i = 1; i < 60; i++) {
			if (((x >> i) & 1) == 1) {
				ret |= (((x & ((1L << i) - 1)) + 1) & 1) << i;
			}
		}
		return ret;
	}

	long g(long x) {
		long ret = 0;
		for (long i = 1; i <= x; i++) {
			ret ^= i;
		}
		return ret;
	}

	long solve2(long x, long m) {
		return f(x + m - 1) ^ f(x - 1);
	}

	void solve() {
		int n = nextInt();
		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans ^= solve2(nextLong(), nextLong());
		}
		if (ans == 0) {
			out.println("bolik");
		} else {
			out.println("tolik");
		}
	}
}
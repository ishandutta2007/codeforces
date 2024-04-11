import static java.lang.Math.min;

import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	void solve() {
		long n = nextLong();
		int m = nextInt();
		int mod = nextInt();
		for (int i = 0; i < m; i++) {
			long l = nextLong() - 1;
			long r = nextLong() - 1;
			long a = nextLong() - 1;
			long b = nextLong() - 1;
			long ans1 = get(n, l, r, min(n - 1, b), mod);
			long ans2 = get(n, l, r, min(n - 1, a - 1), mod);
			// System.err.println(ans1 + " " + ans2);
			long ans = ((ans1 - ans2) % mod + mod) % mod;
			// long stupid = 0;
			// for (long j = l; j <= r; j++) {
			// long e = get(n, j);
			// if (e >= a && e <= b) {
			// stupid += e + 1;
			// stupid %= mod;
			// }
			// }
			// if (stupid != ans) {
			// System.err.println(stupid + " " + ans);
			// throw new AssertionError();
			// }
			out.println(ans);
		}
	}

	static long get(long n, long k) {
		if (n == 1) {
			return k == 0 ? 0 : Long.MAX_VALUE;
		}
		long mid = (n + 1) >> 1;
		if (k >= mid) {
			return get(n - mid, k - mid) * 2 + 1;
		} else {
			return get(mid, k) * 2;
		}
	}

	static int get(long n, long l, long r, long x, int mod) {
		if (x < 0) {
			return 0;
		}
		// System.err.println("X = " + x);
		// long a = get1(n, r, x, mod);
		// long b = get1(n, l - 1, x, mod);
		// long c = get2(n, r, x, mod);
		// long d = get2(n, l - 1, x, mod);
		// System.err.println(a + " " + b + " " + c + " " + d);
		// return (int) (((a - b + c - d) % mod + mod) % mod);
		long ret = 0;
		get3(n, r, x, mod);
		ret += A + B;
		get3(n, l - 1, x, mod);
		ret -= A + B;
		return (int) (((ret % mod) + mod) % mod);
	}

	static long A;
	static long B;

	static void get3(long n, long x, long y, int mod) {
		if (y < 0 || x < 0) {
			A = 0;
			B = 0;
			return;
		}
		if (n == 1) {
			A = 0;
			B = 1;
			return;
		}
		long mid = (n + 1) >> 1;
		if (x < mid) {
			get3(mid, x, y >> 1, mod);
			A = (A * 2) % mod;
		} else {
			get3(n - mid, x - mid, (y - 1) >> 1, mod);
			A = (f(y, mod) + A * 2 + B) % mod;
			B = (g(y, mod) + B) % mod;
		}
	}

	static long get1(long n, long x, long y, int mod) {
		if (y < 0 || x < 0) {
			return 0;
		}
		if (n == 1) {
			return 0;
		}
		long mid = (n + 1) >> 1;
		if (x < mid) {
			return (get1(mid, x, y >> 1, mod) * 2) % mod;
		} else {
			return ((f(y, mod) + get1(n - mid, x - mid, (y - 1) >> 1, mod) * 2 + get2(
					n - mid, x - mid, (y - 1) >> 1, mod)) % mod);
		}
	}

	static long get2(long n, long x, long y, int mod) {
		if (y < 0 || x < 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
		long mid = (n + 1) >> 1;
		if (x < mid) {
			return get2(mid, x, y >> 1, mod);
		} else {
			return (g(y, mod) + get2(n - mid, x - mid, (y - 1) >> 1, mod))
					% mod;
		}
	}

	static long g(long x, int mod) {
		if ((x & 1) == 1) {
			--x;
		}
		return (((x >> 1) + 1) % mod);
	}

	static long f(long x, int mod) {
		if ((x & 1) == 1) {
			--x;
		}
		x >>= 1;
		long y = x % mod;
		long z = ((long) mod * (mod + 1) >> 1) % mod;
		z = (z * ((x / mod) % mod)) % mod;
		return ((y * (y + 1) + z * 2) % mod);
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			File file = new File("d.in");
			if (file.canRead()) {
				System.setIn(new FileInputStream(file));
			}
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

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
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

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new D().run();
	}
}
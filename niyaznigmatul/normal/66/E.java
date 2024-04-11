import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {

	void solve() {
		int n = nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < b.length; i++) {
			b[i] = nextInt();
		}
		boolean[] can1 = solve(a, b);
		reverse(a);
		reverse(b);
		int tmp = b[0];
		for (int i = 0; i + 1 < n; i++) {
			b[i] = b[i + 1];
		}
		b[n - 1] = tmp;
		boolean[] can2 = solve(a, b);
		reverse(can2);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			can1[i] |= can2[i];
			if (can1[i]) {
				++ans;
			}
		}
		out.println(ans);
		for (int i = 0; i < n; i++) {
			if (can1[i]) {
				out.print(i + 1 + " ");
			}
		}
	}

	void reverse(int[] a) {
		for (int i = 0; i < a.length - i - 1; i++) {
			int t = a[i];
			a[i] = a[a.length - i - 1];
			a[a.length - i - 1] = t;
		}
	}

	void reverse(boolean[] a) {
		for (int i = 0; i < a.length - i - 1; i++) {
			boolean t = a[i];
			a[i] = a[a.length - i - 1];
			a[a.length - i - 1] = t;
		}
	}

	static boolean[] solve(int[] A, int[] B) {
		int n = A.length;
		long[] a = new long[2 * n];
		for (int i = 0; i < n; i++) {
			a[2 * i] = A[i];
		}
		for (int i = 0; i < n; i++) {
			a[2 * i + 1] = -B[i];
		}
		n <<= 1;
		for (int i = 1; i < n; i++) {
			a[i] += a[i - 1];
		}
		long[] b = new long[n];
		long[] c = new long[n];
		b[0] = a[0];
		for (int i = 1; i < n; i++) {
			b[i] = Math.min(b[i - 1], a[i]);
		}
		c[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			c[i] = Math.min(c[i + 1], a[i]);
		}
		boolean[] can = new boolean[n >> 1];
		Arrays.fill(can, true);
		for (int i = 0; i < n; i += 2) {
			long minFront = c[i];
			long minBack = i == 0 ? Long.MAX_VALUE / 2 : b[i - 1];
			long gotBack = i == 0 ? 0 : a[i - 1];
			if (minFront - gotBack < 0 || minBack + a[n - 1] - gotBack < 0) {
				can[i >> 1] = false;
			}
		}
		return can;
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
		new E().run();
	}
}
import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {

	void solve() {
		int n = nextInt();
		long x = nextLong();
		long y = nextLong();
		int p = nextInt();
		int[] a = new int[n];
		if (n == 1) {
			out.println(nextInt() % p);
			return;
		}
		int min = Integer.MAX_VALUE;
		int sumAll = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			min = Math.min(min, a[i]);
			sumAll = (sumAll + a[i]) % p;
		}
		int first = a[0];
		int last = n == 1 ? 0 : a[n - 1];
		int bestSum = Integer.MIN_VALUE;
		int bestMax = Integer.MIN_VALUE;
		for (int i = 0; i + 1 < n; i++) {
			if (a[i] + a[i + 1] > bestSum
					|| (a[i] + a[i + 1] == bestSum && Math.max(a[i], a[i + 1]) > bestMax)) {
				bestSum = a[i] + a[i + 1];
				bestMax = Math.max(a[i], a[i + 1]);
			}
		}
		int sum1;
		int max;
		if (x == 0) {
			max = Integer.MIN_VALUE;
			for (int i = 0; i < n; i++) {
				max = Math.max(max, a[i]);
			}
			sum1 = sumAll;
		} else {
			int got = getIt(sumAll, first, last, p, x);
			sum1 = (got) % p;
			max = getFib(bestSum - bestMax, bestMax, x, p);
		}
		int sum2;
		if (y == 0) {
			sum2 = sum1;
		} else {
			sum2 = (getIt(sum1, min, max, p, y)) % p;
		}
		out.println((sum2) % p);
	}

	int getIt(int sum, int a, int b, int p, long t) {
		int ret = (int) ((((long) sum - a - b) % p + p) % p * modPow(3, t, p) % p);
		ret = (int) ((ret + ((long) a + b) % p * (1 + sumPow(3, t, p))) % p);
		return ret;
	}

	int sumPow(int a, long b, int mod) {
		int ret = 0;
		int c = 1;
		while (b > 0) {
			if ((b & 1) == 1) {
				ret = (int) (((long) ret * a + c) % mod);
			}
			c = (int) (((long) c * a + c) % mod);
			a = (int) ((long) a * a % mod);
			b >>= 1;
		}
		return ret;
	}

	int getFib(int a, int b, long n, int p) {
		Matrix m = new Matrix(2);
		m.a[0][0] = m.a[0][1] = m.a[1][0] = 1;
		m = modPow(m, n, p);
		return (int) (((long) m.a[0][0] * b + (long) m.a[0][1] * a) % p);
	}

	static class Matrix {
		int[][] a;
		int n;

		Matrix(int n) {
			this.n = n;
			a = new int[n][n];
		}

		Matrix multiply(Matrix b, int p) {
			Matrix ret = new Matrix(n);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int got = 0;
					for (int k = 0; k < n; k++) {
						got = (int) ((got + (long) a[i][k] * b.a[k][j] % p) % p);
					}
					ret.a[i][j] = got;
				}
			}
			return ret;
		}

	}

	Matrix modPow(Matrix a, long b, int p) {
		int n = a.n;
		Matrix ret = new Matrix(n);
		for (int i = 0; i < n; i++) {
			ret.a[i][i] = 1;
		}
		while (b > 0) {
			if ((b & 1) == 1) {
				ret = ret.multiply(a, p);
			}
			a = a.multiply(a, p);
			b >>= 1;
		}
		return ret;
	}

	int modPow(int a, long b, int p) {
		int ret = 1;
		while (b > 0) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % p);
			}
			a = (int) ((long) a * a % p);
			b >>= 1;
		}
		return ret;
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
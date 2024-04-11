import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int getAnswer(String s, int k) {
		int n = s.length();
		int[][] dp = new int[n + 1][k + 1];
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i][1] = 1;
			for (int j = 2; j <= k; j++) {
				for (int l = 1; l < i; l++) {
					dp[i][j] += dp[i - l][j - 1];
					if (dp[i][j] >= mod) {
						dp[i][j] -= mod;
					}
				}
			}
		}
		int res = 0;
		for (int from = 0; from < n; from++)
			for (int to = from; to < n; to++) {
				int value = 0;
				for (int i = from; i <= to; i++) {
					value = (int) ((value * 10L + (s.charAt(i) - '0')) % mod);
				}
				int mul = 0;
				for (int c1 = 0; c1 < k; c1++) {
					mul = (int) ((mul + dp[from][c1] * 1L * dp[n - to - 1][k - c1 - 1])
							% mod);
				}
				// if (mul != 0)
				// System.err.println((to - from + 1) + "->" + mul);
				res = (int) ((res + value * 1L * mul) % mod);
			}
		return res;
	}

	void divs(int n) {
		for (int x = 2; x * x <= n; x++) {
			while (n % x == 0) {
				System.err.print(x + " ");
				n /= x;
			}
		}
		if (n != 1) {
			System.err.print(n);
		}
		System.err.println();
	}

	final int mod = (int) 1e9 + 7;
	final int MAX = (int) 1e5 + 10;
	int[] fact = new int[MAX];
	int[] factInv = new int[MAX];

	void precalc() {
		fact[0] = 1;
		BigInteger modBI = BigInteger.valueOf(mod);
		for (int i = 1; i < MAX; i++) {
			fact[i] = (int) (fact[i - 1] * 1L * i % mod);
		}
		for (int i = 0; i < MAX; i++) {
			factInv[i] = BigInteger.valueOf(fact[i]).modInverse(modBI)
					.intValue();
		}
	}

	int getAnswerFast(String s, int k) {
		int n = s.length();
		int res = 0;
		int[] prefSum = new int[n + 1];
		int[] pow10 = new int[n + 1];
		pow10[0] = 1;
		int power10 = 1;
		for (int len = 1; len <= n; len++) {
			int tmpMul = power10;
			tmpMul = (int) (tmpMul * 1L * getC(n - len - 1, k - 2) % mod);
			prefSum[len] = tmpMul + prefSum[len - 1];
			if (prefSum[len] >= mod) {
				prefSum[len] -= mod;
			}
			power10 = (int) (power10 * 10L % mod);
			pow10[len] = power10;
		}
		for (int i = 0; i < n; i++) {
			int mul = prefSum[n - i - 1];
			for (int len = n - i; len <= n - i; len++) {
				int tmpMul = pow10[len - 1];
				tmpMul = (int) (tmpMul
						* 1L
						* getC(n - len - 1 + (len == n - i ? 1 : 0), k - 2
								+ (len == n - i ? 1 : 0)) % mod);
				mul += tmpMul;
				if (mul >= mod) {
					mul -= mod;
				}
			}
			res = (int) ((res + mul * 1L * (s.charAt(i) - '0')) % mod);
		}
		return res;
	}

	int getC(int n, int k) {
		if (k < 0 || k > n) {
			return 0;
		}
		int res = (int) (fact[n] * 1L * factInv[k] % mod * factInv[n - k] % mod);
		return res;
	}

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		String s = in.next();
		if (k == 0) {
			long res = 0;
			for (int i = 0; i < s.length(); i++) {
				res = (res * 10 + s.charAt(i) - '0') % mod;
			}
			out.println(res);
			return;
		}
		precalc();
		out.println(getAnswerFast(s, k + 1));
	}

	void solve123() {
		precalc();
		final int M = 50;
		Random rnd = new Random(123);
		for (int it = 0; it < 123123; it++) {
			System.err.println("ITER = " + it);
			int n = 1 + rnd.nextInt(M);
			int k = 1 + rnd.nextInt(n);
			char[] a = new char[n];
			for (int i = 0; i < n; i++) {
				a[i] = (char) ('0' + rnd.nextInt(10));
			}
			String s = new String(a);
			int my = getAnswerFast(s, k);
			int cor = getAnswer(s, k);
			if (my != cor) {
				System.err.println(s + " " + k);
				System.err.println("my = " + my);
				System.err.println("corr = " + cor);
				throw new AssertionError();
			}
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
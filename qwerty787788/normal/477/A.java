import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	long fast(int a, int b) {
		long mod = (long) 1e9 + 7;
		long res = 0;
		long res2 = 0;
		long tmp = (1 + a) * 1L * a / 2;
		tmp %= mod;
		for (int o = 1; o < b; o++) {
			res += o * 1L * a % mod;
			if (res > mod)
				res -= mod;
			res2 += tmp * o;
				res2 %= mod;
		}
		res2 = res2 * 1L * b % mod;
		return (res + res2) % mod;
	}
	
	void solve() {
		out.println(fast(in.nextInt(), in.nextInt()));
	}

	void solve2() {
		for (int a = 1; a <= 100; a++)
			for (int b = 1; b <= 100; b++) {
				System.err.println(a + " " + b);
				long sum = 0;
				for (int x = 0; x < 111111; x++) {
					if (x % b != 0) {
						int k = (x / b) / (x % b);
						if ((x % b) * k == x / b) {
							if (k >= 1 && k <= a) {
								sum += x;
								System.err.println(x);
							}
						}
					}
				}
				if (sum != fast(a, b)) {
					System.err.println(sum + " " + fast(a, b));
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
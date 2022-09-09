import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final int mod = (int) 1e9 + 7;
	int[] fact, factInv;
	int[] pow2;

	void solve() {
		final int MAX2 = (int) 1e6 + 10;
		pow2 = new int[MAX2];
		pow2[0] = 1;
		for (int i = 1; i < MAX2; i++) {
			pow2[i] = pow2[i - 1] + pow2[i - 1];
			if (pow2[i] >= mod) {
				pow2[i] -= mod;
			}
		}
		fact = new int[MAX2];
		factInv = new int[MAX2];
		fact[0] = 1;
		for (int i = 1; i < MAX2; i++) {
			fact[i] = (int) ((fact[i - 1] * 1L * i) % mod);
		}
		factInv[MAX2 - 1] = BigInteger.valueOf(fact[MAX2 - 1])
				.modInverse(BigInteger.valueOf(mod)).intValue();
		for (int i = MAX2 - 2; i >= 0; i--) {
			factInv[i] = (int) ((factInv[i + 1] * 1L * (i + 1)) % mod);
		}
		int n = in.nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = in.nextInt();
		}
		final int MAX = (int) 1e6;
		int[] div = new int[MAX];
		Arrays.fill(div, -1);
		for (int x = 2; x < MAX; x++) {
			if (div[x] == -1) {
				for (int y = x; y < MAX; y += x) {
					div[y] = x;
				}
			}
		}
		ArrayList<Integer>[] primes = new ArrayList[MAX];
		for (int i = 0; i < MAX; i++) {
			if (div[i] == i) {
				primes[i] = new ArrayList<>();
			}
		}
		for (int i = 0; i < n; i++) {
			int val = t[i];
			while (val != 1) {
				int d = div[val];
				int pow = 0;
				while (val % d == 0) {
					val /= d;
					pow++;
				}
				primes[d].add(pow);
			}
		}
		long result = 0;
		for (int pr = 0; pr < MAX; pr++) {
			if (primes[pr] != null && primes[pr].size() != 0) {
				result += get(primes[pr], n);
			}
		}
		out.println(result % mod);
	}

	int c(int n, int k) {
		if (k < 0 || k > n) {
			return 0;
		}
		return (int) (fact[n] * 1L * factInv[k] % mod * factInv[n - k] % mod);
	}

	int get(ArrayList<Integer> powers, int n) {
		int max = 0;
		for (int x : powers) {
			max = Math.max(x, max);
		}
		int[] cnt = new int[max + 2];
		for (int x : powers) {
			cnt[x]++;
		}
		int total = powers.size();
		int left = n - total;
		int right = total;
		long result = 0;
		for (int pos = 0; pos < max; pos++) {
			int fullLeft = pow2[left] - 1, fullRight = pow2[right] - 1;
			if (fullLeft < 0) {
				fullLeft += mod;
			}
			if (fullRight < 0) {
				fullRight += mod;
			}
			for (int min = 1; min <= Math.min(left, right); min++) {
				int cleft = c(left, min), cright = c(right, min);
				fullLeft -= cleft;
				if (fullLeft < 0) {
					fullLeft += mod;
				}
				fullRight -= cright;
				if (fullRight < 0) {
					fullRight += mod;
				}
				result += min
						* 1L
						* ((cleft * 1L * fullRight + cright * 1L * fullLeft + cleft
								* 1L * cright) % mod);
				result %= mod;
			}
			left += cnt[pos + 1];
			right -= cnt[pos + 1];
		}
		return (int) (result % mod);
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test2.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
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
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] primes = new int[100];
	int[] cnt = new int[100];
	int sz;
	int[] div;

	void get(int v) {
		sz = 0;
		while (v != 1) {
			int d = div[v];
			cnt[sz] = 0;
			primes[sz] = d;
			while (v % d == 0) {
				cnt[sz]++;
				v /= d;
			}
			sz++;
		}
	}

	void genDivs(int from, int cur, ArrayList<Integer> rs) {
		if (from == sz) {
			rs.add(cur);
		} else {
			for (int i = 0; i <= cnt[from]; i++) {
				genDivs(from + 1, cur, rs);
				cur *= primes[from];
			}
		}
	}

	void solve() {
		 final int MAX = (int) 1e6 + 10;
		 final int MAX2 = MAX;
//		final int MAX = 10, MAX2 = 10;
		int[] fact = new int[MAX2];
		int[] factInv = new int[MAX2];
		final int mod = (int) 1e9 + 7;
		fact[0] = 1;
		for (int i = 1; i < MAX2; i++) {
			fact[i] = (int) ((fact[i - 1] * 1L * i) % mod);
		}
//		factInv[MAX2 - 1] = BigInteger.valueOf(fact[MAX2 - 1])
//				.modInverse(BigInteger.valueOf(mod)).intValue();
		factInv[MAX2 - 1] = 238460277;
//		System.err.println(factInv[MAX2 - 1]);
		for (int i = MAX2 - 2; i >= 0; i--) {
			factInv[i] = (int) ((factInv[i + 1] * 1L * (i + 1)) % mod);
		}
		div = new int[MAX];
		Arrays.fill(div, -1);
		for (int i = 2; i < MAX; i++) {
			if (div[i] == -1) {
				for (int j = i; j < MAX; j += i) {
					div[j] = i;
				}
			}
		}
		int[][] divs = new int[MAX][];
		ArrayList<Integer> tmp = new ArrayList<>();
		for (int i = 1; i < MAX; i++) {
			get(i);
			tmp.clear();
			genDivs(0, 1, tmp);
			divs[i] = new int[tmp.size()];
			for (int j = 0; j < divs[i].length; j++) {
				divs[i][j] = tmp.get(j);
			}
		}
		int n = in.nextInt();
		int k = in.nextInt();
		int q = in.nextInt();
		int[] cnt = new int[MAX];
		for (int i = 0; i < n; i++) {
			int ai = in.nextInt();
			for (int d : divs[ai]) {
				cnt[d]++;
			}
		}
		int[] c_n_k = new int[MAX2];
		int[] c_n_k_1 = new int[MAX2];
		for (int nn = 0; nn < MAX2 - 2; nn++) {
			if (nn >= k) {
				c_n_k[nn] = (int) ((fact[nn] * 1L * factInv[k] % mod * 1L
						* factInv[nn - k] % mod));
			} else {
				c_n_k[nn] = 0;
			}
			if (nn >= k - 1) {
				c_n_k_1[nn] = (int) ((fact[nn] * 1L * factInv[k - 1] % mod * 1L
						* factInv[nn - k + 1] % mod));
			} else {
				c_n_k_1[nn] = 0;
			}
		}
		int[] result = new int[MAX];
		for (int gcd = MAX - 1; gcd >= 1; gcd--) {
			if (cnt[gcd] >= k) {
				result[gcd] += c_n_k[cnt[gcd]];
				if (result[gcd] >= mod) {
					result[gcd] -= mod;
				}
			}
			for (int d : divs[gcd]) {
				if (d == gcd) {
					continue;
				}
				result[d] -= result[gcd];
				if (result[d] < 0) {
					result[d] += mod;
				}
			}
		}
		long sum = 0;
		for (int gcd = 1; gcd < MAX; gcd++) {
			sum += gcd * 1L * result[gcd];
			sum %= mod;
		}
		int[] sub = new int[MAX];
		int[] time = new int[MAX];
		Arrays.fill(time, -1);
		for (int i = 0; i < q; i++) {
			int val = in.nextInt();
			for (int it = divs[val].length - 1; it >= 0; it--) {
				int x = divs[val][it];
				if (cnt[x] >= k - 1) {
					int add = c_n_k_1[cnt[x]];
					if (time[x] == i) {
						add -= sub[x];
						if (add < 0) {
							add += mod;
						}
					}
					sum += add * 1L * x;
					for (int d2 : divs[x]) {
						if (d2 == x) {
							continue;
						}
						if (time[d2] != i) {
							time[d2] = i;
							sub[d2] = 0;
						}
						sub[d2] += add;
						if (sub[d2] >= mod) {
							sub[d2] -= mod;
						}
					}
				}
			}
			for (int d : divs[val]) {
				cnt[d]++;
			}
			sum %= mod;
			out.println(sum);
		}
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
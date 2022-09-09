import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve2() {
		Random rnd = new Random(123);
		for (int it = 0; it < 1000; it++) {
			System.err.println(it);
			int k = 20;
			int n = 1 << k;
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = rnd.nextInt(100);
			int[] b = a.clone();
			int[] c = a.clone();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < i; j++)
					if ((j & i) == j) {
						b[j] += b[i];
					}
			}
			for (int bit = k - 1; bit >= 0; bit--)
				for (int s = n - 1; s >= 0; s--)
					if (((1 << bit) & s) != 0)
						c[s ^ (1 << bit)] += c[s];
			for (int i = 0; i < n; i++)
				if (c[i] != b[i])
					throw new AssertionError();
		}
	}

	void solve() {
		int n = in.nextInt();
		final int T = 20;
		final int MAX = 1 << T;
		final int MOD = (int) 1e9 + 7;
		int[] cnt = new int[MAX];
		for (int i = 0; i < n; i++) {
			cnt[in.nextInt()]++;
		}
		// for (int i = 0; i < MAX; i++) {
		// for (int j = 0; j < i; j++)
		// if ((j & i) == j) {
		// cnt[j] += cnt[i];
		// }
		// }
		for (int bit = T - 1; bit >= 0; bit--)
			for (int s = MAX - 1; s >= 0; s--)
				if (((1 << bit) & s) != 0)
					cnt[s ^ (1 << bit)] += cnt[s];
		int[] pow = new int[MAX];
		pow[0] = 1;
		for (int i = 1; i < MAX; i++) {
			pow[i] = (pow[i - 1] * 2) % MOD;
		}
		int res = 0;
		for (int i = 0; i < MAX; i++) {
			if (cnt[i] == 0)
				continue;
			int mul = (Integer.bitCount(i) & 1) == 0 ? 1 : -1;
			int resAdd = pow[cnt[i]] - 1;
			if (resAdd == -1)
				resAdd += MOD;
			res += resAdd * mul;
			if (res < 0)
				res += MOD;
			if (res >= MOD)
				res -= MOD;
		}
		out.println(res);
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
import java.io.*;
import java.util.*;

public class CF153DIV1 {
	FastScanner in;
	PrintWriter out;

	long lcm(long x, long y) {
		return x / gcd(x, y) * y;
	}
	
	long gcd(long x, long y) {
		return x == 0 ? y : gcd(y % x, x);
	}
	
	int k;
	int mod = 0;
	long max = -1;
	
	long res(long a, long b) {
		long f = a / (long) mod;
		long s = b / (long) mod;
		if (s == f) {
			long[] cost = new long[mod];
			Arrays.fill(cost, Long.MAX_VALUE);
			cost[(int) (a % (long) mod)] = 0;
			for (int i = (int) (a % (long) mod); i > 0; i--) {
				for (int j = 2; j <= k; j++) {
					int r = i % j;
					cost[i - r] = Math.min(cost[i - r], cost[i] + 1);
				}
				cost[i - 1] = Math.min(cost[i - 1], cost[i] + 1);
			}
			return cost[(int) (b % (long) mod)];
		}
		long ans = 0;
		if ((int) (a % (long) mod) != mod - 1) {
			long[] cost = new long[mod];
			Arrays.fill(cost, Long.MAX_VALUE);
			cost[(int) (a % (long) mod)] = 0;
			for (int i = (int) (a % (long) mod); i > 0; i--) {
				for (int j = 2; j <= k; j++) {
					int r = i % j;
					cost[i - r] = Math.min(cost[i - r], cost[i] + 1);
				}
				cost[i - 1] = Math.min(cost[i - 1], cost[i] + 1);
			}
			ans = 1 + cost[0];
			a /= (long) mod;
			a *= (long) mod;
			a--;
		}
		f = a / (long) mod;
		s = b / (long) mod;
		ans += (1L + max) * (f - s);
		return ans + res(a - mod * (f - s), b);
	}
	
	void solve() {
		long a = in.nextLong();
		long b = in.nextLong();
		k = in.nextInt();
		mod = 1;
		for (int i = 2; i <= k; i++) {
			mod = (int) lcm(mod, i);
		}
		long[] cost = new long[mod];
		Arrays.fill(cost, Long.MAX_VALUE);
		cost[mod - 1] = 0;
		for (int i = mod - 1; i > 0; i--) {
			for (int j = 2; j <= k; j++) {
				int r = i % j;
				cost[i - r] = Math.min(cost[i - r], cost[i] + 1);
			}
			cost[i - 1] = Math.min(cost[i - 1], cost[i] + 1);
		}
		max = cost[0];
		out.println(res(a, b));
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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
	}

	public static void main(String[] args) {
		new CF153DIV1().runIO();
	}
}
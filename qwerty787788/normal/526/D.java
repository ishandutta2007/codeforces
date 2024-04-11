import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	Random rnd = new Random();
	final int mod = BigInteger.valueOf((int) 1e9 + rnd.nextInt(100000))
			.nextProbablePrime().intValue();
	final int mul = 239;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		String s = in.next();
		int[] pow = new int[n + 1];
		int[] hash = new int[n + 1];
		pow[0] = 1;
		for (int i = 1; i <= n; i++) {
			pow[i] = (int) (pow[i - 1] * 1L * mul % mod);
		}
		for (int i = 1; i <= n; i++) {
			hash[i] = (int) ((hash[i - 1] * 1L * mul + s.charAt(i - 1)) % mod);
		}
		int[] maxPref = new int[n];
		for (int len = 1; len <= n; len++) {
			if (len * k > n) {
				break;
			}
			long needHash = hash[len];
			long powTmp = pow[len];
			boolean ok = true;
			for (int i = 1; i < k; i++) {
				long curHash = (hash[len * (i + 1)] - hash[len * i] * powTmp)
						% mod;
				if (curHash < 0) {
					curHash += mod;
				}
				if (curHash != needHash) {
					ok = false;
					break;
				}
			}
			if (ok) {
				maxPref[len * k - 1] = len;
			}
		}
		int[] sum = new int[n];
		for (int i = 0; i < n; i++) {
			if (maxPref[i] == 0) {
				continue;
			}
			sum[i]++;
			int left = 0, right = maxPref[i] + 1;
			right = Math.min(right, n - i);
			while (right - left > 1) {
				int mid = (right + left) >> 1;
				long curHash = (hash[i + mid + 1] - hash[i + 1] *1L* pow[mid])
						% mod;
				if (curHash < 0) {
					curHash += mod;
				}
				if (curHash == hash[mid]) {
					left = mid;
				} else {
					right = mid;
				}
			}
			maxPref[i] = left;
			int next = i + maxPref[i] + 1;
			if (next < n) {
				sum[next]--;
			}
		}
		int ss = 0;
		char[] res = new char[n];
		for (int i = 0; i < n; i++) {
			ss += sum[i];
			res[i] = ss > 0 ? '1' : '0';
		}
		out.println(new String(res));
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
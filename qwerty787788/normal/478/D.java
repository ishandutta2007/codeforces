import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int r = in.nextInt();
		int g = in.nextInt();
		int left = 0, right = (int) 1e4;
		while (right - left > 1) {
			int mid = (left + right) / 2;
			int[] a = new int[] { r, g };
			for (int layer = mid; layer > 0; layer--) {
				Arrays.sort(a);
				a[1] -= layer;
				if (a[1] < 0) {
					break;
				}
			}
			if (a[0] < 0 || a[1] < 0) {
				right = mid;
			} else {
				left = mid;
			}
		}
		final int mod = (int) 1e9 + 7;
		int[] cnt = new int[r + 1];
		cnt[0] = 1;
		for (int layer = 1; layer <= left; layer++) {
			for (int was = r; was >= 0; was--)
				if (cnt[was] != 0) {
					if (was + layer <= r) {
						cnt[was + layer] += cnt[was];
						if (cnt[was + layer] >= mod)
							cnt[was + layer] -= mod;
					}
				}
		}
		int atLeast = left * (left + 1) / 2 - g;
		long result = 0;
		for (int i = Math.max(atLeast, 0); i <= r; i++)
			result += cnt[i];
		out.println(result % mod);
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
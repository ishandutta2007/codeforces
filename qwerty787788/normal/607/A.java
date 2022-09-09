import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class O implements Comparable<O> {
		int a, b;

		public O(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(O o) {
			return Integer.compare(a, o.a);
		}

	}

	void solve() {
		int n = in.nextInt();
		O[] a = new O[n];
		for (int i = 0; i < n; i++) {
			a[i] = new O(in.nextInt(), in.nextInt());
		}
		Arrays.sort(a);
		int[] dp = new int[n];
		for (int i = 0; i < n; i++) {
			int l = -1, r = i;
			while (r - l > 1) {
				int m = (l + r) >> 1;
				if (a[i].a - a[i].b <= a[m].a) {
					r = m;
				} else {
					l = m;
				}
			}
			dp[i] = (l == -1 ? 0 : dp[l]) + (i - r);
		}
		int result = dp[n - 1];
		for (int i = 0; i < n; i++) {
			result = Math.min(result, dp[i] + n - i - 1);
		}
		out.println(result);
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

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
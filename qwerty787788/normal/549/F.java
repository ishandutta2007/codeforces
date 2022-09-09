import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] a;
	int[] b;
	int k;
	long res = 0;
	int[] cnt;

	void go(int l, int r) {
		if (l == r) {
			return;
		}
		int m = (l + r) / 2;
		go(l, m);
		go(m + 1, r);
		{
			int curMax = 0, curSum = 0, curMaxRem = 0;
			int it = m + 1;
			int sumRight = 0;
			for (int pos = m; pos >= l; pos--) {
				if (a[pos] > curMax) {
					curMax = a[pos];
					curMaxRem = b[pos];
				}
				curSum += b[pos];
				if (curSum >= k) {
					curSum -= k;
				}
				while (it <= r && a[it] <= curMax) {
					sumRight += b[it];
					if (sumRight >= k) {
						sumRight -= k;
					}
					cnt[sumRight]++;
					it++;
				}
				int needSum = curMaxRem - curSum;
				if (needSum < 0) {
					needSum += k;
				}
				res += cnt[needSum];
			}
			it = m + 1;
			sumRight = 0;
			for (; it <= r && a[it] <= curMax; it++) {
				sumRight += b[it];
				if (sumRight >= k) {
					sumRight -= k;
				}
				cnt[sumRight]--;
			}
		}
		{
			int curMax = 0, curSum = 0, curMaxRem = 0;
			int it = m;
			int sumLeft = 0;
			for (int pos = m + 1; pos <= r; pos++) {
				if (a[pos] > curMax) {
					curMax = a[pos];
					curMaxRem = b[pos];
				}
				curSum += b[pos];
				if (curSum >= k) {
					curSum -= k;
				}
				while (it >= l && a[it] < curMax) {
					sumLeft += b[it];
					if (sumLeft >= k) {
						sumLeft -= k;
					}
					cnt[sumLeft]++;
					it--;
				}
				int needSum = curMaxRem - curSum;
				if (needSum < 0) {
					needSum += k;
				}
				res += cnt[needSum];
			}
			it = m;
			sumLeft = 0;
			for (; it >= l && a[it] < curMax; it--) {
				sumLeft += b[it];
				if (sumLeft >= k) {
					sumLeft -= k;
				}
				cnt[sumLeft]--;
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		k = in.nextInt();
		a = new int[n];
		b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			b[i] = a[i] % k;
		}
		cnt = new int[k];
		go(0, n - 1);
		out.println(res);
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
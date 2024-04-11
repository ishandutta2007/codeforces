import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();

		int k = in.nextInt();
		char[] a = in.next().toCharArray();
		boolean[] free = new boolean[n];
		for (int i = 0; i < n; i++) {
			free[i] = a[i] == '0';
		}
		int[] sum = new int[n + 1];
		for (int i = 0; i < n; i++) {
			sum[i + 1] = sum[i] + (free[i] ? 1 : 0);
		}
		int left = 0, right = n + 1;
		while (right - left > 1) {
			int mid = (left + right) / 2;
			boolean ok = false;
			for (int my = 0; my < n; my++) {
				if (free[my]) {
					int fr = Math.max(0, my - mid);
					int to = Math.min(n - 1, my + mid);
					int cur = sum[to + 1] - sum[fr];
					if (cur >= k + 1) {
						ok = true;
					}
				}
			}
			if (!ok) {
				left = mid;
			} else {
				right = mid;
			}
		}
		out.println(right);
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
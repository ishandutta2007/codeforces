import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int getNextK(int pos, int curK) {
		int curP = (pos - 1) / curK;
		if (curP == 0) {
			return Integer.MAX_VALUE;
		}
		int l = curK, r = (int) 1e6;
		while (r - l > 1) {
			int mid = (l + r) >>> 1;
			if ((pos - 1) / mid == curP) {
				l = mid;
			} else {
				r = mid;
			}
		}
		return r;
	}

	int getNextK2(int pos, int curK) {
		int curP = (pos - 1) / curK;
		if (curP == 0) {
			return Integer.MAX_VALUE;
		}
		return (pos + curP - 1) / curP;
	}

	void solve1232() {
		for (int pos = 1; pos <= 20; pos++) {
			for (int k = 1; k <= 20; k++) {
				out.print(getNextK(pos, k) + " ");
			}
			out.println();
		}
	}

	void solve123() {
		long START = System.currentTimeMillis();
		final int n = 2 * 100000;
		for (int i = 1; i < n; i++) {
			for (int curK = 1; curK < n;) {
				int nextK = getNextK2(i, curK);
				curK = nextK;
			}
		}
		System.err.println(System.currentTimeMillis() - START);
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		long[] sum = new long[n + 1];
		for (int i = 1; i < n; i++) {
			for (int curK = 1; curK < n;) {
				int curParent = (i - 1) / curK;
				int nextK = getNextK2(i, curK);
				nextK = Math.min(nextK, n);
				if (a[i] < a[curParent]) {
					sum[curK]++;
					sum[nextK]--;
				}
				curK = nextK;
			}
		}
		long now = 0;
		for (int i = 1; i < n; i++) {
			now += sum[i];
			out.print(now + " ");
		}
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
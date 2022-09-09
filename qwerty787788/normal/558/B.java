import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		final int MAX = (int) 1e6 + 1;
		int[] cnt = new int[MAX];
		int[] first = new int[MAX];
		int[] last = new int[MAX];
		for (int i = 0; i < n; i++) {
			int v = a[i];
			cnt[v]++;
			if (cnt[v] == 1) {
				first[v] = i;
			}
			last[v] = i;
		}
		int bestFrom = 0, bestTo = n ;
		int maxCnt = 0;
		for (int i = 0; i < MAX; i++) {
			maxCnt = Math.max(maxCnt, cnt[i]);
		}
		for (int i = 0; i < MAX; i++) {
			if (cnt[i] == maxCnt) {
				if (last[i] - first[i] <= bestTo - bestFrom) {
					bestFrom = first[i];
					bestTo = last[i];
				}
			}
		}
		out.println((bestFrom + 1) + " " + (bestTo + 1));
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
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int getAnswer(int[] a, int l, int r, int curH) {
		int result = (r - l + 1);
		int minH = Integer.MAX_VALUE;
		for (int i = l; i <= r; i++) {
			minH = Math.min(minH, a[i]);
		}
		int result2 = minH - curH;
		int lastL = -1;
		for (int i = l; i <= r; i++) {
			if (a[i] == minH) {
				if (lastL != -1) {
					result2 += getAnswer(a, lastL, i - 1, minH);
					lastL = -1;
				}
			} else {
				if (lastL == -1) {
					lastL = i;
				}
			}
		}
		if (lastL != -1) {
			result2 += getAnswer(a, lastL, r, minH);
		}
		return Math.min(result, result2);
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		out.println(getAnswer(a, 0, n - 1, 0));
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
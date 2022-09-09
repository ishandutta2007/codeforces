import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] pref(int[] a) {
		int n = a.length;
		int[] pi = new int[n];
		for (int i = 1; i < n; ++i) {
			int j = pi[i - 1];
			while (j > 0 && a[i] != a[j])
				j = pi[j - 1];
			if (a[i] == a[j])
				++j;
			pi[i] = j;
		}
		return pi;
	}

	void solve() {
		int n = in.nextInt();
		int w = in.nextInt();
		int[] a = new int[n - 1];
		int[] b = new int[w - 1];
		int f = in.nextInt();
		for (int i = 0; i < n - 1; i++) {
			int c = in.nextInt();
			a[i] = c - f;
			f = c;
		}
		f = in.nextInt();
		for (int i = 0; i < w - 1; i++) {
			int c = in.nextInt();
			b[i] = c - f;
			f = c;
		}
		if (w == 1) {
			out.println(n);
			return;
		}
		int[] arr = new int[n - 1 + w];
		for (int i = 0; i < b.length; i++) {
			arr[i] = b[i];
		}
		arr[b.length] = Integer.MAX_VALUE;
		for (int i = 0; i < a.length; i++) {
			arr[b.length + i + 1] = a[i];
		}
		int[] pr = pref(arr);
		int result = 0;
		for (int i = b.length + 1; i < pr.length; i++) {
			if (pr[i] == b.length) {
				result++;
			}
		}
		out.println(result);
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
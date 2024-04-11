import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int[] failUp = new int[n];
		Arrays.fill(failUp, Integer.MAX_VALUE);
		for (int i = n - 2; i >= 0; i--) {
			if (a[i + 1] < a[i])
				failUp[i] = i;
			else
				failUp[i] = failUp[i + 1];
		}
		int[] failDown = new int[n];
		Arrays.fill(failDown, Integer.MAX_VALUE);
		for (int i = n - 2; i >= 0; i--) {
			if (a[i + 1] > a[i])
				failDown[i] = i;
			else
				failDown[i] = failDown[i + 1];
		}
		for (int i = 0; i < m; i++) {
			int l = in.nextInt() - 1;
			int r = in.nextInt() - 1;
			int t = failUp[l];
			if (t != Integer.MAX_VALUE)
				t = failDown[t];
			if (t >= r)
				out.println("Yes");
			else
				out.println("No");
		}
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
		new CF().runIO();
	}
}
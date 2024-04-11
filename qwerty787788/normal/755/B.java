import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		String[] s = new String[n];
		HashSet<String> was = new HashSet();
		for (int i = 0; i < n; i++) {
			s[i] = in.next();
			was.add(s[i]);
		}
		String[] t = new String[m];
		int common = 0;
		for (int i = 0; i < m; i++) {
			t[i] = in.next();
			if (was.contains(t[i])) {
				common++;
			}
		}
		n -= common;
		m -= common;
		boolean first = true;
		while (true) {
			if (common > 0) {
				common--;
			} else {
				if (first) {
					if (n > 0) {
						n--;
					} else {
						out.println("NO");
						return;
					}
				} else {
					if (m > 0) {
						m--;
					} else {
						out.println("YES");
						return;
					}
				}
			}
			first = !first;
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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
		new B().runIO();
	}
}
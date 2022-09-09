import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		char[] ss = in.next().toCharArray();
		int[] s = new int[ss.length];
		for (int i = 0; i < s.length; i++) {
			s[i] = ss[i] - '0';
		}
		int n = s.length;
		for (int i = 0; i < n; i++) {
			if (s[i] == 0 || s[i] == 8) {
				out.println("YES");
				out.println(s[i]);
				return;
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == 0) {
				continue;
			}
			for (int j = i + 1; j < n; j++) {
				int val = s[i] * 10 + s[j];
				if (val % 8 == 0) {
					out.println("YES");
					out.println(val);
					return;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == 0) {
				continue;
			}
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					int val = s[i] * 100 + s[j] * 10 + s[k];
					if (val % 8 == 0) {
						out.println("YES");
						out.println(val);
						return;
					}
				}
			}
		}
		out.println("NO");
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
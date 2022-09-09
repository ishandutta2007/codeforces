import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	String read() {
		char[] s1 = in.next().toCharArray();
		char[] s2 = in.next().toCharArray();
		String res = "";
		if (s1[0] != 'X') {
			res += s1[0];
		}
		if (s1[1] != 'X') {
			res += s1[1];
		}
		if (s2[1] != 'X') {
			res += s2[1];
		}
		if (s2[0] != 'X') {
			res += s2[0];
		}
		return res;
	}

	void solve() {
		String s1 = read();
		String s2 = read();
		for (int add = 0; add < 3; add++) {
			boolean ok = true;
			for (int i = 0; i < 3; i++) {
				if (s1.charAt(i) != s2.charAt((i + add) % 3)) {
					ok = false;
				}
			}
			if (ok) {
				out.println("YES");
				return;
			}
		}
		out.println("NO");
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
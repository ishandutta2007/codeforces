import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		String s = in.next();
		int bal = 0;
		int cnt = 0;
		int lastUse = 0;
		int lastPos = -1;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				bal++;
			} else {
				if (s.charAt(i) == ')') {
					bal--;
				} else {
					lastPos = i;
					bal--;
					cnt++;
				}
			}
		}
		lastUse = bal;
		bal = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				bal++;
			} else {
				if (s.charAt(i) == ')') {
					bal--;
				} else {
					bal--;
					if (i == lastPos) {
						bal -= lastUse;
					}
				}
				if (bal < 0) {
					out.println(-1);
					return;
				}
			}
		}
		if (lastUse < 0) {
			out.println(-1);
		} else {
			for (int i = 0; i < cnt - 1; i++) {
				out.println(1);
			}
			out.println(lastUse + 1);
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
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	String[] from, to;
	int n;

	HashMap<String, Integer> can = new HashMap<>();

	boolean can(String s) {
		if (can.containsKey(s)) {
			return can.get(s) == 1;
		}
		if (s.length() == 1) {
			return s.charAt(0) == 'a';
		} else {
			for (int i = 0; i < from.length; i++) {
				if (s.startsWith(from[i])) {
					if (can(to[i] + s.substring(2))) {
						can.put(s, 1);
						return true;
					}
				}
			}
			can.put(s, 0);
			return false;
		}
	}

	int go(String cur) {
		if (cur.length() == n) {
			if (can(cur)) {
				return 1;
			}
			return 0;
		} else {
			int res = 0;
			for (char a = 'a'; a <= 'f'; a++) {
				res += go(cur + a);
			}
			return res;
		}
	}

	void solve() {
		n = in.nextInt();
		int q = in.nextInt();
		from = new String[q];
		to = new String[q];
		for (int i = 0; i < q; i++) {
			from[i] = in.next();
			to[i] = in.next();
		}
		out.println(go(""));
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
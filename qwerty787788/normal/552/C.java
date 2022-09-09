import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int w = in.nextInt();
		int n = in.nextInt();
		if (w <= 3) {
			out.println("YES");
			return;
		}
		ArrayList<Long> all = new ArrayList<>();
		long cur = 1;
		long MAX = (long) 1e10;
		while (cur < MAX) {
			all.add(cur);
			cur *= w;
		}
		int sz = all.size();
		for (int st = 0; st < 1 << sz; st++) {
			long now = n;
			for (int i = 0; i < sz; i++) {
				if (((1 << i) & st) != 0) {
					now += all.get(i);
				}
			}
			for (int i = sz - 1; i >= 0; i--) {
				if (((1 << i) & st) == 0) {
					if (now - all.get(i) >= 0) {
						now -= all.get(i);
					}
				}
			}
			if (now == 0) {
				out.println("YES");
				return;
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
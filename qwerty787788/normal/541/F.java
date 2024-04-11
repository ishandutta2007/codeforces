import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int T = in.nextInt();
		ArrayList<Integer>[] g = new ArrayList[T + 1];
		for (int i = 0; i < g.length; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			int ti = in.nextInt();
			int qi = in.nextInt();
			g[T - ti].add(qi);
		}
		for (int i = g.length - 1; i >= 0; i--) {
			Collections.sort(g[i]);
			Collections.reverse(g[i]);
			if (i == 0) {
				out.println(g[0].get(0));
			} else {
				for (int j = 0; j < g[i].size(); j += 2) {
					int sum = g[i].get(j);
					if (j + 1 < g[i].size()) {
						sum += g[i].get(j + 1);
					}
					g[i - 1].add(sum);
				}
			}
		}

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
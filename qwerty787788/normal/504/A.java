import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] d = new int[n];
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			d[i] = in.nextInt();
			s[i] = in.nextInt();
		}
		ArrayList<Integer>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		ArrayList<Integer> all = new ArrayList<>();
		int qIt = 0;
		boolean[] was = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (d[i] <= 1) {
				all.add(i);
				was[i] = true;
			}
		}
		int sz = 0;
		while (qIt < all.size()) {
			int v = all.get(qIt++);
			if (d[v] == 0) {
				continue;
			}
			int next = s[v];
			d[next]--;
			s[next] ^= v;
			if (!was[next] && d[next] <= 1) {
				was[next] = true;
				all.add(next);
			}
			g[v].add(next);
			g[next].add(v);
			sz++;
		}
		out.println(sz);
		for (int i = 0; i < n; i++)
			for (int to : g[i])
				if (to > i) {
					out.println(i + " " + to);
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
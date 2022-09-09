import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Edge {
		int to;
		boolean used;

		public Edge(int to) {
			super();
			this.to = to;
		}

		Edge rev;
	}

	ArrayList<Edge>[] g;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			Edge e1 = new Edge(to);
			Edge e2 = new Edge(fr);
			e1.rev = e2;
			e2.rev = e1;
			g[fr].add(e1);
			g[to].add(e2);
		}
		int last = -1;
		for (int i = 0; i < n; i++) {
			if (g[i].size() % 2 == 1) {
				if (last == -1) {
					last = i;
				} else {
					Edge e1 = new Edge(i);
					Edge e2 = new Edge(last);
					e1.rev = e2;
					e2.rev = e1;
					g[last].add(e1);
					g[i].add(e2);
					last = -1;
				}
			}
		}
		ArrayList<Integer> st = new ArrayList<>();
		st.add(0);
		ArrayList<Integer> res = new ArrayList<>();
		while (st.size() != 0) {
			int v = st.get(st.size() - 1);
			if (g[v].size() == 0) {
				res.add(v);
				st.remove(st.size() - 1);
			} else {
				Edge e = g[v].get(g[v].size() - 1);
				g[v].remove(g[v].size() - 1);
				if (e.used || e.rev.used) {
					continue;
				}
				e.used = true;
				st.add(e.to);
			}
		}
		if (res.size() % 2 == 0) {
			res.add(0);
		}
		out.println(res.size() - 1);
		boolean ok = true;
		for (int i = 0; i < res.size() - 1; i++) {
			int fr = res.get(i);
			int to = res.get(i + 1);
			if (ok) {
				out.println((fr + 1) + " " + (to + 1));
			} else {
				out.println((to + 1) + " " + (fr + 1));
			}
			ok = !ok;
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
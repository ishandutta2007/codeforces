import java.io.*;
import java.util.*;

public class CF {

	class Road {
		int to;
		boolean pr;

		Road(int to, int type) {
			this.to = to;
			this.pr = type == 2;
		}
	}

	ArrayList<Road>[] g;
	boolean[] ans;

	boolean go(int v, int p, boolean need) {
		boolean res = false;
		for (int i = 0; i < g[v].size(); i++) {
			Road r = g[v].get(i);
			if (r.to == p)
				continue;
			boolean answer = go(r.to, v, r.pr);
			if (answer)
				res = true;
		}
		if (need && !res) {
			ans[v] = true;
			res = true;
		}
		return res;
	}

	void solve() {
		int n = in.nextInt();
		g = new ArrayList[n];
		ans = new boolean[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			int type = in.nextInt();
			g[fr].add(new Road(to, type));
			g[to].add(new Road(fr, type));
		}
		int su = 0;
		go(0, -1, false);
		for (int i = 0; i < n; i++)
			if (ans[i])
				su++;
		out.println(su);
		for (int i = 0; i < n; i++)
			if (ans[i])
				out.print((i + 1) + " ");
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
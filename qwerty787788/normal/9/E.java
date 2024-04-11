import java.io.*;
import java.util.*;

public class CF {

	boolean[] was;

	ArrayList<Integer>[] g;

	boolean go(int v, int p) {
		was[v] = true;
		for (int x : g[v])
			if (x != p)
				if (was[x])
					return true;
				else
					go(x, v);
		return false;
	}

	boolean isCycle(ArrayList<Integer>[] g) {
		int n = g.length;
		was = new boolean[n];
		boolean res = false;
		this.g = g;
		for (int i = 0; i < n; i++)
			if (!was[i])
				res |= go(i, -1);
		return res;
	}

	ArrayList<Integer> ans1 = new ArrayList<>();
	ArrayList<Integer> ans2 = new ArrayList<>();

	boolean find(ArrayList<Integer>[] g) {
		int m = 0;
		int n = g.length;
		for (int i = 0; i < n; i++)
			m += g[i].size();
		m /= 2;
		if (m > n)
			return false;
		boolean cycle = isCycle(g);
		if (m == n) {
			if (!cycle)
				return false;
			for (int i = 0; i < n; i++)
				if (g[i].size() != 2)
					return false;
			was = new boolean[n];
			go(0, -1);
			for (int i = 0; i < n; i++)
				if (!was[i])
					return false;
			return true;
		}
		for (int fr = 0; fr < n; fr++)
			for (int to = fr; to < n; to++) {
				g[fr].add(to);
				g[to].add(fr);
				ans1.add(fr);
				ans2.add(to);
				if (find(g)) {
					return true;
				} else {
					g[fr].remove(g[fr].size() - 1);
					g[to].remove(g[to].size() - 1);
					ans1.remove(ans1.size() - 1);
					ans2.remove(ans2.size() - 1);
				}
			}
		return false;
	}

	class Dsu {
		int[] p;

		Dsu(int n) {
			p = new int[n];
			for (int i = 0; i < n; i++)
				p[i] = i;
		}

		int get(int v) {
			return v == p[v] ? v : (p[v] = get(p[v]));
		}

		void union(int v, int u) {
			v = get(v);
			u = get(u);
			if (u == v)
				return;
			p[v] = u;
		}
	}

	void realSolve() {
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<Integer>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		if (n <= 5 || m >= n) {
			if (!find(g)) {
				out.println("NO");
			} else {
				out.println("YES");
				out.println(ans1.size());
				for (int i = 0; i < ans1.size(); i++)
					out.println((ans1.get(i) + 1) + " " + (ans2.get(i) + 1));
			}
		} else {
			Dsu dsu = new Dsu(n);
			for (int i = 0; i < n; i++)
				for (int x : g[i])
					dsu.union(i, x);
			for (int fr = 0; fr < n; fr++)
				for (int to = fr; to < n; to++)
					if (m < n && dsu.get(fr) != dsu.get(to) && g[fr].size() < 2
							&& g[to].size() < 2) {
						g[fr].add(to);
						g[to].add(fr);
						ans1.add(fr);
						ans2.add(to);
						dsu.union(fr, to);
						m++;
					}
			for (int fr = 0; fr < n; fr++)
				for (int to = fr + 1; to < n; to++)
					if (m == n - 1 && g[fr].size() == 1 && g[to].size() == 1) {
						g[fr].add(to);
						g[to].add(fr);
						ans1.add(fr);
						ans2.add(to);
						dsu.union(fr, to);
						m++;
					}
			//for (int i = 0; i < ans1.size(); i++) {
			//	System.err.println(ans1.get(i) + " " + ans2.get(i));
			//}
			was = new boolean[n];
			this.g = g;
			go(0, -1);
			boolean ok = true;
			for (int i = 0; i < n; i++)
				if (g[i].size() != 2)
					ok = false;
			for (int i = 0; i < n; i++)
				if (!was[i])
					ok = false;
			if (!ok) {
				out.println("NO");
			} else {
				out.println("YES");
				out.println(ans1.size());
				for (int i = 0; i < ans1.size(); i++)
					out.println((ans1.get(i) + 1) + " " + (ans2.get(i) + 1));
			}
		}
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solve() {
		in = new InputReader(new File("object.in"));
		try {
			out = new PrintWriter(new File("object.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		realSolve();

		out.close();
	}

	void solveIO() {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	public static void main(String[] args) {
		new CF().solveIO();
	}
}
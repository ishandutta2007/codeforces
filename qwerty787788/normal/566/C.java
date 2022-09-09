import java.io.*;
import java.util.*;

public class A {

	Random rnd = new Random(123);

	int[] p;

	int get(int x) {
		return p[x] == x ? p[x] : (p[x] = get(p[x]));
	}

	void unite(int x, int y) {
		p[get(x)] = get(y);
	}

	final int MAX = 100;

	class Edge {
		int to, cost;

		public Edge(int to, int cost) {
			super();
			this.to = to;
			this.cost = cost;
		}

	}

	ArrayList<Edge>[] g;

	double go(int v, int len, int p) {
		double res = w[v] * Math.pow(len, 1.5);
		for (Edge e : g[v]) {
			if (e.to != p) {
				res += go(e.to, len + e.cost, v);
			}
		}
		return res;
	}

	double stupid() {
		double res = Double.MAX_VALUE;
		int n = g.length;
		for (int v = 0; v < n; v++) {
			res = Math.min(res, go(v, 0, -1));
		}
		return res;
	}

	double f(int v, int p, int len, boolean sq) {
		double res = w[v] * Math.pow(len, sq ? 0.5 : 1.5);
		for (Edge e : g[v]) {
			if (e.to != p) {
				res += f(e.to, v, len + e.cost, sq);
			}
		}
		return res;
	}

	int[] w;

	void solve() {
		int n = in.nextInt();
		w = new int[n];
		for (int i = 0; i < n; i++) {
			w[i] = in.nextInt();
		}
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<A.Edge>();
		}
		for (int i = 0; i < n - 1; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			int cost = in.nextInt();
			g[fr].add(new Edge(to, cost));
			g[to].add(new Edge(fr, cost));
		}
		double res = smart2();
		out.println((1 + result) + " " + res);
	}

	class O implements Comparable<O> {
		int id;
		double ff;

		public O(int id, double ff) {
			super();
			this.id = id;
			this.ff = ff;
		}

		@Override
		public int compareTo(O arg0) {
			return -Double.compare(ff, arg0.ff);
		}

	}

	double goSmart(int v, int p) {
		double my = go(v, 0, -1);
		int to = -1;
		ArrayList<O> all = new ArrayList<A.O>();
		for (Edge e : g[v]) {
			if (e.to == p) {
				continue;
			}
			double ff = f(e.to, v, e.cost, false);
			all.add(new O(e.to, ff));
		}
		Collections.sort(all);
		for (int i = 0; i < Math.min(all.size(), 2); i++) {
			double value = go(all.get(i).id, 0, -1);
			if (value < my) {
				my = value;
				to = all.get(i).id;
			}
		}
		if (to != -1) {
			return goSmart(to, v);
		}
		return my;
	}

	boolean[] removed;
	int[] sz;

	int calcSz(int v, int p) {
		sz[v] = 1;
		for (Edge e : g[v]) {
			if (e.to != p && !removed[e.to]) {
				sz[v] += calcSz(e.to, v);
			}
		}
		return sz[v];
	}

	int bestNext(int v) {
		double myF = Double.MAX_VALUE;
		int to = -1;
		ArrayList<O> all = new ArrayList<A.O>();
		for (Edge e : g[v]) {
			if (removed[e.to]) {
				continue;
			}
			double ff = f(e.to, v, e.cost, false);
			all.add(new O(e.to, ff));
		}
		Collections.sort(all);
		for (int i = 0; i < Math.min(all.size(), 2); i++) {
			double value = go(all.get(i).id, 0, -1);
			if (value < myF) {
				myF = value;
				to = all.get(i).id;
			}
		}
		return to;
	}

	int bestNextNew(int v) {
		double myF = Double.MAX_VALUE;
		int to = -1;
		for (Edge e : g[v]) {
			if (removed[e.to]) {
				continue;
			}
//			double ffM1 = f(e.to, v, e.cost - 1);
			double ffP1 = f(e.to, v, e.cost + 1, true);
			double val = -ffP1;
			if (val < myF) {
				myF = val;
				to = e.to;
			}
		}
		return to;
	}

	double centroidGo(int v) {
		calcSz(v, v);
		int total = sz[v];
		int par = v;
		while (true) {
			boolean ch = false;
			for (Edge e : g[v]) {
				if (e.to == par) {
					continue;
				}
				if (!removed[e.to]) {
					if (sz[e.to] * 2 >= total) {
						par = v;
						v = e.to;
						ch = true;
						break;
					}
				}
			}
			if (!ch) {
				break;
			}
		}
		double myF = go(v, 0, -1);
		int to = bestNextNew(v);
		if (to != -1 && f(to, to, 0, false) > myF) {
			to = -1;
		}
		if (to != -1) {
			removed[v] = true;
			return centroidGo(to);
		}
		result = v;
		return myF;
	}

	int result;

	double smart2() {
		int n = g.length;
		sz = new int[n];
		removed = new boolean[n];
		return centroidGo(0);
	}

	double smart() {
		return goSmart(0, -1);
	}

	private void solve123() {
		for (int it = 0; it < 123123; it++) {
			System.err.println("iter = " + it);
			int n = 1 + rnd.nextInt(MAX);
			g = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				g[i] = new ArrayList<A.Edge>();
			}
			p = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = i;
			}
			w = new int[n];
			for (int i = 0; i < n; i++) {
				w[i] = rnd.nextInt(MAX);
			}
			for (int i = 0; i < n - 1; i++) {
				int x = rnd.nextInt(n);
				int y = rnd.nextInt(n);
				if (get(x) == get(y)) {
					i--;
					continue;
				}
				unite(x, y);
				int cost = 1 + rnd.nextInt(MAX);
				g[x].add(new Edge(y, cost));
				g[y].add(new Edge(x, cost));
			}
			double correct = stupid();
			double my = smart2();
			if (!same(my, correct)) {
				throw new AssertionError();
			}
		}
	}

	final double eps = 1e-6;

	boolean same(double x, double y) {
		if (Math.abs(x - y) < eps) {
			return true;
		}
		if (Math.abs(x - y) / Math.max(Math.abs(x), Math.abs(y)) < eps) {
			return true;
		}
		return false;
	}

	class FastScanner {
		StringTokenizer st;
		BufferedReader br;

		FastScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return null;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					return null;
				}
			}
			return st.nextToken();
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					return false;
				}
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

	FastScanner in;
	PrintWriter out;

	void runFile() {
		in = new FastScanner("a.in");
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	public static void main(String[] args) {
		new A().run();
	}
}
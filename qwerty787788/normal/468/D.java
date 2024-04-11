import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Edge {
		int to, cost;

		public Edge(int to, int cost) {
			super();
			this.to = to;
			this.cost = cost;
		}

	}

	ArrayList<Edge>[] g;
	int[] sz;
	int[] id;

	int go(int v, int p) {
		sz[v] = 1;
		for (Edge e : g[v])
			if (e.to != p) {
				sz[v] += go(e.to, v);
			}
		return sz[v];
	}

	long answer = 0;

	void go2(int v, int p, int curId, long length) {
		id[v] = curId;
		answer += 2 * length;
		for (Edge e : g[v]) {
			if (e.to != p) {
				go2(e.to, v, curId, length + e.cost);
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		if (n == 1) {
			out.println("0 1");
			return;
		}
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			int cost = in.nextInt();
			g[fr].add(new Edge(to, cost));
			g[to].add(new Edge(fr, cost));
		}
		sz = new int[n];
		int total = go(0, -1);
		int center = 0, parent = -1;
		while (true) {
			boolean ok = true;
			for (Edge e : g[center]) {
				if (e.to != parent) {
					if (sz[e.to] * 2 > total) {
						parent = center;
						center = e.to;
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				break;
			}
		}
		int it = 1;
		id = new int[n];
		for (Edge e : g[center]) {
			go2(e.to, center, it++, e.cost);
		}
		out.println(answer);
		Subtree[] subtrees = new Subtree[it];
		for (int i = 0; i < it; i++) {
			subtrees[i] = new Subtree(i);
		}
		for (int i = 0; i < n; i++) {
			subtrees[id[i]].addElement(i);
		}
		TreeSet<Subtree> ts = new TreeSet<>();
		for (int i = 0; i < it; i++) {
			ts.add(subtrees[i]);
		}
		int[] diff = new int[it];
		for (int i = 0; i < n; i++) {
			diff[id[i]]++;
		}
		for (int i = 0; i < it; i++) {
			diff[i] = (n - diff[i]) - diff[i];
		}
		TreeSet<Pair> pairs = new TreeSet<>();
		Pair[] pairsArr = new Pair[it];
		for (int i = 1; i < it; i++) {
			pairsArr[i] = new Pair(diff[i], i);
			pairs.add(pairsArr[i]);
		}

		boolean[] used = new boolean[n];

		for (int i = 0; i < n; i++) {
			Pair p = pairs.pollFirst();
			if (p.value - i <= 0) {
				ArrayList<Integer> one = new ArrayList<>();
				ArrayList<Integer> two = new ArrayList<>();
				for (int j = 0; j < n; j++)
					if (!used[j]) {
						if (id[j] == p.id) {
							one.add(j);
						} else {
							two.add(j);
						}
					}
				int itOne = 0, itTwo = 0;
				for (int j = i; j < n; j++) {
					if (id[j] != p.id) {
						out.print((1 + one.get(itOne++)) + " ");
					} else {
						out.print((1 + two.get(itTwo++)) + " ");
					}
				}
				break;
			}
			pairs.add(p);

			Subtree x = ts.pollFirst();
			if (x.id == id[i] && i != center) {
				Subtree t = ts.pollFirst();
				ts.add(x);
				x = t;
			}
			int val = x.ids.pollFirst();
			if (x.ids.size() == 0) {
				x.curMin = Integer.MAX_VALUE;
			} else {
				x.curMin = x.ids.first();
			}
			ts.add(x);
			out.print((val + 1) + " ");
			if (id[i] != 0) {
				pairs.remove(pairsArr[id[i]]);
				pairsArr[id[i]].value++;
				pairs.add(pairsArr[id[i]]);
			}
			if (x.id != 0) {
				pairs.remove(pairsArr[x.id]);
				pairsArr[x.id].value++;
				pairs.add(pairsArr[x.id]);
			}
			used[val] = true;
		}
	}

	class Subtree implements Comparable<Subtree> {
		TreeSet<Integer> ids;
		int curMin;
		int id;

		public Subtree(int id) {
			this.id = id;
			curMin = Integer.MAX_VALUE;
			ids = new TreeSet<>();
		};

		void addElement(int x) {
			curMin = Math.min(curMin, x);
			ids.add(x);
		}

		@Override
		public int compareTo(Subtree o) {
			return Integer.compare(curMin, o.curMin);
		}

		@Override
		public String toString() {
			return "Subtree [ids=" + ids + ", curMin=" + curMin + ", id=" + id
					+ "]";
		}

	}

	class Pair implements Comparable<Pair> {
		int value, id;

		public Pair(int value, int id) {
			super();
			this.value = value;
			this.id = id;
		}

		@Override
		public int compareTo(Pair o) {
			if (value == o.value)
				return Integer.compare(id, o.id);
			return Integer.compare(value, o.value);
		}

		@Override
		public String toString() {
			return "Pair [value=" + value + ", id=" + id + "]";
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
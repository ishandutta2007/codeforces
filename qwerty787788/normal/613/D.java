import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	int[] h;
	int[][] up;
	final int MAX = 20;

	int[] tin, tout;
	int time;

	void go(int v, int p, int curH) {
		h[v] = curH;
		up[0][v] = p;
		for (int i = 1; i < MAX; i++) {
			up[i][v] = up[i - 1][up[i - 1][v]];
		}
		tin[v] = time++;
		for (int to : g[v]) {
			if (to != p) {
				go(to, v, curH + 1);
			}
		}
		tout[v] = time++;
	}

	boolean isParent(int x, int y) {
		return tin[y] >= tin[x] && tout[y] <= tout[x];
	}

	int lca(int x, int y) {
		if (isParent(x, y)) {
			return x;
		}
		for (int i = MAX - 1; i >= 0; i--) {
			if (!isParent(up[i][x], y)) {
				x = up[i][x];
			}
		}
		return up[0][x];
	}

	class V {
		int v;
		int time;

		public V(int v, int time) {
			super();
			this.v = v;
			this.time = time;
		}

	}

	class Ans {
		boolean haveVertex;
		int cost;
		int v;

		public Ans(boolean haveVertex, int cost, int v) {
			super();
			this.haveVertex = haveVertex;
			this.cost = cost;
			this.v = v;
		}

	}

	class CurrentVertex {
		int parent;
		ArrayList<CurrentVertex> g;
		boolean inQ;
		int id;

		@Override
		public String toString() {
			return "CurrentVertex [parent=" + parent + ", g=" + g + ", inQ="
					+ inQ + ", id=" + id + "]";
		}

		public CurrentVertex(int id) {
			parent = -1;
			this.id = id;
			g = new ArrayList<>();
		}

		Ans calc() {
			if (inQ) {
				int cost = 0;
				for (CurrentVertex next : g) {
					Ans child = next.calc();
					if (child == null) {
						return null;
					}
					cost += child.cost;
					if (child.haveVertex) {
						if (h[child.v] == h[id] + 1) {
							return null;
						}
						cost++;
					}
				}
				return new Ans(true, cost, id);
			}
			int cost = 0;
			int cnt = 0;
			int v1 = -1;
			for (CurrentVertex next : g) {
				Ans child = next.calc();
				if (child == null) {
					return null;
				}
				cost += child.cost;
				if (child.haveVertex) {
					cnt++;
					v1 = child.v;
				}
			}
			if (cnt == 0) {
				return new Ans(false, cost, -1);
			} else {
				if (cnt == 1) {
					return new Ans(true, cost, v1);
				} else {
					return new Ans(false, cost + 1, id);
				}
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i + 1 < n; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		up = new int[MAX][n];
		tin = new int[n];
		time = 0;
		tout = new int[n];
		h = new int[n];
		go(0, 0, 0);
		int q = in.nextInt();
		int[] used = new int[n];
		Arrays.fill(used, -1);
		CurrentVertex[] ver = new CurrentVertex[n];
		for (int i = 0; i < q; i++) {
			int k = in.nextInt();
			int[] all = new int[k];
			V[] vv = new V[k * 2];
			ArrayList<CurrentVertex> allV = new ArrayList<>();
			for (int j = 0; j < k; j++) {
				all[j] = in.nextInt() - 1;
				used[all[j]] = i;
				ver[all[j]] = new CurrentVertex(all[j]);
				ver[all[j]].inQ = true;
				allV.add(ver[all[j]]);
				vv[j * 2] = new V(all[j], tin[all[j]]);
				vv[j * 2 + 1] = new V(all[j], tout[all[j]]);
			}
			//if (k == 1) {
		//		out.println(-1);
	//			continue;
//			}
			Arrays.sort(vv, new Comparator<V>() {

				@Override
				public int compare(V o1, V o2) {
					return Integer.compare(o1.time, o2.time);
				}

			});
			for (int j = 0; j + 1 < vv.length; j++) {
				int u = lca(vv[j].v, vv[j + 1].v);
				if (used[u] != i) {
					used[u] = i;
					ver[u] = new CurrentVertex(u);
					allV.add(ver[u]);
				}
			}
			Collections.sort(allV, new Comparator<CurrentVertex>() {

				@Override
				public int compare(CurrentVertex o1, CurrentVertex o2) {
					return Integer.compare(tin[o1.id], tin[o2.id]);
				}
			});
			ArrayList<CurrentVertex> stack = new ArrayList<>();
			CurrentVertex root = allV.get(0);
			for (CurrentVertex v : allV) {
				while (stack.size() > 0
						&& !isParent(stack.get(stack.size() - 1).id, v.id)) {
					stack.remove(stack.size() - 1);
				}
				if (stack.size() > 0) {
					stack.get(stack.size() - 1).g.add(v);
				}
				stack.add(v);
			}
			Ans ans = root.calc();
			out.println(ans == null ? -1 : ans.cost);
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

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
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Edge implements Comparable<Edge> {
		int fr, to, color;

		public Edge(int fr, int to, int color) {
			super();
			this.fr = fr;
			this.to = to;
			this.color = color;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(color, o.color);
		}

	}

	int[] parent;

	int get(int x) {
		return parent[x] == x ? x : (parent[x] = get(parent[x]));
	}

	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			parent[x] = y;
		}
	}
	
	int qSz;
	int[] q;
	int[] bigId;
	int[] answer;
	ArrayList<Integer>[] all;
	ArrayList<Integer>[] qu;
	int[]fr;
	int[] to;
	int[] bigs;
	int[][] cnt;
	
	void upd() {
		for (int i = 0; i < qSz; i++) {
			int v = q[i];
			int root = get(v);
			if (bigId[v] == -1) {
				for (int curQ : qu[v]) {
					int another = fr[curQ] + to[curQ] - v;
					if (get(another) == root) {
						answer[curQ]++;
					}
				}
			}
			all[root].add(v);
		}
		for (int i = 0; i < bigs.length; i++) {
			int v = bigs[i];
			int root = get(v);
			for (int x : all[root])
				if (x != v && bigId[x] != -1) {
					cnt[i][bigId[x]]++;
				}
		}
		for (int i = 0; i < qSz; i++) {
			int v = q[i];
			int root = get(v);
			all[root].clear();
		}
		for (int i = 0; i < qSz; i++) {
			parent[q[i]] = q[i];
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		Edge[] allE = new Edge[m];
		for (int i = 0; i < m; i++) {
			allE[i] = new Edge(in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
		}
		final int BIG = 444;
		int[] colors = new int[n];
		for (Edge e : allE) {
			colors[e.fr]++;
			colors[e.to]++;
		}
		bigId = new int[n];
		int cntBig = 0;
		Arrays.fill(bigId, -1);
		for (int i = 0; i < n; i++) {
			if (colors[i] >= BIG) {
				bigId[i] = cntBig++;
			}
		}
		bigs = new int[cntBig];
		for (int i = 0; i < n; i++) {
			if (bigId[i] != -1) {
				bigs[bigId[i]] = i;
			}
		}
		int qq = in.nextInt();
		fr = new int[qq];
		to = new int[qq];
		for (int i = 0; i < qq; i++) {
			fr[i] = in.nextInt() - 1;
			to[i] = in.nextInt() - 1;
		}
		answer = new int[qq];
		qu = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			qu[i] = new ArrayList<>();
		}
		for (int i = 0; i < qq; i++) {
			if (bigId[fr[i]] == -1 || bigId[to[i]] == -1) {
				if (colors[fr[i]] < colors[to[i]]) {
					qu[fr[i]].add(i);
				} else {
					qu[to[i]].add(i);
				}
			}
		}
		Arrays.sort(allE);
		int lastColor = -1;
		q = new int[n];
		int[] used = new int[n];
		parent = new int[n];
		cnt = new int[cntBig][cntBig];
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		int time = 0;
		qSz = 0;
		all = new ArrayList[n + 1];
		for (int i = 0; i < all.length; i++) {
			all[i] = new ArrayList<>();
		}
		for (Edge e : allE) {
			if (e.color != lastColor) {
				upd();
				time++;
				qSz = 0;
			}
			if (used[e.fr] != time) {
				used[e.fr] = time;
				q[qSz++] = e.fr;
			}
			if (used[e.to] != time) {
				used[e.to] = time;
				q[qSz++] = e.to;
			}
			unite(e.fr, e.to);
			lastColor = e.color;
		}
		upd();
		for (int i = 0; i < qq; i++) {
			if (bigId[fr[i]] != -1 && bigId[to[i]] != -1) {
				answer[i] = cnt[bigId[fr[i]]][bigId[to[i]]];
			}
		}
		for (int ans : answer) {
			out.println(ans);
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
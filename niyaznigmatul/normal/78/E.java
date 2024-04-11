import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {

	void solve() {
		int n = nextInt();
		int t = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < n; i++) {
			c[i] = nextToken().toCharArray();
		}
		int[][] infectTime = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(infectTime[i], Integer.MAX_VALUE);
		}
		Queue<State> q = new ArrayDeque<State>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[i][j] == 'Z') {
					q.add(new State(i, j));
					infectTime[i][j] = 0;
				}
			}
		}
		while (!q.isEmpty()) {
			State state = q.poll();
			for (int dir = 0; dir < 4; dir++) {
				int x = state.x + DX[dir];
				int y = state.y + DY[dir];
				if (x < 0 || y < 0 || x >= n || y >= n || c[x][y] == 'Y'
						|| infectTime[x][y] != Integer.MAX_VALUE) {
					continue;
				}
				infectTime[x][y] = infectTime[state.x][state.y] + 1;
				q.add(new State(x, y));
			}
		}
		int[][][][] dist = new int[n][n][][];
		for (int i = 0; i < n; i++) {
			// System.err.println(Arrays.toString(infectTime[i]));
			for (int j = 0; j < n; j++) {
				dist[i][j] = findDists(n, c, i, j, infectTime);
			}
		}
		Graph g = new Graph(1 + n * n + n * n + 1);
		int sink = 1 + 2 * n * n;
		int shiftCapsule = 1 + n * n;
		int shiftMen = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[i][j] != '0' && c[i][j] != 'Y' && c[i][j] != 'Z') {
					g.addEdge(0, i * n + j + shiftMen, 0, c[i][j] - '0');
				}
			}
		}
		char[][] capsule = new char[n][];
		for (int i = 0; i < n; i++) {
			capsule[i] = nextToken().toCharArray();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (capsule[i][j] != '0' && capsule[i][j] != 'Y'
						&& capsule[i][j] != 'Z') {
					g.addEdge(i * n + j + shiftCapsule, sink, 0,
							capsule[i][j] - '0');
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					for (int k2 = 0; k2 < n; k2++) {
						if (dist[i][j][k][k2] <= t) {
							g.addEdge(i * n + j + shiftMen, k * n + k2
									+ shiftCapsule, 0, 1 << 20);
						}
					}
					// System.err.println(Arrays.toString(dist[i][j][k]));
				}
				// System.err.println();
			}
		}
		out.println(g.getMaxFlow(0, sink));
	}

	static int[][] findDists(int n, char[][] c, int startX, int startY,
			int[][] infectTime) {
		if (c[startX][startY] == 'Y' || c[startX][startY] == 'Z') {
			return new int[n][n];
		}
		Queue<State> q = new ArrayDeque<State>();
		int[][] d = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(d[i], Integer.MAX_VALUE);
		}
		q.add(new State(startX, startY));
		d[startX][startY] = 0;
		while (!q.isEmpty()) {
			State state = q.poll();
			for (int dir = 0; dir < 4; dir++) {
				int x = state.x + DX[dir];
				int y = state.y + DY[dir];
				int newD = d[state.x][state.y] + 1;
				if (x < 0 || y < 0 || x >= n || y >= n || c[x][y] == 'Y'
						|| c[x][y] == 'Z' || d[x][y] != Integer.MAX_VALUE
						|| newD >= infectTime[x][y]) {
					continue;
				}
				d[x][y] = newD;
				q.add(new State(x, y));
			}
		}
		int[][] e = new int[n][];
		for (int i = 0; i < n; i++) {
			e[i] = d[i].clone();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] == Integer.MAX_VALUE) {
					continue;
				}
				for (int dir = 0; dir < 4; dir++) {
					int x = i + DX[dir];
					int y = j + DY[dir];
					if (x < 0 || y < 0 || x >= n || y >= n || c[x][y] == 'Y'
							|| c[x][y] == 'Z') {
						continue;
					}
					if (d[i][j] + 1 == infectTime[x][y]
							&& d[i][j] + 1 < e[x][y]) {
						e[x][y] = d[i][j] + 1;
					}
				}
			}
		}
		return e;
	}

	static int[] DX = { 1, 0, -1, 0 };
	static int[] DY = { 0, 1, 0, -1 };

	static class State {
		int x;
		int y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	static class Edge {
		int from;
		int to;
		int flow;
		int cap;
		Edge rev;

		public Edge(int from, int to, int flow, int cap) {
			super();
			this.from = from;
			this.to = to;
			this.flow = flow;
			this.cap = cap;
		}

	}

	static class Graph {
		ArrayList<Edge>[] edges;
		int[] cur;
		int[] q;
		int[] d;
		int n;

		public Graph(int n) {
			edges = new ArrayList[n];
			this.n = n;
			for (int i = 0; i < edges.length; i++) {
				edges[i] = new ArrayList<Edge>();
			}
		}

		void addEdge(int from, int to, int flow, int cap) {
			Edge e1 = new Edge(from, to, flow, cap);
			Edge e2 = new Edge(to, from, -flow, 0);
			e1.rev = e2;
			e2.rev = e1;
			edges[from].add(e1);
			edges[to].add(e2);
		}

		boolean bfs(int source, int target) {
			int head = 0;
			int tail = 1;
			Arrays.fill(d, Integer.MAX_VALUE);
			d[source] = 0;
			q[0] = source;
			while (head < tail) {
				int x = q[head++];
				for (Edge e : edges[x]) {
					if (e.cap - e.flow > 0 && d[e.to] == Integer.MAX_VALUE) {
						d[e.to] = d[x] + 1;
						q[tail++] = e.to;
						if (e.to == target) {
							return true;
						}
					}
				}
			}
			return false;
		}

		int dfs(int x, int target, int cMin) {
			if (x == target) {
				return cMin;
			}
			for (int i = cur[x]; i < edges[x].size(); cur[x] = ++i) {
				Edge e = edges[x].get(i);
				if (d[e.to] != d[x] + 1 || e.cap - e.flow == 0) {
					continue;
				}
				int add = dfs(e.to, target, Math.min(cMin, e.cap - e.flow));
				if (add == 0) {
					continue;
				}
				e.flow += add;
				e.rev.flow -= add;
				return add;
			}
			return 0;
		}

		long getMaxFlow(int source, int target) {
			cur = new int[n];
			q = new int[n];
			d = new int[n];
			long flow = 0;
			while (bfs(source, target)) {
				Arrays.fill(cur, 0);
				while (true) {
					int add = dfs(source, target, Integer.MAX_VALUE);
					if (add == 0) {
						break;
					}
					flow += add;
				}
			}
			return flow;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new E().run();
	}
}
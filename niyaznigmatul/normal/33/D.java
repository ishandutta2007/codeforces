import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {
	public static void main(String[] args) {
		new D().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
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

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
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

	class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		long dist2(Point p) {
			long dx = x - p.x;
			long dy = y - p.y;
			return dx * dx + dy * dy;
		}
	}

	class Circle extends Point {
		int r;

		public Circle(int r, int x, int y) {
			super(x, y);
			this.r = r;
		}

		boolean contains(Circle c) {
			return contains((Point) c) && r > c.r;
		}

		boolean contains(Point p) {
			long d = dist2(p);
			return d < (long) r * r;
		}
	}

	ArrayList<Integer>[] edges;
	int[] parent;
	int[][] dist;
	boolean[] was;

	void dfs(int x, int p) {
		parent[x] = p;
		was[x] = true;
		for (int i = 0; i < dist.length; i++) {
			if (!was[i] || i == x) {
				continue;
			}
			if (dist[x][i] == 0) {
				dist[x][i] = dist[i][x] = (dist[parent[x]][i] + 1);
			}
		}
		for (int i : edges[x]) {
			if (i == p) {
				continue;
			}
			dfs(i, x);
		}		
		for (int i = parent[x], j = 1; i != -1; i = parent[i], j++) {
			dist[x][i] = dist[i][x] = j;
		}
	}

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		Point[] p = new Point[n];
		for (int i = 0; i < p.length; i++) {
			p[i] = new Point(nextInt(), nextInt());
		}
		Circle[] c = new Circle[m];
		for (int i = 0; i < c.length; i++) {
			c[i] = new Circle(nextInt(), nextInt(), nextInt());
		}
		Arrays.sort(c, new Comparator<Circle>() {
			@Override
			public int compare(Circle o1, Circle o2) {
				return o1.r < o2.r ? 1 : o1.r > o2.r ? -1 : 0;
			}
		});
		int[] par = new int[m + 1];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < i; j++) {
				if (c[j].contains(c[i])) {
					par[i + 1] = j + 1;
				}
			}
		}
		edges = new ArrayList[m + 1];
		for (int i = 0; i < edges.length; i++) {
			edges[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i < par.length; i++) {
			edges[par[i]].add(i);
			edges[i].add(par[i]);
		}
		parent = new int[m + 1];
		dist = new int[m + 1][m + 1];
		was = new boolean[m + 1];
		dfs(0, -1);
		int[] inWhich = new int[n];
		for (int i = 0; i < p.length; i++) {
			for (int j = 0; j < c.length; j++) {
				if (c[j].contains(p[i])) {
					inWhich[i] = j + 1;
				}
			}
		}
		for (int i = 0; i < k; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			out.println(dist[inWhich[x]][inWhich[y]]);
		}
	}
}
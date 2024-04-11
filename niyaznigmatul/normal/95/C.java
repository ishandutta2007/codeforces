import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	static class Edge {
		int from;
		int to;
		int w;

		public Edge(int from, int to, int w) {
			super();
			this.from = from;
			this.to = to;
			this.w = w;
		}

	}

	static class Element implements Comparable<Element> {
		long d;
		int v;

		public Element(long d, int v) {
			this.d = d;
			this.v = v;
		}

		@Override
		public int compareTo(Element e) {
			if (d != e.d) {
				return d < e.d ? -1 : 1;
			}
			return v - e.v;
		}

	}

	static ArrayList<Edge>[] edges;
	static int n;

	static long[] dijkstra(int source) {
		Element[] elements = new Element[n];
		for (int i = 0; i < n; i++) {
			elements[i] = new Element(Long.MAX_VALUE, i);
		}
		elements[source].d = 0;
		TreeSet<Element> q = new TreeSet<Element>();
		q.add(elements[source]);
		while (!q.isEmpty()) {
			Element cur = q.pollFirst();
			for (Edge e : edges[cur.v]) {
				Element sec = elements[e.to];
				if (sec.d > cur.d + e.w) {
					q.remove(sec);
					sec.d = cur.d + e.w;
					q.add(sec);
				}
			}
		}
		long[] ans = new long[n];
		for (int i = 0; i < n; i++) {
			ans[i] = elements[i].d;
		}
		return ans;
	}

	void solve() {
		n = nextInt();
		int m = nextInt();
		int start = nextInt() - 1;
		int finish = nextInt() - 1;
		edges = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<Edge>();
		}
		for (int i = 0; i < m; i++) {
			int from = nextInt() - 1;
			int to = nextInt() - 1;
			int w = nextInt();
			edges[from].add(new Edge(from, to, w));
			edges[to].add(new Edge(to, from, w));
		}
		long[][] dist = new long[n][];
		for (int i = 0; i < n; i++) {
			dist[i] = dijkstra(i);
		}
		int[] thres = new int[n];
		int[] cost = new int[n];
		for (int i = 0; i < n; i++) {
			thres[i] = nextInt();
			cost[i] = nextInt();
		}
		int[][] edges = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(edges[i], Integer.MAX_VALUE);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				if (dist[i][j] <= thres[i]) {
					edges[i][j] = cost[i];
				}
			}
		}
		long[] d = new long[n];
		boolean[] was = new boolean[n];
		Arrays.fill(d, Long.MAX_VALUE);
		d[start] = 0;
		while (true) {
			int min = -1;
			for (int i = 0; i < n; i++) {
				if (was[i] || d[i] == Long.MAX_VALUE) {
					continue;
				}
				if (min == -1 || d[min] > d[i]) {
					min = i;
				}
			}
			if (min == -1) {
				break;
			}
			was[min] = true;
			for (int i = 0; i < n; i++) {
				if (edges[min][i] == Integer.MAX_VALUE) {
					continue;
				}
				if (d[i] > d[min] + edges[min][i]) {
					d[i] = d[min] + edges[min][i];
				}
			}
		}
		out.println(d[finish] == Long.MAX_VALUE ? -1 : d[finish]);
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
		new C().run();
	}
}
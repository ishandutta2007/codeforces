import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {

	static class Edge {
		int from;
		int to;

		public Edge(int from, int to) {
			this.from = from;
			this.to = to;
		}

	}

	static class BadWay {
		int a;
		int b;
		int c;

		public BadWay(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}

		@Override
		public int hashCode() {
			final int prime = 33533;
			int result = 0;
			result = prime * result + a;
			result = prime * result + b;
			result = prime * result + c;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			BadWay other = (BadWay) obj;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			if (c != other.c)
				return false;
			return true;
		}

	}

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		Edge[] edges = new Edge[2 * m + 1];
		edges[0] = new Edge(0, 0);
		HashSet<BadWay> bad = new HashSet<BadWay>();
		ArrayList<Integer>[] edgesList = new ArrayList[n];
		for (int i = 0; i < edgesList.length; i++) {
			edgesList[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= m; i++) {
			int from = nextInt() - 1;
			int to = nextInt() - 1;
			edges[2 * i - 1] = new Edge(from, to);
			edges[2 * i] = new Edge(to, from);
			edgesList[from].add(2 * i - 1);
			edgesList[to].add(2 * i);
		}
		for (int i = 0; i < k; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			int c = nextInt() - 1;
			bad.add(new BadWay(a, b, c));
		}
		int[] lastEdge = new int[edges.length];
		lastEdge[0] = -1;
		int[] q = new int[2 * m + 1];
		int[] d = new int[2 * m + 1];
		Arrays.fill(d, 1, d.length, Integer.MAX_VALUE);
		int head = 0;
		int tail = 1;
		while (head < tail) {
			int edge = q[head++];
			int v = edges[edge].from;
			int u = edges[edge].to;
			for (int i : edgesList[u]) {
				BadWay way = new BadWay(v, u, edges[i].to);
				if (bad.contains(way)) {
					continue;
				}
				if (d[i] > d[edge] + 1) {
					d[i] = d[edge] + 1;
					q[tail++] = i;
					lastEdge[i] = edge;
				}
			}
		}
		int min = -1;
		for (int i = 0; i < edges.length; i++) {
			if (edges[i].to == n - 1 && d[i] != Integer.MAX_VALUE) {
				if (min == -1 || d[min] > d[i]) {
					min = i;
				}
			}
		}
		if (min == -1) {
			out.println(-1);
			return;
		}
		out.println(d[min]);
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = min; i >= 0; i = lastEdge[i]) {
			ans.add(edges[i].to);
		}
		Collections.reverse(ans);
		for (int i : ans) {
			out.print(1 + i + " ");
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
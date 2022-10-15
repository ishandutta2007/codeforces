import static java.util.Arrays.fill;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D implements Runnable {

	static List<Integer>[] edges;
	static boolean[] cycle;
	static boolean[] was;

	static boolean dfs(int v, int p, List<Integer> path) {
		was[v] = true;
		path.add(v);
		for (int e : edges[v]) {
			if (e == p) {
				continue;
			}
			if (was[e]) {
				int i = 0;
				while (path.get(i) != e) {
					i++;
				}
				while (i < path.size()) {
					cycle[path.get(i)] = true;
					i++;
				}
				return true;
			}
			if (dfs(e, v, path)) {
				return true;
			}
		}
		path.remove(path.size() - 1);
		return false;
	}

	void solve() {
		int n = nextInt();
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; i++) {
			int from = nextInt() - 1;
			int to = nextInt() - 1;
			edges[from].add(to);
			edges[to].add(from);
		}
		List<Integer> list = new ArrayList<Integer>();
		cycle = new boolean[n];
		was = new boolean[n];
		dfs(0, -1, list);
		Queue<Integer> q = new ArrayDeque<Integer>();
		int[] d = new int[n];
		fill(d, Integer.MAX_VALUE);
		for (int i = 0; i < n; i++) {
			if (cycle[i]) {
				q.add(i);
				d[i] = 0;
			}
		}
		while (!q.isEmpty()) {
			int v = q.poll();
			for (int i : edges[v]) {
				if (d[i] != Integer.MAX_VALUE) {
					continue;
				}
				d[i] = d[v] + 1;
				q.add(i);
			}
		}
		for (int i : d) {
			out.print(i + " ");
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
		new D().run();
	}
}
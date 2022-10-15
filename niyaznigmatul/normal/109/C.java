import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	static List<Integer> allLucky = new ArrayList<Integer>();
	static {
		allLucky.add(4);
		allLucky.add(7);
		for (int i = 0; i < allLucky.size(); i++) {
			int j = allLucky.get(i);
			{
				long e = j * 10L + 4;
				if (e < Integer.MAX_VALUE) {
					allLucky.add((int) e);
				}
			}

			{
				long e = j * 10L + 7;
				if (e < Integer.MAX_VALUE) {
					allLucky.add((int) e);
				}
			}
		}
	}

	static Set<Integer> luckies = new HashSet<Integer>();

	static {
		for (int i : allLucky) {
			luckies.add(i);
		}
	}

	static int[][] edges;
	static boolean[][] is;

	void solve() {
		n = nextInt();
		edges = new int[n][];
		is = new boolean[n][];
		int[] a = new int[n - 1];
		int[] b = new int[n - 1];
		boolean[] c = new boolean[n - 1];
		int[] deg = new int[n];
		for (int i = 0; i < n - 1; i++) {
			a[i] = nextInt() - 1;
			b[i] = nextInt() - 1;
			c[i] = luckies.contains(nextInt());
			deg[a[i]]++;
			deg[b[i]]++;
		}
		for (int i = 0; i < n; i++) {
			edges[i] = new int[deg[i]];
			is[i] = new boolean[deg[i]];
		}
		for (int i = 0; i < n - 1; i++) {
			edges[a[i]][--deg[a[i]]] = b[i];
			is[a[i]][deg[a[i]]] = c[i];
			edges[b[i]][--deg[b[i]]] = a[i];
			is[b[i]][deg[b[i]]] = c[i];
		}
		down = new int[n];
		count = new int[n];
		dfs(0, -1);
		ans = new long[n];
		dfs2(0, -1, 0);
		long answer = 0;
		for (int i = 0; i < n; i++) {
			answer += ans[i];
		}
		out.println(answer);
	}

	static void dfs(int v, int p) {
		count[v] = 1;
		down[v] = 0;
		for (int i = 0; i < edges[v].length; i++) {
			int e = edges[v][i];
			if (e == p) {
				continue;
			}
			dfs(e, v);
			count[v] += count[e];
			if (is[v][i]) {
				down[v] += count[e];
			} else {
				down[v] += down[e];
			}
		}
	}

	static void dfs2(int v, int p, int up) {
		long all = up + down[v];
		ans[v] = all * (all - 1);
		for (int i = 0; i < edges[v].length; i++) {
			int e = edges[v][i];
			if (e == p) {
				continue;
			}
			int newUp = is[v][i] ? (n - count[e]) : (up + down[v] - down[e]);
			dfs2(e, v, newUp);
		}
	}

	static int n;
	static long[] ans;
	static int[] count;
	static int[] down;

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
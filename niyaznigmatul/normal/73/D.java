import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	static int[][] edges;
	static boolean[] was;

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] deg = new int[n];
		for (int i = 0; i < m; i++) {
			from[i] = nextInt() - 1;
			to[i] = nextInt() - 1;
			deg[from[i]]++;
			deg[to[i]]++;
		}
		edges = new int[n][];
		for (int i = 0; i < n; i++) {
			edges[i] = new int[deg[i]];
		}
		for (int i = 0; i < m; i++) {
			edges[from[i]][--deg[from[i]]] = to[i];
			edges[to[i]][--deg[to[i]]] = from[i];
		}
		was = new boolean[n];
		int[] comp = new int[n + 1];
		int all = 0;
		for (int i = 0; i < n; i++) {
			if (was[i]) {
				continue;
			}
			comp[dfs(i)]++;
			all++;
		}
		if (k == 1) {
			out.println(Math.max(0, all - 2));
			return;
		}
		int can = 2;
		for (int i = 2; i <= n; i++) {
			can += comp[i] * (Math.min(i, k) - 2);
		}
		int ans = Math.max(0, comp[1] - can);
		ans = (ans + 1) / 2;
		out.println(ans);
	}

	static int dfs(int v) {
		was[v] = true;
		int ret = 1;
		for (int i = 0; i < edges[v].length; i++) {
			int e = edges[v][i];
			if (was[e]) {
				continue;
			}
			ret += dfs(e);
		}
		return ret;
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
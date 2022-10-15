import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	int[][] edges;
	int[][] edgesGCD;
	int[][] edgesLCM;
	boolean[] was;

	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}

	void solve() {
		int n = nextInt();
		int[] deg = new int[n];
		int m = nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		int[] c = new int[m];
		int[] d = new int[m];
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			deg[x]++;
			deg[y]++;
			a[i] = x;
			b[i] = y;
			c[i] = nextInt();
			d[i] = nextInt();
		}
		long[] lcm = new long[n];
		long[] gcd = new long[n];
		Arrays.fill(lcm, 1);
		Arrays.fill(gcd, 0);
		for (int i = 0; i < m; i++) {
			lcm[a[i]] = lcm(lcm[a[i]], c[i]);
			lcm[b[i]] = lcm(lcm[b[i]], c[i]);
			gcd[a[i]] = gcd(gcd[a[i]], d[i]);
			gcd[b[i]] = gcd(gcd[b[i]], d[i]);
		}
		edges = new int[n][];
		edgesGCD = new int[n][];
		edgesLCM = new int[n][];
		for (int i = 0; i < n; i++) {
			edges[i] = new int[deg[i]];
			edgesGCD[i] = new int[deg[i]];
			edgesLCM[i] = new int[deg[i]];
		}
		for (int i = 0; i < m; i++) {
			int cur = --deg[a[i]];
			edges[a[i]][cur] = b[i];
			edgesGCD[a[i]][cur] = c[i];
			edgesLCM[a[i]][cur] = d[i];
			cur = --deg[b[i]];
			edges[b[i]][cur] = a[i];
			edgesGCD[b[i]][cur] = c[i];
			edgesLCM[b[i]][cur] = d[i];
		}

		ArrayList<Integer> nums = new ArrayList<Integer>();
		was = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (was[i]) {
				continue;
			}
			nums.add(i);
			dfs1(i);
		}
		curTime = new int[n];
		ans = new int[n];
		for (int v : nums) {
			boolean ok = false;
			for (long i = lcm[v]; gcd[v] == 0 || i <= gcd[v]; i += lcm[v]) {
				// if (gcd[v] % i != 0) {
				// continue;
				// }
				++T;
				ans[v] = (int) i;
				if (dfs(v)) {
					ok = true;
					break;
				}
			}
			if (!ok) {
				out.println("NO");
				return;
			}
		}
		for (int i = 0; i < m; i++) {
			if (gcd(ans[a[i]], ans[b[i]]) == c[i]
					&& lcm(ans[a[i]], ans[b[i]]) == d[i]) {

			} else {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		for (int i : ans) {
			out.print(i + " ");
		}
	}

	boolean dfs(int x) {
		curTime[x] = T;
		for (int i = 0; i < edges[x].length; i++) {
			int e = edges[x][i];
			if (curTime[e] != T) {
				if ((long) edgesGCD[x][i] * edgesLCM[x][i] % ans[x] != 0) {
					return false;
				}
				long got = (long) edgesGCD[x][i] * edgesLCM[x][i] / ans[x];
				if (edgesLCM[x][i] % got != 0) {
					return false;
				}
				ans[e] = (int) (got);
				if (!dfs(e)) {
					return false;
				}
			}
		}
		return true;
	}

	int[] ans;
	int[] curTime;
	int T;

	void dfs1(int x) {
		was[x] = true;
		for (int i = 0; i < edges[x].length; i++) {
			int e = edges[x][i];
			if (!was[e]) {
				dfs1(e);
			}
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
		new C().run();
	}
}
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

	class E {
		int l, r;

		public E(int l, int r) {
			this.l = l;
			this.r = r;
		}

	}

	boolean dfs(int v, HashMap<Integer, Integer> hm, int[] ans, boolean[] was, boolean should) {
		if (was[v]) {
			return false;
		}
		was[v] = true;
		if (e[v].r - e[v].l <= 100) {
			for (int i = e[v].l; i <= e[v].r; i++) {
				if (!hm.containsKey(i) || dfs(hm.get(i), hm, ans, was, false)) {
					hm.put(i, v);
					ans[v] = i;
					return true;
				}
			}
		} else {
			for (int it = 0; should || it < 100; it++) {
				int i = rand.nextInt(e[v].r - e[v].l + 1) + e[v].l;
				if (!hm.containsKey(i) || dfs(hm.get(i), hm, ans, was, false)) {
					hm.put(i, v);
					ans[v] = i;
					return true;
				}
			}
		}
		return false;
	}

	final Random rand = new Random(this.hashCode());

	E[] e;

	void solve() {
		int n = nextInt();
		e = new E[n];
		for (int i = 0; i < e.length; i++) {
			e[i] = new E(nextInt(), nextInt());
		}
		HashMap<Integer, Integer> has = new HashMap<Integer, Integer>();
		int[] ans = new int[n];
		boolean[] was = new boolean[n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(was, false);
			dfs(i, has, ans, was, true);
		}
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
		}
	}
}
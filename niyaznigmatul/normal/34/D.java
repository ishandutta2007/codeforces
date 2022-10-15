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

	int[] head;
	int[] next;
	int[] v;
	int curEdge;

	void addEdge(int x, int y) {
		curEdge++;
		next[curEdge] = head[x];
		head[x] = curEdge;
		v[curEdge] = y;
	}

	int[] parent;

	void dfs(int x, int p) {
		parent[x] = p;
		for (int e = head[x]; e != 0; e = next[e]) {
			int i = v[e];
			if (i == p) {
				continue;
			}
			dfs(i, x);
		}
	}

	void solve() {
		int n = nextInt();
		int r1 = nextInt() - 1;
		int r2 = nextInt() - 1;
		head = new int[2 * (n - 1) + 1];
		next = new int[2 * (n - 1) + 1];
		v = new int[2 * (n - 1) + 1];
		curEdge = 0;
		for (int i = 0; i < n; i++) {
			if (i == r1) {
				continue;
			}
			int x = nextInt() - 1;
			addEdge(i, x);
			addEdge(x, i);
		}
		parent = new int[n];
		dfs(r2, -1);
		for (int i = 0; i < n; i++) {
			if (i == r2) {
				continue;
			}
			out.print(1 + parent[i] + " ");
		}
	}
}
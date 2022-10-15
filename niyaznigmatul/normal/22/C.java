import java.io.*;
import java.util.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new C().run();
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

	class Edge {
		int x, y;

		public Edge(int x, int y) {
			this.x = x;
			this.y = y;
		}

	}

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int v = nextInt();
		if (m < n - 1 || m > (n - 1) * (n - 2) / 2 + 1) {
			out.println("-1");
			return;
		}
		ArrayList<Edge> ans = new ArrayList<Edge>();
		for (int i = 2; i <= n; i++) {
			ans.add(new Edge(i - 1, i));
		}
		m -= n - 1;
		for (int i = 2; i <= n; i++) {
			if (m == 0) {
				break;
			}
			for (int j = i + 2; j <= n; j++) {
				if (m == 0) {
					break;
				}
				--m;
				ans.add(new Edge(i, j));
			}
		}
		int[] a = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
		a[v] = 2;
		a[2] = v;
		for (Edge e : ans) {
			e.x = a[e.x];
			e.y = a[e.y];
			out.println(e.x + " " + e.y);
		}
	}
}
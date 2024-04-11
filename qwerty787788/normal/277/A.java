import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	boolean[][] is;
	boolean[] was;
	int n;

	void go(int x) {
		was[x] = true;
		for (int to = 0; to < n; to++)
			if (is[x][to] && !was[to])
				go(to);
	}

	void solve() {
		n = in.nextInt();
		int m = in.nextInt();
		boolean[][] a = new boolean[n][m];
		int dontknow = 0;
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			for (int j = 0; j < x; j++)
				a[i][in.nextInt() - 1] = true;
			if (x == 0)
				dontknow ++;
		}
		if (dontknow == n) {
			out.println(n);
			return;
		}
		is = new boolean[n][n];
		for (int i = 0; i < m; i++) {
			for (int x = 0; x < n; x++)
				for (int y = 0; y < n; y++)
					if (a[x][i] && a[y][i])
						is[x][y] = true;
		}
		was = new boolean[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!was[i]) {
				go(i);
				ans++;
			}
		}
		out.println(ans - 1);
	}

	void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
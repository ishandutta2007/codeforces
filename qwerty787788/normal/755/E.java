import java.io.*;
import java.util.*;

public class E {
	FastScanner in;
	PrintWriter out;

	int getDiam(boolean[][] g) {
		int n = g.length;
		int[][] d = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(d[i], Integer.MAX_VALUE / 2);
			for (int j = 0; j < n; j++) {
				if (g[i][j]) {
					d[i][j] = 1;
				}
			}
			d[i][i] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					d[j][k] = Math.min(d[j][k], d[j][i] + d[i][k]);
				}
			}
		}
		int diam = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				diam = Math.max(diam, d[i][j]);
			}
		}
		return diam == Integer.MAX_VALUE / 2 ? -1 : diam;
	}

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		if (k == 3) {
			if (n >= 4) {
				out.println(3 + 2 * (n - 4));
				out.println("1 2");
				out.println("2 3");
				out.println("3 4");
				for (int id = 5; id <= n; id++) {
					out.println((id) + " " + 2);
					out.println((id) + " " + 3);
				}
			} else {
				out.println(-1);
			}
			return;
		}
		if (k == 2) {
			if (n >= 5) {
				out.println(4 + 2 * (n - 4));
				out.println("1 2");
				out.println("2 3");
				out.println("3 4");
				out.println("1 4");
				for (int id = 5; id <= n; id++) {
					out.println((id) + " " + 2);
					out.println((id) + " " + 3);
				}
			} else {
				out.println(-1);
			}
			return;
		}
		out.println(-1);
	}

	void solve123() {
		int n = 3;
		Random rnd = new Random(123);
		boolean[][] g = new boolean[n][n];
		boolean[] can = new boolean[n + 1];
		for (int it = 0; it < 123123; it++) {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					g[i][j] = g[j][i] = rnd.nextBoolean();
				}
			}
			int d1 = getDiam(g);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					g[i][j] = !g[i][j];
				}
			}
			int d2 = getDiam(g);
			int d = Math.min(d1, d2);
			if (d != -1) {
				can[d] = true;
			}
			System.err.println(Arrays.toString(can));
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new E().runIO();
	}
}
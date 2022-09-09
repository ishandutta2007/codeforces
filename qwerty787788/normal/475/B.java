import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int N = n * m;
		boolean[][] can = new boolean[N][N];
		for (int i = 0; i < N; i++)
			can[i][i] = true;
		String s = in.next();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '<') {
				for (int j = 1; j < m; j++) {
					can[i * m + j][i * m + j - 1] = true;
				}
			} else {
				for (int j = 0; j < m - 1; j++) {
					can[i * m + j][i * m + j + 1] = true;
				}
			}
		}
		s = in.next();
		for (int j = 0; j < s.length(); j++) {
			if (s.charAt(j) == '^') {
				for (int i = 1; i < n; i++) {
					can[i * m + j][(i - 1) * m + j] = true;
				}
			} else {
				for (int i = 0; i < n - 1; i++) {
					can[i * m + j][(i + 1) * m + j] = true;
				}
			}
		}
//		for (int i = 0; i < N; i++)
//			for (int j = 0; j < N; j++)
//				if (can[i][j]) {
//					System.err.println((i / m) + " " + (i % m) + " -> "
//							+ (j / m) + " " + (j % m));
//				}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					can[j][k] |= (can[j][i] && can[i][k]);
		boolean ok = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!can[i][j]) {
					ok = false;
				}
		out.println(ok ? "YES" : "NO");
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
		new CF().runIO();
	}
}
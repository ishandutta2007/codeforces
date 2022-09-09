import java.io.*;
import java.util.*;

public class CF229A {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++)
			s[i] = in.next();
		int[][] a = new int[n][3 * m];
		for (int i = 0; i < n; i++)
			for (int k = 0; k < 3; k++)
				for (int j = 0; j < m; j++)
					a[i][j + k * m] = s[i].charAt(j) == '0' ? 0 : 1;
		int[][][] best = new int[n][3 * m][2];
		for (int i = 0; i < n; i++) {
			int bestL = Integer.MIN_VALUE / 2;
			for (int j = 0; j < 3 * m; j++) {
				if (a[i][j] == 1)
					bestL = j;
				best[i][j][0] = bestL;
			}
			int bestR = Integer.MAX_VALUE / 2;
			for (int j = 3 * m - 1; j >= 0; j--) {
				if (a[i][j] == 1)
					bestR = j;
				best[i][j][1] = bestR;
			}
		}
		int[][] dist = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				dist[i][j] = Math.min(j + m - best[i][j + m][0], best[i][j + m][1] - j - m);
		long ans = Long.MAX_VALUE;
		for (int tr = 0; tr < m; tr++) {
			long sum = 0;
			for (int i = 0; i < n; i++)
				sum += dist[i][tr];
			ans = Math.min(ans, sum);
		}
		if (ans > Integer.MAX_VALUE / 4)
			ans = -1;
		out.println(ans);
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
	}

	public static void main(String[] args) {
		new CF229A().runIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;


	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		String[] s= new String[n];
		for (int i = 0; i < n; i++)
			s[i] = in.next();
		int[][] r = new int[n][m];
		int[][] u = new int[n][m];
		int[][] l = new int[n][m];
		for (int i = n - 1; i >= 0; i--)
			for (int j = 0; j < m;j++) {
				if (s[i].charAt(j) == 'R')
					r[i][j] = 1;
				if (s[i].charAt(j) == 'U' && (i % 2 == 0))
					u[i][j] = 1;
				if (s[i].charAt(j) == 'L')
					l[i][j] = 1;
				if (i < n -1 && j > 0)
					r[i][j] += r[i +1][j - 1];
				if (i < n - 1)
					u[i][j] += u[i + 1][j];
				if (i < n - 1 && j < m - 1)
					l[i][j] += l[i + 1][j + 1];
			}
		for (int i = 0; i < m;i++) {
			int val = r[0][i] + l[0][i] + u[0][i];
			out.print(val + " ");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

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
		new CF().runIO();
	}
}
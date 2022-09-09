import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int m = in.nextInt();
		int n = in.nextInt();
		if (n == 3) {
			if (m == 3) {
				out.println("0 0");
				out.println("10 0");
				out.println("0 10");
			} else {
				if (m == 4) {
					out.println("0 0");
					out.println("10 0");
					out.println("0 10");
					out.println("3 3");
				} else {
					out.println(-1);
				}
			}
		} else {
			if (n == 4) {
				int[][] ans = { { 176166, 6377 }, { 709276, 539564 },
						{ 654734, 174109 }, { 910147, 434207 },
						{ 790497, 366519 }, { 606663, 21061 },
						{ 859328, 886001 } };
				if (m == 8) {
					ans = new int[][] { { 60171, 23507 }, { 33886, 84554 },
							{ 57486, 88250 }, { 5906, 89174 },
							{ 79902, 76760 }, { 86185, 83750 },
							{ 78759, 74967 }, { 45472, 85367 } };
				}
				for (int i = 0; i < m; i++)
					out.println(ans[i][0] + " " + ans[i][1]);

			} else {
				int[] x = new int[n];
				int[] y = new int[n];
				double r = 7 * 1e7;
				for (int i = 0; i < n; i++) {
					double angle = (i + 0.) / n * 2 * Math.PI;
					x[i] = (int) (r * Math.cos(angle));
					y[i] = (int) (r * Math.sin(angle));
					out.println(x[i] + " " + y[i]);
				}
				double addAngle = 0. / n * Math.PI;
				r = 1e3;
				for (int i = 0; i < n; i++) {
					double angle = addAngle + (i + 0.) / n * 2 * Math.PI;
					x[i] = (int) (r * Math.cos(angle) + r + r);
					y[i] = (int) (r * Math.sin(angle) + 7);
					if (n + i < m)
						out.println(x[i] + " " + y[i]);
				}
			}
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
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
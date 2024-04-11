import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		boolean[][] r = new boolean[n][n];
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			r[fr][to] = r[to][fr] = true;
		}
		int[][] cnt = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				for (int k = 0; k < n; k++)
					if (r[i][k] && r[j][k]) {
						cnt[i][j]++;
						cnt[j][i]++;
					}
		long res = 0;
		for (int i1 = 0; i1 < n; i1++)
			for (int i2 = 0; i2 < n; i2++)
				if (r[i1][i2])
					for (int i3 = 0; i3 < n; i3++)
						if (i3 != i1 && i3 != i2) {
							int c1 = cnt[i3][i1];
							if (r[i2][i3])
								c1--;
							int c2 = cnt[i3][i2];
							if (r[i1][i3])
								c2--;
							res += c1 * 1L * c2;
						}
		int[] neighbors = new int[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (r[i][j])
					neighbors[i]++;
		for (int i1 = 0; i1 < n; i1++)
			for (int i2 = i1 + 1; i2 < n; i2++)
				if (r[i1][i2])
					for (int i3 = i2 + 1; i3 < n; i3++)
						if (r[i1][i3] && r[i2][i3]) {
							res -= 2 * (neighbors[i1] - 2);
							res -= 2 * (neighbors[i2] - 2);
							res -= 2 * (neighbors[i3] - 2);
						}
		out.println(res / 10);
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
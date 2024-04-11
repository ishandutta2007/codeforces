import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] t = new int[n];
		int sum = 1;
		for (int i = 0; i < n; i++) {
			t[i] = in.nextInt();
			sum += t[i];
		}
		t[0]--;
		final int MAX = sum * 2 + 1;
		boolean[][] res = new boolean[MAX][MAX];
		int[][] dir = new int[MAX][MAX];
		dir[MAX / 2][MAX / 2] = 1;
		res[MAX / 2][MAX / 2] = true;
		int[][] dir2 = new int[MAX][MAX];
		int[] dx = new int[] { 0, -1, -1, -1, 0, 1, 1, 1 };
		int[] dy = new int[] { 1, 1, 0, -1, -1, -1, 0, 1 };
		for (int o = 0; o < n; o++) {
			for (int it = 0; it < t[o]; it++) {
				for (int i = 0; i < MAX; i++) {
					Arrays.fill(dir2[i], 0);
				}
				for (int i = 0; i < MAX; i++) {
					for (int j = 0; j < MAX; j++) {
						for (int k = 0; k < 8; k++) {
							if (((1 << k) & dir[i][j]) != 0) {
								int ni = i + dx[k];
								int nj = j + dy[k];
								dir2[ni][nj] |= 1 << k;
								res[ni][nj] = true;
							}
						}
					}
				}
				int[][] tmp = dir;
				dir = dir2;
				dir2 = tmp;
			}
			{
				for (int i = 0; i < MAX; i++) {
					Arrays.fill(dir2[i], 0);
				}
				for (int i = 0; i < MAX; i++) {
					for (int j = 0; j < MAX; j++) {
						for (int k = 0; k < 8; k++) {
							if (((1 << k) & dir[i][j]) != 0) {
								for (int dk = -1; dk < 2; dk += 2) {
									dir2[i][j] |= 1 << ((k + dk + 8) % 8);
								}
							}
						}
					}
				}
				int[][] tmp = dir;
				dir = dir2;
				dir2 = tmp;
			}

		}
		int ans = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				ans += res[i][j] ? 1 : 0;
			}
		}
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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {

	int gcd(int x, int y) {
		return x == 0 ? y : gcd(y % x, x);
	}

	ArrayList<Integer>[] gr;

	boolean[] was;

	void go(int v) {
		was[v] = true;
		for (int i = 0; i < gr[v].size(); i++)
			if (!was[gr[v].get(i)])
				go(gr[v].get(i));
	}

	boolean connected(int[][] a) {
		int n = a.length;
		int m = a[0].length;
		int[] qx = new int[n * m];
		int[] qy = new int[n * m];
		int it = 0, sz = 0;
		int stX = -1, stY = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1) {
					stX = i;
					stY = j;
				}
		sz = 1;
		qx[0] = stX;
		qy[0] = stY;
		boolean[][] was = new boolean[n][m];
		was[stX][stY] = true;
		while (it < sz) {
			int x = qx[it];
			int y = qy[it++];
			for (int ite = 0; ite < 4; ite++) {
				int nx = x + dx[ite];
				int ny = y + dy[ite];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (was[nx][ny] || a[nx][ny] == 0)
						continue;
					was[nx][ny] = true;
					qx[sz] = nx;
					qy[sz++] = ny;
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!was[i][j] && a[i][j] == 1)
					return false;
		return true;
	}

	int[] dx = { -1, 0, 0, 1 };
	int[] dy = { 0, -1, 1, 0 };

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = in.nextInt();
		if (!connected(a)) {
			out.println(-1);
			return;
		}
		int[][] c = new int[n][m];
		for (int i = 0; i < n; i++) {
			c[i] = a[i].clone();
		}

		int[][] sum = new int[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sum[i + 1][j + 1] = c[i][j] + sum[i][j + 1] + sum[i + 1][j]
						- sum[i][j];
			}
		}

		int[][] b = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1) {
					boolean[] h = new boolean[4];
					for (int it = 0; it < 4; it++) {
						int nx = i + dx[it];
						int ny = j + dy[it];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m)
							if (a[nx][ny] == 1)
								h[it] = true;
					}
					if ((h[0] || h[3]) && (h[1] || h[2]))
						b[i][j] = 1;
					int cc = 0;
					for (int ii = 0; ii < 4; ii++)
						if (h[ii])
							cc++;
					if (cc == 1)
						b[i][j] = 1;
				}
		a = b;
		boolean[] hasX = new boolean[n];
		boolean[] hasY = new boolean[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1) {
					hasX[i] = true;
					hasY[j] = true;
				}
		int minX = -1, minY = -1;
		for (int i = 0; i < n; i++)
			if (hasX[i]) {
				minX = i;
				break;
			}
		for (int i = 0; i < m; i++)
			if (hasY[i]) {
				minY = i;
				break;
			}
		int g = 0;
		for (int i = 0; i < n; i++) {
			if (hasX[i])
				g = gcd(g, i - minX);
		}
		for (int i = 0; i < m; i++)
			if (hasY[i])
				g = gcd(g, i - minY);
		if (g <= 1) {
			out.println(-1);
			return;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (c[i][j] == 1 && (i - minX) % g == 0 && (j - minY) % g == 0)
					a[i][j] = 1;
		int[][] id = new int[n][m];
		for (int i = 0; i < n; i++)
			Arrays.fill(id[i], -1);
		int sz = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1) {
					id[i][j] = sz++;
				}
		}
		gr = new ArrayList[sz];
		for (int i = 0; i < sz; i++)
			gr[i] = new ArrayList<>();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1) {
					for (int it = 0; it < 4; it++) {
						int nx = i + dx[it] * g;
						int ny = j + dy[it] * g;
						if (nx >= 0 && nx < n && ny >= 0 && ny < m)
							if (a[nx][ny] == 1) {
								if (sum(sum, i, j, nx, ny) == g + 1) {
									gr[id[i][j]].add(id[nx][ny]);
								}
							}
					}
				}
		was = new boolean[sz];
		int cnt = 0;
		for (int i = 0; i < sz; i++) {
			if (gr[i].size() % 2 != 0) {
				cnt++;
			}
		}
		if (cnt != 0 && cnt != 2) {
			out.println(-1);
			return;
		}
		for (int i = 2; i <= g; i++)
			if (g % i == 0) {
				out.print(i + " ");
			}
	}

	private int sum(int[][] sum, int i, int j, int nx, int ny) {

		int r1 = Math.min(i, nx), c1 = Math.min(j, ny);
		int r2 = Math.max(i, nx), c2 = Math.max(j, ny);
		
		return sum[r2 + 1][c2 + 1] - sum[r1][c2 + 1] - sum[r2 + 1][c1] + sum[r1][c1];
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
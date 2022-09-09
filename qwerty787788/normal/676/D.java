import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		int[] dx = new int[] { 0, 1, 0, -1 };
		int[] dy = new int[] { -1, 0, 1, 0 };
		String s = "+-|^><vLRUD*";
		// <v>^
		int[] rev = new int[] { 2, 3, 0, 1 };
		String[] can = new String[] { "1111", "1010", "0101", "0001", "0010",
				"1000", "0100", "0111", "1101", "1110", "1011", "0000" };
		int[][][] d = new int[4][n][m];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				Arrays.fill(d[i][j], Integer.MAX_VALUE);
			}
		}
		int sz = 4 * n * m;
		int[] qR = new int[sz];
		int[] qX = new int[sz];
		int[] qY = new int[sz];
		int qSz = 1;
		int qIt = 0;
		qR[0] = 0;
		int xs = in.nextInt() - 1;
		int ys = in.nextInt() - 1;
		qX[0] = xs;
		qY[0] = ys;
		int xe = in.nextInt() - 1;
		int ye = in.nextInt() - 1;
		d[0][xs][ys] = 0;
		while (qIt < qSz) {
			int rot = qR[qIt], x = qX[qIt], y = qY[qIt];
			qIt++;
			{
				int nrot = (rot + 1) % 4;
				if (d[nrot][x][y] > d[rot][x][y] + 1) {
					d[nrot][x][y] = d[rot][x][y] + 1;
					qR[qSz] = nrot;
					qX[qSz] = x;
					qY[qSz++] = y;
				}
			}
			for (int it = 0; it < 4; it++) {
				int nx = x + dx[it], ny = y + dy[it];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				if (d[rot][nx][ny] <= d[rot][x][y] + 1) {
					continue;
				}
				if (can[s.indexOf(a[x][y])].charAt((it + rot) % 4) == '0') {
					continue;
				}
				if (can[s.indexOf(a[nx][ny])].charAt(rev[(it + rot) % 4]) == '0') {
					continue;
				}
				d[rot][nx][ny] = d[rot][x][y] + 1;
				qR[qSz] = rot;
				qX[qSz] = nx;
				qY[qSz++] = ny;
			}
		}
		int res = Integer.MAX_VALUE;
		for (int it = 0; it < 4; it++) {
			res = Math.min(res, d[it][xe][ye]);
		}
		out.println(res == Integer.MAX_VALUE ? -1 : res);
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test2.out"));

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
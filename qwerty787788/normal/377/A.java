import java.io.*;
import java.util.*;

public class CF {

	int[] dx = new int[] { -1, 0, 0, 1 };
	int[] dy = new int[] { 0, -1, 1, 0 };

	int n, m, k;

	char[][] res;
	boolean[][] was;

	void go(int x, int y) {
		if (x < 0 || x >= n)
			return;
		if (y < 0 || y >= m)
			return;
		if (was[x][y])
			return;
		if (res[x][y] == '#')
			return;
		was[x][y] = true;
		for (int it = 0; it < 4; it++) {
			go(x + dx[it], y + dy[it]);
		}
		if (k > 0) {
			k--;
			res[x][y] = 'X';
		}
	}

	void solve() {
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++)
			s[i] = in.next();
		res = new char[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = s[i].charAt(j);
		was = new boolean[n][m];
		boolean f = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (!f && res[i][j] == '.') {
					go(i, j);
					f = true;
				}
			}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				out.print(res[i][j]);
			}
			out.println();
		}
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
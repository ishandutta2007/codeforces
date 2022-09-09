import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[][] cId;
	int comps = 0;

	int[] dx = new int[] { -1, 0, 0, 1 };
	int[] dy = new int[] { 0, -1, 1, 0 };
	int n;

	void go(int x, int y) {
		if (x < 0 || y < 0 || x >= n || y >= n) {
			return;
		}
		if (cId[x][y] != -1 || a[x][y] == 'X') {
			return;
		}
		cId[x][y] = comps;
		for (int it = 0; it < dx.length; it++) {
			go(x + dx[it], y + dy[it]);
		}
	}
	char[][] a;

	void solve() {
		n = in.nextInt();
		int k = in.nextInt();
		a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		cId = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(cId[i], -1);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cId[i][j] == -1 && a[i][j] == '.') {
					go(i, j);
					comps++;
				}
			}
		}
		sz = new int[comps];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cId[i][j] != -1) {
					sz[cId[i][j]]++;
				}
			}
		}
		int best = 0;
		int[][] sum = new int[n + 1][n + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
				if (a[i][j] == '.') {
					sum[i + 1][j + 1]++;
				}
			}
		}
		cnt = new int[comps];
		for (int stX = 0; stX + k <= n; stX++) {
			Arrays.fill(cnt, 0);
			sumSizes = k * k;
			for (int i = 0; i < k; i++) {
				for (int j = -1; j <= k; j++) {
					add(stX + i, j);
				}
			}
			for (int i = 0; i < k; i++) {
				add(stX - 1, i);
				add(stX + k, i);
			}
			for (int stY = 0; stY + k <= n; stY++) {
				int curAns = sum[stX + k][stY + k] - sum[stX][stY + k]
						- sum[stX + k][stY] + sum[stX][stY];
				curAns = -curAns + sumSizes;
				best = Math.max(best, curAns);
				for (int i = 0; i < k; i++) {
					rem(stX + i, stY - 1);
					add(stX + i, stY + k + 1);
				}
				rem(stX - 1, stY);
				rem(stX + k, stY);
				add(stX - 1, stY + k);
				add(stX + k, stY + k);
			}
		}
		out.println(best);
	}

	int sumSizes;

	void add(int x, int y) {
		if (x < 0 || x >= n || y < 0 || y >= n) {
			return;
		}
		if (cId[x][y] == -1) {
			return;
		}
		cnt[cId[x][y]]++;
		if (cnt[cId[x][y]] == 1) {
			sumSizes += sz[cId[x][y]];
		}
	}

	void rem(int x, int y) {
		if (x < 0 || x >= n || y < 0 || y >= n) {
			return;
		}
		if (cId[x][y] == -1) {
			return;
		}
		cnt[cId[x][y]]--;
		if (cnt[cId[x][y]] == 0) {
			sumSizes -= sz[cId[x][y]];
		}
	}

	int[] cnt;
	int[] sz;

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
import java.io.*;
import java.util.*;

public class CF {

	String[] s;
	int n, m;
	int[][] d;

	boolean cycle = false;

	String type = "^v<>";
	int[] dx = { 0, 0, -1, 1 };
	int[] dy = { -1, 1, 0, 0 };
	int[][] color;
	int[] qI, qJ;
	int qit, qsz;

	int getDist(int i, int j) {
		if (color[i][j] == 1)
			return Integer.MAX_VALUE;
		if (d[i][j] != -1)
			return d[i][j];
		if (s[i].charAt(j) == '#')
			return 0;
		color[i][j] = 1;
		qI[qsz] = i;
		qJ[qsz++] = j;
		int qst = qit;
		while (qit < qsz) {
			int ii = qI[qit];
			int jj = qJ[qit++];
			if (s[ii].charAt(jj) == '#') {
				d[ii][jj] = 0;
				continue;
			}
			int v = type.indexOf(s[ii].charAt(jj));
			int nx = ii + dy[v];
			int ny = jj + dx[v];
			if (color[nx][ny] == 1) {
				cycle = true;
				return Integer.MAX_VALUE;
			} else {
				if (color[nx][ny] == 0) {
					color[nx][ny] = 1;
					qI[qsz] = nx;
					qJ[qsz++] = ny;
				}
			}
		}
		for (int it = qit - 1; it >= qst; it--) {
			int ii = qI[it];
			int jj = qJ[it];
			color[ii][jj] = 2;
			if (s[ii].charAt(jj) == '#') {
				d[ii][jj] = 0;
				continue;
			}
			int v = type.indexOf(s[ii].charAt(jj));
			int nx = ii + dy[v];
			int ny = jj + dx[v];
			d[ii][jj] = 1 + d[nx][ny];
		}
		return d[i][j];
	}

	boolean[][] used;

	boolean go(int i, int j) {
		if (s[i].charAt(j) == '#')
			return true;
		if (used[i][j])
			return false;
		qI[qsz] = i;
		qJ[qsz++] = j;
		used[i][j] = true;
		while (qit < qsz) {
			int ii = qI[qit];
			int jj = qJ[qit++];
			if (s[ii].charAt(jj) == '#')
				return true;
			int v = type.indexOf(s[ii].charAt(jj));
			int nx = ii + dy[v];
			int ny = jj + dx[v];
			if (used[nx][ny])
				return false;
			qI[qsz] = nx;
			qJ[qsz++] = ny;
			if (s[nx].charAt(ny) != '#')
				used[nx][ny] = true;
		}
		return true;
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		s = new String[n];
		for (int i = 0; i < n; i++)
			s[i] = in.next();
		d = new int[n][m];
		qI = new int[n * m * 2];
		qJ = new int[n * m * 2];
		color = new int[n][m];
		for (int i = 0; i < n; i++)
			Arrays.fill(d[i], -1);
		int maxDist = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				d[i][j] = getDist(i, j);
				maxDist = Math.max(maxDist, d[i][j]);
			}
		if (cycle) {
			out.println(-1);
			return;
		}
		used = new boolean[n][m];
		int num = 0;
		qit = 0;
		qsz = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (d[i][j] == maxDist)
					if (go(i, j))
						num++;
			}
		if (num > 1) {
			out.println(maxDist * 2);
		} else {
			out.println(Math.max(0, maxDist * 2 - 1));
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
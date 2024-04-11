import java.io.*;
import java.util.*;
import java.math.*;

public class J implements Runnable {
	public static void main(String[] args) {
		new J().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	void solve() {
		int n = nextInt();
		int m = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < c.length; i++) {
			c[i] = nextToken().toCharArray();
		}
		int black = 0;
		int white = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] == 'b') {
					black++;
				}
				if (c[i][j] == 'w') {
					white++;
				}
			}
		}
		if (black * 2 != white) {
			out.println("NO");
			return;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] != 'b') {
					continue;
				}
				if (!check(c, i, j, 0, 2) && !check(c, i, j, 1, 3)) {
					out.println("NO");
					return;
				}
			}
		}
		Queue<Pair> q = new ArrayDeque<Pair>();
		HashSet<Pair> was = new HashSet<J.Pair>();
		char[][] ans = new char[n][m];
		for (int i = 0; i < ans.length; i++) {
			Arrays.fill(ans[i], '.');
		}
		while (true) {
			boolean added = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (c[i][j] != 'b') {
						continue;
					}
					if (!check(c, i, j, 0, 2) || !check(c, i, j, 1, 3)) {
						Pair e = new Pair(i, j);
						q.add(e);
						was.add(e);
						added = true;
					}
				}
			}
			if (!added) {
				break;
			}
			while (!q.isEmpty()) {
				Pair p = q.poll();
				if (check(c, p.x, p.y, 0, 2)) {
					char ch = getColor(ans, p.x, p.y, 0, 2);
					if (ch >= 'e') {
						out.println("NO");
						return;
					}
					color(ans, c, p.x, p.y, 0, 2, ch);
					addBros(q, was, c, p.x, p.y, 0, 2);
				} else if (check(c, p.x, p.y, 1, 3)) {
					char ch = getColor(ans, p.x, p.y, 1, 3);
					if (ch >= 'e') {
						out.println("NO");
						return;
					}
					color(ans, c, p.x, p.y, 1, 3, ch);
					addBros(q, was, c, p.x, p.y, 1, 3);
				} else {
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
		for (int i = 0; i < ans.length; i++) {
			out.println(new String(ans[i]));
		}
	}

	private void addBros(Queue<Pair> q, HashSet<Pair> was, char[][] c, int x,
			int y, int dir1, int dir2) {
		addBros(q, was, c, x + DX[dir1], y + DY[dir1]);
		addBros(q, was, c, x + DX[dir2], y + DY[dir2]);
	}

	private void addBros(Queue<Pair> q, HashSet<Pair> was, char[][] c, int x,
			int y) {
		for (int dir = 0; dir < DX.length; dir++) {
			int xx = x + DX[dir];
			int yy = y + DY[dir];
			if (xx < 0 || yy < 0 || xx >= c.length || yy >= c[0].length
					|| c[xx][yy] != 'b') {
				continue;
			}
			if (!check(c, xx, yy, 0, 2) || !check(c, xx, yy, 1, 3)) {
				Pair e = new Pair(xx, yy);
				if (!was.contains(e)) {
					q.add(e);
					was.add(e);
				}
			}
		}
	}

	private void color(char[][] ans, char[][] c, int x, int y, int dir1,
			int dir2, char ch) {
		c[x + DX[dir1]][y + DY[dir1]] = c[x + DX[dir2]][y + DY[dir2]] = c[x][y] = '.';
		ans[x + DX[dir1]][y + DY[dir1]] = ans[x + DX[dir2]][y + DY[dir2]] = ans[x][y] = ch;
	}

	char getColor(char[][] c, int x, int y, int dir1, int dir2) {
		boolean[] was = new boolean[5];
		mark(c, was, x + DX[dir1], y + DY[dir1]);
		mark(c, was, x, y);
		mark(c, was, x + DX[dir2], y + DY[dir2]);
		for (int i = 0; i < was.length; i++) {
			if (!was[i]) {
				return (char) (i + 'a');
			}
		}
		return 'e';
	}

	void mark(char[][] c, boolean[] was, int x, int y) {
		if (x < 0 || y < 0 || x >= c.length || y >= c[0].length) {
			return;
		}
		for (int dir = 0; dir < DX.length; dir++) {
			int xx = x + DX[dir];
			int yy = y + DY[dir];
			if (xx < 0 || yy < 0 || xx >= c.length || yy >= c[0].length
					|| c[xx][yy] == '.') {
				continue;
			}
			was[c[xx][yy] - 'a'] = true;
		}
	}

	class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		private J getOuterType() {
			return J.this;
		}

	}

	final int[] DX = { 1, 0, -1, 0 };
	final int[] DY = { 0, 1, 0, -1 };

	boolean check(char[][] c, int x, int y, int dir1, int dir2) {
		return check(c, x, y, dir1) && check(c, x, y, dir2);
	}

	boolean check(char[][] c, int x, int y, int dir) {
		int xx = x + DX[dir];
		int yy = y + DY[dir];
		return (xx >= 0 && yy >= 0 && xx < c.length && yy < c[0].length && c[xx][yy] == 'w');
	}
}
import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

	static final int[] DX = { 1, 0, -1, 0 };
	static final int[] DY = { 0, 1, 0, -1 };

	void solve() {
		long time = System.currentTimeMillis();
		n = nextInt();
		m = nextInt();
		c = new char[n][m];
		for (int i = 0; i < n; i++) {
			c[i] = nextToken().toCharArray();
		}
		w = new int[n][m];
		for (int i = 0; i < n; i++) {
			Arrays.fill(w[i], -1);
		}
		char[][] d = new char[n][];
		for (int i = 0; i < n; i++) {
			d[i] = c[i].clone();
		}
		int nextOne = 0;
		blockX = new int[ALL_BLOCKS];
		blockY = new int[ALL_BLOCKS];
		while (true) {
			boolean found = false;
			all: for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (d[i][j] != '.') {
						if (i + 1 >= n || j + 1 >= m || d[i + 1][j] == '.'
								|| d[i][j + 1] == '.' || d[i + 1][j + 1] == '.') {
							throw new AssertionError();
						}
						w[i][j] = w[i + 1][j] = w[i][j + 1] = w[i + 1][j + 1] = nextOne;
						d[i][j] = d[i + 1][j] = d[i][j + 1] = d[i + 1][j + 1] = '.';
						blockX[nextOne] = i;
						blockY[nextOne] = j;
						found = true;
						break all;
					}
				}
			}
			if (!found) {
				break;
			}
			nextOne++;
		}
		boolean[][] hasEdge;
		hasEdge = new boolean[ALL_BLOCKS][ALL_BLOCKS];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] == '.') {
					continue;
				}
				for (int dir = 0; dir < 4; dir++) {
					int x = i + DX[dir];
					int y = j + DY[dir];
					if (x < 0 || y < 0 || x >= n || y >= m
							|| c[x][y] != c[i][j]) {
						continue;
					}
					hasEdge[w[x][y]][w[i][j]] = hasEdge[w[i][j]][w[x][y]] = true;
				}
			}
		}
		edges = new int[ALL_BLOCKS][];
		for (int i = 0; i < ALL_BLOCKS; i++) {
			int cnt = 0;
			for (int j = 0; j <= i; j++) {
				if (hasEdge[i][j]) {
					cnt++;
				}
			}
			edges[i] = new int[cnt];
			for (int j = 0, k = 0; j <= i; j++) {
				if (hasEdge[i][j]) {
					edges[i][k++] = j;
				}
			}
		}
		color = new int[nextOne];
		Arrays.fill(color, -1);
		out.println(go(0));
		for (int i = 0; i < n; i++) {
			out.println(new String(answer[i]));
		}
		System.err.println(System.currentTimeMillis() - time);
	}

	static int[][] edges;
	final static int ALL_BLOCKS = 14;
	static int[] chosen = new int[7];
	static boolean[][] was = new boolean[7][7];
	static int[] blockX;
	static int[] blockY;
	final static int[] OFFSET_X = { 0, 0, 1, 1 };
	final static int[] OFFSET_Y = { 0, 1, 0, 1 };
	static int n;
	static int m;
	static char[][] c;
	static int[] color;
	static int[][] w;
	static char[][] answer;

	static void check() {
		for (int i = 0; i < 7; i++) {
			for (int j = i; j < 7; j++) {
				if (!was[i][j]) {
					System.err.println(i + " " + j);
					System.err.println(Arrays.toString(color));
					throw new AssertionError();
				}
			}
		}
	}

	static int go(int curBlock) {
		if (curBlock == ALL_BLOCKS) {
			if (answer == null) {
				answer = new char[n][m];
				for (int i = 0; i < n; i++) {
					Arrays.fill(answer[i], '.');
				}
				for (int i = 0; i < ALL_BLOCKS; i++) {
					for (int j = 0; j < 4; j++) {
						answer[blockX[i] + OFFSET_X[j]][blockY[i] + OFFSET_Y[j]] = (char) (color[i] + '0');
					}
				}
			}
			return 1;
		}
		int ret = 0;
		for (int i = 0; i < chosen.length; i++) {
			if (curBlock == 0 && i > 0) {
				ret *= 42;
				break;
			}
			if (curBlock == 1 && i > 1) {
				break;
			}
			if (chosen[i] == 2) {
				continue;
			}
			color[curBlock] = i;
			if (!check(curBlock)) {
				color[curBlock] = -1;
				continue;
			}
			chosen[i]++;
			process(curBlock, true);
			ret += go(curBlock + 1);
			process(curBlock, false);
			chosen[i]--;
			color[curBlock] = -1;
		}
		return ret;
	}

	static boolean check(int curBlock) {
		int colorWas = 0;
		for (int j : edges[curBlock]) {
			int c1 = color[j];
			int c2 = color[curBlock];
			if (((colorWas >> c1) & 1) == 1) {
				return false;
			}
			colorWas |= 1 << c1;
			if (c1 > c2) {
				int t = c1;
				c1 = c2;
				c2 = t;
			}
			if (was[c1][c2]) {
				return false;
			}
		}
		return true;
	}

	static void process(int curBlock, boolean what) {
		for (int j : edges[curBlock]) {
			int c1 = color[j];
			int c2 = color[curBlock];
			if (c1 > c2) {
				int t = c1;
				c1 = c2;
				c2 = t;
			}
			was[c1][c2] = what;
		}
	}

	// static int go(int curBlock) {
	// if (curBlock == ALL_BLOCKS) {
	// return 1;
	// }
	// int mask = 0;
	// for (int i = 0; i < chosen.length; i++) {
	// mask *= 3;
	// mask += chosen[i];
	// }
	// if (dict[curBlock][mask] >= 0) {
	// return dict[curBlock][mask];
	// }
	// int ret = 0;
	// for (int i = 0; i < chosen.length; i++) {
	// if (chosen[i] == 2) {
	// continue;
	// }
	// color[curBlock] = i;
	// if (!check(curBlock)) {
	// color[curBlock] = -1;
	// continue;
	// }
	// chosen[i]++;
	// process(curBlock, true);
	// ret += go(curBlock + 1);
	// process(curBlock, false);
	// chosen[i]--;
	// color[curBlock] = -1;
	// }
	// return dict[curBlock][mask] = ret;
	// }
	//
	// static boolean process(int curBlock, boolean what) {
	// for (int j = 0; j < 4; j++) {
	// int x = blockX[curBlock] + OFFSET_X[j];
	// int y = blockY[curBlock] + OFFSET_Y[j];
	// int col = color[w[x][y]];
	// for (int dir = 0; dir < 4; dir++) {
	// int xx = x + DX[dir];
	// int yy = y + DY[dir];
	// if (xx >= n || yy >= m || xx < 0 || yy < 0
	// || c[xx][yy] != c[x][y]) {
	// continue;
	// }
	// int c1 = col;
	// int c2 = color[w[xx][yy]];
	// if (c1 == -1 || c2 == -1) {
	// continue;
	// }
	// if (c1 > c2) {
	// int t = c1;
	// c1 = c2;
	// c2 = t;
	// }
	// was[c1][c2] = what;
	// }
	// }
	// return true;
	// }
	//
	// static boolean check(int curBlock) {
	// for (int j = 0; j < 4; j++) {
	// int x = blockX[curBlock] + OFFSET_X[j];
	// int y = blockY[curBlock] + OFFSET_Y[j];
	// int col = color[w[x][y]];
	// for (int dir = 0; dir < 4; dir++) {
	// int xx = x + DX[dir];
	// int yy = y + DY[dir];
	// if (xx >= n || yy >= m || xx < 0 || yy < 0
	// || c[xx][yy] != c[x][y]) {
	// continue;
	// }
	// int c1 = col;
	// int c2 = color[w[xx][yy]];
	// if (c1 == -1 || c2 == -1) {
	// continue;
	// }
	// if (c1 > c2) {
	// int t = c1;
	// c1 = c2;
	// c2 = t;
	// }
	// if (was[c1][c2]) {
	// return false;
	// }
	// }
	// }
	// return true;
	// }

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

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
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

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}
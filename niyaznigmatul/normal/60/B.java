import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	void solve() {

		n = nextInt();
		m = nextInt();
		k = nextInt();
		c = new char[n][m][];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c[i][j] = nextToken().toCharArray();
			}
		}
		int x = nextInt() - 1;
		int y = nextInt() - 1;
		was = new boolean[n][m][k];
		out.println(dfs(0, x, y));
	}

	boolean[][][] was;
	char[][][] c;
	int n;
	int m;
	int k;
	final int[] DX = { 1, 0, -1, 0, 0, 0 };
	final int[] DY = { 0, 1, 0, -1, 0, 0 };
	final int[] DZ = { 0, 0, 0, 0, 1, -1 };

	int dfs(int x, int y, int z) {
		was[x][y][z] = true;
		int ret = 1;
		for (int dir = 0; dir < DX.length; dir++) {
			int xx = x + DX[dir];
			int yy = y + DY[dir];
			int zz = z + DZ[dir];
			if (xx < 0 || yy < 0 || zz < 0 || xx >= n || yy >= m || zz >= k
					|| c[xx][yy][zz] == '#' || was[xx][yy][zz]) {
				continue;
			}
			ret += dfs(xx, yy, zz);
		}
		return ret;
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
		new B().run();
	}
}
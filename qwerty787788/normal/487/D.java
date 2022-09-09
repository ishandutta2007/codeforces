import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int n, m;
	char[][] a;

	int UNKNOWN = -10;
	int CYCLE = -11;

	class SegmentTree {
		int xFrom, xTo;
		int[] upRowX, upRowY, downRowX, downRowY;
		SegmentTree up, down;

		SegmentTree(int xFrom, int xTo) {
			this.xFrom = xFrom;
			this.xTo = xTo;
			upRowX = new int[m];
			downRowX = new int[m];
			upRowY = new int[m];
			downRowY = new int[m];
			if (xFrom != xTo) {
				int mid = (xTo + xFrom) >> 1;
				up = new SegmentTree(xFrom, mid);
				down = new SegmentTree(mid + 1, xTo);
				update();
			} else {
				Arrays.fill(upRowX, UNKNOWN);
				Arrays.fill(downRowX, UNKNOWN);
				for (int y = 0; y < m; y++) {
					get(xFrom, y);
				}
			}
		}

		void get(int x, int y) {
			if (upRowX[y] != UNKNOWN) {
				return;
			}
			upRowX[y] = downRowX[y] = CYCLE;
			char c = a[x][y];
			if (c == '^') {
				upRowX[y] = downRowX[y] = x - 1;
				upRowY[y] = downRowY[y] = y;
				return;
			}
			if (c == '<') {
				if (y == 0) {
					upRowX[y] = downRowX[y] = x;
					upRowY[y] = downRowY[y] = -1;
				} else {
					get(x, y - 1);
					upRowX[y] = downRowX[y] = upRowX[y - 1];
					upRowY[y] = downRowY[y] = upRowY[y - 1];
				}
			}
			if (c == '>') {
				if (y == m - 1) {
					upRowX[y] = downRowX[y] = x;
					upRowY[y] = downRowY[y] = m;
				} else {
					get(x, y + 1);
					upRowX[y] = downRowX[y] = upRowX[y + 1];
					upRowY[y] = downRowY[y] = upRowY[y + 1];
				}
			}
		}

		void update() {
			for (int i = 0; i < m; i++) {
				upRowX[i] = up.upRowX[i];
				upRowY[i] = up.upRowY[i];
			}
			for (int i = 0; i < m; i++) {
				int x1 = down.downRowX[i];
				int y1 = down.downRowY[i];
				if (x1 == down.xFrom - 1) {
					int nX = up.downRowX[y1];
					int nY = up.downRowY[y1];
					x1 = nX;
					y1 = nY;
				}
				downRowX[i] = x1;
				downRowY[i] = y1;
			}
		}

		void update(int x) {
			if (xFrom == xTo) {
				Arrays.fill(upRowX, UNKNOWN);
				Arrays.fill(downRowX, UNKNOWN);
				for (int y = 0; y < m; y++) {
					get(xFrom, y);
				}
			} else {
				int mid = (xFrom + xTo) >> 1;
				if (mid >= x) {
					up.update(x);
				} else {
					down.update(x);
				}
				update();
			}
		}

		Pair getAns(int x, int y) {
			if (xFrom == xTo) {
				return new Pair(upRowX[y], upRowY[y]);
			}
			int mid = (xFrom + xTo) >> 1;
			if (mid >= x) {
				Pair p = up.getAns(x, y);
				return p;
			} else {
				Pair p = down.getAns(x, y);
				if (p.x == CYCLE) {
					return p;
				}
				if (p.x == down.xFrom - 1) {
					int nx = up.downRowX[p.y];
					int ny = up.downRowY[p.y];
					p.x = nx;
					p.y = ny;
				}
				return p;
			}
		}

	}

	class Pair {
		int x, y;

		public Pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	void solve() {
		n = in.nextInt();
		m = in.nextInt();
		int q = in.nextInt();
		a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		SegmentTree st = new SegmentTree(0, n - 1);
		for (int i = 0; i < q; i++) {
			if (in.next().equals("C")) {
				int x = in.nextInt() - 1;
				int y = in.nextInt() - 1;
				a[x][y] = in.next().charAt(0);
				st.update(x);
			} else {
				int x = in.nextInt() - 1;
				int y = in.nextInt() - 1;
				Pair p = st.getAns(x, y);
				if (p.x == CYCLE) {
					out.println("-1 -1");
				} else {
					out.println((p.x + 1) + " " + (p.y + 1));
				}
			}
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

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
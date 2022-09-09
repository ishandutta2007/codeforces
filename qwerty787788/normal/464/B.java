import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[][] coords;
	int[] x = new int[8];
	int[] y = new int[8];
	int[] z = new int[8];

	class Obj implements Comparable<Obj> {
		int id;
		long dist;

		public Obj(int id, long dist) {
			super();
			this.id = id;
			this.dist = dist;
		}

		@Override
		public int compareTo(Obj o) {
			return Long.compare(dist, o.dist);
		}

	}

	Obj[] all = new Obj[8];
	boolean[] used = new boolean[8];

	boolean go(int v) {
		if (v == 8) {
			for (int i = 0; i < n; i++) {
				all[i].id = i;
				long dx = x[i] - x[0];
				long dy = y[i] - y[0];
				long dz = z[i] - z[0];
				all[i].dist = dx * dx + dy * dy + dz * dz;
			}
			Arrays.sort(all);
			Arrays.fill(used, false);
			boolean ok = true;
			if (all[1].dist != all[2].dist || all[1].dist != all[3].dist
					|| all[1].dist == 0) {
				ok = false;
			}
			for (int x1 = 0; x1 < 2; x1++)
				for (int y1 = 0; y1 < 2; y1++)
					for (int z1 = 0; z1 < 2; z1++) {
						int myX = x[0], myY = y[0], myZ = z[0];
						if (x1 == 1) {
							myX += x[all[1].id] - x[0];
							myY += y[all[1].id] - y[0];
							myZ += z[all[1].id] - z[0];
						}
						if (y1 == 1) {
							myX += x[all[2].id] - x[0];
							myY += y[all[2].id] - y[0];
							myZ += z[all[2].id] - z[0];
						}
						if (z1 == 1) {
							myX += x[all[3].id] - x[0];
							myY += y[all[3].id] - y[0];
							myZ += z[all[3].id] - z[0];
						}
						boolean f = false;
						for (int i = 0; i < 8; i++)
							if (x[i] == myX && y[i] == myY && z[i] == myZ)
								if (!used[i]) {
									used[i] = true;
									f = true;
									break;
								}
						if (!f) {
							ok = false;
							break;
						}
					}
			if (ok) {
				out.println("YES");
				for (int i = 0; i < n; i++) {
					out.println(x[i] + " " + y[i] + " " + z[i]);
				}
				return true;
			}
		} else {
			for (int x1 = 0; x1 < 3; x1++)
				for (int y1 = 0; y1 < 3; y1++)
					if (x1 != y1) {
						if (v == 0 && (x1 != 0 || y1 != 1))
							continue;
						int z1 = 0 + 1 + 2 - x1 - y1;
						x[v] = coords[x1][v];
						y[v] = coords[y1][v];
						z[v] = coords[z1][v];
						if (go(v + 1))
							return true;
					}
		}
		return false;
	}

	int n = 8;

	void solve() {
		coords = new int[3][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				coords[j][i] = in.nextInt();
		for (int i = 0; i < n; i++) {
			all[i] = new Obj(0, 0);
		}
		if (!go(0)) {
			out.println("NO");
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
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Point {
		double x, y;

		public Point(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	Point rotat(Point a, int angl) {
		double angle = angl / 180. * Math.PI;
		double cos = Math.cos(angle);
		double sin = Math.sin(angle);
		double x = a.x * cos + a.y * sin;
		double y = -a.x * sin + a.y * cos;
		return new Point(x, y);
	}

	class SegmentTree {
		int[] angle;
		Point[] d;

		SegmentTree(int n) {
			angle = new int[n * 4];
			d = new Point[n * 4];
			build(0, 0, n - 1);
		}

		void build(int v, int l, int r) {
			if (l == r) {
				d[v] = new Point(1, 0);
				angle[v] = 0;
			} else {
				int m = (l + r) >> 1;
				build(v * 2 + 1, l, m);
				build(v * 2 + 2, m + 1, r);
				d[v] = new Point(0, 0);
				update(v);
			}
		}

		void update(int v) {
			angle[v] = (angle[v * 2 + 1] + angle[v * 2 + 2]) % 360;
			Point o = rotat(d[v * 2 + 2], angle[v * 2 + 1]);
			d[v].x = d[v * 2 + 1].x + o.x;
			d[v].y = d[v * 2 + 1].y + o.y;
		}

		void add(int v, int l, int r, int needPos, int addV) {
			if (l == r) {
				double curLen = Math.sqrt(d[v].x * d[v].x + d[v].y * d[v].y);
				double mul = (addV + curLen) / curLen;
				d[v].x *= mul;
				d[v].y *= mul;
			} else {
				int m = (l + r) >> 1;
				if (m >= needPos) {
					add(v * 2 + 1, l, m, needPos, addV);
				} else {
					add(v * 2 + 2, m + 1, r, needPos, addV);
				}
				update(v);
			}
		}

		void rotate(int v, int l, int r, int needPos, int a) {
			if (l == r) {
				angle[v] += a;
				angle[v] %= 360;
				d[v] = rotat(d[v], a);
			} else {
				int m = (l + r) >> 1;
				if (m >= needPos) {
					rotate(v * 2 + 1, l, m, needPos, a);
				} else {
					rotate(v * 2 + 2, m + 1, r, needPos, a);
				}
				update(v);
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		SegmentTree st = new SegmentTree(n);
		for (int i = 0; i < m; i++) {
			if (in.nextInt() == 1) {
				int id = in.nextInt() - 1;
				int add = in.nextInt();
				st.add(0, 0, n - 1, id, add);
			} else {
				int id = in.nextInt() - 1;
				int angle = in.nextInt();
				st.rotate(0, 0, n - 1, id, angle);
			}
			out.println(st.d[0].x + " " + st.d[0].y);
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
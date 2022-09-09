import java.io.*;
import java.util.*;

public class E {

	class Point implements Comparable<Point> {
		int type;
		int x, y;

		public Point(int type, int x, int y) {
			super();
			this.type = type;
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Point o) {
			if (x == o.x) {
				if (y == o.y) {
					return Integer.compare(type, o.type);
				}
				return Integer.compare(o.y, y);
			}
			return Integer.compare(x, o.x);
		}

	}

	int vectMul(Point a, Point b, Point c) {
		long res = (b.x - a.x) * 1L * (c.y - a.y) - (b.y - a.y) * 1L
				* (c.x - a.x);
		return Long.signum(res);
	}

	private void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		in.nextInt();
		in.nextInt();
		Point[] a = new Point[n + m];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(1, in.nextInt(), in.nextInt());
		}
		for (int i = 0; i < m; i++) {
			a[n + i] = new Point(2, in.nextInt(), in.nextInt());
		}
		Arrays.sort(a);
		ArrayList<Point> all = new ArrayList<E.Point>();
		for (Point p : a) {
			if (all.size() > 0 && all.get(all.size() - 1).x == p.x
					&& all.get(all.size() - 1).y == p.y) {
				continue;
			}
			while (all.size() > 1
					&& vectMul(all.get(all.size() - 2),
							all.get(all.size() - 1), p) > 0) {
				all.remove(all.size() - 1);
			}
//			if (all.size() == 1 && all.get(all.size() - 1).x == p.x) {
//				continue;
//			}
			if (all.size() == 1 && all.get(all.size() - 1).y < p.y) {
				all.remove(all.size() - 1);
			}
			all.add(p);
		}
		boolean secondWin = true;
		for (Point p : all) {
			if (p.type == 1) {
				secondWin = false;
				break;
			}
		}
		out.println(secondWin ? "Min" : "Max");
	}

	class FastScanner {
		StringTokenizer st;
		BufferedReader br;

		FastScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return null;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					return null;
				}
			}
			return st.nextToken();
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					return false;
				}
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

	FastScanner in;
	PrintWriter out;

	void runFile() {
		in = new FastScanner("a.in");
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	public static void main(String[] args) {
		new E().run();
	}
}
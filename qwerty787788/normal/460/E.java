import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Point implements Comparable<Point> {
		int x, y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Point o) {
			if (x == o.x)
				return Integer.compare(y, o.y);
			return Integer.compare(x, o.x);
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}

	}

	int vectMul(Point a, Point b, Point c) {
		int val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
		return Integer.signum(val);
	}

	ArrayList<Point> convexHull(ArrayList<Point> pts) {
		Collections.sort(pts);
		ArrayList<Point> down = new ArrayList<>();
		ArrayList<Point> up = new ArrayList<>();
		Point f = pts.get(0);
		Point s = pts.get(pts.size() - 1);
		for (int i = 0; i < pts.size(); i++) {
			Point cur = pts.get(i);
			if (vectMul(f, s, cur) >= 0) {
				// up
				while (up.size() > 1
						&& vectMul(up.get(up.size() - 2),
								up.get(up.size() - 1), cur) >= 0) {
					up.remove(up.size() - 1);
				}
				up.add(cur);
			}
			if (vectMul(f, s, cur) <= 0) {
				// down
				while (down.size() > 1
						&& vectMul(down.get(down.size() - 2),
								down.get(down.size() - 1), cur) <= 0) {
					down.remove(down.size() - 1);
				}
				down.add(cur);
			}
		}
		down.addAll(up.subList(1, up.size() - 1));
		return down;
	}

	ArrayList<Point> all;

	void go(int from, int curCnt, int curSum, int sumX, int sumY, int sumX2,
			int sumY2) {
		if (from == all.size())
			return;
		if (curCnt == need) {
			if (curSum > bestSum) {
				bestSum = curSum;
				for (int i = 0; i < need; i++)
					best[i] = res[i];
			}
		} else {
			go(from + 1, curCnt, curSum, sumX, sumY, sumX2, sumY2);
			curSum += all.get(from).x * all.get(from).x * curCnt + sumX2 - 2 * sumX * all.get(from).x;
			curSum += all.get(from).y * all.get(from).y * curCnt + sumY2 - 2 * sumY * all.get(from).y;
			res[curCnt++] = all.get(from);
			sumX += all.get(from).x;
			sumX2 += all.get(from).x * all.get(from).x;
			sumY += all.get(from).y;
			sumY2 += all.get(from).y * all.get(from).y;
			go(from, curCnt, curSum, sumX, sumY, sumX2, sumY2);
		}
	}

	Point[] res;
	Point[] best;

	long bestSum = -1;
	int need;

	void solve() {
		need = in.nextInt();
		int r = in.nextInt();
		all = new ArrayList<>();
		for (int x = -r; x <= r; x++)
			for (int y = -r; y <= r; y++)
				if (x * x + y * y <= r * r)
					all.add(new Point(x, y));
		all = convexHull(all);
		Collections.sort(all, new Comparator<Point>() {

			@Override
			public int compare(Point o1, Point o2) {
				int d1 = o1.x * o1.x + o1.y * o1.y;
				int d2 = o2.x * o2.x + o2.y * o2.y;
				return -Integer.compare(d1, d2);
			}
		});
		ArrayList<Point> tmp = new ArrayList<>();
		tmp.addAll(all.subList(0, Math.min(32, all.size())));
		all = tmp;
		res = new Point[need];
		best = new Point[need];
		go(0, 0, 0, 0, 0, 0, 0);
		out.println(bestSum);
		for (int i = 0; i < need; i++) {
			out.println(best[i].x + " " + best[i].y);
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
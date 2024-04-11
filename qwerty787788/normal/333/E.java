import java.io.*;
import java.util.*;

public class CF {

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

	}

	boolean cw(Point a, Point b, Point c) {
		return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
	}

	boolean ccw(Point a, Point b, Point c) {
		return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
	}

	ArrayList<Point> getConvexHull(ArrayList<Point> a) {
		ArrayList<Point> res = new ArrayList<>();
		if (a.size() <= 1 || a.size() > 500) {
			return a;
		}
		Point p1 = a.get(0);
		Point p2 = a.get(a.size() - 1);
		ArrayList<Point> up = new ArrayList<>();
		ArrayList<Point> down = new ArrayList<>();
		up.add(p1);
		down.add(p2);
		for (int i = 1; i < a.size(); ++i) {
			if (i == a.size() - 1 || cw(p1, a.get(i), p2)) {
				while (up.size() >= 2
						&& !cw(up.get(up.size() - 2), up.get(up.size() - 1),
								a.get(i)))
					up.remove(up.size() - 1);
				up.add(a.get(i));
			}
			if (i == a.size() - 1 || ccw(p1, a.get(i), p2)) {
				while (down.size() >= 2
						&& !ccw(down.get(down.size() - 2),
								down.get(down.size() - 1), a.get(i)))
					down.remove(down.size() - 1);
				down.add(a.get(i));
			}
		}
		for (int i = 0; i < up.size(); ++i)
			res.add(up.get(i));
		for (int i = down.size() - 2; i > 0; --i)
			res.add(down.get(i));
		return res;
	}

	int dist(Point p1, Point p2) {
		int dx = p1.x - p2.x;
		int dy = p1.y - p2.y;
		return dx * dx + dy * dy;
	}

	int maxDist(ArrayList<Point> a) {
		if (a.size() <= 1)
			return 0;
		a = getConvexHull(a);
		int ans = 0;
		int n = a.size();
		int curBestId = 0;
		int bestDist = 0;
		for (int i = 0; i < n; i++) {
			bestDist = dist(a.get(i), a.get(curBestId));
			while (true) {
				int next = (curBestId + 1);
				if (next == n)
					next = 0;
				int dd = dist(a.get(i), a.get(next));
				if (dd >= bestDist) {
					bestDist = dd;
					curBestId = next;
				} else {
					break;
				}
			}
			if (bestDist > ans)
				ans = bestDist;
		}
		return ans;
	}

	void realSolve() throws IOException {
		int n = in.nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++)
			a[i] = new Point(in.nextInt(), in.nextInt());
		Arrays.sort(a);
		int l = 0, r = 500000000;
		while (r - l > 1) {
			int m = (l + r) / 2;
			boolean ok = false;
			for (int first = 0; first < n; first++) {
				ArrayList<Point> allOk = new ArrayList<>();
				for (int i = 0; i < n; i++)
					if (dist(a[first], a[i]) >= m)
						allOk.add(a[i]);
				int dmax = maxDist(allOk);
				if (dmax >= m) {
					ok = true;
					break;
				}
			}
			if (ok) {
				l = m;
			} else {
				r = m;
			}
		}
		out.println(Math.sqrt(l) / 2);
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
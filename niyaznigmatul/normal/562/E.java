import java.io.*;
import java.util.*;

public class E {

	static void solve() throws IOException {
		int m = in.nextInt();
		int n = in.nextInt();
		in.nextInt();
		in.nextInt();
		Point[] q = new Point[m];
		for (int i = 0; i < m; i++) {
			q[i] = new Point(in.nextInt(), in.nextInt(), 1);
		}
		Point[] p = new Point[n + 3];
		long maxY = 0;
		long maxX = 0;
		for (int i = 0; i < n; i++) {
			p[i] = new Point(in.nextInt(), in.nextInt(), 0);
			maxY = Math.max(maxY, p[i].y);
			maxX = Math.max(maxX, p[i].x);
		}
		p[n] = new Point(0, 0, 2);
		p[n + 1] = new Point(0, maxY, 2);
		p[n + 2] = new Point(maxX, 0, 2);
		Point[] z = convexHull(p);
		for (Point e : q) {
			int l = 1;
			int r = z.length - 1;
			while (l < r - 1) {
				int mid = (l + r) >> 1;
				if ((long) z[mid].x * e.y - (long) e.x * z[mid].y >= 0) {
					l = mid;
				} else {
					r = mid;
				}
			}
			long la = z[l + 1].y - z[l].y;
			long lb = z[l].x - z[l + 1].x;
			long lc = -z[l].x * la - z[l].y * lb;
			if (la * e.x + lb * e.y + lc >= 0) {
				out.println("Max");
				return;
			}
		}
		out.println("Min");
	}

	static Point[] convexHull(Point[] p) {
		p = p.clone();
		for (int i = 0; i < p.length; i++) {
			if (p[i].x < p[0].x || p[i].x == p[0].x && p[i].y < p[0].y) {
				Point t = p[i];
				p[i] = p[0];
				p[0] = t;
			}
		}
		final Point first = p[0];
		Arrays.sort(p, 1, p.length, new Comparator<Point>() {
			@Override
			public int compare(Point o1, Point o2) {
				long x1 = o1.x - first.x;
				long y1 = o1.y - first.y;
				long x2 = o2.x - first.x;
				long y2 = o2.y - first.y;
				int c = Long.signum(x1 * y2 - x2 * y1);
				if (c != 0)
					return -c;
				return Long.signum(x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2);
			}
		});
		int sz = 2;
		for (int i = 2; i < p.length; i++) {
			while (sz > 1 && vmulFromPoint(p[sz - 2], p[sz - 1], p[i]) <= 0) {
				--sz;
			}
			p[sz++] = p[i];
		}
		return Arrays.copyOf(p, sz);
	}

	static long vmulFromPoint(Point first, Point o1, Point o2) {
		long x1 = o1.x - first.x;
		long y1 = o1.y - first.y;
		long x2 = o2.x - first.x;
		long y2 = o2.y - first.y;
		return x1 * y2 - x2 * y1;
	}

	static class Point {
		long x;
		long y;
		int type;

		public Point(long x, long y, int type) {
			this.x = x;
			this.y = y;
			this.type = type;
		}

	}

	static InputReader in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	static class InputReader {
		BufferedReader br;

		public InputReader(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
		}

		public int nextInt() throws IOException {
			int c = br.read();
			while (c <= 32) {
				c = br.read();
			}
			boolean negative = false;
			if (c == '-') {
				negative = true;
				c = br.read();
			}
			int x = 0;
			while (c > 32) {
				x = x * 10 + c - '0';
				c = br.read();
			}
			return negative ? -x : x;
		}

		public long nextLong() throws IOException {
			int c = br.read();
			while (c <= 32) {
				c = br.read();
			}
			boolean negative = false;
			if (c == '-') {
				negative = true;
				c = br.read();
			}
			long x = 0;
			while (c > 32) {
				x = x * 10 + c - '0';
				c = br.read();
			}
			return negative ? -x : x;
		}

		public String next() throws IOException {
			int c = br.read();
			while (c <= 32) {
				c = br.read();
			}
			StringBuilder sb = new StringBuilder();
			while (c > 32) {
				sb.append((char) c);
				c = br.read();
			}
			return sb.toString();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}
}
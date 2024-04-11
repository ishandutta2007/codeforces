import java.io.*;
import java.util.*;

public class F {
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

	class Event implements Comparable<Event> {
		double time;
		int type;

		// 0 - first come somewhere
		// 1 - second come somewhere
		// 2 - ids change
		public Event(double time, int type) {
			super();
			this.time = time;
			this.type = type;
		}

		@Override
		public int compareTo(Event o) {
			return Double.compare(time, o.time);
		}

	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(in.nextInt(), in.nextInt());
		}
		double sumLen = 0;
		int[] dLen = new int[n];
		for (int i = 0; i < n; i++) {
			double dx = a[(i + 1) % n].x - a[i].x;
			double dy = a[(i + 1) % n].y - a[i].y;
			dLen[i] = (int) (Math.abs(dx) + Math.abs(dy));
			sumLen += dLen[i];
		}
		double diff = sumLen / m;
		int firstPos = 0;
		int secondPos = 0;
		double timeFirst = 0;
		double timeSecond = diff;
		while (dLen[secondPos] <= timeSecond) {
			timeSecond -= dLen[secondPos];
			secondPos++;
		}
		ArrayList<Event> events = new ArrayList<>();
		for (int i = 1; i <= m; i++) {
			events.add(new Event(i * diff, 2));
		}
		double now = 0;
		for (int i = 0; i < n; i++) {
			now += dLen[i];
			events.add(new Event(now, 0));
			if (now > diff) {
				events.add(new Event(now - diff, 1));
			} else {
				events.add(new Event(now - diff + sumLen, 1));
			}
		}
		Collections.sort(events);
		double curTime = 0;
		int currentIds = 0;
		ArrayList<Segment> segments = new ArrayList<>();
		for (Event e : events) {
			double dTime = e.time - curTime;
			if (dTime > eps) {
				Point firstFrom = getPosition(a[firstPos],
						a[(firstPos + 1) % n], timeFirst);
				Point secondFrom = getPosition(a[secondPos], a[(secondPos + 1)
						% n], timeSecond);

				timeFirst += dTime;
				timeSecond += dTime;

				Point firstTo = getPosition(a[firstPos], a[(firstPos + 1) % n],
						timeFirst);
				Point secondTo = getPosition(a[secondPos], a[(secondPos + 1)
						% n], timeSecond);
				segments.add(new Segment(currentIds, curTime - currentIds
						* diff, curTime - currentIds * diff + dTime, sub(
						firstFrom, secondFrom), sub(firstTo, secondTo)));
			}
			curTime = e.time;
			if (e.type == 2) {
				currentIds++;
			}
			if (e.type == 0) {
				firstPos = (firstPos + 1) % n;
				timeFirst = 0;
			}
			if (e.type == 1) {
				secondPos = (secondPos + 1) % n;
				timeSecond = 0;
			}
		}
		double left = 0, right = 1e4;

		OkEvent[] ev = new OkEvent[segments.size() * 2];
		for (int i = 0; i < ev.length; i++) {
			ev[i] = new OkEvent(0, 0, 0);
		}
		int[] cnt = new int[m + 2];
		final int M = 25;
		if (ok(1, segments, ev, cnt, m)) {
			right = 1;
			for (int iter = 0; iter < M; iter++){
				double mid = (left + right) / 2;
				if (ok(mid, segments, ev, cnt, m)) {
					right = mid;
				} else {
					left = mid;
				}
			}
		} else {
			left = 1;
			for (int iter = 0; iter < M; iter++) {
				double mid = Math.sqrt(left * right);
				if (ok(mid, segments, ev, cnt, m)) {
					right = mid;
				} else {
					left = mid;
				}
			}
		}
		out.println((left + right) / 2);
	}
	
	boolean ok(double mid, ArrayList<Segment> segments, OkEvent[] ev, int[] cnt, int m) {
		boolean ok = false;
		int evSz = 0;
		for (Segment s : segments) {
			double[] roots = solveSq(s, mid);
			if (roots == null || roots[0] > roots[1]) {
				continue;
			}
			double tFrom = roots[0], tTo = roots[1];
			ev[evSz].id = s.id;
			ev[evSz].time = s.left + (s.right - s.left) * tFrom;
			ev[evSz].type = 1;
			evSz++;
			ev[evSz].id = s.id;
			ev[evSz].time = s.left + (s.right - s.left) * tTo;
			ev[evSz].type = -1;
			evSz++;
		}
		Arrays.sort(ev, 0, evSz);
		int nowOk = 0;
		for (int i = 0; i < evSz; i++) {
			OkEvent e = ev[i];
			cnt[e.id] += e.type;
			if (cnt[e.id] == 0) {
				nowOk--;
			}
			if (cnt[e.id] == 1 && e.type == 1) {
				nowOk++;
				if (nowOk == m) {
					ok = true;
				}
			}
		}
		return ok;
	}

	double[] solveSq(Segment s, double mid) {
		double A = (s.from.x - s.to.x) * (s.from.x - s.to.x)
				+ (s.from.y - s.to.y) * (s.from.y - s.to.y);
		double B = 2 * (s.from.x * (s.to.x - s.from.x) + s.from.y
				* (s.to.y - s.from.y));
		double C = s.from.x * s.from.x + s.from.y * s.from.y - mid * mid;
		// A t^2 + B t + C <= 0
		double tFrom, tTo;
		if (Math.abs(A) <= eps) {
			// B *t <= -C
			if (Math.abs(B) <= eps) {
				if (C <= 0) {
					tFrom = 0;
					tTo = 1;
				} else {
					return null;
				}
			} else {
				if (B > 0) {
					tTo = -C / B;
					tFrom = 0;
				} else {
					tFrom = -C / B;
					tTo = 1;
				}
			}
		} else {
			double d = B * B - 4 * A * C;
			if (d < 0) {
				return null;
			}
			tFrom = (-B - Math.sqrt(d)) / (2 * A);
			tTo = (-B + Math.sqrt(d)) / (2 * A);
		}
		tFrom = Math.max(tFrom, 0);
		tTo = Math.min(tTo, 1);
		return new double[] { tFrom, tTo };
	}

	final double eps = 1e-9;

	class OkEvent implements Comparable<OkEvent> {
		int id;
		int type;
		double time;

		public OkEvent(int id, int type, double time) {
			super();
			this.id = id;
			this.type = type;
			this.time = time;
		}

		@Override
		public int compareTo(OkEvent o) {
			return Double.compare(time, o.time);
		}

	}

	Point sub(Point a, Point b) {
		return new Point(a.x - b.x, a.y - b.y);
	}

	Point getPosition(Point from, Point to, double time) {
		double tot = Math.abs(to.x - from.x) + Math.abs(to.y - from.y);
		double alpha = time / tot;
		return new Point(to.x * alpha + from.x * (1 - alpha), to.y * alpha
				+ from.y * (1 - alpha));
	}

	class Segment {
		int id;
		double left, right;
		Point from, to;
		double A, B, C;

		public Segment(int id, double left, double right, Point from, Point to) {
			super();
			this.id = id;
			this.left = left;
			this.right = right;
			this.from = from;
			this.to = to;
			A = from.y - to.y;
			B = to.x - from.x;
			C = -(from.x * A + from.y * B);
		}

	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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
		new F().runIO();
	}
}
import java.io.*;
import java.util.*;

public class E {
	FastScanner in;
	PrintWriter out;

	final int mod = (int) 1e9 + 7;

	class Segment implements Comparable<Segment> {
		int id;
		int h, l, r, s;
		int ans;

		public Segment(int id, int h, int l, int r, int s) {
			super();
			this.id = id;
			this.h = h;
			this.l = l;
			this.r = r;
			this.s = s;
		}

		@Override
		public int compareTo(Segment o) {
			return Integer.compare(h, o.h);
		}

		boolean willUse(int y) {
			return y <= h + s;
		}
	}

	ArrayList<Integer>[] ids;
	Segment[] segments;

	Segment max(Segment s1, Segment s2) {
		if (s1 == null) {
			return s2;
		}
		if (s2 == null) {
			return s1;
		}
		return s1.h > s2.h ? s1 : s2;
	}

	Segment getSegment(int v, int l, int r, int x, int y) {
		Segment res = null;
		while (ids[v].size() > 0) {
			Segment s = segments[ids[v].get(ids[v].size() - 1)];
			if (s.willUse(y)) {
				res = max(res, s);
				break;
			} else {
				ids[v].remove(ids[v].size() - 1);
			}
		}
		if (l != r) {
			int mid = (l + r) >> 1;
			if (mid >= x) {
				res = max(res, getSegment(v * 2 + 1, l, mid, x, y));
			} else {
				res = max(res, getSegment(v * 2 + 2, mid + 1, r, x, y));
			}
		}
		return res;
	}

	int w;

	int getAns(int x, int y) {
		Segment s = getSegment(0, 0, w - 1, x, y);
		if (s != null) {
			return s.ans;
		}
		return 1;
	}

	void addSegment(int v, int l, int r, Segment s) {
		if (s.l <= l && s.r >= r) {
			ids[v].add(s.id);
			return;
		}
		if (s.l > r || s.r < l) {
			return;
		}
		int mid = (l + r) >> 1;
		addSegment(v * 2 + 1, l, mid, s);
		addSegment(v * 2 + 2, mid + 1, r, s);
	}

	void solve() {
		int h = in.nextInt();
		w = in.nextInt();
		int n = in.nextInt();
		segments = new Segment[n];
		ids = new ArrayList[4 * w];
		for (int i = 0; i < ids.length; i++) {
			ids[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			segments[i] = new Segment(i, in.nextInt(), in.nextInt() - 1,
					in.nextInt() - 1, in.nextInt());
		}
		Arrays.sort(segments);
		for (int i = 0; i < n; i++) {
			segments[i].id = i;
		}
		for (int i = 0; i < n; i++) {
			Segment s = segments[i];
			if (s.l != 0) {
				s.ans += getAns(s.l - 1, s.h);
			} else {
				s.ans += getAns(s.r + 1, s.h);
			}
			if (s.r != w - 1) {
				s.ans += getAns(s.r + 1, s.h);
			} else {
				s.ans += getAns(s.l - 1, s.h);
			}
			if (s.ans >= mod) {
				s.ans -= mod;
			}
			addSegment(0, 0, w - 1, s);
		}
		long result = 0;
		for (int i = 0; i < w; i++) {
			result += getAns(i, h + 1);
		}
		out.println(result % mod);
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
		new E().runIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Segment implements Comparable<Segment> {
		int from, to, value;

		public Segment(int from, int to, int value) {
			super();
			this.from = from;
			this.to = to;
			this.value = value;
		}

		@Override
		public int compareTo(Segment o) {
			if (from == o.from) {
				return Integer.compare(to, o.to);
			}
			return Integer.compare(from, o.from);
		}

		@Override
		public String toString() {
			return "Segment [from=" + from + ", to=" + to + ", value=" + value
					+ "]";
		}

	}

	void addSegment(TreeSet<Segment> segments, Segment cur) {
		while (true) {
			Segment tmp = segments.lower(new Segment(cur.to, Integer.MAX_VALUE,
					0));
			if (tmp == null) {
				segments.add(cur);
				break;
			}
			if (tmp.value >= cur.value) {
				if (tmp.to < cur.to) {
					segments.add(new Segment(tmp.to + 1, cur.to, cur.value));
				}
				return;
			}
			if (tmp.to < cur.from) {
				segments.add(cur);
				break;
			}
			segments.remove(tmp);
			if (tmp.to > cur.to) {
				segments.add(new Segment(cur.to + 1, tmp.to, tmp.value));
			}
			if (tmp.from < cur.from) {
				segments.add(new Segment(tmp.from, cur.from - 1, tmp.value));
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

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		private CF getOuterType() {
			return CF.this;
		}

	}

	void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		TreeSet<Segment> ySegm = new TreeSet<>();
		ySegm.add(new Segment(1, n, 0));
		TreeSet<Segment> xSegm = new TreeSet<>();
		xSegm.add(new Segment(1, n, 0));
		HashSet<Pair> allPairs = new HashSet<>();
		for (int i = 0; i < q; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			String dir = in.next();
			boolean goesUp = dir.charAt(0) == 'U';
			Pair now = new Pair(x, y);
			if (allPairs.contains(now)) {
				out.println(0);
				continue;
			}
			allPairs.add(now);
			if (goesUp) {
				Segment seg = ySegm.lower(new Segment(x, Integer.MAX_VALUE, 0));
				int curLen = y - seg.value;
				out.println(curLen);
				if (curLen != 0) {
					addSegment(xSegm, new Segment(y - curLen + 1, y, x));
				}
			} else {
				Segment seg = xSegm.lower(new Segment(y, Integer.MAX_VALUE, 0));
				int curLen = x - seg.value;
				out.println(curLen);
				if (curLen != 0) {
					addSegment(ySegm, new Segment(x - curLen + 1, x, y));
				}
			}
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
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
import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	static class Segment {
		int l;
		int r;

		public Segment(int l, int r) {
			super();
			this.l = l;
			this.r = r;
		}

		@Override
		public String toString() {
			return "Segment [l=" + l + ", r=" + r + "]";
		}

	}

	static class SegmentTree {
		static class Node {
			Node l;
			Node r;
			int sum;
		}

		Node root;
		int n;

		public SegmentTree(int n) {
			this.n = n;
			root = new Node();
		}

		int getSum(Node v, int l, int r, int left, int right) {
			if (v == null) {
				return 0;
			}
			if (l <= left && right <= r) {
				return v.sum;
			}
			if (r <= left || right <= l) {
				return 0;
			}
			int m = (left + right) >> 1;
			return getSum(v.l, l, r, left, m) + getSum(v.r, l, r, m, right);
		}

		int getSum(int l, int r) {
			return getSum(root, l, r, 0, n);
		}

		void add(int x, int y) {
			Node v = root;
			int l = 0;
			int r = n;
			while (l < r - 1) {
				v.sum += y;
				int m = (l + r) >> 1;
				if (x < m) {
					if (v.l == null) {
						v.l = new Node();
					}
					v = v.l;
					r = m;
				} else {
					if (v.r == null) {
						v.r = new Node();
					}
					v = v.r;
					l = m;
				}
			}
			v.sum += y;
		}
	}

	void solve() {
		TreeSet<Segment> ts1 = new TreeSet<Segment>(new Comparator<Segment>() {
			@Override
			public int compare(Segment o1, Segment o2) {
				int e1 = o1.r - o1.l;
				int e2 = o2.r - o2.l;
				if (e1 == e2) {
					return o1.l < o2.l ? 1 : o1.l > o2.l ? -1 : 0;
				}
				return e1 < e2 ? 1 : -1;
			}
		});
		TreeSet<Segment> ts2 = new TreeSet<Segment>(new Comparator<Segment>() {
			@Override
			public int compare(Segment o1, Segment o2) {
				return o1.l > o2.l ? 1 : o1.l < o2.l ? -1 : 0;
			}
		});
		HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
		int n = nextInt();
		int m = nextInt();
		Segment all = new Segment(0, n);
		SegmentTree stree = new SegmentTree(n);
		ts1.add(all);
		ts2.add(all);
		Segment test = new Segment(0, 0);
		for (int i = 0; i < m; i++) {
			int x = nextInt();
			if (x == 0) {
				int l = nextInt();
				int r = nextInt();
				out.println(stree.getSum(l - 1, r));
			} else {
				if (hm.containsKey(x)) {
					int w = hm.get(x);
					hm.remove(x);
					stree.add(w, -1);
					test.l = test.r = w;
					Segment left = ts2.floor(test);
					Segment right = ts2.ceiling(test);
					Segment newSegment = new Segment(w, w + 1);
					if (left != null && left.r == w) {
						newSegment.l = left.l;
						ts1.remove(left);
						ts2.remove(left);
					}
					if (right != null && right.l == w + 1) {
						newSegment.r = right.r;
						ts1.remove(right);
						ts2.remove(right);
					}
					ts1.add(newSegment);
					ts2.add(newSegment);
				} else {
					Segment most = ts1.pollFirst();
					ts2.remove(most);
					int w = (most.l + most.r) >> 1;
					hm.put(x, w);
					stree.add(w, 1);
					Segment left = new Segment(most.l, w);
					Segment right = new Segment(w + 1, most.r);
					if (left.l < left.r) {
						ts1.add(left);
						ts2.add(left);
					}
					if (right.l < right.r) {
						ts1.add(right);
						ts2.add(right);
					}
				}
			}
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new D().run();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class SegmentTree {
		int[] value;
		int[] min;

		SegmentTree(int n, int[] value) {
			this.value = value;
			min = new int[n * 4];
			build(0, 0, n - 1);
		}

		void build(int v, int l, int r) {
			if (l == r) {
				min[v] = l;
			} else {
				int m = (l + r) >> 1;
				build(v * 2 + 1, l, m);
				build(v * 2 + 2, m + 1, r);
				upd(v);
			}
		}

		int get(int v, int l, int r, int needL, int needR) {
			if (needL > needR) {
				return -1;
			}
			if (l == needL && r == needR) {
				return min[v];
			}
			int m = (l + r) >> 1;
			int res = getMin(get(v * 2 + 1, l, m, needL, Math.min(needR, m)),
					get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR));
			return res;
		}

		int getMin(int x, int y) {
			if (x == -1) {
				return y;
			}
			if (y == -1) {
				return x;
			}
			return value[x] < value[y] ? x : y;
		}

		void upd(int v) {
			min[v] = getMin(min[v * 2 + 1], min[v * 2 + 2]);
		}
	}

	int[] value;
	SegmentTree st;
	int max;
	int d;

	int lowerBould(int need) {
		int l = -1, r = o.length;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (o[mid].pos >= need) {
				r = mid;
			} else {
				l = mid;
			}
		}
		return r;
	}

	int getMin(int l, int r) {
		int from = lowerBould(l);
		int to = lowerBould(r + 1) - 1;
		if (from <= to && from < value.length) {
			int res = st.get(0, 0, value.length - 1, from, to);
			if (res == -1) {
				return -1;
			}
			return o[res].pos;
		} else {
			return -1;
		}
	}

	long go(int l, int r, int have) {
		int rp = lowerBould(l);
		if (r - l <= max) {
			return Math.max(0, r - l - have) * 1L * value[rp];
		}
		int id = getMin(l + 1, r - 1);
		if (id == -1 || value[lowerBould(id)] == Integer.MAX_VALUE) {
			return Long.MAX_VALUE;
		}
		long cost = (max - have) * 1L * value[rp];
		if (id - l > max) {
			long left = go(l, id, max);
			if (left == Long.MAX_VALUE) {
				return Long.MAX_VALUE;
			}
			cost += left;
			have = 0;
		} else {
			have = max - (id - l);
		}
		long right = go(id, r, have);
		if (right == Long.MAX_VALUE) {
			return Long.MAX_VALUE;
		}
		return cost + right;
	}

	class O implements Comparable<O> {
		int pos, value;

		public O(int pos, int value) {
			super();
			this.pos = pos;
			this.value = value;
		}

		@Override
		public int compareTo(O arg0) {
			return Integer.compare(pos, arg0.pos);
		}

	}

	O[] o;

	void solve() {
		d = in.nextInt();
		max = in.nextInt();
		int m = in.nextInt();
		o = new O[m + 1];
		o[m] = new O(0, 0);
		for (int i = 0; i < m; i++) {
			o[i] = new O(in.nextInt(), in.nextInt());
		}
		Arrays.sort(o);
		value = new int[o.length];
		for (int i = 0; i < o.length; i++) {
			value[i] = o[i].value;
		}
		st = new SegmentTree(value.length, value);
		long result = go(0, d, 0);
		out.println(result == Long.MAX_VALUE ? -1 : result);
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test2.out"));

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
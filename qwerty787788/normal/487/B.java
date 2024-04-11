import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int it;

	class O implements Comparable<O> {
		int id;
		int value;

		O(int value) {
			id = it++;
			this.value = value;
		}

		@Override
		public int compareTo(O o) {
			return value == o.value ? Integer.compare(id, o.id) : Integer
					.compare(value, o.value);
		}
	}

	class SegmentTree {
		int[] min;

		SegmentTree(int n) {
			min = new int[n * 4];
			Arrays.fill(min, Integer.MAX_VALUE);
		}

		int get(int v, int l, int r, int needL, int needR) {
			if (needL > needR) {
				return Integer.MAX_VALUE;
			}
			if (l == needL && r == needR) {
				return min[v];
			}
			int mid = (l + r) >> 1;
			int res = get(v * 2 + 1, l, mid, needL, Math.min(needR, mid));
			res = Math
					.min(res,
							get(v * 2 + 2, mid + 1, r,
									Math.max(needL, mid + 1), needR));
			return res;
		}

		void set(int v, int l, int r, int pos, int value) {
			if (l == r) {
				min[v] = value;
			} else {
				int mid = (l + r) >> 1;
				if (mid >= pos) {
					set(v * 2 + 1, l, mid, pos, value);
				} else {
					set(v * 2 + 2, mid + 1, r, pos, value);
				}
				min[v] = Math.min(min[v * 2 + 1], min[v * 2 + 2]);
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int s = in.nextInt();
		int l = in.nextInt();
		O[] a = new O[n];
		for (int i = 0; i < n; i++) {
			a[i] = new O(in.nextInt());
		}
		SegmentTree st = new SegmentTree(n + 1);
		st.set(0, 0, n, 0, 0);
		int from = 0;
		TreeSet<O> ts = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			ts.add(a[i]);
			while (ts.last().value - ts.first().value > s) {
				ts.remove(a[from++]);
			}
			int max = i - l + 1;
			int res = st.get(0, 0, n, from, max);
			if (res != Integer.MAX_VALUE) {
				st.set(0, 0, n, i + 1, res + 1);
			}
		}
		int result = st.get(0, 0, n, n, n);
		out.println(result == Integer.MAX_VALUE ? -1 : result);
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
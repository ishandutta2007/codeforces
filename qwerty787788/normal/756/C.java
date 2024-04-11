import java.io.*;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	class SegmentTree {
		int[] sub;
		int[] add;

		public SegmentTree(int n) {
			sub = new int[n * 4];
			add = new int[n * 4];
		}

		void set(int v, int l, int r, int pos, int val) {
			if (l == r) {
				if (val == 1) {
					add[v] = 1;
				} else {
					sub[v] = 1;
				}
			} else {
				int mid = (l + r) >> 1;
				if (mid >= pos) {
					set(v * 2 + 1, l, mid, pos, val);
				} else {
					set(v * 2 + 2, mid + 1, r, pos, val);
				}
				if (add[v * 2 + 1] >= sub[v * 2 + 2]) {
					sub[v] = sub[v * 2 + 1];
					add[v] = add[v * 2 + 1] + add[v * 2 + 2] - sub[v * 2 + 2];
				} else {
					sub[v] = sub[v * 2 + 1] + sub[v * 2 + 2] - add[v * 2 + 1];
					add[v] = add[v * 2 + 2];
				}
			}
		}

		int getPos(int v, int l, int r, int dels) {
			if (l == r) {
				if (dels > 0) {
				 	return -1;
				}
				return r;
			}
			int mid = (l + r) >> 1;
			if (add[v * 2 + 2] > dels) {
				return getPos(v * 2 + 2, mid+1, r, dels);
			}
			dels -= add[v * 2 + 2];
			dels += sub[v * 2 + 2];
			return getPos(v * 2 + 1, l, mid, dels);
		}
	}

	void solve() {
		int n = in.nextInt();
		int[] vals = new int[n];
		Arrays.fill(vals, -1);
		SegmentTree st = new SegmentTree(n);
		for (int i = 0; i < n; i++) {
			int pos = in.nextInt() - 1;
			int type = in.nextInt();
			if (type == 0) {
				st.set(0, 0, n - 1, pos, -1);
			} else {
				int val = in.nextInt();
				vals[pos] = val;
				st.set(0, 0, n - 1, pos, 1);
			}
			int p = st.getPos(0, 0, n - 1, 0);
			out.println(p == -1 ? -1 : vals[p]);
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
		new C().runIO();
	}
}
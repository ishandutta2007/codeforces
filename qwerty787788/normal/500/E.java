import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class CF {
	FastScanner in;
	PrintWriter out;

	class SegmentTree {
		int[] max;
		int n;

		SegmentTree(int n) {
			this.n = n;
			max = new int[n * 4];
			Arrays.fill(max, -1);
		}

		int getMax(int v, int l, int r, int needL, int needR) {
			if (needR < needL)
				return -1;
			if (l == needL && r == needR)
				return max[v];
			int m = (l + r) >>> 1;
			return Math.max(getMax(v * 2 + 1, l, m, needL, Math.min(needR, m)),
					getMax(v * 2 + 2, m + 1, r, Math.max(m + 1, needL), needR));
		}

		void upd(int v, int l, int r, int p, int val) {
			if (l == r) {
				max[v] = val;
			} else {
				int m = (l + r) >>> 1;
				if (m >= p) {
					upd(v * 2 + 1, l, m, p, val);
				} else {
					upd(v * 2 + 2, m + 1, r, p, val);
				}
				max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
			}
		}
	}

	final int MAX = 10_000_000;
	int cnt = 0;
	int[] add = new int[MAX];
	int[] left = new int[MAX];
	int[] right = new int[MAX];

	int genTree(int l, int r) {
		if (l == r) {
			return cnt++;
		} else {
			int m = (l + r) >>> 1;
			int id = cnt++;
			left[id] = genTree(l, m);
			right[id] = genTree(m + 1, r);
			return id;
		}
	}

	int addTree(int curTree, int l, int r, int needL, int addVal) {
		if (needL > r) {
			return curTree;
		}
		if (needL <= l) {
			int resId = cnt++;
			left[resId] = left[curTree];
			right[resId] = right[curTree];
			add[resId] = add[curTree] + addVal;
			return resId;
		}
		int resId = cnt++;
		int m = (l + r) >>> 1;
		left[resId] = addTree(left[curTree], l, m, needL, addVal);
		right[resId] = addTree(right[curTree], m + 1, r, needL, addVal);
		add[resId] = add[curTree];
		return resId;
	}

	int getAns(int tree, int l, int r, int need) {
		if (l == r) {
			return add[tree];
		} else {
			int m = (l + r) >>> 1;
			if (m >= need) {
				return add[tree] + getAns(left[tree], l, m, need);
			} else {
				return add[tree] + getAns(right[tree], m + 1, r, need);
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int[] p = new int[n + 1];
		int[] l = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = in.nextInt();
			l[i] = in.nextInt();
		}
		SegmentTree st = new SegmentTree(n);
		int[] ans = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			int curMax = p[i] + l[i];
			int left = i, right = n;
			while (right - left > 1) {
				int mid = (left + right) >> 1;
				if (p[mid] <= p[i] + l[i]) {
					left = mid;
				} else {
					right = mid;
				}
			}
			curMax = Math.max(curMax, st.getMax(0, 0, n - 1, i, left));
			st.upd(0, 0, n - 1, i, curMax);
			ans[i] = curMax;
		}
		int[] trees = new int[n + 1];
		trees[n] = genTree(0, n - 1);
		for (int i = n - 1; i >= 0; i--) {
			int left = i;
			int right = n;
			while (right - left > 1) {
				int mid = (left + right) >>> 1;
				if (p[mid] <= ans[i]) {
					left = mid;
				} else {
					right = mid;
				}
			}
			trees[i] = addTree(trees[right], 0, n - 1, right, p[right] - ans[i]);
		}
		int qq = in.nextInt();
		for (int q = 0; q < qq; q++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			out.println(getAns(trees[fr], 0, n - 1, to));
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
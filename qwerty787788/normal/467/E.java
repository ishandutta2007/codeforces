import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class SegmentTree {
		int[] val;
		int[] max;

		SegmentTree(int n) {
			val = new int[n];
			max = new int[n * 4];
			Arrays.fill(val, -1);
			build(0, 0, n - 1);
		}

		void build(int v, int l, int r) {
			if (l == r) {
				max[v] = l;
			} else {
				int m = (l + r) >> 1;
				build(v * 2 + 1, l, m);
				build(v * 2 + 2, m + 1, r);
				upd(v);
			}
		}

		void update(int v, int l, int r, int pos, int newVal) {
			if (l == r) {
				val[l] = newVal;
			} else {
				int m = (l + r) >> 1;
				if (pos <= m) {
					update(v * 2 + 1, l, m, pos, newVal);
				} else {
					update(v * 2 + 2, m + 1, r, pos, newVal);
				}
				upd(v);
			}
		}

		int get(int v, int l, int r, int needL, int more) {
			if (r < needL)
				return -1;
			if (val[max[v]] <= more)
				return -1;
			if (l == r)
				return l;
			int m = (l + r) >>> 1;
			int v1 = get(v * 2 + 1, l, m, needL, more);
			if (v1 != -1)
				return v1;
			return get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), more);
		}

		void upd(int v) {
			int m1 = max[v * 2 + 1];
			int m2 = max[v * 2 + 2];
			if (val[m1] >= val[m2]) {
				max[v] = m1;
			} else {
				max[v] = m2;
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		HashMap<Integer, Integer> pr = new HashMap<>();
		int[] prev = new int[n];
		int[] next = new int[n];
		Arrays.fill(next, -1);
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			Integer x = pr.get(a[i]);
			if (x == null) {
				prev[i] = -1;
			} else {
				prev[i] = x;
			}
			pr.put(a[i], i);
		}
		for (int i = 0; i < n; i++)
			if (prev[i] != -1)
				next[prev[i]] = i;
		int[] bestFrom = new int[n];
		Arrays.fill(bestFrom, -1);
		SegmentTree st = new SegmentTree(n);
		for (int pos = 0; pos < n; pos++) {
			int p = prev[pos];
			if (p != -1) {
				int lastPos = st.get(0, 0, n - 1, pos + 1, p);
				if (lastPos != -1) {
					bestFrom[lastPos] = Math.max(bestFrom[lastPos], p);
				}
			}
			if (next[pos] != -1)
				st.update(0, 0, n - 1, next[pos], pos);
			{
				int x1 = prev[pos];
				if (x1 != -1) {
					int x2 = prev[x1];
					if (x2 != -1) {
						int x3 = prev[x2];
						if (x3 != -1) {
							if (x3 > bestFrom[pos]) {
								bestFrom[pos] = x3;
							}
						}
					}
				}
			}
		}
		int[] dp = new int[n];
		boolean[] use = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				dp[i] = dp[i - 1];
			}
			if (bestFrom[i] != -1) {
				int newOne = 1;
				if (bestFrom[i] > 0)
					newOne += dp[bestFrom[i] - 1];
				if (newOne > dp[i]) {
					dp[i] = newOne;
					use[i] = true;
				}
			}
		}
		int x = n - 1;
		ArrayList<Integer> answer = new ArrayList<>();
		while (x >= 0) {
			if (use[x]) {
				answer.add(a[x]);
				answer.add(a[bestFrom[x]]);
				answer.add(a[x]);
				answer.add(a[bestFrom[x]]);
				x = bestFrom[x] - 1;
			} else {
				x--;
			}
		}
		Collections.reverse(answer);
		out.println(answer.size());
		for (int xx : answer) {
			out.print(xx + " ");
		}
		out.println();
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
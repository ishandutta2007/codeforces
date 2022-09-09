import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class SegmentTree {
		int n;
		int[] sum;
		int realMax;

		SegmentTree(int n, int realMax) {
			this.n = n;
			this.realMax = realMax;
			sum = new int[n * 4];
		}

		void add(int v, int l, int r, int need, int add) {
			if (l == r) {
				sum[v] += add;
				if (sum[v] >= realMax) {
					sum[v] = realMax;
				}
			} else {
				int m = (l + r) >> 1;
				if (need <= m) {
					add(v * 2 + 1, l, m, need, add);
				} else {
					add(v * 2 + 2, m + 1, r, need, add);
				}
				sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
			}
		}

		int get(int v, int l, int r, int needL, int needR) {
			if (needL > needR) {
				return 0;
			}
			if (l == needL && r == needR) {
				return sum[v];
			}
			int m = (l + r) >> 1;
			return get(v * 2 + 1, l, m, needL, Math.min(needR, m))
					+ get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR);
		}
	}

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		int q = in.nextInt();
		SegmentTree stA = new SegmentTree(n, a);
		SegmentTree stB = new SegmentTree(n, b);
		for (int i = 0; i < q; i++) {
			if (in.nextInt() == 1) {
				int day = in.nextInt() - 1;
				int cnt = in.nextInt();
				stA.add(0, 0, n - 1, day, cnt);
				stB.add(0, 0, n - 1, day, cnt);
			} else {
				int from = in.nextInt() - 1;
				int to = from + k - 1;
				int result = stB.get(0, 0, n - 1, 0, from - 1);
				result += stA.get(0, 0, n - 1, to + 1, n - 1);
				out.println(result);
			}
		}
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
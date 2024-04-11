import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class SegmentTree {
		int[][] cnt;
		int[] type;
		int[] from, to;
		// 0 - noth
		// 1 - incr order
		// 2 - decr order
		int n;

		SegmentTree(String s) {
			n = s.length();
			cnt = new int[26][n * 4];
			type = new int[n * 4];
			from = new int[n * 4];
			to = new int[n * 4];
			build(0, 0, n - 1, s);
		}

		void update(int v) {
			int left = v * 2 + 1, right = v * 2 + 2;
			for (int i = 0; i < 26; i++) {
				cnt[i][v] = cnt[i][left] + cnt[i][right];
			}
		}

		void build(int v, int l, int r, String s) {
			from[v] = l;
			to[v] = r;
			if (l == r) {
				cnt[s.charAt(l) - 'a'][v]++;
			} else {
				int m = (l + r) >>> 1;
				int left = v * 2 + 1, right = v * 2 + 2;
				build(left, l, m, s);
				build(right, m + 1, r, s);
				update(v);
			}
		}

		void get(int v, int l, int r, int needL, int needR, int[] sum) {
			if (needL > needR) {
				return;
			}
			if (needL == l && needR == r) {
				for (int i = 0; i < 26; i++) {
					sum[i] += cnt[i][v];
				}
				return;
			}
			relax(v, l, r);
			int m = (l + r) >>> 1;
			get(v * 2 + 1, l, m, needL, Math.min(needR, m), sum);
			get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, sum);
		}

		void set(int v, int l, int r, int needL, int needR, int[] sum,
				int nextType) {
			if (needL > needR) {
				return;
			}
			if (needL == l && needR == r) {
				int sz = needR - needL + 1;
				type[v] = nextType;
				if (nextType == 1) {
					for (int i = 0; i < 26; i++) {
						int more = Math.min(sum[i], sz);
						sz -= more;
						sum[i] -= more;
						cnt[i][v] = more;
					}
				} else {
					for (int i = 25; i >= 0; i--) {
						int more = Math.min(sum[i], sz);
						sz -= more;
						sum[i] -= more;
						cnt[i][v] = more;
					}
				}
				return;
			}
			relax(v, l, r);
			int m = (l + r) >>> 1;
			set(v * 2 + 1, l, m, needL, Math.min(needR, m), sum, nextType);
			set(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, sum,
					nextType);
			update(v);
		}

		void relax(int v, int l, int r) {
			if (type[v] == 0) {
				return;
			}
			if (l == r) {
				type[v] = 0;
				return;
			}
			int left = v * 2 + 1, right = v * 2 + 2;
			if (type[v] == 1) {
				int szLeft = to[left] - from[left] + 1;
				for (int i = 0; i < 26; i++) {
					int more = Math.min(cnt[i][v], szLeft);
					szLeft -= more;
					cnt[i][left] = more;
				}
				int szRight = to[right] - from[right] + 1;
				for (int i = 25; i >= 0; i--) {
					int more = Math.min(cnt[i][v], szRight);
					szRight -= more;
					cnt[i][right] = more;
				}
			} else {
				int szLeft = to[left] - from[left] + 1;
				for (int i = 25; i >= 0; i--) {
					int more = Math.min(cnt[i][v], szLeft);
					szLeft -= more;
					cnt[i][left] = more;
				}
				int szRight = to[right] - from[right] + 1;
				for (int i = 0; i < 26; i++) {
					int more = Math.min(cnt[i][v], szRight);
					szRight -= more;
					cnt[i][right] = more;
				}
			}
			type[left] = type[right] = type[v];
			type[v] = 0;
		}

		void print(int v, int l, int r) {
			relax(v, l, r);
			if (l == r) {
				for (int i = 0; i < 26; i++) {
					for (int j = 0; j < cnt[i][v]; j++) {
						out.print((char) ('a' + i));
					}
				}
			} else {
				int m = (l + r) >>> 1;
				print(v * 2 + 1, l, m);
				print(v * 2 + 2, m + 1, r);
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int qq = in.nextInt();
		String s = in.next();
		SegmentTree st = new SegmentTree(s);
		int[] su = new int[26];
		for (int q = 0; q < qq; q++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			int type = in.nextInt();
			st.get(0, 0, n - 1, fr, to, su);
			st.set(0, 0, n - 1, fr, to, su, type == 1 ? 1 : 2);
		}
		st.print(0, 0, n - 1);
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
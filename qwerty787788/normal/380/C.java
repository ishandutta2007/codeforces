import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	class SegmentTree {
		int[] su;
		int n;

		SegmentTree(int n) {
			this.n = n;
			su = new int[4 * n];
		}

		int get(int v, int l, int r, int needL, int needR) {
			if (needL > needR)
				return 0;
			if (needL <= l && needR >= r)
				return su[v];
			int m = (l + r) >> 1;
			return get(v * 2 + 1, l, m, needL, Math.min(needR, m))
					+ get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR);
		}

		int get(int l, int r) {
			return get(0, 0, n - 1, l, r);
		}

		void upd(int v, int l, int r, int need, int s) {
			if (l == r) {
				su[v] += s;
			} else {
				int m = (l + r) >> 1;
				if (m >= need)
					upd(v * 2 + 1, l, m, need, s);
				else
					upd(v * 2 + 2, m + 1, r, need, s);
				su[v] = su[v * 2 + 1] + su[v * 2 + 2];
			}
		}

		void upd(int v, int c) {
			upd(0, 0, n - 1, v, c);
		}
	}

	class Ev {
		int to, id;

		Ev(int to, int id) {
			this.to = to;
			this.id = id;
		}
	}

	void solve() {
		String s = in.next();
		int n = in.nextInt();
		int[] l = new int[n];
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = in.nextInt() - 1;
			r[i] = in.nextInt() - 1;
		}
		int m = s.length();
		int[] lvl = new int[m];
		int[] next = new int[m];
		Arrays.fill(next, -1);
		ArrayList<Integer> q = new ArrayList<>();
		int nowLvl = 0;
		for (int i = 0; i < m; i++) {
			if (s.charAt(i) == '(') {
				q.add(i);
				nowLvl++;
				lvl[i] = nowLvl;
			} else {
				if (q.size() > 0) {
					int last = q.get(q.size() - 1);
					q.remove(q.size() - 1);
					next[last] = i;
					next[i] = last;
					lvl[i] = nowLvl;
				}
				nowLvl--;
				if (nowLvl < 0)
					nowLvl = 0;
			}
		}
		ArrayList<Ev>[] as = new ArrayList[m];
		for (int i = 0; i < m; i++)
			as[i] = new ArrayList<>();
		for (int i = 0; i < n; i++)
			as[l[i]].add(new Ev(r[i], i));
		int[] ans = new int[n];
		SegmentTree st1 = new SegmentTree(m);
		SegmentTree st2 = new SegmentTree(m);
		for (int i = 0; i < m; i++)
			if (next[i] != -1) {
				if (s.charAt(i) == '(')
					st1.upd(i, 1); else
						st2.upd(i, 1);
			}
		for (int left = 0; left < m; left++) {
			if (left != 0) {
				if (next[left - 1] > left - 1) {
					st1.upd(left - 1, -1);
					st2.upd(next[left - 1], -1);
				}
			}
			for (int i = 0; i < as[left].size(); i++) {
				Ev e = as[left].get(i);
				int res1 = st1.get(0, e.to);
				int res2 = st2.get(0, e.to);
				ans[e.id] = Math.min(res1, res2) * 2;
			}
		}
		for (int i = 0; i < n; i++)
			out.println(ans[i]);
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
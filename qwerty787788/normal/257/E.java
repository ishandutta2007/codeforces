import java.io.*;
import java.util.*;

public class CF159DIV2 {
	FastScanner in;
	PrintWriter out;

	class SegmentTree {
		int n;
		int[] t;

		SegmentTree(int n) {
			this.n = n;
			t = new int[n];
		}

		int get(int r) {
			int result = 0;
			for (; r >= 0; r = (r & (r + 1)) - 1)
				result += t[r];
			return result;
		}

		void add(int i, int delta) {
			for (; i < n; i = (i | (i + 1)))
				t[i] += delta;
		}

		int get(int l, int r) {
			return get(r) - get(l - 1);
		}

	}

	class People implements Comparable<People> {
		int id, t, from, to;

		public People(int id, int t, int from, int to) {
			super();
			this.id = id;
			this.t = t;
			this.from = from;
			this.to = to;
		}

		@Override
		public int compareTo(People arg0) {
			return t - arg0.t;
		}

	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		People[] a = new People[n];
		for (int i = 0; i < n; i++)
			a[i] = new People(i, in.nextInt(), in.nextInt() - 1,
					in.nextInt() - 1);
		Arrays.sort(a);
		long curT = 0;
		SegmentTree curS = new SegmentTree(m);
		int curFl = 0;
		int curGo = 0;// 0 - nothing, 1, - up, -1 - down;
		long nextLift = Long.MAX_VALUE;
		int it = 0;
		ArrayList<Integer>[] wantedGo = new ArrayList[m];
		ArrayList<Integer>[] wantedInside = new ArrayList[m];
		for (int i = 0; i < m; i++) {
			wantedGo[i] = new ArrayList<Integer>();
			wantedInside[i] = new ArrayList<Integer>();
		}
		long[] answ = new long[n];
		while (true) {
			long nextPers = Long.MAX_VALUE;
			if (it < n)
				nextPers = a[it].t;
			long timeAdd = Math.min(nextPers, nextLift) - curT;
			if (timeAdd > 1e16)
				break;
			curT += timeAdd;
			curFl += timeAdd * curGo;
			curS.add(curFl, -wantedGo[curFl].size());
			for (int i = 0; i < wantedGo[curFl].size(); i++)
				answ[a[wantedGo[curFl].get(i)].id] = curT;
			wantedGo[curFl].clear();
			while (it < n && a[it].t == curT) {
				wantedInside[a[it].from].add(it);
				curS.add(a[it++].from, 1);
			}
			curS.add(curFl, -wantedInside[curFl].size());
			for (int i = 0; i < wantedInside[curFl].size(); i++) {
				curS.add(a[wantedInside[curFl].get(i)].to, 1);
				wantedGo[a[wantedInside[curFl].get(i)].to]
						.add(wantedInside[curFl].get(i));
			}
			wantedInside[curFl].clear();
			int needDown = curS.get(0, curFl);
			int needUp = curS.get(curFl, m - 1);
			nextLift = Long.MAX_VALUE;
			if (needUp == 0 && needDown == 0) {
				curGo = 0;
			} else if (needUp >= needDown) {
				curGo = 1;
				int l = curFl, r = m;
				while (r - l > 1) {
					int med = (l + r) / 2;
					if (curS.get(curFl, med) != 0) {
						r = med;
					} else {
						l = med;
					}
				}
				nextLift = curT + (r - curFl);
			} else {

				curGo = -1;
				int l = -1, r = curFl;
				while (r - l > 1) {
					int med = (l + r) / 2;
					if (curS.get(med, curFl) != 0) {
						l = med;
					} else {
						r = med;
					}
				}
				nextLift = curT + (curFl - l);
			}
		}
		for (int i = 0; i < n; i++)
			out.println(answ[i]);
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
		new CF159DIV2().runIO();
	}
}
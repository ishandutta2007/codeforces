import java.io.*;
import java.util.*;

public class CF {

	class Seg implements Comparable<Seg> {
		int l, r;

		Seg(int l, int r) {
			this.l = l;
			this.r = r;
		}

		@Override
		public int compareTo(Seg o) {
			if (l == o.l)
				return Integer.compare(r, o.r);
			return Integer.compare(l, o.l);
		}
	}

	class SegmentTree {
		int n;
		int[] s;

		public SegmentTree(int n) {
			this.n = n;
			s = new int[n * 4];
		}

		int get(int v, int l, int r, int need) {
			if (l == r)
				return s[v];
			int m = (l + r) >> 1;
			if (m >= need)
				return get(v * 2 + 1, l, m, need) + s[v];
			return get(v * 2 + 2, m + 1, r, need) + s[v];
		}

		int get(int v) {
			return get(0, 0, n - 1, v);
		}

		void upd(int v, int l, int r, int needL, int needR) {
			if (needR < needL)
				return;
			if (l == needL && r == needR) {
				s[v]++;
				return;
			}
			int m = (l + r) >> 1;
			upd(v * 2 + 1, l, m, needL, Math.min(needR, m));
			upd(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR);
		}

		void upd(int l, int r) {
			upd(0, 0, n - 1, l, r);
		}
	}

	class Event implements Comparable<Event> {
		int v;
		int it;
		int time;

		Event(int v, int it, int time) {
			this.v = v;
			this.it = it;
			this.time = time;
		}

		@Override
		public int compareTo(Event o) {
			return Integer.compare(time, o.time);
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		Seg[] s = new Seg[n];
		for (int i = 0; i < n; i++) {
			s[i] = new Seg(in.nextInt(), in.nextInt());
		}
		int[][] p = new int[m][];
		int su = 0;
		for (int i = 0; i < m; i++) {
			int k = in.nextInt();
			su += k;
			p[i] = new int[k];
			for (int j = 0; j < k; j++)
				p[i][j] = in.nextInt();
		}
		int[] ans = new int[m];
		SegmentTree sum = new SegmentTree((int) 1e6 + 2);
		Arrays.sort(s);
		Event[] allEvents = new Event[su];
		int iter = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < p[i].length; j++) {
				int time = j == 0 ? 0 : p[i][j - 1] + 1;
				Event newEvent = new Event(i, j, time);
				allEvents[iter++] = newEvent;
			}
		Arrays.sort(allEvents);
		int it = s.length - 1;
		for (int i = allEvents.length - 1; i >= 0; i--) {
			int nowTime = allEvents[i].time;
			while (it != -1 && s[it].l >= nowTime) {
				sum.upd(s[it].l, s[it].r);
				it--;
			}
			ans[allEvents[i].v] += sum.get(p[allEvents[i].v][allEvents[i].it]);
		}
		for (int i = 0; i < m; i++)
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
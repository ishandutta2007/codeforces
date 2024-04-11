import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Time implements Comparable<Time> {
		int id;
		int type;
		int time;

		public Time(int id, int type, int time) {
			super();
			this.id = id;
			this.type = type;
			this.time = time;
		}

		@Override
		public String toString() {
			return "Time [id=" + id + ", type=" + type + ", time=" + time + "]";
		}

		@Override
		public int compareTo(Time o) {
			if (time == o.time) {
				return Integer.compare(o.type, type);
			}
			return Integer.compare(time, o.time);
		}

	}

	int[] fr, to;
	ArrayList<Integer>[] qId;
	int[] have;
	final int MAX = 4001;
	int[][] ans = new int[20][MAX];
	boolean[][] nowOn;
	boolean[] on;
	int[] prefMax = new int[MAX];
	int n;

	void go(int l, int r, int h) {
		int sTmp = sum[r] - (l == 0 ? 0 : sum[l - 1]);
		if (sTmp == 0)
			return;
		for (int j = 0; j < MAX; j++) {
			ans[h + 1][j] = ans[h][j];
		}
		for (int i = 0; i < n; i++) {
			if (!on[i] && l >= fr[i] && r < to[i]) {
				on[i] = true;
				nowOn[h + 1][i] = true;
				int cCost = c[i];
				int cH = hh[i];
				for (int j = MAX - 1 - cCost; j >= 0; j--) {
					if (ans[h + 1][j] != -1) {
						ans[h + 1][j + cCost] = Math.max(ans[h + 1][j + cCost],
								ans[h + 1][j] + cH);
					}
				}
			}
		}
		if (l == r) {
			prefMax[0] = ans[h + 1][0];
			for (int i = 1; i < MAX; i++) {
				prefMax[i] = Math.max(prefMax[i - 1], ans[h + 1][i]);
			}
			for (int id : qId[l]) {
				answer[id] = prefMax[have[id]];
				// System.err.println(id+"?");
				// for (int j = 0; j < n; j++)
				// if (on[j]) {
				// System.err.print(j+" ");
				// }
				// System.err.println();
			}
		} else {
			int m = (l + r) >>> 1;
			go(l, m, h + 1);
			go(m + 1, r, h + 1);
		}
		for (int j = 0; j < n; j++) {
			if (nowOn[h + 1][j]) {
				nowOn[h + 1][j] = false;
				on[j] = false;
			}
		}
	}

	int[] answer;
	int[] c;
	int[] hh;
	int[] sum;

	void solve() {
		n = in.nextInt();
		int p = in.nextInt();
		c = new int[n];
		hh = new int[n];
		int[] t = new int[n];
		Time[] a = new Time[n * 2 + 1];
		for (int i = 0; i < n; i++) {
			c[i] = in.nextInt();
			hh[i] = in.nextInt();
			t[i] = in.nextInt();
			a[i * 2] = new Time(i, 1, t[i]);
			a[i * 2 + 1] = new Time(i, -1, t[i] + p - 1);
		}
		a[a.length - 1] = new Time(-1, -1, -1);
		Arrays.sort(a);
		fr = new int[n];
		to = new int[n];
		for (int i = 1; i < a.length; i++) {
			if (a[i].type == 1) {
				fr[a[i].id] = i;
			} else {
				to[a[i].id] = i;
			}
		}
		qId = new ArrayList[a.length];
		for (int i = 0; i < qId.length; i++) {
			qId[i] = new ArrayList<>();
		}
		int qq = in.nextInt();
		have = new int[qq];
		for (int q = 0; q < qq; q++) {
			int time = in.nextInt();
			have[q] = in.nextInt();
			int rTime = 0;
			for (int j = 1; j < a.length; j++) {
				if (time > a[j].time || (time == a[j].time && a[j].type == 1)) {
					rTime = j;
				}
			}
			qId[rTime].add(q);
		}
		answer = new int[qq];
		Arrays.fill(ans[0], -1);
		ans[0][0] = 0;
		on = new boolean[n];
		nowOn = new boolean[20][n];
		sum = new int[a.length];
		for (int i = 0; i < a.length; i++) {
			sum[i] = qId[i].size();
			if (i != 0) {
				sum[i] += sum[i - 1];
			}
		}
		go(0, a.length - 1, 0);
		for (int i = 0; i < qq; i++) {
			out.println(answer[i] + " ");
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
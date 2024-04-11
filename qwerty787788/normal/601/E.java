import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final int mod = (int) 1e9 + 7;
	final long mod2 = mod * 1L * mod;
	final int p = (int) 1e7 + 19;
	int[] pow;

	class U {
		int cost;
		int w;

		public U(int cost, int w) {
			super();
			this.cost = cost;
			this.w = w;
		}

		@Override
		public String toString() {
			return "U [cost=" + cost + ", w=" + w + "]";
		}

	}

	class O {
		int from, to;
		O left, right;

		ArrayList<U> u;

		O(int from, int to) {
			this.from = from;
			this.to = to;
			u = new ArrayList<>();
			if (from != to) {
				int mid = (from + to) / 2;
				this.left = new O(from, mid);
				this.right = new O(mid + 1, to);
			}
		}

		void add(int fr, int to, U cur) {
			if (fr > this.to || to < this.from) {
				return;
			}
			if (fr <= this.from && this.to <= to) {
				u.add(cur);
				return;
			}
			if (this.from != this.to) {
				left.add(fr, to, cur);
				right.add(fr, to, cur);
			}
		}

		void go(int h) {
			if (ans[h] == null) {
				ans[h] = new int[k + 1];
			}
			for (int i = 0; i <= k; i++) {
				ans[h][i] = ans[h - 1][i];
			}
			for (U cur : u) {
				for (int i = k - cur.w; i >= 0; i--) {
					int nans = ans[h][i] + cur.cost;
					if (nans > ans[h][i + cur.w]) {
						ans[h][i + cur.w] = nans;
					}
				}
			}
			if (this.from == this.to) {
				long answer = 0;
				for (int i = 1; i <= k; i++) {
					answer += ans[h][i] * 1L * pow[i - 1];
					if (answer >= mod2) {
						answer -= mod2;
					}
				}
				out.println(answer % mod);
			} else {
				left.go(h + 1);
				right.go(h + 1);
			}
		}
	}

	int k;

	int[][] ans = new int[100][];

	void solve() {
		int n = in.nextInt();
		k = in.nextInt();
		pow = new int[k];
		pow[0] = 1;
		for (int i = 1; i < k; i++) {
			pow[i] = (int) ((pow[i - 1] * 1L * p) % mod);
		}
		int[] v = new int[n];
		int[] w = new int[n];
		for (int i = 0; i < n; i++) {
			v[i] = in.nextInt();
			w[i] = in.nextInt();
		}
		int q = in.nextInt();
		int[] type = new int[q];
		int[] qA = new int[q];
		int[] qB = new int[q];
		int time = 0;
		int total = n;
		int[] timeC = new int[q];
		for (int i = 0; i < q; i++) {
			type[i] = in.nextInt();
			if (type[i] == 1) {
				qA[i] = in.nextInt();
				qB[i] = in.nextInt();
				timeC[i] = time;
				total++;
			} else {
				if (type[i] == 2) {
					qA[i] = in.nextInt();
					timeC[i] = time;
				} else {
					++time;
				}
			}
		}
		int[] from = new int[total];
		int[] to = new int[total];
		int[] costi = new int[total];
		int[] wi = new int[total];
		for (int i = 0; i < n; i++) {
			costi[i] = v[i];
			wi[i] = w[i];
		}
		Arrays.fill(to, time);
		total = n;
		time = 0;
		for (int i = 0; i < q; i++) {
			if (type[i] == 1) {
				costi[total] = qA[i];
				wi[total] = qB[i];
				from[total] = time;
				total++;
			} else {
				if (type[i] == 2) {
					to[qA[i] - 1] = time;
				} else {
					time++;
				}
			}
		}

		O root = new O(0, time - 1);
		for (int i = 0; i < total; i++) {
			root.add(from[i], to[i] - 1, new U(costi[i], wi[i]));
		}
		ans[0] = new int[k + 1];
		root.go(1);
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
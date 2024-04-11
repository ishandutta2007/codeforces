import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Q implements Comparable<Q> {
		int add, id;

		public Q(int add, int id) {
			super();
			this.add = add;
			this.id = id;
		}

		@Override
		public int compareTo(Q o) {
			return -Integer.compare(add, o.add);
		}

	}

	class Mul implements Comparable<Mul> {
		int id;
		int num;
		long coef;

		public Mul(int id, int num, long coef) {
			super();
			this.id = id;
			this.num = num;
			this.coef = coef;
		}

		@Override
		public int compareTo(Mul o) {
			if (num == -1 && o.num == -1) {
				return -Long.compare(coef, o.coef);
			}
			if (num != -1 && o.num != -1) {
				return Long.signum(o.coef * a[num] - coef * a[o.num]);
			}
			if (num == -1) {
				long tmp = (o.coef + a[o.num]) / a[o.num];
				if (tmp > coef) {
					return 1;
				}
				if (tmp < coef) {
					return -1;
				}
				if (a[o.num] * coef == o.coef + a[o.num]) {
					return 0;
				}
				return 1;
			}
			if (o.num == -1) {
				long tmp = (coef + a[num]) / a[num];
				if (tmp > o.coef) {
					return -1;
				}
				if (tmp < o.coef) {
					return 1;
				}
				if (a[num] * o.coef == coef + a[num]) {
					return 0;
				}
				return -1;
			}
			return 0;
		}

		@Override
		public String toString() {
			return "Mul [id=" + id + ", num=" + num + ", coef=" + coef + "]";
		}

	}

	long[] a;

	class Use implements Comparable<Use> {
		int id;
		int type;

		public Use(int id, int type) {
			super();
			this.id = id;
			this.type = type;
		}

		@Override
		public int compareTo(Use o) {
			return Integer.compare(type, o.type);
		}

		@Override
		public String toString() {
			return "Use [id=" + id + ", type=" + type + "]";
		}

	}

	void solve() {
		int k = in.nextInt();
		int n = in.nextInt();
		int m = in.nextInt();
		a = new long[k];
		for (int i = 0; i < k; i++) {
			a[i] = in.nextInt();
		}
		int[] maxSet = new int[k];
		int[] id = new int[k];
		int[] mtype = new int[n];
		ArrayList<Q>[] can = new ArrayList[k];
		for (int i = 0; i < k; i++) {
			can[i] = new ArrayList<>();
		}
		PriorityQueue<Mul> pq = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			int type = in.nextInt();
			mtype[i] = type;
			int num = in.nextInt() - 1;
			int coef = in.nextInt();
			if (type == 1) {
				if (maxSet[num] < coef) {
					maxSet[num] = coef;
					id[num] = i;
				}
			} else {
				if (type == 2) {
					can[num].add(new Q(coef, i));
				} else {
					pq.add(new Mul(i, -1, coef));
				}
			}
		}
		int[] it = new int[k];
		for (int i = 0; i < k; i++) {
			if (maxSet[i] > a[i]) {
				can[i].add(new Q((int) (maxSet[i] - a[i]), id[i]));
			}
			Collections.sort(can[i]);
			if (can[i].size() != 0) {
				pq.add(new Mul(can[i].get(0).id, i, can[i].get(0).add));
			}
		}
		ArrayList<Use> use = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			if (pq.size() == 0) {
				break;
			}
			Mul mul = pq.poll();
			if (mul.num != -1) {
				a[mul.num] += mul.coef;
				it[mul.num]++;
				if (it[mul.num] != can[mul.num].size()) {
					pq.add(new Mul(can[mul.num].get(it[mul.num]).id, mul.num,
							can[mul.num].get(it[mul.num]).add));
				}
			}
			use.add(new Use(mul.id, mtype[mul.id]));
		}
		Collections.sort(use);
		out.println(use.size());
		for (Use u : use) {
			out.print((1 + u.id) + " ");
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
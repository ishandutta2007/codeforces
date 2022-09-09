import java.io.*;
import java.util.*;

public class CF {

	class Pers {
		int id, left, right, v;

		Pers(int id, int left, int v, int right) {
			this.id = id;
			this.left = left;
			this.right = right;
			this.v = v;
		}
	}

	int MAX = (int) (3 * 1e5 + 11);

	class SegTree {
		int n;
		int[] sum;
		int[] maxPref;
		int[] where;

		SegTree(int n) {
			this.n = n;
			sum = new int[4 * n];
			maxPref = new int[4 * n];
			where = new int[4 * n];
		}

		int[] max(int[] v1, int[] v2) {
			if (v1[0] > v2[0])
				return v1;
			return v2;
		}

		void add(int v, int l, int r, int need, int cc) {
			if (l == r) {
				sum[v] += cc;
				maxPref[v] = sum[v];
				where[v] = l;
			} else {
				int m = (l + r) >> 1;
				if (m >= need)
					add(v * 2 + 1, l, m, need, cc);
				else
					add(v * 2 + 2, m + 1, r, need, cc);
				sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
				int v1 = maxPref[v * 2 + 1];
				int v2 = maxPref[v * 2 + 2] + sum[v * 2 + 1];
				if (v1 >= v2) {
					maxPref[v] = v1;
					where[v] = where[v * 2 + 1];
				} else {
					maxPref[v] = v2;
					where[v] = where[v * 2 + 2];
				}
			}
		}

		void add(int need, int cc) {
			add(0, 0, n - 1, need, cc);
		}

		int[] getRes(int v, int l, int r, int needL, int needR) {
			return new int[] { maxPref[0], where[0] };
		}
	}

	void solve() {
		int n = in.nextInt();
		Pers[] a = new Pers[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Pers(i, in.nextInt(), in.nextInt(), in.nextInt());
		}
		Arrays.sort(a, new Comparator<Pers>() {
			@Override
			public int compare(Pers o1, Pers o2) {
				return Integer.compare(o1.left, o2.left);
			}
		});
		SegTree st = new SegTree(MAX);
		Pers[] b = new Pers[n];
		for (int i = 0; i < n; i++)
			b[i] = new Pers(a[i].id, a[i].left, a[i].v, a[i].right);
		Arrays.sort(b, new Comparator<Pers>() {
			@Override
			public int compare(Pers o1, Pers o2) {
				return Integer.compare(o1.v, o2.v);
			}
		});
		int iter = 0;
		int[] max = new int[2];
		int whoLeft = 0;
		for (int i = 0; i < n; i++) {
			Pers p = a[i];
			st.add(p.v, 1);
			st.add(p.right + 1, -1);
			while (iter != n && b[iter].v < p.left) {
				st.add(b[iter].v, -1);
				st.add(b[iter].right + 1, 1);
				iter++;
			}
			int[] best = st.getRes(0, 0, MAX - 1, a[i].left, MAX - 1);
			if (best[0] > max[0]) {
				max = best;
				whoLeft = i;
			}
		}
		out.println(max[0]);
		int left = a[whoLeft].left;
		int right = max[1];
		for (int i = 0; i < n; i++) {
			if (a[i].left <= left && a[i].right >= right && a[i].v <= right && a[i].v >= left) {
				out.print((a[i].id + 1) + " ");
			}
		}
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
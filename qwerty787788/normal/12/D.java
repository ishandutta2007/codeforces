import java.io.*;
import java.util.*;

public class CF {

	class People implements Comparable<People> {
		int x, y, z;

		public People(int x, int y, int z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}

		@Override
		public int compareTo(People o) {
			if (x != o.x)
				return Integer.compare(x, o.x);
			if (y != o.y)
				return Integer.compare(y, o.y);
			if (z != o.z)
				return Integer.compare(z, o.z);
			return 0;
		}
	}

	class SegmentTree {
		int n;
		int[] max;

		SegmentTree(int n) {
			this.n = n;
			max = new int[4 * n];
		}

		int get(int v, int l, int r, int need) {
			if (l == r)
				return max[v];
			int m = (l + r) / 2;
			if (m >= need)
				return Math.max(max[v], get(v * 2 + 1, l, m, need));
			return Math.max(max[v], get(v * 2 + 2, m + 1, r, need));
		}

		void update(int v, int l, int r, int needL, int needR, int val) {
			if (needR < needL)
				return;
			if (l == needL && r == needR) {
				max[v] = Math.max(max[v], val);
				return;
			}
			int m = (l + r) / 2;
			update(v * 2 + 1, l, m, needL, Math.min(m, needR), val);
			update(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, val);
		}

		int get(int v) {
			return get(0, 0, n - 1, v);
		}

		void update(int l, int r, int val) {
			update(0, 0, n - 1, l, r, val);
		}
	}

	int stupid(int[] a, int[] b, int[] c) {
		int n = a.length;
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[j] > a[i] && b[j] > b[i] && c[j] > c[i]) {
					res++;
					break;
				}
		return res;
	}

	Random rnd = new Random(123);

	int[] getRandomArray(int n) {
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = rnd.nextInt(100);
		return res;
	}

	void realSolve() {
		// long sta = System.currentTimeMillis();
		for (int iet = 0; iet < 1; iet++) {
			// System.err.println(iet);
			int n = in.nextInt();
			// int n = 500000;
			// int[] a = getRandomArray(n);
			// int[] b = getRandomArray(n);
			// int[] c = getRandomArray(n);

			int[] a = new int[n];
			int[] b = new int[n];
			int[] c = new int[n];

			for (int i = 0; i < n; i++)
				a[i] = in.nextInt();
			for (int i = 0; i < n; i++)
				b[i] = in.nextInt();
			for (int i = 0; i < n; i++)
				c[i] = in.nextInt();

			if (iet == 5) {
				System.err.println("!");
			}
			// long sta1 = System.currentTimeMillis();
			ArrayList<Integer> xx = new ArrayList<>();
			TreeSet<Integer> ts = new TreeSet<>();
			for (int i = 0; i < n; i++) {
				// ts.add(a[i]);
				// ts.add(b[i]);
				// ts.add(c[i]);
				// xx.add(a[i]);
				xx.add(b[i]);
				// xx.add(c[i]);
			}
			Collections.sort(xx);
			HashMap<Integer, Integer> hm = new HashMap<>();
			int it = 0;
			int last = Integer.MIN_VALUE;
			for (int x : xx) {
				if (x != last) {
					hm.put(x, it++);
					last = x;
				}
			}
			People[] p = new People[n];
			for (int i = 0; i < n; i++) {
				p[i] = new People(a[i], hm.get(b[i]), c[i]);
			}
			Arrays.sort(p);
			SegmentTree st = new SegmentTree(it + 1);
			int res = 0;
			int checkLast = n - 1;
			for (int i = n - 1; i >= 0; i--) {
				while (checkLast != -1 && p[checkLast].x == p[i].x) {
					int getMinZ = st.get(p[checkLast].y);
					if (getMinZ > p[checkLast].z)
						res++;
					checkLast--;
				}
				st.update(0, p[i].y - 1, p[i].z);
			}
			// if (res != stupid(a, b, c))
			// throw new AssertionError(Arrays.toString(a) + "\n"
			// + Arrays.toString(b) + "\n" + Arrays.toString(c));
			out.println(res);
		}
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solve() {
		in = new InputReader(new File("object.in"));
		try {
			out = new PrintWriter(new File("object.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		realSolve();

		out.close();
	}

	void solveIO() {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	public static void main(String[] args) {
		new CF().solveIO();
	}
}
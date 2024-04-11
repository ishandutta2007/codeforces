import java.io.*;
import java.util.*;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CF {
	FastScanner in;
	PrintWriter out;

	String imp = "Impossible";

	ArrayList<Integer>[] g;

	int[] left;
	boolean[] was;
	int[] leftSide, rightSide;
	int[] whereOnLeft;
	int[] right;

	boolean go(int v) {
		if (was[v]) {
			return false;
		}
		was[v] = true;
		for (int to : g[v]) {
			int rId = rightSide[to];
			int pos = whereOnLeft[rId];
			if (right[pos] != -1 && whereOnLeft[rightSide[right[pos]]] == v) {
				continue;
			}
			if (left[to] == -1 || go(left[to])) {
				left[to] = v;
				right[v] = to;
				return true;
			}
		}
		return false;
	}

	void solve() {
		final int max = 100000;
		boolean[] isPrime = new boolean[max];
		Arrays.fill(isPrime, true);
		for (int i = 2; i < max; i++)
			if (isPrime[i])
				for (int j = i + i; j < max; j += i) {
					isPrime[j] = false;
				}
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		long START = System.currentTimeMillis();
		int[] id = new int[n];
		for (int i = 0; i < n; i++) {
			id[i] = i;
		}
		Random rnd = new Random(123);
		int even = 0;
		for (int i = 0; i < n; i++)
			if (a[i] % 2 == 0)
				even++;
		if (even * 2 != n) {
			out.println(imp);
			return;
		}
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		was = new boolean[n];
		right = new int[n];
		left = new int[n];
		while (System.currentTimeMillis() - START < 1500) {
			leftSide = id.clone();
			for (int i = 0; i < n; i++) {
				int x = rnd.nextInt(i + 1);
				int tmp = leftSide[x];
				leftSide[x] = leftSide[i];
				leftSide[i] = tmp;
			}
			rightSide = id.clone();
			for (int i = 0; i < n; i++) {
				int x = rnd.nextInt(i + 1);
				int tmp = rightSide[x];
				rightSide[x] = rightSide[i];
				rightSide[i] = tmp;
			}
			whereOnLeft = new int[n];
			for (int i = 0; i < n; i++) {
				whereOnLeft[leftSide[i]] = i;
			}
			for (int i = 0; i < n; i++) {
				g[i].clear();
				for (int j = 0; j < n; j++) {
					int x1 = a[leftSide[i]];
					int y1 = a[rightSide[j]];
					if (isPrime[x1 + y1]) {
						g[i].add(j);
					}
				}
			}
			Arrays.fill(left, -1);
			boolean ok = true;
			for (int i = 0; i < n; i++) {
				Arrays.fill(was, false);
				if (!go(i)) {
					ok = false;
					break;
				}
			}
			if (ok) {
				ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
				Arrays.fill(was, false);
				for (int i = 0; i < n; i++) {
					if (!was[i]) {
						ArrayList<Integer> cur = new ArrayList<>();
						int now = i;
						while (true) {
							was[now] = true;
							cur.add(leftSide[now]);
							now = whereOnLeft[rightSide[right[now]]];
							if (now == i) {
								break;
							}
						}
						ans.add(cur);
					}
				}
				out.println(ans.size());
				for (ArrayList<Integer> x : ans) {
					out.print(x.size());
					if (x.size() == 2) {
						throw new AssertionError();
					}
					for (int i = 0; i < x.size(); i++) {
						if (!isPrime[a[x.get(i)] + a[x.get((i + 1) % x.size())]]) {
							throw new AssertionError();
						}
					}
					for (int y : x) {
						out.print(" " + (1 + y));
					}
					out.println();
				}
				return;
			}
		}
		out.println(imp);
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
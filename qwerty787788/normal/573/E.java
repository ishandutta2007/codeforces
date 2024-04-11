import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Fenwick {
		long[] a;
		int n;

		Fenwick(int n) {
			this.n = n;
			a = new long[n];
		}

		long get(int r) {
			long res = 0;
			for (; r >= 0; r = (r & (r + 1)) - 1) {
				res += a[r];
			}
			return res;
		}

		void add(int v, long value) {
			for (; v < n; v = v | (v + 1)) {
				a[v] += value;
			}
		}
	}

	long getAnswer(int[] a) {
		long START = System.currentTimeMillis();
		ArrayList<Integer> negative = new ArrayList<>();
		long sum = 0, result = 0;
		for (int i = a.length - 1; i >= 0; i--) {
			if (a[i] >= 0) {
				sum += a[i];
				result += sum;
			} else {
				negative.add(i);
			}
		}
		int n = a.length;
		Fenwick used = new Fenwick(n);
		Fenwick vals = new Fenwick(n);
		for (int i = 0; i < n; i++) {
			if (a[i] >= 0) {
				used.add(i, 1);
				vals.add(i, a[i]);
			}
		}
		boolean[] usedNow = new boolean[n];
		while (System.currentTimeMillis() - START < 5000) {
			Collections.shuffle(negative);
			for (int pos : negative) {
				if (!usedNow[pos]) {
					long change = vals.get(n - 1) - vals.get(pos) + a[pos]
							* (used.get(pos) + 1);
					if (change > 0) {
						result += change;
						used.add(pos, 1);
						usedNow[pos] = true;
						vals.add(pos, a[pos]);
					}
				} else {
					long change = -vals.get(n - 1) + vals.get(pos - 1) - a[pos]
							* (used.get(pos - 1));
					if (change > 0) {
						result += change;
						used.add(pos, -1);
						usedNow[pos] = false;
						vals.add(pos, -a[pos]);
					}
				}
			}
		}
		return result;
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		out.println(getAnswer(a));
	}

	void run() {
		try {
			in = new FastScanner(new File("B.in"));
			out = new PrintWriter(new File("B.out"));

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
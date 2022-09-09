import java.io.*;
import java.util.*;

public class Copy_4_of_CF {
	FastScanner in;
	PrintWriter out;

	class O implements Comparable<O> {
		int x, y;

		public O(int x, int y) {
			super();
			this.x = Math.min(x, y);
			this.y = Math.max(x, y);
		}

		@Override
		public int compareTo(O o) {
			if (x != o.x) {
				return Integer.compare(x, o.x);
			}
			return Integer.compare(y, o.y);
		}

	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		ArrayList<Integer> pos = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i + 1 < n; i++) {
			if (i % 2 == 0) {
				if (a[i + 1] <= a[i]) {
					pos.add(i);
				}
			} else {
				if (a[i + 1] >= a[i]) {
					pos.add(i);
				}
			}
		}
		if (pos.size() > 20) {
			out.println(0);
			return;
		}
		ArrayList<Integer> inter = new ArrayList<>();
		HashSet<Integer> was = new HashSet<>();
		for (int x : pos) {
			if (!was.contains(x)) {
				inter.add(x);
				was.add(x);
			}
			if (!was.contains(x + 1)) {
				inter.add(x + 1);
				was.add(x + 1);
			}
		}
		int result = 0;
		ArrayList<Integer> inter2 = inter;
		if (inter.size() <= 3) {
			inter2 = new ArrayList<>();
			for (int x = 0; x < n; x++) {
				inter2.add(x);
			}
		}
		ArrayList<O> o = new ArrayList<>();
		for (int f : inter) {
			for (int s : inter2) {
				int tmp = a[f];
				a[f] = a[s];
				a[s] = tmp;
				{
					boolean ok = true;
					for (int x : pos) {
						if (x % 2 == 0) {
							if (a[x + 1] <= a[x]) {
								ok = false;
								break;
							}
						} else {
							if (a[x + 1] >= a[x]) {
								ok = false;
								break;
							}
						}
					}
					for (int x : new int[] { f - 1, f, s - 1, s }) {
						if (x >= 0 && x + 1 < n) {
							if (x % 2 == 0) {
								if (a[x + 1] <= a[x]) {
									ok = false;
									break;
								}
							} else {
								if (a[x + 1] >= a[x]) {
									ok = false;
									break;
								}
							}
						}
					}
					if (ok) {
						o.add(new O(f, s));
					}
				}
				tmp = a[f];
				a[f] = a[s];
				a[s] = tmp;
			}
		}
		Collections.sort(o);
		for (int i = 0; i < o.size(); i++) {
			if (i == 0
					|| (o.get(i).x != o.get(i - 1).x || o.get(i).y != o
							.get(i - 1).y)) {
				result++;
			}
		}
		out.println(result);
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test2.out"));

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
		new Copy_4_of_CF().runIO();
	}
}
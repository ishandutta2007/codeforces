import java.io.*;
import java.util.*;
import java.util.function.Function;
import java.util.function.ToDoubleFunction;
import java.util.function.ToIntFunction;
import java.util.function.ToLongFunction;

public class CF {
	FastScanner in;
	PrintWriter out;

	class O implements Comparable<O> {
		int l, r, id;

		public O(int l, int r, int id) {
			super();
			this.l = l;
			this.r = r;
			this.id = id;
		}

		public int compareTo(O arg0) {
			if (r != arg0.r) {
				return Integer.compare(r, arg0.r);
			}
			return Integer.compare(id, arg0.id);
		}

	}

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		O[] a = new O[n];
		for (int i = 0; i < n; i++) {
			a[i] = new O(in.nextInt(), in.nextInt(), i);
		}
		int best = -1;
		int bestL = -1, bestR = -1;
		Arrays.sort(a, new Comparator<O>() {
			public int compare(O arg0, O arg1) {
				return Integer.compare(arg0.l, arg1.l);
			}
		});
		TreeSet<O> ts = new TreeSet<CF.O>();
		for (O o : a) {
			ts.add(o);
			while (ts.size() > k) {
				ts.pollFirst();
			}
			if (ts.size() == k) {
				int l = o.l;
				int r = Math.max(l - 1, ts.first().r);
				if (r - l + 1 > best) {
					best = r - l + 1;
					bestL = l;
					bestR = r;
				}
			}
		}
		out.println(best);
		for (int i = 0; i < n; i++) {
			if (a[i].l <= bestL && a[i].r >= bestR || best == 0) {
				out.print(a[i].id + 1);
				out.print(" ");
				k--;
				if (k == 0) {
					break;
				}
			}
		}
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
		new CF().runIO();
	}
}
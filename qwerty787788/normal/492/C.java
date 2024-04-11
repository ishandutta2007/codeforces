import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Obj implements Comparable<Obj>{
		int max;
		int cost;

		public Obj(int max, int cost) {
			super();
			this.max = max;
			this.cost = cost;
		}

		@Override
		public int compareTo(Obj o) {
			return Integer.compare(cost, o.cost);
		}

	}

	void solve() {
		int n = in.nextInt();
		int r = in.nextInt();
		long need = in.nextInt() * 1L * n;
		Obj[] a = new Obj[n];
		for (int i = 0; i < n; i++) {
			int ai = in.nextInt();
			int bi = in.nextInt();
			need -= ai;
			a[i] = new Obj(r - ai, bi);
		}
		Arrays.sort(a);
		long result = 0;
		for (int i = 0; i < n; i++) {
			int use = (int) Math.min(need, a[i].max);
			if (use < 0)
				use = 0;
			result += use * 1L * a[i].cost;
			need -= use;
		}
		out.println(result);
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
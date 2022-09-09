import java.io.*;
import java.util.*;

public class CF {
	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int h = in.nextInt();
		h = 1;
		int[] m = new int[n];
		for (int i = 0; i < n; i++) {
			m[i] = in.nextInt();
		}
		int[] v = new int[n];
		for (int i = 0; i < n; i++) {
			v[i] = in.nextInt();
		}
		Lemming[] all = new Lemming[n];
		for (int i = 0; i < n; i++) {
			all[i] = new Lemming(m[i], v[i], i);
		}
		Arrays.sort(all);
		int[] best = new int[k];
		int[] cur = new int[k];
		double left = 0, right = 1e8 + 1;
		for (int iter = 0; iter < 120; iter++) {
			double mid = (left + right) / 2;
			int tot = 0;
			for (Lemming lem : all) {
				double needTime = (tot + 1) * h;
				if (needTime <= mid * (lem.v + 0.)) {
					cur[tot++] = lem.id;
					if (tot == k) {
						break;
					}
				}
			}
			if (tot == k) {
				right = mid;
				for (int i = 0; i < k; i++) {
					best[i] = cur[i];
				}
			} else {
				left = mid;
			}
		}
	
		for (int vv : best) {
			out.print(vv + 1);
			out.print(" ");
		}
	}

	class Rational implements Comparable<Rational> {
		long x, y;

		public Rational(long x, long y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Rational o) {
			return Long.compare(x * o.y, o.x * y);
		}

	}

	class Lemming implements Comparable<Lemming> {
		int m, v, id;

		public Lemming(int m, int v, int id) {
			super();
			this.m = m;
			this.v = v;
			this.id = id;
		}

		@Override
		public int compareTo(Lemming o) {
			if (m == o.m) {
				return Integer.compare(v, o.v);
			}
			return Integer.compare(m, o.m);
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

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class O implements Comparable<O> {
		int id, pos;

		public O(int id, int pos) {
			super();
			this.id = id;
			this.pos = pos;
		}

		@Override
		public int compareTo(O o) {
			return Integer.compare(pos, o.pos);
		}

	}

	int lessOrEq(O[] a, int pos) {
		int l = 0, r = a.length;
		while (r - l > 1) {
			int m = (l + r) >>> 1;
			if (a[m].pos <= pos) {
				l = m;
			} else {
				r = m;
			}
		}
		return a[l].id;
	}

	int biggerOrEq(O[] a, int pos) {
		int l = -1, r = a.length - 1;
		while (r - l > 1) {
			int m = (l + r) >>> 1;
			if (a[m].pos >= pos) {
				r = m;
			} else {
				l = m;
			}
		}
		return a[r].id;
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		O[] a = new O[n];
		O[] b = new O[n];
		for (int i = 0; i < n; i++) {
			a[i] = new O(i, in.nextInt());
			b[i] = a[i];
		}
		Arrays.sort(a);
		for (int i = 0; i < m; i++) {
			int start = in.nextInt() - 1;
			int len = in.nextInt();
			while (true) {
				int first = lessOrEq(a, b[start].pos + len);
				int moreLength = len - (b[first].pos - b[start].pos);
				int second = biggerOrEq(a, b[first].pos - moreLength);
				int nowLength = moreLength - (b[first].pos - b[second].pos);
				if (second == start) {
					if (nowLength == len) {
						out.println(start + 1);
						break;
					} else {
						len %= (len - nowLength);
					}
				} else {
					start = second;
					len = nowLength;
				}
			}
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
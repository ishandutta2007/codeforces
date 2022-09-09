import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] fr = new int[m];
		int[] to = new int[m];
		for (int i = 0; i < m; i++) {
			fr[i] = in.nextInt() - 1;
			to[i] = in.nextInt() - 1;
		}
		int left = 0, right = m + 1;
		ArrayList<Integer>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		int[] ins = new int[n];
		int[] q = new int[n];
		while (right - left > 1) {
			int mid = (left + right) >> 1;
			for (int i = 0; i < n; i++) {
				g[i].clear();
			}
			for (int i = 0; i < mid; i++) {
				g[fr[i]].add(to[i]);
			}
			Arrays.fill(ins, 0);
			for (int i = 0; i < mid; i++) {
				ins[to[i]]++;
			}
			int qIt = 0, qSz = 0;
			for (int i = 0; i < n; i++) {
				if (ins[i] == 0) {
					q[qSz++] = i;
				}
			}
			boolean ok = true;
			while (qIt < qSz) {
				if (qIt + 1 != qSz) {
					ok = false;
					break;
				}
				int v = q[qIt++];
				for (int to1 : g[v]) {
					ins[to1]--;
					if (ins[to1] == 0) {
						q[qSz++] = to1;
					}
				}
			}
			if (qSz != n) {
				ok = false;
			}
			if (ok) {
				right = mid;
			} else {
				left = mid;
			}
		}
		out.println(right == m + 1 ? -1 : right);

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
		new CF().runIO();
	}
}
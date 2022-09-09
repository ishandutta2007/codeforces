import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < n; j++) {
				g[i][j] = s.charAt(j) == '1';
			}
		}
		boolean[] was = new boolean[n];
		int[] ans = new int[n];
		int[] q = new int[n];
		for (int i = 0; i < n; i++) {
			if (!was[i]) {
				int qIt = 0, qSz = 1;
				q[0] = i;
				was[i] = true;
				ArrayList<Integer> all = new ArrayList<>();
				while (qIt < qSz) {
					int v = q[qIt++];
					all.add(v);
					for (int j = 0; j < n; j++) {
						if (!was[j] && g[v][j]) {
							was[j] = true;
							q[qSz++] = j;
						}
					}
				}
				ArrayList<Integer> vals = new ArrayList<>();
				for (int j = 0; j < all.size(); j++) {
					vals.add(a[all.get(j)]);
				}
				Collections.sort(vals);
				Collections.sort(all);
				for (int j = 0; j < vals.size(); j++) {
					ans[all.get(j)] = vals.get(j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
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
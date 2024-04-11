import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] a;
	ArrayList<Integer>[] g;

	long[][] go(int v, int p) {
		long[][] res = new long[3][3];
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}
			long[][] child = go(to, v);
			long[][] next = new long[3][3];
			for (int neP = 0; neP < 2; neP++) {
				for (int wasP = 0; wasP + neP < 3; wasP++) {
					for (int cnt1 = 0; cnt1 < 3; cnt1++) {
						for (int cnt2 = 0; cnt2 + cnt1 < 3; cnt2++) {
							next[wasP + neP][cnt1 + cnt2] = Math.max(next[wasP
									+ neP][cnt1 + cnt2], res[wasP][cnt1]
									+ child[neP][cnt2]);
						}
					}
				}
			}
			res = next;
		}
		long[][] realRes = new long[2][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i < 2) {
					realRes[i][j] = Math.max(realRes[i][j], res[i][j]
							+ (i == 1 ? a[v] : 0));
				}
				if (j < 2) {
					realRes[0][j + 1] = Math.max(realRes[0][j + 1], res[i][j]
							+ a[v]);
				}
			}
		}
		return realRes;
	}

	void solve() {
		int n = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i + 1 < n; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		long[][] answer = go(0, -1);
		out.println(answer[0][2]);
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
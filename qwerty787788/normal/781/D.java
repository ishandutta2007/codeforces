import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		final int LOG = 62;
		BitSet[][][] go = new BitSet[2][LOG][n];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < LOG; j++) {
				for (int k = 0; k < n; k++) {
					go[i][j][k] = new BitSet(n);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			int type = in.nextInt();
			go[type][0][fr].set(to);
		}
		for (int log = 1; log < LOG; log++) {
			for (int i = 0; i < n; i++) {
				for (int type = 0; type < 2; type++) {
					for (int j = 0; j < n; j++) {
						if (go[type][log - 1][i].get(j)) {
							go[type][log][i].or(go[1 - type][log - 1][j]);
						}
					}
				}
			}
		}
		long maxLen = 0;
		BitSet can = new BitSet();
		can.set(0);
		int curType = 0;
		for (int i = LOG - 1; i >= 0; i--) {
			BitSet next = new BitSet();
			for (int j = 0; j < n; j++) {
				if (can.get(j)) {
					next.or(go[curType][i][j]);
				}
			}
			if (next.cardinality() != 0) {
				curType = 1 - curType;
				can = next;
				maxLen += 1L << i;
			}
		}
		if (maxLen > (long) 1e18) {
			out.println(-1);
		} else {
			out.println(maxLen);
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
		new D().runIO();
	}
}
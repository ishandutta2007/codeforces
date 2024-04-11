import java.io.*;
import java.util.*;

public class CF {

	int[] res;

	void upd(int v, int l, int r, int need, int val, int type) {
		if (l == r) {
			res[v] = val;
		} else {
			int m = (l + r) >> 1;
			if (m >= need) {
				upd(v * 2 + 1, l, m, need, val, 1 - type);
			} else {
				upd(v * 2 + 2, m + 1, r, need, val, 1 - type);
			}
			if (type == 0) {
				res[v] = res[v * 2 + 1] | res[v * 2 + 2];
			} else {
				res[v] = res[v * 2 + 1] ^ res[v * 2 + 2];
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[1 << n];
		res = new int[4 * (1 << n)];
		int firstOperation = 1 - (n % 2);
		for (int i = 0; i < 1 << n; i++) {
			a[i] = in.nextInt();
			upd(0, 0, (1 << n) - 1, i, a[i], firstOperation);
		}
		for (int i = 0; i < m; i++) {
			int v = in.nextInt() - 1;
			int val = in.nextInt();
			upd(0, 0, (1 << n) - 1, v, val, firstOperation);
			out.println(res[0]);
		}
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
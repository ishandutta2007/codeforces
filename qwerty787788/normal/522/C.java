import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			int m = in.nextInt();
			int k = in.nextInt();
			int[] a = new int[k];
			for (int i = 0; i < k; i++) {
				a[i] = in.nextInt();
			}
			int[] remMore = new int[k];
			boolean fail = false;
			int first = 0, second = 0;
			for (int i = 0; i < m - 1; i++) {
				int tj = in.nextInt() - 1;
				int rj = in.nextInt();
				if (rj == 1) {
					fail = true;
				}
				if (fail) {
					if (tj == -1) {
						second++;
					} else {
						remMore[tj]++;
					}
				} else {
					if (tj == -1) {
						first++;
					} else {
						a[tj]--;
					}
				}
			}
			int minNeed = Integer.MAX_VALUE / 2;
			for (int i = 0; i < k; i++) {
				if (remMore[i] == 0) {
					minNeed = Math.min(minNeed, a[i]);
				}
			}
			for (int i = 0; i < k; i++) {
				if (remMore[i] == 0 && a[i] <= first) {
					out.print("Y");
				} else {
					if (first + second - minNeed - a[i] + remMore[i] >= 0) {
						out.print("Y");
					} else {
						out.print("N");
					}
				}
			}
			out.println();
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
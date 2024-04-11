import java.io.*;
import java.util.*;

public class CFC {
	FastScanner in;
	PrintWriter out;

	double probMoreOrEq(int min, int max, int moreOrEq) {
		if (moreOrEq > max) {
			return 0.0;
		}
		if (moreOrEq <= min) {
			return 1.0;
		}
		return (max - moreOrEq + 1) / (max - min + 1.);
	}

	double probLessOrEq(int min, int max, int lessOrEq) {
		return 1 - probMoreOrEq(min, max, lessOrEq + 1);
	}

	void solve() {
		int n = in.nextInt();
		int[] l = new int[n];
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = in.nextInt();
			r[i] = in.nextInt();
		}
		double result = 0;
		final int MAX = 10000 + 123;
		for (int value = 0; value <= MAX; value++) {
			for (int winner = 0; winner < n; winner++) {
				for (int second = 0; second < n; second++) {
					if (second == winner) {
						continue;
					}
					if (l[second] > value || r[second] < value) {
						continue;
					}
					double pr = 1.0 / (r[second] - l[second] + 1.);
					for (int k = 0; k < n; k++) {
						if (k == second) {
							continue;
						}
						if (k == winner) {
							if (winner > second) {
								pr *= probMoreOrEq(l[k], r[k], value);
							} else {
								pr *= probMoreOrEq(l[k], r[k], value + 1);
							}
						} else {
							if (k < second) {
								pr *= probLessOrEq(l[k], r[k], value);
							} else {
								pr *= probLessOrEq(l[k], r[k], value - 1);
							}
						}
					}
					result += pr * value;
				}
			}
		}
		out.println(result);
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
		new CFC().runIO();
	}
}
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int m = in.nextInt();
		int t = in.nextInt();
		int r = in.nextInt();
		final int ADD = 333;
		int[] cnt = new int[ADD * 3];
		boolean[] need = new boolean[ADD * 3];
		for (int i = 0; i < m; i++) {
			int wi = in.nextInt() + ADD;
			need[wi] = true;
		}
		boolean[] start = new boolean[ADD * 3];
		int result = 0;
		for (int i = 0; i < need.length; i++) {
			if (need[i]) {
				while (cnt[i] < r) {
					int from = i;
					while (from + t - 1 >= i && start[from]) {
						from--;
					}
					if (from + t - 1 < i) {
						out.println(-1);
						return;
					}
					result++;
					start[from] = true;
					for (int j = 0; j < t; j++) {
						cnt[from + j]++;
					}
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
		new CF().runIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;
	
	boolean can(int len, int sum) {
		return sum >=0 && sum <= 9 * len;
	}

	void solve() {
		int len = in.nextInt();
		int sum = in.nextInt();
		if (len == 1) {
			if (sum >= 0 && sum < 10) {
				out.println(sum + " "+  sum);
				return;
			}
			out.println("-1 -1");
			return;
		}
		int maxSum = len * 9;
		int minSum = 1;
		if (minSum <= sum && maxSum >= sum) {
			int nsum = sum;
			for (int i = 0; i < len; i++) {
				for (int use = 0; use < 10; use++) {
					if (use == 0 && i == 0)
						continue;
					if (can(len - i - 1, nsum - use)) {
						out.print(use);
						nsum -= use;
						break;
					}
				}
			}
			out.print(" ");
			nsum = sum;
			for (int i = 0; i < len; i++) {
				for (int use = 9; use >= 0; use--) {
					if (use == 0 && i == 0)
						continue;
					if (can(len - i - 1, nsum - use)) {
						out.print(use);
						nsum -= use;
						break;
					}
				}
			}
			out.println();
		} else {
			out.println("-1 -1");
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
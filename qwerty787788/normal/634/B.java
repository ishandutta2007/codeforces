import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		long sum = in.nextLong();
		long xor = in.nextLong();
		long[] dp = new long[] { 1, 0 };
		for (int bit = 0; bit < 50; bit++) {
			long[] ndp = new long[2];
			long needSum = (sum >> bit) & 1;
			long needXor = (xor >> bit) & 1;
			for (int was = 0; was < 2; was++) {
				for (int b1 = 0; b1 < 2; b1++) {
					for (int b2 = 0; b2 < 2; b2++) {
						long mySum = (b1 + b2 + was) % 2;
						long myXor = b1 ^ b2;
						if (myXor == needXor && mySum == needSum) {
							ndp[(b1 + b2 + was) >> 1] += dp[was];
						}
					}
				}
			}
			dp = ndp;
		}
		out.println(dp[0] - (sum == xor ? 2 : 0));
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
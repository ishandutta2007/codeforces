import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		boolean[] def = new boolean[n + 1];
		int[] coef = new int[n + 1];
		boolean allDef = true;
		boolean compMove = true;
		for (int i = 0; i <= n; i++) {
			String s = in.next();
			if (!s.equals("?")) {
				def[i] = true;
				coef[i] = Integer.parseInt(s);
				compMove = !compMove;
			} else {
				allDef = false;
			}
		}
		if (allDef) {
			Random rnd = new Random();
			for (int it = 0; it < 5; it++) {
				final int mod = BigInteger
						.valueOf((int) 1e9 + rnd.nextInt(100000))
						.nextProbablePrime().intValue();
				long mul = 1;
				long res = 0;
				for (int i = 0; i <= n; i++) {
					res += mul * coef[i];
					res %= mod;
					mul = (mul * k) % mod;
				}
				if (res != 0) {
					out.println("No");
					return;
				}
			}
			out.println("Yes");
		} else {
			if (k == 0) {
				if (def[0]) {
					out.println(coef[0] == 0 ? "Yes" : "No");
				} else {
					out.println(compMove ? "No" : "Yes");
				}
			} else {
				out.println(n % 2 == 0 ? "No" : "Yes");
			}
		}
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
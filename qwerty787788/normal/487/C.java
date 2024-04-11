import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] res;

	boolean go(boolean[] was, boolean[] was2, int last, int from) {
		int n = was.length;
		if (from == n) {
			for (int i = 0; i < n; i++) {
				out.print(res[i] + " ");
			}
			return true;
		} else {
			for (int i = 0; i < n; i++) {
				if (!was[i]) {
					int ne = (last * (i + 1) % n);
					if (!was2[ne]) {
						was[i] = true;
						was2[ne] = true;
						res[from] = i + 1;
						if (go(was, was2, ne, from + 1)) {
							return true;
						}
						was[i] = false;
						was2[ne] = false;
					}
				}
			}
			return false;
		}
	}

	void solve() {
		int n = in.nextInt();
		if (n != 4 && n != 1 && !BigInteger.valueOf(n).isProbablePrime(100)) {
			out.println("NO");
			return;
		}
		if (n < 10) {
			boolean[] was = new boolean[n];
			boolean[] was2 = new boolean[n];
			res = new int[n];
			out.println("YES");
			go(was, was2, 1, 0);
		} else {
			out.println("YES");
			BigInteger MOD = BigInteger.valueOf(n);
			for (int i = 1; i <= n; i++) {
				if (i == 1) {
					out.print("1 ");
				} else {
					int val = (int) (i
							* 1L
							* BigInteger.valueOf(i - 1).modInverse(MOD)
									.intValue() % n);
					if (i == n) {
						val = n;
					}
					out.print(val + " ");
				}
			}
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

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
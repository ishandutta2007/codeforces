import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		final int MAX = 2222;
		BigInteger[] a = new BigInteger[n];
		for (int i = 0; i < n; i++) {
			a[i] = new BigInteger(in.next());
		}
		BitSet[] repr = new BitSet[MAX];
		BigInteger[] value = new BigInteger[MAX];
		for (int i = 0; i < n; i++) {
			BigInteger cur = a[i];
			BitSet what = new BitSet(n);
			what.set(i);
			boolean f = false;
			for (int j = 0; j < MAX; j++) {
				if (cur.testBit(j)) {
					if (repr[j] == null) {
						f = true;
						repr[j] = what;
						value[j] = cur;
						break;
					} else {
						cur = cur.xor(value[j]);
						what.xor(repr[j]);
					}
				}
			}
			if (f) {
				out.println(0);
			} else {
				what.set(i, false);
				int cnt = 0;
				for (int j = 0; j < n; j++)
					if (what.get(j)) {
						cnt++;
					}
				out.print(cnt);
				for (int j = 0; j < n; j++)
					if (what.get(j)) {
						out.print(" " + j);
					}
				out.println();
			}
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
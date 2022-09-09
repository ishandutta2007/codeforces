import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	final int mod = (int) 1e9 + 7;
	final int MAX = (int) 1e5 + 10;
	int[] fact, factInv;

	void prec() {
		fact = new int[MAX];
		fact[0] = 1;
		for (int i = 1; i < MAX; i++) {
			fact[i] = (int) (fact[i - 1] * 1L * i % mod);
		}
		factInv = new int[MAX];
		BigInteger modI = BigInteger.valueOf(mod);
		for (int i = 0; i < MAX; i++) {
			factInv[i] = BigInteger.valueOf(fact[i]).modInverse(modI)
					.intValue();
		}
	}

	int c(int n, int k) {
		if (k == 0 || k == n) {
			return 1;
		}
		int res = (int) (fact[n] * 1L * factInv[n - k] % mod * 1L * factInv[k] % mod);
		return res;
	}

	class O implements Comparable<O> {
		int x, y;

		public O(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(O o) {
			return Integer.compare(x + y, o.x + o.y);
		}

	}

	void solve() {
		int n = 6;
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int res = 0;
		while (true) {
			boolean ch = false;
			for (int i = 0; i < n; i++) {
				if (a[i] > 0 && a[(i + 2) % n] > 0) {
					res += a[(i + 1) % n] * 2 + 1;
					a[(i + 1) % n]++;
					a[i]--;
					a[(i + 2) % n]--;
					ch = true;
				}
			}
			if (!ch) {
				break;
			}
		}
		out.println(res);
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return null;
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	final int mod = (int) 1e9 + 7;
	final int MAX = 2 * (int) 1e5 + 10;
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
		prec();
		int h = in.nextInt();
		int w = in.nextInt();
		int n = in.nextInt();
		O[] a = new O[n + 1];
		for (int i = 0; i < n; i++) {
			a[i] = new O(in.nextInt(), in.nextInt());
		}
		a[n] = new O(h, w);
		Arrays.sort(a);
		int[] dp = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			dp[i] = c(a[i].x + a[i].y - 2, a[i].x - 1);
			for (int j = 0; j < i; j++) {
				if (a[j].x <= a[i].x && a[j].y <= a[i].y) {
					int sub = (int) (c(a[i].x - a[j].x + a[i].y - a[j].y,
							a[i].x - a[j].x) * 1L * dp[j] % mod);
					dp[i] -= sub;
					if (dp[i] < 0) {
						dp[i] += mod;
					}
				}
			}
		}
		out.println(dp[n]);
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
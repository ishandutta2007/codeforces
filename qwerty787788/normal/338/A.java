import java.io.*;
import java.util.*;

public class CF {

	long mod = (long) 1e9 + 9;

	class Pair {
		long a, b;

		public Pair(long a, long b) {
			super();
			this.a = a % mod;
			this.b = b % mod;
		}

	}

	int k;

	long pow(long n, long k) {
		if (k == 0)
			return 1;
		long m1 = pow(n, k / 2);
		m1 = (m1 * m1) % mod;
		if (k % 2 != 0)
			m1 = (m1 * n) % mod;
		return m1;
	}

	long st(int n, int m, int k) {
		int parts = n / k;
		int used = n - m;
		if (parts > n - m) {
			long cur = 0;
			int counter = 0;
			int need = parts - (n - m);
			for (int i = 1; i <= n; i++) {
				if (counter + 1 == k && need <= 0) {
					counter = 0;
					used--;
				} else {
					counter++;
					cur++;
					if (counter == k) {
						counter = 0;
						cur = (cur * 2) % mod;
						need--;
					}
				}
			}
			if (used < 0)
				throw new AssertionError();
			return cur;
		} else {
			return m;
		}
	}

	long mysol(int n, int m, int k) {
		this.k = k;
		int parts = n / k;
		if (parts > n - m) {
			long ost = n - (n - m) * k;
			long power = ost / k;
			long res = pow(2, power + 1);
			long cur = ((res - 2 + mod) % mod) * k;
			cur %= mod;
			cur += Math.max(0, m - power * k);
			cur %= mod;
			return cur;
		} else {
			return m;
		}
	}

	void realSolve() throws IOException {
		 int n = in.nextInt();
		 int m = in.nextInt();
		 k = in.nextInt();
		 out.println(mysol(n, m, k));
		/*Random rnd = new Random(123);
		for (int t = 0; t < 10000; t++) {
			System.err.println(t);
			int n = rnd.nextInt(100) + 2;
			int m = rnd.nextInt(n + 1);
			int k = rnd.nextInt(n - 1) + 2;

			if (t == 16) {
				System.err.println("!");
			}
			long r1 = mysol(n, m, k);
			long r2 = st(n, m, k);
			if (r1 != r2)
				throw new AssertionError(r1 + " " + r2);

		}*/
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

		realSolve();

		out.close();

	}

	void solve() throws IOException {
		in = new InputReader(new File("input.txt"));
		out = new PrintWriter(new File("output.txt"));

		realSolve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
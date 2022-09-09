import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	long mod = (long) 1e9 + 7;
	int MAX = 222000;
	long[] fact;
	long[] inv;

	long c(int n, int k) {
		long res = fact[n];
		res = (res * inv[n - k]) % mod;
		res = (res * inv[k]) % mod;
		return res;
	}

	void realSolve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		int g = in.nextInt();
		int firstOne = 0;
		if (g != 0) {
			firstOne++;
		}
		long res = 0;
		int MAX = 222000;
		BigInteger mo = BigInteger.valueOf(mod);
		fact = new long[MAX];
		fact[0] = 1;
		for (int i = 1; i < MAX; i++)
			fact[i] = (fact[i - 1] * i) % mod;
		inv = new long[MAX];
		for (int i = 0; i < MAX; i++)
			inv[i] = BigInteger.valueOf(fact[i]).modInverse(mo).intValue();
		for (int one = firstOne; one < n + m - 1; one += 2) {
			int cntZerosOst = n - one;
			int cntOnesOst = m - 1;
			if (cntOnesOst >= 0 && cntZerosOst >= 0) {
				res += c(cntOnesOst + cntZerosOst, cntOnesOst);
				res %= mod;
			}
		}
		if ((n + m) % 2 == g) {
			if (m == 1)
				res++;
		}
		if (m == 0) {
			if (n % 2 != g)
				res++;
		}
		out.println(res % mod);
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

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
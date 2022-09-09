import java.io.*;
import java.util.*;

public class CF {

	// long mod = (long) 1e9 + 7;
	int[] pow;
	long mul = 53;

	int[] getHash(String s) {
		int n = s.length();
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = (int) ((s.charAt(i) + (i == 0 ? 0 : mul * res[i - 1])));
		}
		return res;
	}

	int[] h1, h2;

	boolean isPalindrome(int len) {
		if (len == 1)
			return true;
		int n = h1.length;
		int hh1 = h1[len / 2 - 1];
		int fr = n - len - 1;
		int to = fr + len / 2;
		int sz = to - fr;
		int hh2 = (int) (h2[to] - (fr < 0 ? 0 : h2[fr]) * 1L * pow[sz]);
		// hh2 = ((hh2 % mod) + mod) % mod;
		return hh1 == hh2;
	}

	int[] getPowers(int n) {
		int[] res = new int[n + 1];
		res[0] = 1;
		for (int i = 1; i <= n; i++) {
			res[i] = (int) ((res[i - 1] * mul));
		}
		return res;
	}

	void realSolve() {
		String s = in.next();
		String sRev = new StringBuilder(s).reverse().toString();
		h1 = getHash(s);
		h2 = getHash(sRev);
		pow = getPowers(s.length() + 1);
		int[] res = new int[s.length()];
		long ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (isPalindrome(i + 1)) {
				res[i] = 1 + (i == 0 ? 0 : res[(i - 1) / 2]);
			}
			ans += res[i];
		}
		out.println(ans);
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

	void solve() {
		in = new InputReader(new File("object.in"));
		try {
			out = new PrintWriter(new File("object.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		realSolve();

		out.close();
	}

	void solveIO() {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	public static void main(String[] args) {
		new CF().solveIO();
	}
}
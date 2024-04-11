import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;

	private class StringHash {
		private int[] val1;
		private HashHelper helper;
		String s;

		public StringHash(int[] val1, HashHelper helper, String s) {
			super();
			this.val1 = val1;
			this.helper = helper;
			this.s = s;
		}

		public int getIntHash(int l, int r) {
			long result = val1[r + 1] - val1[l] * 1L * helper.pow1[r - l + 1];
			result %= helper.MOD1;
			if (result < 0) {
				result += helper.MOD1;
			}
			return (int) result;
		}

	}

	private class HashHelper {
		final Random rnd = new Random();
		final int BILLION = (int) 1e9;
		final int MUL = 239;
		final int MOD1 = BigInteger
				.valueOf(BILLION + rnd.nextInt(BILLION / 10))
				.nextProbablePrime().intValue();
		final int MOD2 = BigInteger
				.valueOf(BILLION + rnd.nextInt(BILLION / 10))
				.nextProbablePrime().intValue();
		int[] pow1;

		public HashHelper(final int n) {
			pow1 = new int[n];
			pow1[0]= 1;
			for (int i = 1; i < n; i++) {
				pow1[i] = (int) (pow1[i - 1] * 1L * MUL % MOD1);
			}
		}

		StringHash generateHash(String s) {
			return new StringHash(generateIntHash(s, MOD1), this, s);
		}

		public int compareInt(StringHash s1, int from1, int to1, StringHash s2,
				int from2, int to2) {
			int len = Math.min(to1 - from1, to2 - from2) + 1;
			int l = 0, r = len + 1;
			while (r - l > 1) {
				int mid = (l + r) >>> 1;
				if (s1.getIntHash(from1, from1 + mid - 1) == s2.getIntHash(
						from2, from2 + mid - 1)) {
					l = mid;
				} else {
					r = mid;
				}
			}
			if (l == len) {
				if (to1 - from1 == to2 - from2) {
					return 0;
				}
				return (to1 - from1) - (to2 - from2);
			}
			return s1.s.charAt(from1 + l) - s2.s.charAt(from2 + l);
		}

		private int[] generateIntHash(String s, int MOD) {
			int[] result = new int[s.length() + 1];
			for (int i = 0; i < s.length(); i++) {
				result[i + 1] = (int) ((result[i] * 1L * MUL + s.charAt(i)) % MOD);
			}
			return result;
		}
	}

	void solve() {
		String s = in.next();
		int n = s.length();
		s = s + s;
		HashHelper helper = new HashHelper(s.length() + 1);
		StringHash hash = helper.generateHash(s);
		int[] bal = new int[n + n - 1];
		for (int i = 0; i < n + n - 1; i++) {
			if (s.charAt(i) == '(') {
				bal[i]++;
			} else {
				bal[i]--;
			}
			if (i > 0) {
				bal[i] += bal[i - 1];
			}
		}
		int cur = s.length() - 1;
		int[] balanceChange = new int[n];
		int[] qPos = new int[n + n];
		int[] qValue = new int[n + n];
		int qSz = 0, qFrom = 0;
		for (int pos = n - 1; pos >= 0; pos--) {
			while (cur != pos) {
				cur--;
				int value = bal[cur];
				while (qSz > qFrom && qValue[qSz - 1] >= value) {
					qSz--;
				}
				qValue[qSz] = value;
				qPos[qSz] = cur;
				qSz++;
			}
			while (qPos[qFrom] >= pos + n) {
				qFrom++;
			}
			int prevBalance = pos > 0 ? bal[pos - 1] : 0;
			balanceChange[pos] = qValue[qFrom] - prevBalance;
		}
		int cntOpen = 0;
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == '(') {
				cntOpen++;
			} else {
				cntOpen--;
			}
		}
		int maxBalanceChange = 0;
		if (cntOpen < 0) {
			maxBalanceChange = cntOpen;
		}
		int bestCandidate = -1;
		for (int i = 0; i < n; i++) {
			if (balanceChange[i] >= maxBalanceChange) {
				if (bestCandidate != -1) {
					if (helper.compareInt(hash, i, i + n - 1, hash,
							bestCandidate, bestCandidate + n - 1) >= 0) {
						continue;
					}
				}
				bestCandidate = i;
			}
		}
		if (bestCandidate < 0) {
			throw new AssertionError();
		}
		for (int i = 0; i < -cntOpen; i++) {
			out.print("(");
		}
		for (int i = 0; i < n; i++) {
			out.print(s.charAt(i + bestCandidate));
		}
		for (int i = 0; i < cntOpen; i++) {
			out.print(")");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("A.in"));
			out = new PrintWriter(new File("A.out"));

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
		new A().runIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[3];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
		}
		out.println(solve(a, b, false));
	}

	void solve123() {
		Random rnd = new Random(123);
		final int MAX = 10;

		for (int iter = 0; iter < 123123; iter++) {
			System.err.println(" iter = " + iter);
			int n = 1 + rnd.nextInt(MAX);
			int[] a = new int[3];
			for (int i = 0; i < 3; i++) {
				a[i] = 1 + rnd.nextInt(MAX);
			}
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				b[i] = 1 + rnd.nextInt(MAX);
			}
			if (iter == 264) {
				System.err.println("!!" + Arrays.toString(a) + "  "
						+ Arrays.toString(b));
			}
			int sol1 = solve(a, b, false);
			int sol2 = slow(a, b);
			if (sol1 != sol2) {
				System.err.println("correct = " + sol2 + ", my = " + sol1);
				System.err.println("a = " + Arrays.toString(a) + ", b =  "
						+ Arrays.toString(b));
				throw new AssertionError();
			}
		}
	}

	int slow(int[] a, int[] b) {
		int n = b.length;
		int[] dp = new int[1 << n];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		for (int st = 0; st < 1 << n; st++) {
			int cur = dp[st];
			if (cur != Integer.MAX_VALUE) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						for (int k = 0; k < n; k++) {
							int[] co = new int[n];
							co[i] += a[0];
							co[j] += a[1];
							co[k] += a[2];
							int nmask = st;
							for (int l = 0; l < n; l++) {
								if (co[l] >= b[l]) {
									nmask |= (1 << l);
								}
							}
							dp[nmask] = Math.min(dp[nmask], cur + 1);
						}
					}
				}
			}
		}
		return dp[(1 << n) - 1] == Integer.MAX_VALUE ? -1 : dp[(1 << n) - 1];
	}

	int go(int[] a, int[] b, int[] alr, int i) {
		int res = Integer.MAX_VALUE;
		if (i == b.length) {
			return Math.max(Math.max(alr[0], alr[1]), alr[2]);
		}
		for (int st = 1; st < 1 << 3; st++) {
			int su = 0;
			for (int j = 0; j < 3; j++) {
				if (((1 << j) & st) != 0) {
					su += a[j];
				}
			}
			if (su >= b[i]) {
				for (int j = 0; j < 3; j++) {
					if (((1 << j) & st) != 0) {
						alr[j]++;
					}
				}
				res = Math.min(res, go(a, b, alr, i + 1));
				for (int j = 0; j < 3; j++) {
					if (((1 << j) & st) != 0) {
						alr[j]--;
					}
				}
			}
		}
		return res;
	}

	int solve(int[] a, int[] b, boolean correct) {
		Arrays.sort(a);
		int n = b.length;
		for (int i = 0; i < n; i++) {
			if (b[i] > a[0] + a[1] + a[2]) {
				return -1;
			}
		}
		int[] groups = new int[7];
		for (int st = 1; st < 1 << 3; st++) {
			int su = 0;
			for (int i = 0; i < 3; i++) {
				if (((1 << i) & st) != 0) {
					su += a[i];
				}
			}
			groups[st - 1] = su;
		}
		Arrays.sort(groups);
		int[] cntInGroups = new int[7];
		for (int i = 0; i < n; i++) {
			int val = b[i];
			int j = 0;
			while (groups[j] < val) {
				j++;
			}
			cntInGroups[j]++;
		}
		int res = n;
		int[] spent = new int[4];
		for (int use3 = 0; use3 <= cntInGroups[2]; use3++) {
			Arrays.fill(spent, 0);
			spent[3] += use3;
			int onetwo = spent[1] = spent[2] = cntInGroups[2] - use3;
			
			if (a[0] + a[1] < a[2]) {
				spent[3] += cntInGroups[3];
			} else {
				onetwo += cntInGroups[3];
				spent[1] += cntInGroups[3];
				spent[2] += cntInGroups[3];
			}
			spent[1] += cntInGroups[6];
			spent[2] += cntInGroups[6];
			spent[3] += cntInGroups[6];
			spent[2] += cntInGroups[5];
			spent[3] += cntInGroups[5];

			spent[3] += cntInGroups[4];

			int l = 0, r = cntInGroups[4];
			if (!correct) {
				while (r - l > 5) {
					int m1 = (2 * l + r) / 3;
					int m2 = (l + r * 2) / 3;
					int v1 = go(cntInGroups[0], cntInGroups[1], cntInGroups[4],
							spent[1], spent[2], spent[3], m1);
					int v2 = go(cntInGroups[0], cntInGroups[1], cntInGroups[4],
							spent[1], spent[2], spent[3], m2);
					if (v1 < v2) {
						r = m2;
					} else {
						l = m1;
					}
				}
			}

			for (int m = l; m <= r; m++) {
				int curRes = go(cntInGroups[0], cntInGroups[1], cntInGroups[4],
						spent[1], spent[2], spent[3], m);
				curRes = Math.max(curRes, cntInGroups[5] + cntInGroups[4] + onetwo + cntInGroups[6]);
				res = Math.min(res, curRes);
			}
		}
		return res;
	}

	int go(int a0, int a1, int a2, int alr1, int alr2, int alr3, int useOnes) {
		alr1 += useOnes;
		alr2 += a2 - useOnes;
		int max = Math.max(alr2, alr3);
		int need = Math.min(a1, max - Math.min(alr2, alr3));
		a1 -= need;
		if (alr2 < max) {
			alr2 += need;
		}
		if (alr3 < max) {
			alr3 += need;
		}
		if (a1 > 0) {
			alr3 += (a1 + 1) / 2;
			alr2 += (a1) / 2;
		}
		max = Math.max(Math.max(alr1, alr2), alr3);
		if (alr1 < max) {
			a0 -= max - alr1;
			alr1 = max;
		}
		if (alr2 < max) {
			a0 -= max - alr2;
			alr2 = max;
		}
		if (alr3 < max) {
			a0 -= max - alr3;
			alr3 = max;
		}
		if (a0 > 0) {
			max += (a0 + 2) / 3;
		}
		return max;
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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
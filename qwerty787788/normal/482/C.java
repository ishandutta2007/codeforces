import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.next();
		}
		int len = s[0].length();
		long[][] maskSame = new long[len][n];
		for (int i = 0; i < len; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					if (s[j].charAt(i) == s[k].charAt(i)) {
						maskSame[i][j] |= 1L << k;
					}
		double result = 0;
		double[][] c = new double[22][22];
		for (int i = 0; i < c.length; i++) {
			c[i][0] = 1.0;
			if (i != 0)
				for (int j = 1; j < c[i].length; j++)
					c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
		int[] lastBit = new int[1 << len];
		int[] cntHere = new int[1 << len];
		int[] prevMask = new int[1 << len];
		for (int mask = 0; mask < 1 << len; mask++) {
			if (mask != 0)
				while ((mask & (1 << lastBit[mask])) == 0)
					lastBit[mask]++;
			prevMask[mask] = mask ^ (1 << lastBit[mask]);
			cntHere[mask] = Integer.bitCount(mask);
		}
		long[] dpSame = new long[1 << len];
		for (int cur = 0; cur < n; cur++) {
			Arrays.fill(dpSame, 0);
			for (int mask = 0; mask < 1 << len; mask++) {
				if (mask == 0) {
					dpSame[mask] = (1L << n) - 1;
				} else {
					dpSame[mask] = dpSame[prevMask[mask]]
							& maskSame[lastBit[mask]][cur];
				}
				if (dpSame[mask] != 1L << cur) {
					result += 1 / c[len][cntHere[mask]];
				}
			}
		}
		out.println(result / n);
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
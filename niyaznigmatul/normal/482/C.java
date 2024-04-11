import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < n; i++) {
			c[i] = next().toCharArray();
		}
		if (n == 1) {
			out.println(0);
			return;
		}
		int len = c[0].length;
		long[][] f = new long[n][len];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < len; j++) {
				for (int k = 0; k < n; k++) {
					if (c[i][j] == c[k][j]) {
						f[i][j] |= 1L << k;
					}
				}
			}
		}
		int[] ff = new int[1 << len];
		long[] dpf = new long[1 << len];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dpf, 0);
			dpf[0] = -1;
			long[] z = f[i];
			for (int mask = 1; mask < 1 << len; mask++) {
				int j = 0;
				while (((mask >> j) & 1) == 0)
					++j;
				dpf[mask] = dpf[mask & (mask - 1)] & z[j];
			}
			for (int mask = 0; mask < 1 << len; mask++) {
				if (dpf[mask] == (1L << i)) {
					ff[mask]++;
				}
			}
		}
		double ans = 0;
		double[][] C = new double[len + 1][len + 1];
		for (int i = 0; i <= len; i++) {
			C[i][0] = 1.;
			for (int j = 1; j <= i; j++) {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
		for (int mask = 0; mask < 1 << len; mask++) {
			int k = Integer.bitCount(mask);
			for (int i = 0; i < len; i++) {
				if (((mask >> i) & 1) == 0) {
					int cn = ff[mask | (1 << i)] - ff[mask];
					ans += cn * (k + 1) / C[len][k] / (len - k);
				}
			}
		}
		out.println(ans / n);
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("c.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
		br.close();
	}

	static boolean hasNext() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String next() throws IOException {
		return hasNext() ? st.nextToken() : null;
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
}
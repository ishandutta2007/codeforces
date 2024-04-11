import static java.util.Arrays.deepToString;

import java.io.*;
import java.util.*;

public class B {

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt() - 1;
		int sum = 0;
		int sumWithout = 0;
		for (int i = 0; i < m; i++) {
			int x = nextInt();
			sum += x;
			sumWithout += i != k ? x : 0;
		}
		if (sum < n) {
			out.println(-1);
			return;
		}
		double ans = 1.;
		for (int i = sumWithout + 2; i <= sum; i++) {
			ans *= (i - n);
			ans /= (i - 1);
		}
		out.println(1. - ans);
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static void debug(Object... a) {
		System.err.println(deepToString(a));
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		try {
			File file = new File("stones.in");
			InputStream input = System.in;
			OutputStream output = System.out;
			if (file.canRead()) {
				input = (new FileInputStream(file));
				output = (new PrintStream("stones.out"));
			}
			br = new BufferedReader(new InputStreamReader(input));
			out = new PrintWriter(output);
			solve();
			out.close();
			br.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

}
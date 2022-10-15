import java.io.*;
import java.util.*;

public class D {

	static void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int d = nextInt();
		int[] color = new int[n];
		for (int i = 0; i < m; i++) {
			int k = nextInt();
			for (int j = 0; j < k; j++) {
				color[nextInt() - 1] = i;
			}
		}
		int[][] count = new int[m][n + 1];
		for (int i = 0; i < n; i++) {
			count[color[i]][i + 1] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= n; j++) {
				count[i][j] += count[i][j - 1];
			}
		}
		boolean[] has = new boolean[1 << m];
		for (int i = 0; i + d <= n; i++) {
			int left = i;
			int right = i + d;
			int mask = 0;
			for (int j = 0; j < m; j++) {
				if (count[j][right] - count[j][left] > 0) {
					mask |= 1 << j;
				}
			}
			has[mask] = true;
		}
		for (int i = 1; i < 1 << m; i++) {
			if (has[i]) {
				continue;
			}
			for (int j = 0; j < m; j++) {
				has[i] |= has[i & ~(1 << j)];
			}
		}
		int k = Integer.MAX_VALUE;
		for (int i = 1; i < 1 << m; i++) {
			int j = ((1 << m) - 1) & ~i;
			if (has[j]) {
				continue;
			}
			int z = Integer.bitCount(i);
			if (k > z) {
				k = z;
			}
		}
		out.println(k);
	}

	public static void main(String[] args) throws Exception {
		File file = new File("d.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			// output = new PrintStream("d.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
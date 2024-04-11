import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int k = nextInt();
		int BITS = Integer.numberOfTrailingZeros(Integer.highestOneBit(k)) + 1;
		int finish = 2 + BITS * 3;
		boolean[][] ans = new boolean[1000][1000];
		for (int i = 2; i < finish; i += 3) {
			ans[i][i + 1] = true;
			ans[i][i + 2] = true;
			ans[i + 1][i + 3] = true;
			ans[i + 2][i + 3] = true;
		}
		ans[finish][1] = true;
		int cur = finish + 1;
		for (int i = 0; i < BITS; i++) {
			if (((k >> i) & 1) == 1) {
				if (i == BITS - 1) {
					ans[0][finish - i * 3] = true;
				} else {
					ans[0][cur++] = true;
					for (int j = 1; j < 2 * (BITS - i - 1); j++) {
						ans[cur - 1][cur] = true;
						++cur;
					}
					ans[cur - 1][finish - i * 3] = true;
				}
			}
		}
		ans = Arrays.copyOf(ans, cur);
		for (int i = 0; i < cur; i++) {
			ans[i] = Arrays.copyOf(ans[i], cur);
		}
		finish = cur - 1;
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans.length; j++) {
				if (ans[i][j])
					ans[j][i] = true;
				if (ans[j][i])
					ans[i][j] = true;
			}
		}
		// for (int i = 0; i <= finish; i++) {
		// if (ans[i][i])
		// throw new AssertionError();
		// }
		// int head = 0;
		// int tail = 0;
		// int[] q = new int[finish + 1];
		// q[tail++] = 0;
		// int[] d = new int[finish + 1];
		// int[] ways = new int[finish + 1];
		// Arrays.fill(d, Integer.MAX_VALUE);
		// d[0] = 0;
		// ways[0] = 1;
		// while (head < tail) {
		// int v = q[head++];
		// for (int i = 0; i <= finish; i++) {
		// if (ans[v][i]) {
		// if (d[i] == Integer.MAX_VALUE) {
		// d[i] = d[v] + 1;
		// ways[i] = ways[v];
		// q[tail++] = i;
		// } else if (d[i] == d[v] + 1) {
		// ways[i] += ways[v];
		// }
		// }
		// }
		// }
		// System.err.println(ways[1]);
		out.println(finish + 1);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i <= finish; i++) {
			for (int j = 0; j <= finish; j++) {
				sb.append(ans[i][j] ? 'Y' : 'N');
			}
			sb.append('\n');
		}
		out.print(sb);
	}

	public static void main(String[] args) throws Exception {
		File file = new File("b.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			// output = new PrintStream("b.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static boolean hasNextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String nextToken() throws IOException {
		return hasNextToken() ? st.nextToken() : null;
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
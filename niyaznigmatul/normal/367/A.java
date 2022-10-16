import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		char[] c = nextToken().toCharArray();
		int[][] count = new int[3][c.length + 1];
		for (int i = 0; i < c.length; i++) {
			count["xyz".indexOf(c[i])][i + 1] = 1;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j <= c.length; j++) {
				count[i][j] += count[i][j - 1];
			}
		}
		int m = nextInt();
		int[] d = new int[3];
		for (int i = 0; i < m; i++) {
			int l = nextInt() - 1;
			int r = nextInt();
			for (int j = 0; j < 3; j++) {
				d[j] = count[j][r] - count[j][l];
			}
			Arrays.sort(d);
			if (r - l >= 3 && d[2] - d[0] > 1) {
				out.println("NO");
			} else {
				out.println("YES");
			}
		}
	}

	public static void main(String[] args) throws Exception {
		File file = new File("a.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			//			output = new PrintStream("a.out");
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
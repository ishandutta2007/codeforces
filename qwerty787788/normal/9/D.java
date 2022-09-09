import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		int n = in.nextInt();
		int h = in.nextInt();
		long[][] dp = new long[n + 1][n + 1];
		dp[1][1] = 1;
		dp[0][0] = 1;
		for (int cn = 2; cn <= n; cn++) {
			for (int curH = 1; curH <= n; curH++) {
				for (int id  = 1; id <= cn; id++) {
					long cur = 1;
					long v1 = 0, v2 = 0;
					for (int h1 = 0; h1 <= curH - 1; h1++) {
						v1 += dp[id - 1][h1];
						v2 += dp[cn - id][h1];
					}
					cur = v1 * dp[cn - id][curH - 1] + v2 * dp[id - 1][curH - 1] - dp[cn - id][curH - 1] * dp[id - 1][curH - 1];
					dp[cn][curH] += cur;
				}
			}
		}
		long res =0;
		for (int h1 = h; h1 <= n; h1++)
			res += dp[n][h1];
		out.println(res);
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
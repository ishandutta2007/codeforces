import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		int n = in.nextInt();
		int m = in.nextInt();
		boolean[][] f = new boolean[n][n];
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			f[fr][to] = f[to][fr] = true;
		}
		long[][] dp = new long[n][1 << n];
		for (int i = 0; i < n; i++)
			dp[i][1 << i] = 1;
		long res = 0;
		int[] len = new int[n + 1];
		for (int st = 0; st < 1 << n; st++) {
			int from = Integer.lowestOneBit(st);
			for (int i =0; i < n;i++)
				if (((1<<i) & st) != 0) {
					from =i;
					break;
				}
			for (int to = 0; to < n; to++)
				if (dp[to][st] != 0)
					for (int next = from; next < n; next++)
						if (f[to][next]
								&& ((((1 << next) & st) == 0) || next == from))
							if (next == from) {
								if (Integer.bitCount(st) > 2) {
									res += dp[to][st];
									len[Integer.bitCount(st)] += dp[to][st];
								}
							} else {
								dp[next][st | (1 << next)] += dp[to][st];
							}
		}
		out.println(res / 2);
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
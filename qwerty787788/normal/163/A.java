import java.io.*;
import java.util.*;

public class CF {
	void solve() {
		char[] a = in.next().toCharArray();
		char[] b = in.next().toCharArray();
		final int mod = (int) 1e9 + 7;
		long result = 0;
		int[] dp = new int[b.length];
		int[] dp2 = new int[b.length];
		for (char c : a) {
			Arrays.fill(dp2, 0);
			int sum = 0;
			for (int i = 0; i < dp2.length; i++) {
				if (b[i] == c) {
					dp2[i] = sum + 1;
					if (dp2[i] >= mod) {
						dp2[i] -= mod;
					}
					result += dp2[i];
				}
				sum += dp[i];
				if (sum >= mod) {
					sum -= mod;
				}
			}
			result %= mod;
			int[] tmp = dp;
			dp = dp2;
			dp2 = tmp;
		}
		out.println(result);
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

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
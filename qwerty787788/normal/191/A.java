import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;
		
	boolean prime[];

	public void solve() throws IOException {
		int N = in.nextInt();
		int dp[][] = new int[27][27];
		for (int i = 0; i < 27; i++)
			for (int j = 0; j < 27; j++) {
				dp[i][j] = -1;
			}
		for (int i = 0; i < N; i++) {
			String s = in.next();
			int st = s.charAt(0) - 'a';
			int sp = s.charAt(s.length() - 1) - 'a';
			for (int j = 0; j < 27; j++)
				if (dp[j][st]!= -1)
					dp[j][sp] = Math.max(dp[j][sp], dp[j][st] + s.length());
			dp[st][sp] = Math.max(dp[st][sp], s.length());
		}
		int res = 0;
		for (int i = 0; i < 27; i++)
			if (dp[i][i] > res) res = dp[i][i];
		out.println(res);
	}

	public void run() {
		try {
			//in = new FastScanner(new File("input.txt"));
			//out = new PrintWriter(new File("output.txt"));

			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return null;
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}
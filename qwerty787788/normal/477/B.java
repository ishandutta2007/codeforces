import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[][] ans = new int[n][4];
		int cur = 2;
		for (int i = 0; i < n; i++) {
			if (cur % 3 == 0)
				cur += 2;
			ans[i][0] = cur;
			cur += 2;
		}
		cur = 1;
		for (int i = 0; i < n; i++)
			for (int j = 1; j < 4; j++) {
				ans[i][j] = cur;
				cur += 2;
			}
		int min = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 4; j++)
				min = Math.max(ans[i][j], min);
		out.println(min * k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 4; j++) {
				out.print(ans[i][j] * k + " ");
			}
			out.println();
		}
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
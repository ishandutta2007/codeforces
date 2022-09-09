import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		Integer[] a = new Integer[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		ArrayList<Integer> vals = new ArrayList<>();
		ArrayList<Integer> count = new ArrayList<>();
		for (int i = 0; i < n;) {
			int j = i;
			while (j != n && a[j].equals(a[i])) {
				j++;
			}
			vals.add(a[i]);
			count.add(j - i);
			i = j;
		}
		int m = vals.size();
		long[][] dp = new long[2][m + 1];
		for (int i = 0; i < m; i++) {
			for (int del = 0; del < 2; del++) {
				for (int nowDel = 0; nowDel < 2; nowDel++) {
					boolean can = true;
					if (i != 0 && Math.abs(vals.get(i) - vals.get(i - 1)) == 1) {
						if (del == 0 && nowDel == 0)
							can = false;
					}
					if (can) {
						dp[nowDel][i + 1] = Math.max(dp[nowDel][i + 1],
								dp[del][i]
										+ (nowDel == 1 ? 0 : count.get(i) * 1L
												* vals.get(i)));
					}
				}
			}
		}
		long best = Math.max(dp[0][m], dp[1][m]);
		out.println(best);
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
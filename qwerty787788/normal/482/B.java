import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		long[][] add = new long[32][n + 1];
		int[] ql = new int[m];
		int[] qr = new int[m];
		int[] qq = new int[m];
		for (int i = 0; i < m; i++) {
			int l = in.nextInt() - 1;
			int r = in.nextInt() - 1;
			int q = in.nextInt();
			ql[i] = l;
			qr[i] = r;
			qq[i] = q;
			for (int j = 0; j < 32; j++)
				if (((1 << j) & q) != 0) {
					add[j][l]++;
					add[j][r + 1]--;
				}
		}
		for (int i = 1; i < n; i++)
			for (int j = 0; j < 32; j++)
				add[j][i] += add[j][i - 1];
		int[] vals = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 32; j++)
				if (add[j][i] != 0) {
					vals[i] ^= 1 << j;
					add[j][i] = 1;
				}
		}
		for (int i = 1; i < n; i++)
			for (int j = 0; j < 32; j++)
				add[j][i] += add[j][i - 1];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 32; j++)
				if (((1 << j) & qq[i]) == 0) {
					long now = add[j][qr[i]]
							- (ql[i] == 0 ? 0 : add[j][ql[i] - 1]);
					if (now == qr[i] - ql[i] + 1) {
						out.println("NO");
						return;
					}
				}
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.print(vals[i] + " ");
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
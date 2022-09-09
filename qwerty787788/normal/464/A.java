import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int p = in.nextInt();
		char[] a = in.next().toCharArray();
		for (int i = n - 1; i >= 0; i--) {
			int now = 1 + a[i] - 'a';
			while (now < p) {
				boolean ok = true;
				char nowC = (char) ('a' + now);
				if (i > 0 && a[i - 1] == nowC)
					ok = false;
				if (i > 1 && a[i - 2] == nowC)
					ok = false;
				if (ok) {
					a[i] = nowC;
					for (int j = i + 1; j < n; j++) {
						for (int k = 0; k < p; k++) {
							nowC = (char) ('a' + k);
							boolean ok2 = true;
							if (j > 0 && a[j - 1] == nowC)
								ok2 = false;
							if (j > 1 && a[j - 2] == nowC)
								ok2 = false;
							if (ok2) {
								a[j] = nowC;
								break;
							}
						}
					}
					for (int j = 0; j < n; j++) {
						out.print(a[j]);
					}
					return;
				}
				now++;
			}
		}
		out.println("NO");
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
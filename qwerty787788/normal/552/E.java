import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		char[] a = in.next().toCharArray();
		int n = a.length;
		long result = 0;
		for (int it = 0; it < 2; it++) {
			long[] sum = new long[n];
			long[] mul = new long[n];
			sum[0] = 0;
			mul[0] = a[0] - '0';
			for (int i = 2; i < n; i += 2) {
				if (a[i - 1] == '+') {
					sum[i] = sum[i - 2] + mul[i - 2];
					mul[i] = a[i] - '0';
				} else {
					sum[i] = sum[i - 2];
					mul[i] = mul[i - 2] * (a[i] - '0');
				}
			}
			result = Math.max(result, sum[n - 1] + mul[n - 1]);
			long[] sumS = new long[n];
			long[] mulS = new long[n];
			sumS[n - 1] = 0;
			mulS[n - 1] = a[n - 1] - '0';
			for (int i = n - 3; i >= 0; i -= 2) {
				if (a[i + 1] == '+') {
					sumS[i] = sumS[i + 2] + mulS[i + 2];
					mulS[i] = a[i] - '0';
				} else {
					sumS[i] = sumS[i + 2];
					mulS[i] = mulS[i + 2] * (a[i] - '0');
				}
			}
			for (int i = 1; i < n; i += 2) {
				if (a[i] == '*') {
					long curS = 0, curM = a[i + 1] - '0';
					for (int j = i + 3; j < n; j += 2) {
						if (a[j - 1] == '+') {
							curS += curM;
							curM = a[j] - '0';
						} else {
							curM *= (a[j] - '0');
						}
						long A = sum[i - 1];
						long B = mul[i - 1];
						long C = 0, D = 0;
						if (j == n - 1) {
							C = 1;
							D = 0;
						} else {
							if (a[j + 1] == '+') {
								C = 1;
								D = sumS[j + 2] + mulS[j + 2];
							} else {
								C = mulS[j + 2];
								D = sumS[j + 2];
							}
						}
						long nowRes = A + B * (curS + curM) * C + D;
						result = Math.max(result, nowRes);
					}
				}
			}
			for (int i = 0, j = n - 1; i < j; i++, j--) {
				char tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		out.println(result);
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
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
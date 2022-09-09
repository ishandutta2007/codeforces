import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		final int MAX = 600;
		final double eps = 1e-80;
		double[] pr1 = new double[MAX];
		double[] pr2 = new double[MAX];
		double[] avarage = new double[MAX + 10];
		for (int i = 1; i < avarage.length; i++) {
			for (int j = 1; j <= i; j++)
				avarage[i] += j;
			avarage[i] += i;
			avarage[i] /= i + 1;
		}
		pr1[1] = k;
		int nowMax = 10;
		double result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < MAX; j++) {
				if (j > nowMax) {
					if (pr1[j] < eps) {
						nowMax = j;
						break;
					}
				}
				double nowProb = pr1[j] / k;
				result += nowProb * avarage[j];
				double upProb = 1 / (j + 1.0);
				if (j != MAX - 1)
					pr2[j + 1] += upProb * nowProb;
				pr2[j] += (k - upProb) * nowProb;
			}
			double[] tmp = pr1;
			pr1 = pr2;
			pr2 = tmp;
			int tt = Math.min(nowMax + 10, MAX);
			for (int j = 0; j < tt; j++) {
				pr2[j] = 0;
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
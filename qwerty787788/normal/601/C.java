import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;
	
	double getSum(int fr, int to, double[] sum) {
		fr = Math.max(fr, 0);
		to = Math.min(to, sum.length - 2);
		return sum[to + 1] - sum[fr];
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		if (m == 1) {
			out.println(1.0);
			return;
		}
		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt() - 1;
		}
		int total = n * m * 2 + 4;
		int mid = total / 2;
		// my_place - another_place + mid
		double[] pr = new double[total];
		double[] sum = new double[total + 1];
		pr[mid]  = 1.0;
		for (int i = 0; i < n; i++) {
			sum[0] = 0;
			for (int j = 0; j < total; j++) {
				sum[j + 1] = sum[j] + pr[j];
			}
			for (int diff = 0; diff < total; diff++) {
				// [diff - x .. diff - x + m - 1] - {diff}
				pr[diff] = (getSum(diff - x[i], diff - x[i] + m - 1, sum) - pr[diff]) / (m - 1.0);
			}
		}
		double result = 0;
		for (int i = mid + 1; i < total; i++) {
			result += pr[i];
		}
		out.println(1 + result * (m - 1));
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
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
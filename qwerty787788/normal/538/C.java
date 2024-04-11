import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int total = in.nextInt();
		int n = in.nextInt();
		int[] day = new int[n];
		int[] h = new int[n];
		for (int i = 0; i < n; i++) {
			day[i] = in.nextInt();
			h[i] = in.nextInt();
		}
		int result = 0;
		result = Math.max(result, day[0] - 1 + h[0]);
		result = Math.max(result, total - day[n - 1] + h[n - 1]);
		for (int i = 0; i < n - 1; i++) {
			int cntDays = day[i + 1] - day[i];
			if (Math.abs(h[i] - h[i + 1]) > cntDays) {
				out.println("IMPOSSIBLE");
				return;
			}
			if (h[i] >= h[i + 1]) {
				result = Math.max(result,
						h[i] + (cntDays - Math.abs(h[i] - h[i + 1])) / 2);
			} else {
				result = Math.max(result,
						h[i + 1] + (cntDays - Math.abs(h[i] - h[i + 1])) / 2);
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
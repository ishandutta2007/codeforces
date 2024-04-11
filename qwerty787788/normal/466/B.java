import java.io.*;
import java.util.*;

public class CF22 {
	FastScanner in;
	PrintWriter out;

	void solve() {
		long n = in.nextLong() * 6;
		int a = in.nextInt();
		int b = in.nextInt();
		if (a * 1L * b >= n) {
			out.println(a * 1L * b + "\n" + a + " " + b);
			return;
		}
		long bestS = Long.MAX_VALUE;
		long bestA = 0, bestB = 0;
		for (int MIN = 1; MIN < 1e6; MIN++) {
			if (MIN >= Math.min(a, b)) {
				long mul = 1 + (n - 1) / MIN;
				mul = Math.max(mul, MIN);
				long aTmp = MIN, bTmp = mul;
				if (a > b) {
					long tmp = aTmp;
					aTmp = bTmp;
					bTmp = tmp;
				}
				aTmp = Math.max(aTmp, a);
				bTmp = Math.max(bTmp, b);
				if (aTmp * bTmp <= bestS) {
					bestS = aTmp * bTmp;
					bestA = aTmp;
					bestB = bTmp;
				}
			}
		}
		out.println(bestS + "\n" + bestA + " " + bestB);
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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
		new CF22().runIO();
	}
}
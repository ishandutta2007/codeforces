import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		final int MAX = (int) 1e6 * 4;
		long[] max = new long[MAX];
		int c = in.nextInt();
		int hr = in.nextInt();
		int hb = in.nextInt();
		int wr = in.nextInt();
		int wb = in.nextInt();
		for (int i = 0; i < MAX; i++) {
			if (i + wr < MAX) {
				max[i + wr] = Math.max(max[i + wr], max[i] + hr);
			}
			if (i + wb < MAX) {
				max[i + wb] = Math.max(max[i + wb], max[i] + hb);
			}
		}
		long result = 0;
		for (int i = 0; i < MAX; i++) {
			if (i <= c) {
				result = Math.max(result, max[i]);
			}
		}
		for (int i = 0; i < MAX; i++) {
			if (i * 1L * wr <= c) {
				long curRes = i * 1L * hr + (c - i * wr) / wb * hb;
				result = Math.max(result, curRes);
				if (c - i * wr < MAX) {
					result = Math.max(result, i * 1L * hr + max[c - i * wr]);
				}
			} else {
				break;
			}
		}
		for (int i = 0; i < MAX; i++) {
			if (i * 1L * wb <= c) {
				long curRes = i * 1L * hb + (c - i * wb) / wr * hr;
				result = Math.max(result, curRes);
				if (c - i * wb < MAX) {
					result = Math.max(result, i * 1L * hb + max[c - i * wb]);
				}
			} else {
				break;
			}
		}
		for (int i = 1; i < MAX; i++) {
			long curRes = (c / i) * 1L * max[i] + max[(c - c / i * i)];
			result = Math.max(result, curRes);
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
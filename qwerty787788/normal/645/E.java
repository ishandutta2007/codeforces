import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		final int mod = (int) 1e9 + 7;
		String s = in.next();
		int[] lastTime = new int[k];
		Arrays.fill(lastTime, -1);
		int[] res = new int[k];
		for (int i = 0; i < s.length(); i++) {
			int id = s.charAt(i) - 'a';
			lastTime[id] = i;
			long sum = 1;
			for (int j = 0; j < k; j++) {
				sum += res[j];
			}
			res[id] = (int) (sum % mod);
		}
		for (int i = s.length(); i < s.length() + n; i++) {
			int best = 0;
			for (int j = 0; j < k; j++) {
				if (lastTime[j] < lastTime[best]) {
					best = j;
				}
			}
			lastTime[best] = i;
			long sum = 1;
			for (int j = 0; j < k; j++) {
				sum += res[j];
			}
			res[best] = (int) (sum % mod);
		}
		long result = 1;
		for (int x : res) {
			result += x;
		}
		out.println(result % mod);
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test2.out"));

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
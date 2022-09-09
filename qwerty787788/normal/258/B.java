import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF157DIV1 {
	FastScanner in;
	PrintWriter out;

	String m;
	int[] sum = new int[11];

	void go(boolean less, int var, int numbers, int cur) {
		if (var == 0)
			return;
		if (numbers == m.length()) {
			sum[cur] += var;
		} else {
			int max = 9;
			int lc = 0, lcplus = 0, nlc = 0, nlcplus = 0;
			if (!less)
				max = (int) (m.charAt(numbers) - '0');
			for (int next = 0; next <= max; next++) {
				if (next == max && !less) {
					if (next == 4 || next == 7) {
						nlcplus += var;
					} else {
						nlc += var;
					}
				} else {
					if (next == 4 || next == 7) {
						lcplus += var;
					} else {
						lc += var;
					}
				}
			}
			go(true, lcplus, numbers + 1, cur + 1);
			go(true, lc, numbers + 1, cur);
			go(false, nlcplus, numbers + 1, cur + 1);
			go(false, nlc, numbers + 1, cur);
		}
	}

	long mod = (long) 1e9 + 7;
	long ans = 0;

	void go2(int need, int has, long now) {
		if (need == 0) {
			ans = (ans + now) % mod;
		} else {
			for (int i = 0; i <= has; i++) {
				if (sum[i] > 0) {
					sum[i]--;
					go2(need - 1, has - i, (now * (sum[i] + 1)) % mod);
					sum[i]++;
				}
			}
		}
	}

	void solve() {
		m = in.next();
		go(false, 1, 0, 0);
		sum[0]--;
		for (int i = 1; i <= 10; i++) {
			if (sum[i] > 0) {
				sum[i]--;
				go2(6, i - 1, sum[i] + 1);
				sum[i]++;
			}
		}
		out.println(ans);
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
	}

	public static void main(String[] args) {
		new CF157DIV1().runIO();
	}
}
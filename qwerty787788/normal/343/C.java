import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		long[] h = new long[n];
		for (int i = 0; i < n; i++)
			h[i] = in.nextLong();
		long[] p = new long[m];
		for (int i = 0; i < m; i++) {
			p[i] = in.nextLong();
		}
		long l = -1, r = (long) 1e10 * 3;
		while (r - l > 1) {
			long med = (l + r) >> 1;
			boolean ok = true;
			int cur = 0;
			for (int i = 0; i < n; i++) {
				if (h[i] - med <= p[cur]) {
					long canRight = 0;
					if (p[cur] <= h[i]) {
						canRight = Math.max((med - (h[i] - p[cur])) / 2, (med - 2 * (h[i] - p[cur])));
					} else {
						canRight = med;
					}
					while (cur != m && p[cur] <= h[i] + canRight)
						cur++;
				} else {
					ok = false;
				}
				if (cur == m)
					break;
			}
			if (ok && cur == m) {
				r = med;
			} else {
				l = med;
			}
		}
		out.println(r);
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		long[] pos = new long[n];
		for (int i = 0; i < n; i++)
			pos[i] = in.nextInt() * 2;
		Arrays.sort(pos);
		long l = -1, r = (long) 1e10;
		long[] res = new long[3];
		long[] tmp = new long[3];
		while (r - l > 1) {
			long med = (l + r) >> 1;
			int used = 0;
			long last = Long.MIN_VALUE;
			for (int i = 0; i < n; i++) {
				if (pos[i] > last) {
					used++;
					if (used == 4)
						break;
					last = pos[i] + med * 2;
					tmp[used - 1] = pos[i] + med;
				}
			}
			if (used <= 3) {
				r = med;
				for (int j = 0; j < 3; j++)
					res[j] = tmp[j];
				for (int j = used; j < 3; j++)
					res[j] = res[0];
			} else {
				l = med;
			}
		}
		double ans = r / 2.0;
		out.printf("%.6f\n", ans);
		for (int i = 0; i < 3; i++) {
			double x = res[i] / 2.;
			out.printf("%.6f ", x);
		}
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
		Locale.setDefault(Locale.US);
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
import java.io.*;
import java.util.*;

public class CF159DIV2 {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		double[] a = new double[n];
		for (int i = 0; i < n; i++)
			a[i] = Math.atan2(in.nextInt(), in.nextInt());
		Random rnd = new Random();
		for (int i = 0; i < n; i++) {
			int to = rnd.nextInt(i + 1);
			double tmp = a[to];
			a[to] = a[i];
			a[i] = tmp;
		}
		Arrays.sort(a);
		double maxAns = 0;
		for (int i = 0; i < n; i++) {
			double d = a[(i + 1) % n] - a[i];
			if (d < 0)
				d += Math.PI * 2;
			maxAns = Math.max(maxAns, d);
		}
		maxAns = 2 * Math.PI - maxAns;
		if (a[n - 1] - a[0] < 1e-9)
			maxAns = 0;
		out.println(maxAns / Math.PI * 180.);
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
		new CF159DIV2().runIO();
	}
}
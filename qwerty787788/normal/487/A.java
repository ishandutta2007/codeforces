import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int hpy = in.nextInt();
		int atky = in.nextInt();
		int defy = in.nextInt();
		int hpm = in.nextInt();
		int atkm = in.nextInt();
		int defm = in.nextInt();
		int h = in.nextInt();
		int a = in.nextInt();
		int d = in.nextInt();
		int res = Integer.MAX_VALUE;
		final int MAX = 222;
		for (int addA = 0; addA < MAX; addA++) {
			for (int def = 0; def < MAX; def++) {
				int sub = Math.max(0, addA + atky - defm);
				if (sub != 0) {
					int need = 0;
					int cur = hpm;
					while (cur > 0) {
						need++;
						cur -= sub;
					}
					int my = hpy - need * Math.max(0, atkm - defy - def);
					int cost = 0;
					if (my <= 0) {
						cost += (1 - my) * h;
					}
					cost += addA * a;
					cost += def * d;
					res = Math.min(res, cost);
				}
			}
		}
		out.println(res);
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
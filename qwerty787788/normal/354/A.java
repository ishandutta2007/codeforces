import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		int l = in.nextInt();
		int r = in.nextInt();
		int ql = in.nextInt();
		int qr = in.nextInt();
		int[] w = new int[n];
		for (int i = 0; i < n; i++)
			w[i] = in.nextInt();
		int sumLeft = 0, sumRight = 0;
		for (int i = 0; i < n; i++)
			sumRight += w[i];
		int ans = Integer.MAX_VALUE;
		for (int cntLeft = 0; cntLeft <= n; cntLeft++) {
			if (cntLeft != 0) {
				sumLeft += w[cntLeft - 1];
				sumRight -= w[cntLeft - 1];
			}
			int cntRight = n - cntLeft;
			int costLeft = Math.max(0, (cntLeft - 1) - cntRight) * ql + Math.max(0, (cntRight - 1) - (cntLeft - 1)) * qr;
			int costRight = Math.max(0, (cntLeft - 1) - cntRight + 1) * ql + Math.max(0, (cntRight - 1) - (cntLeft)) * qr;
			int cost = Math.min(costLeft, costRight) + sumLeft * l + sumRight * r;
			ans = Math.min(ans, cost);
		}
		out.println(ans);
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
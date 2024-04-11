import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int res = 0;
		int[] x = new int[n];
		int[] cnt = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			cnt[i] = in.nextInt();
		}
		for (int stDir = 0; stDir < 2; stDir++) {
			int dir = stDir, pos = 0;
			boolean[] was = new boolean[n];
			int cur = 0;
			while (true) {
				int next = -1;
				for (int i = 0; i < n; i++) {
					if (dir == 0 && x[i] < pos) {
						continue;
					}
					if (dir == 1 && x[i] > pos) {
						continue;
					}
					if (was[i]) {
						continue;
					}
					if (dir == 0 && (next == -1 || x[next] > x[i])) {
						next = i;
					}
					if (dir == 1 && (next == -1 || x[next] < x[i])) {
						next = i;
					}
				}
				if (next == -1) {
					break;
				}
				cur += cnt[next];
				pos = x[next];
				was[next] = true;
				dir = 1 - dir;
			}
			res = Math.max(res, cur);
		}
		out.println(res);
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
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] getAns(int x1, int h1, int y1, int a1, int m) {
		boolean[] was = new boolean[m];
		int move = 0;
		while (true) {
			if (was[h1]) {
				return null;
			}
			was[h1] = true;
			h1 = (int) ((x1 * 1L * h1 + y1) % m);
			move++;
			if (h1 == a1) {
				int first = move;
				Arrays.fill(was, false);
				while (true) {
					if (was[h1]) {
						return new int[] { first };
					}
					was[h1] = true;
					h1 = (int) ((x1 * 1L * h1 + y1) % m);
					move++;
					if (h1 == a1) {
						return new int[] { first, move };
					}
				}
			}
		}
	}

	void solve() {
		int m = in.nextInt();
		int h1 = in.nextInt();
		int a1 = in.nextInt();
		int x1 = in.nextInt();
		int y1 = in.nextInt();
		int h2 = in.nextInt();
		int a2 = in.nextInt();
		int x2 = in.nextInt();
		int y2 = in.nextInt();
		if (h1 == a1 || h2 == a2) {
			return;
		}
		int[] f = getAns(x1, h1, y1, a1, m);
		int[] s = getAns(x2, h2, y2, a2, m);
		if (f == null || s == null) {
			out.println(-1);
			return;
		}
		if (f.length == 1 || s.length == 1) {
			if (f.length == 1 && s.length == 1) {
				int ans = f[0] == s[0] ? f[0] : -1;
				out.println(ans);
				return;
			}
			if (f.length == 1) {
				int ans = f[0] >= s[0] && ((s[0] - f[0]) % (s[1] - s[0]) == 0) ? f[0]
						: -1;
				out.println(ans);
				return;
			}
			if (s.length == 1) {
				int ans = s[0] >= f[0] && ((f[0] - s[0]) % (f[1] - f[0]) == 0) ? s[0]
						: -1;
				out.println(ans);
				return;
			}
			out.println(-1);
			return;
		}
		final int MAX = (int) 1e6 * 2 + 123;
		for (int z = 0; z < MAX; z++) {
			long time = f[0] + (f[1] - f[0]) * 1L * z;
			if ((time >= s[0]) && ((time - s[0]) % (s[1] - s[0]) == 0)) {
				out.println(time);
				return;
			}
		}
		out.println(-1);
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
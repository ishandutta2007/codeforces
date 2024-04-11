import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int xp = in.nextInt();
		int yp = in.nextInt();
		int xv = in.nextInt();
		int yv = in.nextInt();
		int it = 0;
		while (true) {
			it++;
			if (it % 2 == 1) {
				if (xp == 0 || yp >= yv && yp > 0) {
					if (xp != xv || yp - 1 != yv) {
						yp--;
					}
				} else {
					if (xp - 1 != xv || yp != yv) {
						xp--;
					}
				}
			} else {
				boolean move = false;
				if (xv > 0 && yv > 0) {
					if (xv - 1 != xp || yv - 1 != yp) {
						xv--;
						yv--;
						move = true;
					}
				}
				if (!move) {
					if (xv > 0 && (xv - 1 != xp || yv != yp)) {
						move = true;
						xv--;
					}
				}
				if (!move) {
					if (yv > 0 && (yv - 1 != yp || xv != xp)) {
						move = true;
						yv--;
					}
				}
			}
			if (xv == 0 && yv == 0) {
				out.println("Vasiliy");
				return;
			}
			if (xp == 0 && yp == 0) {
				out.println("Polycarp");
				return;
			}
		}
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
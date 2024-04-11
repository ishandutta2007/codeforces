import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int m = in.nextInt();
		int cur2 = 0, cur5 = 0;
		int x = 0;
		while (Math.min(cur2, cur5) < m) {
			x++;
			int y = x;
			while (y % 2 == 0) {
				y /= 2;
				cur2++;
			}
			while (y % 5 == 0) {
				y /= 5;
				cur5++;
			}
		}
		ArrayList<Integer> go = new ArrayList<>();
		while (Math.min(cur2, cur5) <= m) {
			go.add(x);
			x++;
			int y = x;
			while (y % 2 == 0) {
				y /= 2;
				cur2++;
			}
			while (y % 5 == 0) {
				y /= 5;
				cur5++;
			}
		}
		out.println(go.size());
		for (int xx : go) {
			out.print(xx + " ");
		}
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
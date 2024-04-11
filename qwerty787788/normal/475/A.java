import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	String[] a = new String[] { "+------------------------+",
			"|O.O.O.#.#.#.#.#.#.#.#.|D|)", "|O.O.O.#.#.#.#.#.#.#.#.|.|",
			"|O.......................|", "|O.O.#.#.#.#.#.#.#.#.#.|.|)",
			"+------------------------+" };

	void solve() {
		int k = in.nextInt();
		char[][] b = new char[a.length][];
		for (int i = 0; i < b.length; i++) {
			b[i] = a[i].toCharArray();
			for (int j = 0; j < b[i].length; j++)
				if (b[i][j] == 'O') {
					b[i][j] = '#';
				}
		}
		while (k > 0) {
			boolean f = false;
			for (int j = 0; j < b[0].length; j++) {
				for (int i = 0; i < b.length; i++) {
					if (b[i][j] == '#' && !f) {
						b[i][j] = 'O';
						f = true;
					}
				}
			}
			k--;
		}
		for (int i = 0; i < b.length; i++) {
			for (int j = 0; j < b[i].length; j++) {
				out.print(b[i][j]);
			}
			out.println();
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
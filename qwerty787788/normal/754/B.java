import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	boolean win(char[][] a, int n, char c) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				boolean ok = true;
				for (int k = 0; k < 3; k++) {
					if (a[i][j + k] != c) {
						ok = false;
					}
				}
				if (ok) {
					return true;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				boolean ok = true;
				for (int k = 0; k < 3; k++) {
					if (a[j + k][i] != c) {
						ok = false;
					}
				}
				if (ok) {
					return true;
				}
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				boolean ok = true;
				for (int k = 0; k < 3; k++) {
					if (a[i + k][j + k] != c) {
						ok = false;
					}
				}
				if (ok) {
					return true;
				}
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				boolean ok = true;
				for (int k = 0; k < 3; k++) {
					if (a[i + k][n - 1 - j - k] != c) {
						ok = false;
					}
				}
				if (ok) {
					return true;
				}
			}
		}
		return false;
	}

	void solve() {
		int n = 4;
		char[][] a = new char[n][n];
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		int cntX = 0, cntO = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'x') {
					cntX++;
				}
				if (a[i][j] == 'o') {
					cntO++;
				}
			}
		}
		char next = 'x';
		if (cntX > cntO) {
			next = 'o';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == '.') {
					a[i][j] = next;
					if (win(a, n, next)) {
						out.println("YES");
						return;
					}
					a[i][j] = '.';
				}
			}
		}
		out.println("NO");
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
		new CF().runIO();
	}
}
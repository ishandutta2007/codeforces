import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		String s = in.next();
		String t = in.next();
		int[][] cnt = new int[2][26];
		for (char c : s.toCharArray()) {
			if (c >= 'a' && c <= 'z') {
				cnt[0][c - 'a']++;
			} else {
				cnt[1][c - 'A']++;
			}
		}
		ArrayList<Character> cc = new ArrayList<>();
		int r1 = 0, r2 = 0;
		for (char c : t.toCharArray()) {
			if (c >= 'a' && c <= 'z') {
				if (cnt[0][c - 'a'] > 0) {
					cnt[0][c - 'a']--;
					r1++;
				} else {
					cc.add(c);
				}
			} else {
				if (cnt[1][c - 'A'] > 0) {
					cnt[1][c - 'A']--;
					r1++;
				} else {
					cc.add(c);
				}
			}
		}
		for (char c : cc) {
			if (c >= 'a' && c <= 'z') {
				if (cnt[1][c - 'a'] > 0) {
					cnt[1][c - 'a']--;
					r2++;
				}
			} else {
				if (cnt[0][c - 'A'] > 0) {
					cnt[0][c - 'A']--;
					r2++;
				}
			}
		}
		out.println(r1 + " " + r2);
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
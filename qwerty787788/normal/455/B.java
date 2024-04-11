import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final int MAX = (int) 1e5 + 10;
	int[][] next = new int[26][MAX];
	boolean[] canWin = new boolean[MAX];
	boolean[] canLose = new boolean[MAX];
	int cnt = 1;

	void add(int v, String s, int from) {
		if (from != s.length()) {
			int x = s.charAt(from) - 'a';
			if (next[x][v] == -1) {
				next[x][v] = cnt++;
			}
			add(next[x][v], s, from + 1);
		}
	}

	void go(int v) {
		int cnt = 0;
		for (int i = 0; i < 26; i++)
			if (next[i][v] != -1) {
				go(next[i][v]);
				if (!canWin[next[i][v]])
					canWin[v] = true;
				cnt++;
				if (!canLose[next[i][v]]) {
					canLose[v] = true;
				}
			}
		if (cnt == 0) {
			canLose[v] = true;
		}
	}

	void solve() {
		for (int i = 0; i < next.length; i++) {
			Arrays.fill(next[i], -1);
		}
		int n = in.nextInt();
		int k = in.nextInt();
		for (int i = 0; i < n; i++) {
			String s = in.next();
			add(0, s, 0);
		}
		go(0);
		boolean canLoseStart = canLose[0], canWinStart = canWin[0];
		if (!canWinStart) {
			out.println("Second");
			return;
		}
		if (canLoseStart) {
			out.println("First");
			return;
		}
		out.println((k % 2 == 0) ? "Second" : "First");
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
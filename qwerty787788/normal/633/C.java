import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final int MAX = 1234567;
	int[][] next = new int[26][MAX];
	String[] str = new String[MAX];
	int cnt = 0;

	void addString(String s, int root) {
		for (int i = s.length() - 1; i >= 0; i--) {
			int x = Character.toLowerCase(s.charAt(i)) - 'a';
			if (next[x][root] == -1) {
				next[x][root] = get();
			}
			root = next[x][root];
		}
		str[root] = s;
	}

	int get() {
		for (int i = 0; i < 26; i++) {
			next[i][cnt] = -1;
		}
		return cnt++;
	}

	void solve() {
		int n = in.nextInt();
		String s = in.next();
		int m = in.nextInt();
		int root = get();
		for (int i = 0; i < m; i++) {
			addString(in.next(), root);
		}
		String[] prev = new String[n + 1];
		boolean[] can = new boolean[n + 1];
		can[0] = true;
		for (int i = 0; i < n; i++) {
			int cur = root;
			if (!can[i]) {
				continue;
			}
			for (int j = i; j < n; j++) {
				int c = s.charAt(j) - 'a';
				if (next[c][cur] == -1) {
					break;
				} else {
					cur = next[c][cur];
				}
				if (str[cur] != null) {
					can[j + 1] = true;
					prev[j + 1] = str[cur];
				}
			}
		}
		int now = n;
		ArrayList<String> res = new ArrayList<>();
		while (now != 0) {
			String use = prev[now];
			now -= use.length();
			res.add(use);
		}
		Collections.reverse(res);
		for (String ss : res) {
			out.print(ss + " ");
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
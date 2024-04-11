import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	String all = "";
	char[][] res;

	int getId(char a, char b) {
		int p1 = all.indexOf(a);
		int p2 = all.indexOf(b);
		int ans = p1 * all.length() + p2;
		res[0][ans] = a;
		res[1][ans] = b;
		return p1 * all.length() + p2;
	}

	int[] sz;
	ArrayList<Integer>[] g;

	void solve() {
		int n = in.nextInt();
		for (int i = 0; i < 26; i++) {
			all = all + (char) ('a' + i);
			all = all + (char) ('A' + i);
		}
		for (int i = 0; i < 10; i++) {
			all = all + (char) ('0' + i);
		}
		int cnt = all.length() * all.length();
		res = new char[2][cnt];
		g = new ArrayList[cnt];
		for (int i = 0; i < cnt; i++) {
			g[i] = new ArrayList<>();
		}
		int[] inD = new int[cnt];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			int from = getId(s.charAt(0), s.charAt(1));
			int to = getId(s.charAt(1), s.charAt(2));
			g[from].add(to);
			inD[to]++;
		}
		int start = -1, end = -1;
		for (int i = 0; i < cnt; i++) {
			if (g[i].size() == inD[i]) {
				continue;
			}
			if (Math.abs(g[i].size() - inD[i]) != 1) {
				out.println("NO");
				return;
			}
			if (g[i].size() > inD[i]) {
				if (start == -1) {
					start = i;
				} else {
					out.println("NO");
					return;
				}
			} else {
				if (end == -1) {
					end = i;
				} else {
					out.println("NO");
					return;
				}
			}
		}
		if (start == -1) {
			start = 0;
			while (g[start].size() == 0) {
				start++;
			}
			end = start;
		}
		sz = new int[cnt];
		for (int i = 0; i < cnt; i++) {
			sz[i] = g[i].size() - 1;
		}
		go(start);
		for (int i = 0; i < cnt; i++) {
			if (sz[i] != -1) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		out.print(res[0][ans.get(ans.size() - 1)]);
		for (int i = ans.size() - 1; i >= 0; i--) {
			int cur = ans.get(i);
			out.print(res[1][cur]);
		}
	}

	ArrayList<Integer> ans = new ArrayList<>();

	void go(int v) {
		while (sz[v] >= 0) {
			int to = g[v].get(sz[v]);
			sz[v]--;
			go(to);
		}
		ans.add(v);
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
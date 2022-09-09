
 import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;

	int go(int v, int parent) {
		int cnt1 = 0, cnt2 = 0, cnt0 = 0;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == parent) {
				continue;
			}
			int u = go(to, v);
			if (u > 2) {
				return 4;
			}
			if (u == 0) {
				cnt0++;
			}
			if (u == 1) {
				cnt1++;
			}
			if (u == 2) {
				cnt2++;
			}
		}
		if (cnt2 > 2) {
			return 4;
		}
		if (cnt2 == 2) {
			return 3;
		}
		if (cnt2 == 1) {
			return 2;
		}
		if (cnt1 > 0) {
			return 2;
		}
		if (cnt0 > 2) {
			return 2;
		}
		if (cnt0 == 2) {
			return 1;
		}
		return 0;
	}

	void solve() {
		int n = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
int root = 0;
while (root != n && g[root].size() != 3) root++;
if (root == n) root = 0;
if (go(root, -1) <= 3)
		{
			out.println("Yes");
return ;		
}
if (g[root].size() == 3) for (int x : g[root]) if (go(x, -1) <= 3) {
out.println("Yes");
return;
} 
			out.println("No");
		}
	

	void run() {
		try {
			in = new FastScanner(new File("B.in"));
			out = new PrintWriter(new File("B.out"));

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
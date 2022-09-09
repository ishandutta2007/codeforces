import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] up;

	int get(int x) {
		return up[x] == x ? x : (up[x] = get(up[x]));
	}

	int[] inT;
	int[] outT;
	int time;
	ArrayList<Integer>[] g;

	void go(int v, int p) {
		inT[v] = time++;
		for (int to : g[v])
			if (to != p) {
				go(to, v);
			}
		outT[v] = time - 1;
	}

	boolean inside(int parent, int u) {
		return (inT[parent] <= inT[u] && outT[parent] >= inT[u]);
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		up = new int[n];
		for (int i = 0; i < n; i++)
			up[i] = i;
		ArrayList<Integer> from = new ArrayList<>();
		ArrayList<Integer> to = new ArrayList<>();
		g = new ArrayList[n];
		boolean[] root = new boolean[n];
		Arrays.fill(root, true);
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		ArrayList<Integer> ask = new ArrayList<>();
		ArrayList<Integer> docId = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			int type = in.nextInt();
			if (type == 1) {
				int v = in.nextInt() - 1;
				int u = in.nextInt() - 1;
				up[v] = u;
				g[u].add(v);
				root[v] = false;
			} else {
				if (type == 2) {
					int v = in.nextInt() - 1;
					int u = get(v);
					from.add(v);
					to.add(u);
				} else {
					ask.add(in.nextInt() - 1);
					docId.add(in.nextInt() - 1);
				}
			}
		}
		inT = new int[n];
		outT = new int[n];
		for (int i = 0; i < n; i++)
			if (root[i])
				go(i, i);
		for (int i = 0; i < ask.size(); i++) {
			int fr = from.get(docId.get(i));
			int to1 = to.get(docId.get(i));
			int what = ask.get(i);
			out.println(inside(to1, what) && inside(what, fr) ? "YES" : "NO");
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
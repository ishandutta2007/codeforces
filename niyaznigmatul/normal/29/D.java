import java.io.*;
import java.util.*;

public class D implements Runnable {
	public static void main(String[] args) {
		new D().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	ArrayList<Integer>[] edges;
	HashSet<Integer>[] leaves;

	void dfs1(int x, int parent) {
		boolean isLeaf = true;
		for (int i : edges[x]) {
			if (i == parent) {
				continue;
			}
			isLeaf = false;
			dfs1(i, x);
			leaves[x].addAll(leaves[i]);
		}
		if (isLeaf) {
			leaves[x].add(x);
		}
	}

	void dfs2(int x, int parent, ArrayList<Integer> ans) {
		boolean isLeaf = true;
		ans.add(x);
		for (int i = 0; i < edges[x].size(); i++) {
			int j = edges[x].get(i);
			if (j == parent) {
				continue;
			}
			isLeaf = false;
			if (leaves[j].contains(path[cnt])) {
				dfs2(j, x, ans);
				ans.add(x);
				if (cnt < path.length && leaves[x].contains(path[cnt])) {
					i = -1;
					continue;
				} else {
					return;
				}
			}
		}
		if (isLeaf) {
			++cnt;
		}
	}

	int[] path;
	int cnt;

	void solve() {
		int n = nextInt();
		edges = new ArrayList[n];
		leaves = new HashSet[n];
		for (int i = 0; i < edges.length; i++) {
			edges[i] = new ArrayList<Integer>();
			leaves[i] = new HashSet<Integer>();
		}
		for (int i = 0; i + 1 < n; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			edges[x].add(y);
			edges[y].add(x);
		}
		dfs1(0, -1);
		path = new int[leaves[0].size()];
		cnt = 0;
		for (int i = 0; i < path.length; i++) {
			path[i] = nextInt() - 1;
		}
		ArrayList<Integer> ans = new ArrayList<Integer>();
		dfs2(0, -1, ans);
		if (ans.size() == 2 * n - 1) {
			for (int i = 0; i < ans.size(); i++) {
				out.print(1 + ans.get(i) + " ");
			}
		} else {
			out.println("-1");
		}
	}
}
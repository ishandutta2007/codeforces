import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	class Edge {
		int to;
		int color;

		public Edge(int to, int color) {
			super();
			this.to = to;
			this.color = color;
		}

		@Override
		public String toString() {
			return "Edge [to=" + to + ", color=" + color + "]";
		}

	}

	ArrayList<Edge>[] g;

	boolean[] was;

	ArrayList<Integer> cur = new ArrayList<>();
	ArrayList<Integer> changed;
	int[] chang;

	boolean dfs(int v, int ch, int needColor) {
		was[v] = true;
		chang[v] = ch;
		cur.add(v);
		if (ch == 1) {
			changed.add(v);
		}
		for (Edge e : g[v]) {
			if (!was[e.to]) {
				if (!dfs(e.to, e.color ^ needColor ^ ch, needColor)) {
					return false;
				}
			} else {
				if ((e.color ^ ch ^ chang[e.to]) != needColor) {
					return false;
				}
			}
		}
		return true;
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			int color = in.next().equals("R") ? 1 : 0;
			Edge e1 = new Edge(to, color);
			Edge e2 = new Edge(fr, color);
			g[fr].add(e1);
			g[to].add(e2);
		}
		was = new boolean[n];
		chang = new int[n];

		ArrayList<Integer> bestAnswer = null;

		for (int needColor = 0; needColor < 2; needColor++) {
			ArrayList<Integer> answer = new ArrayList<>();
			boolean[] was2 = new boolean[n];
			boolean failed = false;
			for (int i = 0; i < n; i++) {
				if (was2[i]) {
					continue;
				}
				ArrayList<Integer> best = null;
				for (int ch = 0; ch < 2; ch++) {
					cur.clear();
					changed = new ArrayList<>();
					if (dfs(i, ch, needColor)) {
						if (best == null || best.size() > changed.size()) {
							best = changed;
						}
					}
					for (int v : cur) {
						was[v] = false;
						was2[v] = true;
					}
				}
				if (best == null) {
					failed = true;
					break;
				}
				for (int x : best) {
					answer.add(x);
				}
			}
			if (failed) {
				continue;
			}
			if (bestAnswer == null || bestAnswer.size() > answer.size()) {
				bestAnswer = answer;
			}
		}
		if (bestAnswer == null) {
			out.println(-1);
		} else {
			out.println(bestAnswer.size());
			for (int i : bestAnswer) {
				out.print((i + 1) + " ");
			}
		}
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
		new B().runIO();
	}
}
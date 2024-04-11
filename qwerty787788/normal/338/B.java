import java.io.*;
import java.util.*;

public class CF {

	boolean[] seen;
	ArrayList<Integer>[] g;
	int[] max;
	int[] realMax;

	class TwoMaxes {
		int m1;
		int m2;

		public TwoMaxes() {
			m1 = Integer.MIN_VALUE / 2;
			m2 = Integer.MIN_VALUE / 2;
		}

		void upd(int v) {
			if (v >= m1) {
				m2 = m1;
				m1 = v;
				return;
			}
			if (v >= m2) {
				m2 = v;
				return;
			}
		}
	}

	int go(int v, int p) {
		max[v] = Integer.MIN_VALUE / 2;
		if (seen[v])
			max[v] = 0;
		for (int i = 0; i < g[v].size(); i++) {
			if (g[v].get(i) != p) {
				max[v] = Math.max(max[v], go(g[v].get(i), v) + 1);
			}
		}
		return max[v];
	}

	void go2(int v, int p, int maxUp) {
		realMax[v] = Math.max(max[v], maxUp);
		TwoMaxes t1 = new TwoMaxes();
		t1.upd(maxUp);
		if (seen[v])
			t1.upd(0);
		for (int i = 0; i < g[v].size(); i++)
			if (g[v].get(i) != p) {
				t1.upd(max[g[v].get(i)] + 1);
			}
		for (int i = 0; i < g[v].size(); i++)
			if (g[v].get(i) != p) {
				int nmax = t1.m1 == max[g[v].get(i)] + 1 ? t1.m2 + 1
						: t1.m1 + 1;
				go2(g[v].get(i), v, nmax);
			}
	}

	void realSolve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		int d = in.nextInt();
		seen = new boolean[n];
		for (int i = 0; i < m; i++) {
			seen[in.nextInt() - 1] = true;
		}
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
		max = new int[n];
		realMax = new int[n];
		go(0, -1);
		go2(0, -1, Integer.MIN_VALUE / 2);
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (realMax[i] <= d) {
				res++;
			}
		}
		out.println(res);
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	void solve() throws IOException {
		in = new InputReader(new File("input.txt"));
		out = new PrintWriter(new File("output.txt"));

		realSolve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Edge {
		int fr, to, work;
		Edge rev;
		boolean used;

		public Edge(int fr, int to, int work) {
			super();
			this.fr = fr;
			this.to = to;
			this.work = work;
		}

	}

	class E2 implements Comparable<E2> {
		int to;
		int costLen;
		int costWork;

		public E2(int to, int costLen, int costWork) {
			super();
			this.to = to;
			this.costLen = costLen;
			this.costWork = costWork;
		}

		@Override
		public int compareTo(E2 o) {
			if (costLen == o.costLen) {
				return -Integer.compare(costWork, o.costWork);
			}
			return Integer.compare(costLen, o.costLen);
		}

	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<Edge>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1, to = in.nextInt() - 1, work = in
					.nextInt();
			Edge e1 = new Edge(fr, to, work);
			Edge e2 = new Edge(to, fr, work);
			e1.rev = e2;
			e2.rev = e1;
			g[fr].add(e1);
			g[to].add(e2);
		}
		Edge[] prev = new Edge[n];
		E2[] cost = new E2[n];
		boolean[] was = new boolean[n];
		PriorityQueue<E2> pq = new PriorityQueue<>();
		pq.add(new E2(0, 0, 0));
		cost[0] = new E2(0, 0, 0);
		while (pq.size() > 0) {
			E2 e = pq.poll();
			int v = e.to;
			if (was[v]) {
				continue;
			}
			was[v] = true;
			for (Edge ee : g[v]) {
				E2 newE = new E2(ee.to, 1 + cost[v].costLen, cost[v].costWork
						+ ee.work);
				if (cost[ee.to] == null || cost[ee.to].compareTo(newE) > 0) {
					cost[ee.to] = newE;
					pq.add(newE);
					prev[ee.to] = ee;
				}
			}
		}
		int v = n - 1;
		while (v != 0) {
			Edge e = prev[v];
			v = e.fr;
			e.used = true;
			e.rev.used = true;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) 
			for (Edge e : g[i]) 
				if (e.to > e.fr) {
					if (e.used && e.work == 0) {
						ans++;
					} else {
						if (!e.used && e.work == 1) {
							ans++;
						}
					}
				}
		out.println(ans);
		for (int i = 0; i < n; i++) 
			for (Edge e : g[i]) 
				if (e.to > e.fr) {
					if (e.used && e.work == 0) {
						out.println((e.fr + 1) + " " + (e.to + 1) + " " + 1);
					} else {
						if (!e.used && e.work == 1) {
							out.println((e.fr + 1) + " " + (e.to + 1) + " " + 0);
						}
					}
				}
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
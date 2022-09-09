import java.io.*;
import java.util.*;

public class CF229B {
	FastScanner in;
	PrintWriter out;

	ArrayList<Road>[] g;
	
	class Road implements Comparable<Road>{
		int fr, to, cost;

		public Road(int fr, int to, int cost) {
			this.fr = fr;
			this.to = to;
			this.cost = cost;
		}

		@Override
		public int compareTo(Road o) {
			return cost - o.cost;
		}
	}
	
	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Road>();
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			int cost = in.nextInt();
			g[fr].add(new Road(fr, to, cost));
			g[to].add(new Road(to, fr, cost));
		}
		ArrayList<Integer>[] times = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			int k = in.nextInt();
			times[i] = new ArrayList<Integer>();
			for (int j = 0; j < k; j++)
				times[i].add(in.nextInt());
		}
		PriorityQueue<Road> roads = new PriorityQueue<Road>();
		int[] ans = new int[n];
		Arrays.fill(ans, Integer.MAX_VALUE);
		ans[0] = 0;
		roads.add(new Road(0, 0, 0));
		while (roads.size() != 0) {
			Road r = roads.peek();
			roads.remove();
			if (ans[r.to] == r.cost) {
				int nowTime = r.cost;
				int it = 0;
				while (it < times[r.to].size() && times[r.to].get(it) <= nowTime) {
					if (times[r.to].get(it) == nowTime)
						nowTime++;
					it++;
				}
				for (Road newRoad : g[r.to]) {
					int cost = newRoad.cost + nowTime;
					if (ans[newRoad.to] > cost) {
						ans[newRoad.to] = cost;
						roads.add(new Road(0, newRoad.to, cost));
					}
				}
			}
		}
		if (ans[n - 1] == Integer.MAX_VALUE)
			ans[n - 1] = -1;
		out.println(ans[n - 1]);
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
	}

	public static void main(String[] args) {
		new CF229B().runIO();
	}
}
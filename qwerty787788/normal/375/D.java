import java.io.*;
import java.util.*;

public class CF {

	int[] color;
	ArrayList<Integer>[] g;
	int[] ans;
	ArrayList<Ask>[] q;

	class Ask {
		int id, cnt;

		Ask(int id, int cnt) {
			this.id = id;
			this.cnt = cnt;
		}
	}

	class Vertex {
		HashMap<Integer, Integer> hm;
		ArrayList<Integer> ans;

		Vertex() {
			hm = new HashMap<>(1);
			ans = new ArrayList<>(1);
		}
	}

	void update(ArrayList<Integer> arr, int from, int to) {
		for (int i = from; i <= to; i++) {
			while (arr.size() <= i)
				arr.add(0);
			arr.set(i, arr.get(i) + 1);
		}
	}

	Vertex union(Vertex v1, Vertex v2) {
		if (v1.hm.size() < v2.hm.size())
			return union(v2, v1);
		for (Map.Entry<Integer, Integer> entry : v2.hm.entrySet()) {
			Integer was = v1.hm.get(entry.getKey());
			if (was == null)
				was = 0;
			update(v1.ans, was + 1, was + entry.getValue());
			v1.hm.put(entry.getKey(), entry.getValue() + was);
		}
		return v1;
	}

	int get(ArrayList<Integer> x, int pos) {
		return pos >= x.size() ? 0 : x.get(pos);
	}

	Vertex go(int v, int p) {
		Vertex res = new Vertex();
		update(res.ans, 0, 1);
		res.hm.put(color[v], 1);
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p)
				continue;
			Vertex xx = go(to, v);
			res = union(res, xx);
		}
		for (int i = 0; i < q[v].size(); i++) {
			ans[q[v].get(i).id] = get(res.ans, q[v].get(i).cnt);
		}
		return res;
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		color = new int[n];
		for (int i = 0; i < n; i++)
			color[i] = in.nextInt() - 1;
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		ans = new int[m];
		q = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			q[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int v = in.nextInt() - 1;
			int how = in.nextInt();
			q[v].add(new Ask(i, how));
		}
		go(0, -1);
		for (int i = 0; i < m; i++)
			out.println(ans[i]);
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
import java.io.*;
import java.util.*;

public class CF8C {
	FastScanner in;
	PrintWriter out;

	int[] x, y;
	int[] av;
	int[][] d = new int[25][25];

	int dist(int v, int u) {
		if (u == v)
			return 0;
		return (d[v][u] == 0 ? d[v][u] = d[u][v] = (x[v] - x[u])
				* (x[v] - x[u]) + (y[v] - y[u]) * (y[v] - y[u]) : d[v][u]);
	}

	void add(int x) {
		av[++av[0]] = x;
	}

	int size() {
		return av[0];
	}

	int get(int i) {
		return av[i + 1];
	}

	int N = 24;
	int[] dp = new int[(1 << N)];
	int[] dpFrom = new int[1 << N];

	void solve() {
		int x1 = in.nextInt();
		int y1 = in.nextInt();
		int n = in.nextInt();

		x = new int[n + 1];
		y = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		x[0] = x1;
		y[0] = y1;
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		av = new int[n + 1];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dist(i, j);
		for (int st = 0; st < (1 << n); st++) {
			if (dp[st] == Integer.MAX_VALUE)
				continue;
			av[0] = 0;
			for (int i = 0; i < n; i++)
				if ((st & (1 << i)) == 0)
					add(i);
			if (av[0] == 0)
				continue;
			for (int i = 0; i < 1; i++)
				for (int j = i + 1; j < av[0]; j++) {
					int val = dp[st] + d[get(i) + 1][0]
							+ d[get(j) + 1][0]
							+ d[get(i) + 1][get(j) + 1];
					if (dp[st | (1 << get(i)) | (1 << get(j))] > val) {
						dp[st | (1 << get(i)) | (1 << get(j))] = val;
						dpFrom[st | (1 << get(i)) | (1 << get(j))] = st;
					}
				}
			for (int i = 0; i < 1; i++) {
				int val = dp[st] + d[get(i) + 1][0] * 2;
				if (dp[st | (1 << get(i))] > val) {
					dp[st | (1 << get(i))] = val;
					dpFrom[st | (1 << get(i))] = st;
				}
			}
		}
		out.println(dp[(1 << n) - 1]);
		int nowSt = (1 << n) - 1;
		ArrayList<Integer> ans = new ArrayList<Integer>();
		ans.add(0);
		while (nowSt != 0) {
			int newSt = dpFrom[nowSt];
			for (int i = 0; i < n; i++)
				if (((1 << i) & nowSt) == (1 << i))
					if (((1 << i) & newSt) == 0)
						ans.add(i + 1);
			ans.add(0);
			nowSt = newSt;
		}
		for (int i = ans.size() - 1; i >= 0; i--)
			out.print(ans.get(i) + " ");
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
		new CF8C().runIO();
	}
}
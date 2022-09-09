import java.io.*;
import java.util.*;

public class CFF {
	FastScanner in;
	PrintWriter out;

	class Edge {
		int fr, to;
		long flow, cap;
		Edge rev;

		Edge(int fr, int to, long cap) {
			this.fr = fr;
			this.to = to;
			this.cap = cap;
		}
	}

	class Flow {
		int n;
		ArrayList<Edge>[] g;

		Flow(int n) {
			this.n = n;
			g = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				g[i] = new ArrayList<>();
			}
			q = new int[n];
			h = new int[n];
			cur = new int[n];
		}

		void addEdge(int fr, int to, long cap) {
			Edge e1 = new Edge(fr, to, cap);
			Edge e2 = new Edge(to, fr, 0);
			e1.rev = e2;
			e2.rev = e1;
			g[fr].add(e1);
			g[to].add(e2);
		}

		int[] h;
		int[] cur;
		int[] q;

		boolean bfs() {
			int qIt = 0, qSz = 0;
			q[qSz++] = 0;
			Arrays.fill(h, -1);
			h[0] = 0;
			while (qIt < qSz) {
				int v = q[qIt++];
				for (Edge e : g[v]) {
					if (e.flow == e.cap)
						continue;
					if (h[e.to] == -1) {
						h[e.to] = h[e.fr] + 1;
						q[qSz++] = e.to;
					}
				}
			}
			return h[n - 1] != -1;
		}

		long dfs(int v, long flow) {
			if (v == n - 1 || flow == 0)
				return flow;
			for (; cur[v] < g[v].size(); cur[v]++) {
				Edge e = g[v].get(cur[v]);
				if (h[e.to] != h[e.fr] + 1 || e.flow == e.cap)
					continue;
				long add = dfs(e.to, Math.min(flow, e.cap - e.flow));
				if (add == 0)
					continue;
				e.flow += add;
				e.rev.flow -= add;
				return add;
			}
			return 0;
		}

		long flow() {
			long res = 0;
			while (bfs()) {
				Arrays.fill(cur, 0);
				while (true) {
					long add = dfs(0, Long.MAX_VALUE);
					if (add == 0)
						break;
					res += add;
				}
			}
			return res;
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int males = in.nextInt();
		int females = in.nextInt();
		boolean meMale = males < females;
		int[] dx = new int[] { -1, 0, 0, 1 };
		int[] dy = new int[] { 0, -1, 1, 0 };
		if (males + (meMale ? 1 : -1) == females) {
			char[][] a = new char[n][];
			for (int i = 0; i < n; i++) {
				a[i] = in.next().toCharArray();
			}
			int[][] id = new int[n][m];
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[i][j] == '.') {
						id[i][j] = cnt++;
					} else {
						id[i][j] = -1;
					}
				}
			}
			int[] xPos = new int[cnt];
			int[] yPos = new int[cnt];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (id[i][j] != -1) {
						xPos[id[i][j]] = i;
						yPos[id[i][j]] = j;
					}
			int[][] time = new int[cnt][cnt];
			int[] q = new int[cnt];
			for (int i = 0; i < cnt; i++) {
				Arrays.fill(time[i], -1);
				time[i][i] = 0;
				q[0] = i;
				int qIt = 0, qSz = 1;
				while (qIt < qSz) {
					int cid = q[qIt++];
					int x = xPos[cid], y = yPos[cid];
					for (int ii = 0; ii < dx.length; ii++) {
						int nx = x + dx[ii];
						int ny = y + dy[ii];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							int rId = id[nx][ny];
							if (rId != -1 && time[i][rId] == -1) {
								time[i][rId] = time[i][cid] + 1;
								q[qSz++] = rId;
							}
						}
					}
				}
			}
			int[] startX = new int[males + females + 1];
			int[] startY = new int[males + females + 1];
			int[] timeNeed = new int[males + females + 1];
			for (int i = 0; i < startX.length; i++) {
				startX[i] = in.nextInt() - 1;
				startY[i] = in.nextInt() - 1;
				timeNeed[i] = in.nextInt();
			}
			int total = males + females + 1;
			boolean[] isMale = new boolean[total];
			for (int i = 0; i < males; i++) {
				isMale[i + 1] = true;
			}
			isMale[0] = meMale;
			for (int i = 0; i < females; i++) {
				isMale[i + 1 + males] = false;
			}
			long left = -1, right = (long) 1e15;
			while (right - left > 1) {
				long mid = (left + right) / 2;
				Flow f = new Flow(2 + cnt + cnt + total);
				for (int i = 0; i < cnt; i++) {
					f.addEdge(1 + total + i, 1 + total + cnt + i, 1);
				}
				for (int i = 0; i < total; i++) {
					if (isMale[i]) {
						f.addEdge(0, i + 1, 1);
						for (int j = 0; j < cnt; j++) {
							int tt = time[id[startX[i]][startY[i]]][j];
							if (tt != -1 && tt * 1L * timeNeed[i] <= mid) {
								f.addEdge(i + 1, total + 1 + j, 1);
							}
						}
					} else {
						f.addEdge(i + 1, f.n - 1, 1);
						for (int j = 0; j < cnt; j++) {
							int tt = time[id[startX[i]][startY[i]]][j];
							if (tt != -1 && tt * 1L * timeNeed[i] <= mid) {
								f.addEdge(cnt + total + 1 + j, 1 + i, 1);
							}
						}
					}
				}
				int needFlow = males;
				if (meMale) {
					needFlow++;
				}
				if (f.flow() == needFlow) {
					right = mid;
				} else {
					left = mid;
				}
			}
			if (left > 1e14) {
				out.println(-1);
			} else {
				out.println(right);
			}
		} else {
			out.println(-1);
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
		new CFF().runIO();
	}
}
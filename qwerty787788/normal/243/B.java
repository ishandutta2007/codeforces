import java.io.*;
import java.util.*;

public class CF150DIV1 {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int h = in.nextInt();
		int t = in.nextInt();
		ArrayList<Integer>[] g = new ArrayList[n];
		int[][] r = new int[2 * m][2];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			r[i][0] = fr;
			r[i][1] = to;
			r[i + m][0] = to;
			r[i + m][1] = fr;
			g[fr].add(to);
			g[to].add(fr);
		}
		int[] used = new int[n];
		//ArrayList<Integer> elements = new ArrayList<Integer>();
		int[] lastTime = new int[n];
		int[] stack = new int[n];
		int stackSz = 0;
		Arrays.fill(lastTime, -1);
		for (int i = 0; i < 2 * m; i++) {
			int u1 = r[i][0];
			int u2 = r[i][1];
			int v1 = g[r[i][0]].size();
			int v2 = g[r[i][1]].size();
			if (v1 >= h+1 && v2 >= t+1) {
				stackSz = 0;
				for (int j = 0; j < g[u1].size(); j++)
					if (g[u1].get(j) != u2) {
						used[g[u1].get(j)] ++;
						if (lastTime[g[u1].get(j)] < i) {
							stack[stackSz++] = g[u1].get(j);
							lastTime[g[u1].get(j)] = i;
						}
					}
				for (int j = 0; j < g[u2].size(); j++)
					if (g[u2].get(j) != u1) {
						used[g[u2].get(j)] +=2;
						if (lastTime[g[u2].get(j)] < i) {
							stack[stackSz++] = g[u2].get(j);
							lastTime[g[u2].get(j)] = i;
						}
					}
				int head = 0, tail = 0, both = 0;
				for (int x1 = 0; x1 < stackSz; x1++) {
					int x = stack[x1];
					if (used[x] == 1)
						head++; else
							if (used[x] == 2) 
								tail++;
							else both++;
				}
				int needH = Math.max(0, h - head);
				int needT = Math.max(0, t - tail);
				if (both >= needH) {
					if (both - needH + tail >= t) {
						out.println("YES");
						out.println((u1 + 1) + " " + (u2 + 1));
						TreeSet<Integer> heads = new TreeSet<Integer>();
						TreeSet<Integer> tails = new TreeSet<Integer>();
						for (int x1 = 0; x1 < stackSz; x1++) {
							int x = stack[x1];
							if (used[x] == 1) {
								if (h > 0) {
									h--;
									heads.add(x + 1);
								}
							} else {
								if (used[x] == 2) {
									if (t > 0) {
										t--;
										tails.add(x + 1);
									}
								} else {
									if (needH > 0) {
										needH--;
										heads.add(x + 1);
									} else {
										if (needT > 0) {
											needT--;
											tails.add(x + 1);
										}
									}
								}
							}
						}
						for (int x : heads){
							out.print(x + " ");
						}
						out.println();
						for (int x : tails) {
							out.print(x + " ");
						}
						return;
					}
				}
				for (int x1 = 0; x1 < stackSz; x1++)
					used[stack[x1]] = 0;
			}
		}
		out.println("NO");
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
		new CF150DIV1().runIO();
	}
}
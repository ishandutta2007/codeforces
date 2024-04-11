import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] remove(int[] a) {
		ArrayList<Integer> res = new ArrayList<>();
		for (int x : a) {
			int sz = res.size();
			if (sz >= 3 && res.get(sz - 1) == x && res.get(sz - 2) == x
					&& res.get(sz - 3) == x) {
				continue;
			}
			res.add(x);
		}
		int[] result = new int[res.size()];
		for (int i = 0; i < result.length; i++) {
			result[i] = res.get(i);
		}
		return result;
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		int cnt0 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				cnt0++;
			}
		}
		int res = Math.max(cnt0, 2);
		a = remove(a);
		n = a.length;
		int[][] go = new int[n][n];
		for (int i = 0; i < n; i++) {
			int it = 0;
			for (int j = 0; j < n; j++) {
				int need = a[i] + a[j];
				while (it < n && a[it] < need) {
					it++;
				}
				go[i][j] = it;
			}
		}
		int[] lastTime = new int[n];
		int time = 0;
		for (int f = 0; f < n; f++) {
			for (int s = 0; s < n; s++) {
				if (f != s && (a[f] != 0 || a[s] != 0)) {
					time++;
					lastTime[f] = time;
					lastTime[s] = time;
					int c1 = f, c2 = s;
					int sz = 2;
					while (true) {
						int ne = go[c1][c2];
						int need = a[c1] + a[c2];
						while (ne < n && a[ne] == need && lastTime[ne] == time) {
							ne++;
						}
						if (ne < n && a[ne] == need && lastTime[ne] < time) {
							c1 = c2;
							c2 = ne;
							lastTime[ne] = time;
							sz++;
						} else {
							break;
						}
					}
					res = Math.max(res, sz);
				}
			}
		}
		out.println(res);
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test2.out"));

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
		new CF().runIO();
	}
}
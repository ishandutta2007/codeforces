import java.io.*;
import java.util.*;

public class CF {

	int n;

	int getSt(int a, int b, int c) {
		if (a == b || a == c || b == c)
			return -1;
		int A = Math.min(Math.min(a, b), c);
		int C = Math.max(Math.max(a, b), c);
		int B = a + b + c - A - C;
		return A * (n + 1) * (n + 1) + B * (n + 1) + C;
	}

	int[] getSt(int st) {
		int C = st % (n + 1);
		st /= (n + 1);
		int B = st % (n + 1);
		st /= n + 1;
		int A = st;
		return new int[] { A, B, C };
	}

	void solve() {
		n = in.nextInt();
		int st = getSt(in.nextInt() - 1, in.nextInt() - 1, in.nextInt() - 1);
		char[][] c = new char[n][n];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < n; j++)
				c[i][j] = s.charAt(j);
		}
		int mm = (n + 1) * (n + 1) * (n + 1);
		int[] q = new int[mm];
		q[0] = st;
		int qit = 0, qsz = 1;
		int[] dist = new int[mm];
		int[] from = new int[mm];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[st] = 0;
		while (qit < qsz) {
			int v = q[qit++];
			int[] state = getSt(v);
			for (int i = 0; i < 3; i++) {
				char col = 'a';
				if (i == 0) {
					col = c[state[1]][state[2]];
					for (int j = 0; j < n; j++)
						if (c[state[0]][j] == col) {
							int nv = getSt(j, state[1], state[2]);
							if (nv == -1 || dist[nv] <= dist[v] + 1)
								continue;
							dist[nv] = dist[v] + 1;
							from[nv] = v;
							q[qsz++] = nv;
						}
				}
				if (i == 1) {
					col = c[state[0]][state[2]];
					for (int j = 0; j < n; j++)
						if (c[state[1]][j] == col) {
							int nv = getSt(j, state[0], state[2]);
							if (nv == -1 || dist[nv] <= dist[v] + 1)
								continue;
							dist[nv] = dist[v] + 1;
							from[nv] = v;
							q[qsz++] = nv;
						}
				}
				if (i == 2) {
					col = c[state[1]][state[0]];
					for (int j = 0; j < n; j++)
						if (c[state[2]][j] == col) {
							int nv = getSt(j, state[1], state[0]);
							if (nv == -1 || dist[nv] <= dist[v] + 1)
								continue;
							dist[nv] = dist[v] + 1;
							from[nv] = v;
							q[qsz++] = nv;
						}
				}
			}
		}
		int need = getSt(0, 1, 2);
		if (dist[need] == Integer.MAX_VALUE) {
			out.println(-1);
		} else {
			out.println(dist[need]);
			ArrayList<Integer> ans1 = new ArrayList<>();
			ArrayList<Integer> ans2 = new ArrayList<>();
			while (need != st) {
				int back = from[need];
				int[] was = getSt(back);
				int[] bec = getSt(need);
				for (int i = 0; i < 3; i++) {
					boolean has = false;
					for (int j = 0; j < 3; j++)
						if (bec[j] == was[i])
							has = true;
					if (!has) {
						ans1.add(was[i] + 1);
					}
				}
				for (int i = 0; i < 3; i++) {
					boolean has = false;
					for (int j = 0; j < 3; j++)
						if (bec[i] == was[j])
							has = true;
					if (!has) {
						ans2.add(bec[i] + 1);
					}
				}
				need = back;
			}
			for (int i = ans1.size() - 1; i >= 0; i--) {
				out.println(ans1.get(i) + " " + ans2.get(i));
			}
		}
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
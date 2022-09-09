import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Obj implements Comparable<Obj> {
		int h, m;

		public Obj(int h, int m) {
			super();
			this.h = h;
			this.m = m;
		}

		@Override
		public int compareTo(Obj o) {
			return Integer.compare(m, o.m);
		}

	}

	void solve() {
		int n = in.nextInt();
		int x = in.nextInt();
		ArrayList<Obj> t1 = new ArrayList<>();
		ArrayList<Obj> t2 = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (in.nextInt() == 0) {
				t1.add(new Obj(in.nextInt(), in.nextInt()));
			} else {
				t2.add(new Obj(in.nextInt(), in.nextInt()));
			}
		}
		Collections.sort(t1);
		Collections.sort(t2);
		int ans = 0;
		for (int startType = 0; startType < 2; startType++) {
			int curT = startType;
			int curAns = 0;
			int curX = x;
			boolean[][] was = new boolean[2][];
			was[0] = new boolean[t1.size()];
			was[1] = new boolean[t2.size()];
			while (true) {
				if (curT == 0) {
					int id = -1;
					for (int i = t1.size() - 1; i >= 0; i--) {
						if (!was[0][i] && t1.get(i).h <= curX) {
							id = i;
							was[0][i] = true;
							curX += t1.get(i).m;
							curAns++;
							break;
						}
					}
					if (id == -1)
						break;
				} else {
					int id = -1;
					for (int i = t2.size() - 1; i >= 0; i--) {
						if (!was[1][i] && t2.get(i).h <= curX) {
							id = i;
							was[1][i] = true;
							curX += t2.get(i).m;
							curAns++;
							break;
						}
					}
					if (id == -1)
						break;
				}
				curT = 1 - curT;
			}
			ans = Math.max(ans, curAns);
		}
		out.println(ans);
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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
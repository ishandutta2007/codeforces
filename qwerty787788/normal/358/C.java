import java.io.*;
import java.util.*;

public class CF {

	class Pair implements Comparable<Pair> {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			return -Integer.compare(x, o.x);
		}
	}

	void solve() {
		int n = in.nextInt();
		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
		}
		boolean[] use = new boolean[n];
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		for (int i = 0; i < n; i++)
			if (x[i] == 0) {
				for (int it = 0; it < 3; it++) {
					if (pq.size() == 0)
						break;
					Pair p = pq.remove();
					use[p.y] = true;
				}
				pq.clear();
			} else {
				pq.add(new Pair(x[i], i));
			}
		int[] cnt = new int[3];
		String[] ss = { "pushStack", "pushQueue", "pushFront", "pushBack" };
		String[] ss2 = { "popStack", "popQueue", "popFront", "popBack" };
		for (int i = 0; i < n; i++) {
			int xx = x[i];
			if (xx != 0) {
				if (use[i]) {
					int min = 0;
					for (int j = 0; j < 3; j++) {
						if (cnt[j] < cnt[min])
							min = j;
					}
					cnt[min]++;
					out.println(ss[min]);
				} else {
					out.println(ss[3]);
				}
			} else {
				int sz = 0;
				for (int j = 0; j < 3; j++)
					if (cnt[j] > 0)
						sz++;
				out.print(sz);
				if (sz != 0)
					out.print(" ");
				for (int j = 0; j < 3; j++)
					if (cnt[j] > 0) {
						cnt[j]--;
						sz--;
						out.print(ss2[j]);
						if (sz != 0)
							out.print(" ");
					}
				out.println();
				for (int j = 0; j < 3; j++)
					cnt[j] = 0;
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
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Q implements Comparable<Q> {
		long from, to;
		int id;

		public Q(long from, long to, int id) {
			super();
			this.from = from;
			this.id = id;
			this.to = to;
		}

		@Override
		public int compareTo(Q o) {
			if (to == o.to) {
				return -Integer.compare(id, o.id);
			}
			return Long.compare(to, o.to);
		}

	}

	class Bridge implements Comparable<Bridge> {
		int id;
		long len;

		public Bridge(int id, long len) {
			super();
			this.id = id;
			this.len = len;
		}

		@Override
		public int compareTo(Bridge o) {
			return Long.compare(len, o.len);
		}

	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		long[] left = new long[n];
		long[] right = new long[n];
		for (int i = 0; i < n; i++) {
			left[i] = in.nextLong();
			right[i] = in.nextLong();
		}
		Bridge[] all = new Bridge[m];
		for (int i = 0; i < m; i++) {
			all[i] = new Bridge(i + 1, in.nextLong());
		}
		Q[] q = new Q[(n - 1)];
		for (int i = 0; i + 1 < n; i++) {
			q[i] = new Q(left[i + 1] - right[i], right[i + 1] - left[i], i);
		}
		Arrays.sort(q, new Comparator<Q>() {

			@Override
			public int compare(Q o1, Q o2) {
				return Long.compare(o1.from, o2.from);
			}
		});
		int it = 0;
		Arrays.sort(all);
		PriorityQueue<Q> pq = new PriorityQueue<>();
		int[] res = new int[n - 1];
		for (int i = 0; i < all.length; i++) {
			while (it < q.length && q[it].from <= all[i].len) {
				pq.add(q[it++]);
			}
			if (pq.size() > 0) {
				Q qq = pq.poll();
				if (qq.to < all[i].len) {
					out.println("No");
					return;
				} else {
					res[qq.id] = all[i].id;
				}
			}
		}
		if (it != q.length) {
			out.println("No");
			return;
		}
		out.println("Yes");
		for (int i = 0; i < n - 1; i++) {
			out.print(res[i] + " ");
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
import java.io.*;
import java.util.*;

public class E {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		long result = 0;
		PriorityQueue<O> pq = new PriorityQueue();
		int[] c = new int[n];
		int[] wasC = new int[n];
		for (int i = 0; i < n; i++) {
			wasC[i] = in.nextInt();
			c[i] = wasC[i] % 100;
		}
		int[] w = new int[n];
		for (int i = 0; i < n; i++) {
			w[i] = in.nextInt();
		}
		boolean[] use = new boolean[n];
		for (int i = 0; i < n; i++) {
			m -= c[i];
			if (c[i] != 0) {
				pq.add(new O(i, w[i] * (100 - c[i])));
			}
			if (m < 0) {
				m += 100;
				O o = pq.poll();
				result += o.cost;
				use[o.id] = true;
			}
		}
		out.println(result);
		for (int i = 0; i < n; i++) {
			if (use[i]) {
				out.println((wasC[i] / 100 + 1) + " 0");
			} else {
				out.println((wasC[i] / 100) + " " + (wasC[i] % 100));
			}
		}
	}

	class O implements Comparable<O> {
		int id;
		int cost;

		public O(int id, int cost) {
			super();
			this.id = id;
			this.cost = cost;
		}

		public int compareTo(O o) {
			return Integer.compare(cost, o.cost);
		}

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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new E().runIO();
	}
}
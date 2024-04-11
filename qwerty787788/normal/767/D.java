import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		final int MAX = (int) 1e7 + 1;
		int[] cnt = new int[MAX];
		int[] f = new int[n];
		for (int i = 0; i < n; i++) {
			f[i] = in.nextInt();
		}
		Arrays.sort(f);
		int it = MAX - 1;
		for (int i = n - 1; i >= 0; i--) {
			int cur = f[i];
			it = Math.min(it, cur);
			while (it != -1 && cnt[it] == k) {
				it--;
			}
			if (it == -1) {
				out.println(-1);
				return;
			}
			cnt[it]++;
		}
		O[] a = new O[m];
		for (int i = 0; i < m; i++) {
			a[i] = new O(i, in.nextInt());
		}
		Arrays.sort(a);
		ArrayList<Integer> result = new ArrayList<Integer>();
		it = MAX - 1;
		for (int i = m - 1; i >= 0; i--) {
			it = Math.min(it, a[i].time);
			while (it != -1 && cnt[it] == k) {
				it--;
			}
			if (it != -1) {
				cnt[it]++;
				result.add(a[i].id);
			}
		}
		out.println(result.size());
		for (int i : result) {
			out.print((1 + i) + " ");
		}
	}

	class O implements Comparable<O> {
		int id;
		int time;

		public O(int id, int time) {
			super();
			this.id = id;
			this.time = time;
		}

		public int compareTo(O o) {
			return Integer.compare(time, o.time);
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
		new D().runIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] p;

	int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}

	void unite(int x, int y) {
		p[get(x)] = get(y);
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		boolean[] isCapital = new boolean[n];
		for (int i = 0; i < k; i++) {
			isCapital[in.nextInt() - 1] = true;
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			unite(fr, to);
		}
		int[] sz = new int[n];
		for (int i = 0; i < n; i++) {
			sz[get(i)]++;
			if (isCapital[i]) {
				isCapital[get(i)] = true;
			}
		}
		int free = 0;
		ArrayList<Integer> all = new ArrayList();
		for (int i = 0; i < n; i++) {
			if (sz[i] == 0) {
				continue;
			}
			if (isCapital[i]) {
				all.add(sz[i]);
			} else {
				free += sz[i];
			}
		}
		if (all.size() == 0) {
			all.add(0);
		}
		Collections.sort(all);
		all.set(all.size() - 1, all.get(all.size() - 1) + free);
		int total = 0;
		for (int size : all) {
			total += size * (size - 1) / 2;
		}
		out.println(total - m);
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
		new CF().runIO();
	}
}
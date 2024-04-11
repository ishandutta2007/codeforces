import java.io.*;
import java.util.*;

public class C {
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
		p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		for (int i = 0; i < n; i++) {
			int fr = in.nextInt() - 1;
			unite(fr, i);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += get(i) == i ? 1 : 0;
		}
		out.println(cnt);
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
		new C().runIO();
	}
}
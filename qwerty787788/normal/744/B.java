import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] res = new int[n];
		Arrays.fill(res, Integer.MAX_VALUE);
		for (int bit = 0; bit < 10; bit++) {
			for (int eq = 0; eq < 2; eq++) {
				boolean g = eq == 0;
				ArrayList<Integer> ask = new ArrayList<Integer>();
				for (int i = 0; i < n; i++) {
					boolean f = (((1 << bit) & i) != 0);
					if (g == f) {
						ask.add(i);
					}
				}
				if (ask.size() == 0) {
					continue;
				}
				out.println(ask.size());
				for (int x : ask) {
					out.print((1 + x) + " ");
				}
				out.println();
				out.flush();
				for (int i = 0; i < n; i++) {
					int cur = in.nextInt();
					boolean f = (((1 << bit) & i) != 0);
					if (g != f) {
						res[i] = Math.min(res[i], cur);
					}
				}
			}
		}
		out.println(-1);
		for (int x : res) {
			out.print(x + " ");
		}
		out.println();
		out.flush();
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
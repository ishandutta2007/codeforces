import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		ArrayList<Integer> a = new ArrayList<>();
		ArrayList<Integer> b = new ArrayList<>();
		boolean lastF = true;
		long s = 0;
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			s += x;
			if (x > 0) {
				lastF = true;
				a.add(x);
			} else {
				lastF = false;
				b.add(-x);
			}
		}
		String fi = "first";
		String se = "second";
		if (s > 0) {
			out.println(fi);
		} else {
			if (s < 0) {
				out.println(se);
			} else {
				for (int i = 0; i < Math.min(a.size(), b.size()); i++) {
					if (a.get(i) > b.get(i)) {
						out.println(fi);
						return;
					} else {
						if (a.get(i) < b.get(i)) {
							out.println(se);
							return;
						}
					}
				}
				if (a.size() > b.size()) {
					out.println(fi);
					return;
				}
				if (a.size() < b.size()) {
					out.println(se);
					return;
				}
				out.println(lastF ? fi : se);
			}
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
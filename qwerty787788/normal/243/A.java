import java.io.*;
import java.util.*;

public class CF150DIV1 {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		HashSet<Integer> all = new HashSet<Integer>();
		TreeSet<Integer> cur = new TreeSet<Integer>();
		TreeSet<Integer> newCur = new TreeSet<Integer>();
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			newCur.clear();
			newCur.add(x);
			for (int j : cur)
				newCur.add(j | x);
			cur.clear();
			for (int j : newCur) {
				cur.add(j);
				all.add(j);
			}
		}
		out.println(all.size());
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
	}

	public static void main(String[] args) {
		new CF150DIV1().runIO();
	}
}
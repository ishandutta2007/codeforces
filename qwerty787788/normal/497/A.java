import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		ArrayList<Integer> from = new ArrayList<>();
		ArrayList<Integer> to = new ArrayList<>();
		from.add(0);
		to.add(n - 1);
		int ans = 0;
		for (int col = 0; col < m; col++) {
			boolean ok = true;
			for (int i = 0; i < from.size(); i++) {
				int f = from.get(i);
				int t = to.get(i);
				for (int x = f; x < t; x++) {
					if (a[x][col] > a[x + 1][col] ){
						ok = false;
					}
				}
			}
			if (ok) {
				ArrayList<Integer> from2 = new ArrayList<>();
				ArrayList<Integer> to2 = new ArrayList<>();
				for (int i = 0; i < from.size(); i++) {
					int f = from.get(i);
					int t = to.get(i);
					int curF = f;
					for (int x = f; x < t; x++) {
						if (a[x][col] < a[x + 1][col] ){
							from2.add(curF);
							to2.add(x);
							curF = x + 1;
						}
					}
					from2.add(curF);
					to2.add(t);
				}
				from = from2;
				to = to2;
			} else {
				ans++;
			}
		}
		out.println(ans);
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
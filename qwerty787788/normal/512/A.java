import java.io.*;
import java.util.*;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;

	final String impossible = "Impossible";
	ArrayList<Integer> order = new ArrayList<>();
	boolean[] was;

	void go(int v) {
		was[v] = true;
		for (int to : g[v]) {
			if (!was[to]) {
				go(to);
			}
		}
		order.add(v);
	}

	void solve() {
		int n = in.nextInt();
		char[][] a = new char[n][];
		was = new boolean[26];
		g = new ArrayList[26];
		for (int i = 0; i < 26; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			a[i] = in.next().toCharArray();
		}
		for (int i = 0; i + 1 < n; i++) {
			int j = 0;
			while (j < a[i].length && j < a[i + 1].length
					&& a[i][j] == a[i + 1][j]) {
				j++;
			}
			if (j == a[i].length) {

			} else {
				if (j == a[i + 1].length) {
					out.println(impossible);
					return;
				} else {
					g[a[i][j] - 'a'].add(a[i + 1][j] - 'a');
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			if (!was[i]) {
				go(i);
			}
		}
		Collections.reverse(order);
		int[] pos = new int[26];
		for (int i = 0; i < order.size(); i++) {
			pos[order.get(i)] = i;
		}
		for (int i = 0; i < 26; i++)
			for (int to : g[i]) {
				if (pos[to] < pos[i]) {
					out.println(impossible);
					return;
				}
			}
		for (int x : order) {
			out.print((char) ('a' + x));
		}
		out.println();
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
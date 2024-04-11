import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	int[] ifMaximizerSet, ifMinimizerSet;
	int[] sz;

	void go(int v, boolean maximizerMove) {
		if (g[v].size() == 0) {
			ifMaximizerSet[v] = ifMinimizerSet[v] = 1;
			sz[v] = 1;
		} else {
			for (int to : g[v]) {
				go(to, !maximizerMove);
				sz[v] += sz[to];
			}
			if (maximizerMove) {
				int smallest = Integer.MAX_VALUE;
				for (int to : g[v]) {
					smallest = Math.min(smallest, sz[to] - ifMaximizerSet[to]);
				}
				ifMaximizerSet[v] = sz[v] - smallest;
				int sum = 0;
				for (int to : g[v]) {
					sum += sz[to] - ifMinimizerSet[to];
				}
				ifMinimizerSet[v] = sz[v] - sum;
			} else {
				int sum = 0;
				for (int to : g[v]) {
					sum += ifMaximizerSet[to] - 1;
				}
				ifMaximizerSet[v] = sum + 1;
				int minMove = Integer.MAX_VALUE;
				for (int to : g[v]) {
					minMove = Math.min(minMove, ifMinimizerSet[to]);
				}
				ifMinimizerSet[v] = minMove;
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			g[in.nextInt() - 1].add(in.nextInt() - 1);
		}
		ifMaximizerSet = new int[n];
		ifMinimizerSet = new int[n];
		sz = new int[n];
		go(0, true);
		out.println(ifMaximizerSet[0] + " " + ifMinimizerSet[0]);
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
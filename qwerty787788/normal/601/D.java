import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	char[] a;

	HashSet<Long> unite(HashSet<Long> a, HashSet<Long> b) {
		if (a.size() > b.size()) {
			for (long x : b) {
				a.add(x);
			}
			return a;
		} else {
			for (long x : a) {
				b.add(x);
			}
			return b;
		}
	}

	int[] c;

	final long mod = BigInteger.valueOf((long) (5 * 1e15)).nextProbablePrime().longValue();
	
	HashSet<Long> go(int v, int p, long curH) {
		HashSet<Long> res = new HashSet<>();
		curH += a[v];
		if (curH >= mod) {
			curH -= mod;
		}
		res.add(curH);
		for (int to : g[v]) {
			if (to != p) {
				HashSet<Long> child = go(to, v, (curH * 239) % mod);
				res = unite(res, child);
			}
		}
		c[v] += res.size();
		return res;
	}

	void solve() {
		int n = in.nextInt();
		c = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = in.nextInt();
		}
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		a = in.next().toCharArray();
		for (int i = 0; i + 1 < n; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		go(0, -1, 0);
		int max = 0;
		for (int x : c) {
			max = Math.max(max, x);
		}
		int cnt = 0;
		for (int x : c) {
			if (max == x) {
				cnt++;
			}
		}
		out.println(max + " " + cnt);
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

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
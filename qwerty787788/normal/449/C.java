import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF22 {
	FastScanner in;
	PrintWriter out;

	int gcd(int x, int y) {
		return x == 0 ? y : gcd(y % x, x);
	}

	int cnt(int x) {
		ArrayList<Integer> a = new ArrayList<>();
		ArrayList<Integer> b = new ArrayList<>();
		ArrayList<Integer> tmp = new ArrayList<>();
		int[] divs = new int[x + 1];
		for (int i = 2; i <= x; i++)
			if (divs[i] == 0)
				for (int j = i + i; j <= x; j += i) {
					divs[j]++;
				}
		boolean[] used = new boolean[x + 1];
		int res = 0;
		for (int gcd = x; gcd > 1; gcd--) {
			if (divs[gcd] != 0)
				continue;
			tmp.clear();
			int maxDiv = -1, last = -1;
			for (int mul = 1; mul * 1L * gcd <= x; mul++) {
				if (!used[mul * gcd]) {
					tmp.add(mul * gcd);
					if (divs[mul * gcd] > maxDiv) {
						maxDiv = divs[mul * gcd];
						last = mul * gcd;
					}
				}
			}
			if (tmp.size() % 2 != 0) {
				for (int i = 0; i < tmp.size(); i++)
					if (tmp.get(i) == last) {
						tmp.remove(i);
					}
			}
			for (int i = 0; i < tmp.size(); i += 2) {
				res++;
				a.add(tmp.get(i));
				b.add(tmp.get(i + 1));
			}
			for (int xx : tmp)
				used[xx] = true;
		}
		out.println(a.size());
		for (int i = 0; i < a.size(); i++) {
			out.println(a.get(i) + " " + b.get(i));
		}
		return res;
	}
	
	void solve() {
		cnt(in.nextInt());
	}

	void solve2() {
		int n = in.nextInt();
		boolean[][] can = new boolean[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (gcd(i + 1, j + 1) != 1)
					can[i][j] = true;
		int[] ans = new int[1 << n];
		for (int st = 0; st < 1 << n; st++) {
			for (int i = 0; i < n; i++)
				if (((1 << i) & st) == 0)
					for (int j = i + 1; j < n; j++)
						if (((1 << j) & st) == 0) {
							if (!can[i][j])
								continue;
							int nst = st ^ (1 << i) ^ (1 << j);
							ans[nst] = Math.max(ans[nst], ans[st] + 1);
						}
		}
		for (int i = 1; i <= n; i++)
			System.err.println(i + ": " + ans[(1 << i) - 1] + " " + cnt(i));
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
		new CF22().runIO();
	}
}
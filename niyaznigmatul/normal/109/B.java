import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	static List<Integer> allLucky = new ArrayList<Integer>();
	static {
		allLucky.add(4);
		allLucky.add(7);
		for (int i = 0; i < allLucky.size(); i++) {
			int j = allLucky.get(i);
			{
				long e = j * 10L + 4;
				if (e < Integer.MAX_VALUE) {
					allLucky.add((int) e);
				}
			}

			{
				long e = j * 10L + 7;
				if (e < Integer.MAX_VALUE) {
					allLucky.add((int) e);
				}
			}
		}
	}

	void solve() {
		int p1 = nextInt();
		int p2 = nextInt();
		int v1 = nextInt();
		int v2 = nextInt();
		int k = nextInt();
		out.println(solve(p1, p2, v1, v2, k));
	}

	static double solve(int p1, int p2, int v1, int v2, int k) {
		double ans = 0;
		for (int i = 0; i + k <= allLucky.size(); i++) {
			int preFirst = i == 0 ? 0 : allLucky.get(i - 1) + 1;
			int first = allLucky.get(i);
			int last = allLucky.get(i + k - 1);
			int aftLast = i + k == allLucky.size() ? Integer.MAX_VALUE
					: allLucky.get(i + k) - 1;
			ans += inters(p1, p2, preFirst, first) / (p2 - p1 + 1)
					* inters(v1, v2, last, aftLast) / (v2 - v1 + 1)
					+ inters(v1, v2, preFirst, first) / (v2 - v1 + 1)
					* inters(p1, p2, last, aftLast) / (p2 - p1 + 1);
			if (first == last) {
				ans -= inters(first, first, p1, p2) / (p2 - p1 + 1)
						* inters(first, first, v1, v2) / (v2 - v1 + 1);
			}
		}
		return ans;
	}

	static double inters(int a, int b, int c, int d) {
		a = Math.max(a, c);
		b = Math.min(b, d);
		return Math.max(b - a + 1, 0);
	}

	static double stupid(int a, int b, int c, int d, int k) {
		double all = 0;
		for (int i = a; i <= b; i++) {
			for (int j = c; j <= d; j++) {
				int count = 0;
				for (int e : allLucky) {
					if (e >= Math.min(i, j) && e <= Math.max(i, j)) {
						count++;
					}
				}
				if (count == k) {
					all++;
				}
			}
		}
		return all / (b - a + 1) / (d - c + 1);
	}

	static final Random rand = new Random();

	static void test() {
		int q = 0;
		while (true) {
			if (++q == 10) {
				System.err.println("TEST");
				q = 0;
			}
			int a = rand.nextInt(500000000);
			int b = a + rand.nextInt(100);
			int c = rand.nextInt(500000000);
			int d = c + rand.nextInt(100);
			int k = rand.nextInt(1000) + 1;
			double ans1 = stupid(a, b, c, d, k);
			double ans2 = solve(a, b, c, d, k);
			if (Math.abs(ans1 - ans2) > 1e-8) {
				System.err.println(a + " " + b + " " + c + " " + d + " " + k);
				System.err.println(ans1);
				System.err.println(ans2);
				throw new AssertionError();
			}
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}
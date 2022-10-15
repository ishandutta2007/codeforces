import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		if ((n & 1) == 0) {
			out.println("Marsel");
			return;
		}
		n = m;
		ArrayList<Integer> divs = new ArrayList<Integer>();
		for (long i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				divs.add((int) i);
				if (i != n / i) {
					divs.add(n / (int) i);
				}
			}
		}
		int[] d = new int[divs.size()];
		for (int i = 0; i < d.length; i++) {
			d[i] = divs.get(i);
		}
		Arrays.sort(d);
		HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
		for (int i = 0; i < d.length; i++) {
			hm.put(d[i], i);
		}
		int[] g = new int[d.length];
		for (int i = 1; i < d.length; i++) {
			HashSet<Integer> hs = new HashSet<Integer>();
			for (int j = 0; j < i; j++) {
				if (d[j] < k) {
					continue;
				}
				if (d[i] % d[j] == 0) {
					if ((d[i] / d[j]) % 2 == 0) {
						hs.add(0);
					} else {
						hs.add(g[j]);
					}
				}
			}
			for (int j = 0;; j++) {
				if (!hs.contains(j)) {
					g[i] = j;
					break;
				}
			}
		}
		if (g[d.length - 1] == 0) {
			out.println("Marsel");
		} else {
			out.println("Timur");
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
		new C().run();
	}
}
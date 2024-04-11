import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	void solve() {
		HashMap<Integer, HashSet<Integer>> hm = new HashMap<Integer, HashSet<Integer>>();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
		}
		int[] b = new int[n];
		for (int i = 0; i < b.length; i++) {
			b[i] = nextInt();
		}
		ArrayList<Pair> ans = new ArrayList<Pair>();
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				continue;
			}
			for (int j = i + 1; j < n; j++) {
				if (b[j] == a[i]) {
					for (int k = j; k > i; k--) {
						ans.add(new Pair(k, k + 1));
						int t = b[k - 1];
						b[k - 1] = b[k];
						b[k] = t;
					}
					break;
				}
			}
		}
		out.println(ans.size());
		for (Pair p : ans) {
			out.println(p.a + " " + p.b);
		}
	}

	class Pair {
		int a;
		int b;

		public Pair(int a, int b) {
			super();
			this.a = a;
			this.b = b;
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
		new D().run();
	}
}
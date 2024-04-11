import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	static class Walrus implements Comparable<Walrus> {
		int x;
		int num;

		public Walrus(int x, int num) {
			super();
			this.x = x;
			this.num = num;
		}

		@Override
		public int compareTo(Walrus o) {
			if (x != o.x) {
				return o.x - x;
			}
			return o.num - num;
		}

	}

	void solve() {
		int n = nextInt();
		Walrus[] w = new Walrus[n];
		for (int i = 0; i < n; i++) {
			w[i] = new Walrus(nextInt(), i);
		}
		Arrays.sort(w);
		TreeSet<Integer> set = new TreeSet<Integer>();
		for (int i = 0; i < n; i++) {
			set.add(i);
		}
		int[] ans = new int[n];
		for (Walrus e : w) {
			Integer i = set.last();
			ans[e.num] = i.intValue();
			set.remove(e.num);
		}
		for (int i = 0; i < n; i++) {
			ans[i] = ans[i] - i - 1;
		}
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
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
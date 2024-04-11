import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {

	static class Bag {
		SortedSet<Integer> single;
		Map<Integer, Integer> multi;

		public Bag() {
			single = new TreeSet<Integer>();
			multi = new HashMap<Integer, Integer>();
		}

		void add(int x) {
			if (multi.containsKey(x)) {
				int e = multi.get(x);
				multi.put(x, e + 1);
				return;
			}
			if (single.contains(x)) {
				single.remove(x);
				multi.put(x, 2);
				return;
			}
			single.add(x);
		}

		boolean remove(int x) {
			if (single.contains(x)) {
				single.remove(x);
				return true;
			}
			if (multi.containsKey(x)) {
				int e = multi.get(x);
				if (e == 2) {
					single.add(x);
					multi.remove(x);
				} else {
					multi.put(x, e - 1);
				}
				return true;
			}
			return false;
		}

		int getMax() {
			if (single.isEmpty()) {
				return Integer.MIN_VALUE;
			}
			return single.last();
		}
	}

	static String getAnswer(Bag b) {
		int got = b.getMax();
		return got == Integer.MIN_VALUE ? "Nothing" : "" + got;
	}

	void solve() {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		Bag b = new Bag();
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < k; i++) {
			b.add(a[i]);
		}
		out.println(getAnswer(b));
		for (int i = k; i < n; i++) {
			b.remove(a[i - k]);
			b.add(a[i]);
			out.println(getAnswer(b));
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
		new E().run();
	}
}
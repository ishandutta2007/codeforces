import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	void solve() {
		int h = nextInt();
		int w = nextInt();
		int a = 0;
		int b = 0;
		long area = Long.MIN_VALUE;
		for (int i = 0; 1L << i <= h; i++) {
			int y = (int) Math.ceil((1 << i) * .8);
			int z = (int) Math.floor((1 << i) * 1.25);
			if (z <= w) {
				long newArea = (long) z * (1 << i);
				if (area < newArea || (area == newArea && (1 << i) > a)) {
					area = newArea;
					a = 1 << i;
					b = z;
				}
			} else if (y <= w) {
				long newArea = (long) w * (1 << i);
				if (area < newArea || (area == newArea && (1 << i) > a)) {
					area = (long) w * (1 << i);
					a = 1 << i;
					b = w;
				}
			}
		}
		for (int i = 0; 1L << i <= w; i++) {
			int y = (int) Math.ceil((1 << i) * .8);
			int z = (int) Math.floor((1 << i) * 1.25);
			if (z <= h) {
				long newArea = (long) (1 << i) * z;
				if (area < newArea || (area == newArea && z > a)) {
					area = (long) z * (1 << i);
					a = z;
					b = 1 << i;
				}
			} else if (y <= h) {
				long newArea = (long) (1 << i) * h;
				if (area < newArea || (area == newArea && h > a)) {
					area = (long) h * (1 << i);
					a = h;
					b = 1 << i;
				}
			}
		}
		out.println(a + " " + b);
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
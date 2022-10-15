import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	void solve() {
		String s = nextToken();
		int n = nextInt();
		int[] left = new int[s.length()];
		Arrays.fill(left, s.length());
		for (int stringIndex = 0; stringIndex < n; stringIndex++) {
			String str = nextToken();
			int[] p = new int[str.length()];
			int k = -1;
			p[0] = -1;
			for (int i = 1; i < p.length; i++) {
				while (k > -1 && str.charAt(k + 1) != str.charAt(i)) {
					k = p[k];
				}
				if (str.charAt(k + 1) == str.charAt(i)) {
					k++;
				}
				p[i] = k;
			}
			k = -1;
			for (int i = 0; i < s.length(); i++) {
				while (k > -1
						&& (k + 1 >= str.length() || str.charAt(k + 1) != s
								.charAt(i))) {
					k = p[k];
				}
				if (k + 1 < str.length() && str.charAt(k + 1) == s.charAt(i)) {
					k++;
				}
				if (k == str.length() - 1) {
					left[i - k] = Math.min(left[i - k], i);
				}
			}
		}
		for (int i = s.length() - 2; i >= 0; i--) {
			left[i] = Math.min(left[i], left[i + 1]);
		}
		int len = 0;
		int pos = -1;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (left[i] - i >= len) {
				len = left[i] - i;
				pos = i;
			}
		}
		out.println(len + " " + (pos));
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
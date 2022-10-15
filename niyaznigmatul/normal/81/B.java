import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	void solve() {
		String s = sc.nextLine();
		boolean hadSpace = false;
		boolean hadDot = false;
		boolean hadNumber = false;
		boolean hadBadSpace = false;
		StringBuilder sb = new StringBuilder();
		int dots = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != '.') {
				dots = 0;
			}
			if (Character.isDigit(s.charAt(i))) {
				if (hadBadSpace) {
					sb.append(' ');
					hadBadSpace = false;
				}
				sb.append(s.charAt(i));
				hadDot = hadSpace = false;
				hadNumber = true;
			} else if (s.charAt(i) == '.') {
				if (!hadDot) {
					hadDot = true;					
				}
				if (dots == 0 && !hadSpace) {
					sb.append(' ');
				}
				sb.append('.');
				hadSpace = false;
				hadNumber = false;
				hadBadSpace = false;
				dots = (dots + 1) % 3;
			} else if (s.charAt(i) == ',') {
				sb.append(',');
				sb.append(' ');
				hadSpace = true;
				hadDot = false;
				hadNumber = false;
				hadBadSpace = false;
			} else if (s.charAt(i) == ' ') {
				if (hadNumber) {
					hadBadSpace = true;
				}
				hadDot = false;
			}
		}
		String ans = sb.toString();
		out.println(ans.trim());
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
import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	final int[] ROME = { 1000, 500, 100, 50, 10, 5, 1 };
	final char[] ROMECHAR = "MDCLXVI".toCharArray();

	void solve() {
		String s1 = nextToken();
		String s2 = nextToken();
		if (s2.equals("R")) {
			int n = Integer.parseInt(nextToken(), Integer.parseInt(s1));
			StringBuilder ans = new StringBuilder();
			String num = (n + "");
			while (num.length() < 4) {
				num = "0" + num;
			}
			int cur = -1;
			for (int i = 0; i < num.length(); i++, cur += 2) {
				if (num.charAt(i) == '0') {
					continue;
				}
				if (num.charAt(i) == '9') {
					ans.append(ROMECHAR[cur + 1]).append(ROMECHAR[cur - 1]);
					continue;
				}
				if (num.charAt(i) == '4') {
					ans.append(ROMECHAR[cur + 1]).append(ROMECHAR[cur]);
					continue;
				}
				int x = num.charAt(i) - '0';
				if (x >= 5) {
					ans.append(ROMECHAR[cur]);
					x -= 5;
				}
				while (x > 0) {
					ans.append(ROMECHAR[cur + 1]);
					--x;
				}
			}
			out.println(ans);
			return;
		}
		out.println(new BigInteger(nextToken(), Integer.parseInt(s1)).toString(
				Integer.parseInt(s2)).toUpperCase());
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
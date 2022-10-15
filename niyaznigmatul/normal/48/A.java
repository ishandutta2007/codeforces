import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

	String[] A = { "paper", "scissors", "rock" };
	String[] B = { "rock", "paper", "scissors" };

	void solve() {
		String[] s = new String[3];
		for (int i = 0; i < s.length; i++) {
			s[i] = nextToken();
		}
		if (s[0].equals(s[1])
				&& s[0].equals(s[2])
				|| (!s[0].equals(s[1]) && !s[0].equals(s[2]) && !s[1]
						.equals(s[2]))) {
			out.println("?");
			return;
		}
		int win;
		int lose;
		String strWin;
		if (s[0].equals(s[1])) {
			win = 2;
			lose = 0;
			strWin = "S";
		} else if (s[0].equals(s[2])) {
			win = 1;
			lose = 0;
			strWin = "M";
		} else {
			win = 0;
			lose = 1;
			strWin = "F";
		}
		for (int i = 0; i < A.length; i++) {
			if (s[win].equals(A[i])) {
				out.println(s[lose].equals(B[i]) ? strWin : "?");
				return;
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
		new A().run();
	}
}
import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

	void solve() {
		int n = nextInt();
		String[] str = new String[n];
		for (int i = 0; i < n; i++) {
			str[i] = nextToken();
		}
		String s = nextToken();
		String sLower = s.toLowerCase();
		boolean[] mark = new boolean[s.length()];
		for (String e : str) {
			e = e.toLowerCase();
			int p = sLower.indexOf(e);
			while (p >= 0) {
				for (int j = p; j < p + e.length(); j++) {
					mark[j] = true;
				}
				p = sLower.indexOf(e, p + 1);
			}
		}
		char letter = nextToken().charAt(0);
		char[] answer = s.toCharArray();
		for (int i = 0; i < s.length(); i++) {
			if (mark[i]) {
				if (answer[i] == letter) {
					if (letter == 'a') {
						answer[i] = 'b';
					} else {
						answer[i] = 'a';
					}
				} else if (Character.isUpperCase(answer[i])
						&& Character.toLowerCase(answer[i]) == letter) {
					if (letter == 'a') {
						answer[i] = 'B';
					} else {
						answer[i] = 'A';
					}
				} else if (Character.isLowerCase(answer[i])) {
					answer[i] = letter;
				} else {
					answer[i] = (char) (letter - 'a' + 'A');
				}
			}
		}
		out.println(new String(answer));
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
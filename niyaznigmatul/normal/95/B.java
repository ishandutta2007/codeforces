import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	void stress() {
		int q = 0;
		Random rand = new Random();
		while (true) {
			if (++q == 100) {
				System.err.println("#");
				q = 0;
			}
			String n = rand.nextInt(100000) + "";
			if (!solve(n).equals(solveSlow(n))) {
				System.err.println(n);
				System.err.println(solve(n));
				System.err.println(solveSlow(n));
				throw new AssertionError();
			}
		}
	}

	void solve() {		
		String s = nextToken();
		out.println(solve(s));
	}

	static boolean isGood(int d) {
		int c4 = 0;
		int c7 = 0;
		while (d > 0) {
			if (d % 10 == 4) {
				c4++;
			} else if (d % 10 == 7) {
				c7++;
			} else {
				return false;
			}
			d /= 10;
		}
		return c4 == c7;
	}

	static String solveSlow(String s) {
		int d = Integer.parseInt(s);
		while (!isGood(d)) {
			d++;
		}
		return d + "";
	}

	static String solve(String s) {
		StringBuilder sb = new StringBuilder();
		int change = -1;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != '4' && s.charAt(i) != '7') {
				change = i;
				break;
			}
		}
		if (change == -1) {
			sb = new StringBuilder(s);
		} else {
			if (s.charAt(change) < '7') {
				for (int i = 0; i < change; i++) {
					sb.append(s.charAt(i));
				}
				sb.append(s.charAt(change) < '4' ? '4' : '7');
				for (int i = change + 1; i < s.length(); i++) {
					sb.append('4');
				}
			} else {
				sb = new StringBuilder(s);
				for (int i = change + 1; i < s.length(); i++) {
					sb.setCharAt(i, '4');
				}
				while (change >= 0 && sb.charAt(change) >= '7') {
					sb.setCharAt(change, '4');
					change--;
				}
				if (change < 0) {
					sb.setLength(0);
					for (int i = 0; i <= s.length(); i++) {
						sb.append('4');
					}
				} else {
					sb.setCharAt(change, '7');
				}
			}
		}
		if (sb.length() % 2 == 1) {
			int len = sb.length() + 1;
			sb.setLength(0);
			for (int i = 0; i < len / 2; i++) {
				sb.append(4);
			}
			for (int i = 0; i < len / 2; i++) {
				sb.append(7);
			}
			return sb.toString();
		} else {
			int c4 = 0;
			int c7 = 0;
			for (int i = 0; i < sb.length(); i++) {
				if (sb.charAt(i) == '4') {
					c4++;
				} else {
					c7++;
				}
			}
			if (c4 == c7) {
				return sb.toString();
			} else if (c4 > c7) {
				for (int i = sb.length() - 1; c4 > c7 && i >= 0; i--) {
					if (sb.charAt(i) == '4') {
						sb.setCharAt(i, '7');
						c4--;
						c7++;
					}
				}
				return sb.toString();
			} else {
				int len = sb.length() / 2;
				boolean ok = true;
				for (int j = 0; j <= len; j++) {
					if (sb.charAt(j) != '7') {
						ok = false;
					}
				}
				if (ok) {
					len = sb.length() + 2;
					sb.setLength(0);
					for (int i = 0; i < len / 2; i++) {
						sb.append(4);
					}
					for (int i = 0; i < len / 2; i++) {
						sb.append(7);
					}
					return sb.toString();
				}
				int left = 0;
				for (int i = sb.length() - 1; i >= 0; i--) {
					if (sb.charAt(i) == '4') {
						if (Math.abs(c4 - 1 - c7 - 1) <= left) {
							sb.setCharAt(i, '7');
							c4--;
							c4 = sb.length() / 2 - c4;
							int j = i + 1;
							for (; c4 > 0; c4--, j++) {
								sb.setCharAt(j, '4');
							}
							while (j < sb.length()) {
								sb.setCharAt(j, '7');
								j++;
							}
							return sb.toString();
						}
					}
					if (sb.charAt(i) == '4') {
						c4--;
					} else {
						c7--;
					}
					left++;
				}
				len = sb.length() + 2;
				sb.setLength(0);
				for (int i = 0; i < len / 2; i++) {
					sb.append(4);
				}
				for (int i = 0; i < len / 2; i++) {
					sb.append(7);
				}
				return sb.toString();
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
		new B().run();
	}
}
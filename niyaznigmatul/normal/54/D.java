import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	void solve() {
		int n = nextInt();
		int k = nextInt();
		String s = nextToken();
		String t = nextToken();
		System.err.println(s.length());
		System.err.println(t.length());
		char[] ans = new char[n];
		Arrays.fill(ans, '?');
		for (int i = 0; i < t.length(); i++) {
			if (t.charAt(i) == '0') {
				continue;
			}
			for (int j = 0; j < s.length(); j++) {
				char ch = s.charAt(j);
				if (ans[i + j] != '?' && ans[i + j] != ch) {
					out.println("No solution");
					return;
				}
				ans[i + j] = ch;
			}
		}
		long time = System.currentTimeMillis();
		loop: while (true) {
			if (System.currentTimeMillis() - time > 1700) {
				System.err.println("time is up");
				out.println("No solution");
				return;
			}
			char[] d = ans.clone();
			for (int i = 0; i < d.length; i++) {
				if (d[i] == '?') {
					boolean found = false;
					for (int j = 0; j < 7; j++) {
						int x = rand.nextInt(k);
						d[i] = (char) (x + 'a');
						boolean ok = true;
						for (int r = Math.max(0, i - s.length() + 1); r <= i
								&& r + s.length() <= n; r++) {
							if (new String(d, r, s.length()).equals(s)) {
								ok = false;
								break;
							}
						}
						if (ok) {
							found = true;
							break;
						}
					}
					if (!found) {
						continue loop;
					}
				}
			}
			String e = new String(d);
			for (int i = 0; i < t.length(); i++) {
				boolean has = t.charAt(i) == '1';
				if (e.substring(i, i + s.length()).equals(s) != has) {
					continue loop;
				}
			}			
			out.println(e);
			return;
		}
	}

	FastScanner sc;
	PrintWriter out;
	Random rand = new Random(this.hashCode());

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
import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

	void solve() {
		String s1 = nextToken();
		String s2 = nextToken();
		int[][] next = new int[26][s1.length()];
		for (int[] d : next) {
			Arrays.fill(d, Integer.MAX_VALUE);
		}
		next[s1.charAt(s1.length() - 1) - 'a'][s1.length() - 1] = s1.length() - 1;
		for (int i = s1.length() - 2; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				next[j][i] = next[j][i + 1];
			}
			next[s1.charAt(i) - 'a'][i] = i;
		}
		int last = 0;
		int ans = 1;
		for (char c : s2.toCharArray()) {
			if (last >= s1.length()) {
				ans++;
				last = 0;
			}
			last = next[c - 'a'][last];
			if (last == Integer.MAX_VALUE) {
				ans++;
				last = next[c - 'a'][0];
				if (last == Integer.MAX_VALUE) {
					out.println(-1);
					return;
				}
			}
			last++;
		}
		out.println(ans);
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
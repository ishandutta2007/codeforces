import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

	final static String ALL = "ROYGBV";

	void solve() {
		String s = nextToken();
		int[] a = new int[6];
		for (char c : s.toCharArray()) {
			a[ALL.indexOf(c)]++;
		}
		int ans = go(0, a, new char[6]);
		out.println(ans);
	}

	static HashSet<String> hs = new HashSet<String>();
	static HashSet<String> was = new HashSet<String>();

	static int go(int x, int[] a, char[] s) {
		if (x == 6) {
			was.clear();
			String e = getMin(s);
			if (hs.contains(e)) {
				return 0;
			}
			hs.add(e);
			return 1;
		}
		int ret = 0;
		for (int i = 0; i < a.length; i++) {
			if (a[i] == 0) {
				continue;
			}
			a[i]--;
			s[x] = ALL.charAt(i);
			ret += go(x + 1, a, s);
			a[i]++;
		}
		return ret;
	}

	static String getMin(char[] c) {
		String ret = new String(c);
		if (was.contains(ret)) {
			return ret;
		}
		was.add(ret);
		{
			char[] t = c.clone();
			char tmp = t[2];
			t[2] = t[3];
			t[3] = t[4];
			t[4] = t[5];
			t[5] = tmp;
			String got = getMin(t);
			if (ret.compareTo(got) > 0) {
				ret = got;
			}
		}
		{
			char[] t = c.clone();
			char tmp = t[5];
			t[5] = t[4];
			t[4] = t[3];
			t[3] = t[2];
			t[2] = tmp;
			String got = getMin(t);
			if (ret.compareTo(got) > 0) {
				ret = got;
			}
		}
		{
			char[] t = c.clone();
			char tmp = t[0];
			t[0] = t[2];
			t[2] = t[1];
			t[1] = t[4];
			t[4] = tmp;
			String got = getMin(t);
			if (ret.compareTo(got) > 0) {
				ret = got;
			}
		}
		{
			char[] t = c.clone();
			char tmp = t[4];
			t[4] = t[1];
			t[1] = t[2];
			t[2] = t[0];
			t[0] = tmp;
			String got = getMin(t);
			if (ret.compareTo(got) > 0) {
				ret = got;
			}
		}
		{
			char[] t = c.clone();
			char tmp = t[0];
			t[0] = t[3];
			t[3] = t[1];
			t[1] = t[5];
			t[5] = tmp;
			String got = getMin(t);
			if (ret.compareTo(got) > 0) {
				ret = got;
			}
		}
		{
			char[] t = c.clone();
			char tmp = t[5];
			t[5] = t[1];
			t[1] = t[3];
			t[3] = t[0];
			t[0] = tmp;
			String got = getMin(t);
			if (ret.compareTo(got) > 0) {
				ret = got;
			}
		}
		return ret;
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
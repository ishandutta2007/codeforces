import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {

	int[] b;
	int[] c;

	static class Number {
		int num;
		int ind;

		public Number(int num, int ind) {
			super();
			this.num = num;
			this.ind = ind;
		}

	}

	void mergeSort(Number[] a, Number[] tmp, int l, int r) {
		if (l + 1 >= r) {
			return;
		}		
		int m = (l + r) >> 1;
		mergeSort(a, tmp, l, m);
		mergeSort(a, tmp, m, r);
		for (int i = l, j = m, k = 0; i < m || j < r; k++) {
			if (j == r || (i < m && a[i].num <= a[j].num)) {
				c[a[i].ind] += j - m;
				tmp[k] = a[i++];
			} else {
				b[a[j].ind] += m - i;
				tmp[k] = a[j++];
			}
		}
		System.arraycopy(tmp, 0, a, l, r - l);
	}

	void solve() {
		int n = nextInt();
		Number[] a = new Number[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Number(nextInt(), i);
		}
		b = new int[n];
		c = new int[n];
		mergeSort(a, new Number[n], 0, n);
		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (long) b[i] * c[i];
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
		new E().run();
	}
}
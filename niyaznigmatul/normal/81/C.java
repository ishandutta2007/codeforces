import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	static class Mark implements Comparable<Mark> {
		int v;
		int num;

		public Mark(int v, int num) {
			super();
			this.v = v;
			this.num = num;
		}

		@Override
		public int compareTo(Mark o) {
			return v - o.v;
		}
	}

	void solve() {
		int n = nextInt();
		int a = nextInt();
		int b = nextInt();
		Mark[] marks = new Mark[n];
		for (int i = 0; i < n; i++) {
			marks[i] = new Mark(nextInt(), i);
		}
		Arrays.sort(marks);
		int[] ans = new int[n];
		if (a < b) {
			Arrays.sort(marks, new Comparator<Mark>() {
				@Override
				public int compare(Mark o1, Mark o2) {
					if (o1.v != o2.v) {
						return o1.v - o2.v;
					}
					return o2.num - o1.num;
				}
			});
			for (int i = 0; i < b; i++) {
				ans[marks[i].num] = 2;
			}
			for (int i = b; i < n; i++) {
				ans[marks[i].num] = 1;
			}
		} else if (a > b) {
			for (int i = 0; i < a; i++) {
				ans[marks[i].num] = 1;
			}
			for (int i = a; i < n; i++) {
				ans[marks[i].num] = 2;
			}
		} else {
			for (int i = 0; i < a; i++) {
				ans[i] = 1;
			}
			for (int i = a; i < n; i++) {
				ans[i] = 2;
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
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
		new C().run();
	}
}
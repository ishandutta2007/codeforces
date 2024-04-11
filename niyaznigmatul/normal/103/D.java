import static java.util.Arrays.*;

import java.io.*;
import java.util.Arrays;

public class D {
	static int BLOCK = 400;

	static class Query implements Comparable<Query> {
		int a;
		int b;
		long answer;

		public Query(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Query o) {
			if (b != o.b) {
				return b - o.b;
			}
			return a - o.a;
		}

	}

	// void maxTest() {
	// Random rand = new Random();
	// out.println(300000);
	// for (int i = 0; i < 300000; i++) {
	// out.println(rand.nextInt(1000000000) + 1);
	// }
	// out.println(300000);
	// for (int i = 0; i < 300000; i++) {
	// out.print(rand.nextInt(300000) + 1 + " ");
	// if (rand.nextBoolean()) {
	// out.print(rand.nextInt(BLOCK) + 1);
	// } else {
	// out.print(rand.nextInt(300000 - BLOCK) + BLOCK);
	// }
	// out.println();
	// }
	// }

	void solve() {
		long time = System.currentTimeMillis();
		int n = nextInt();
		int[] w = new int[n];
		for (int i = 0; i < n; i++) {
			w[i] = nextInt();
		}
		int m = nextInt();
		Query[] q = new Query[m];
		for (int i = 0; i < m; i++) {
			q[i] = new Query(nextInt() - 1, nextInt());
		}
		System.err.println(System.currentTimeMillis() - time);
		Query[] sq = q.clone();
		Arrays.sort(sq);
		Query last = null;
		long[] sum = new long[n];
		for (int i = 0; i < m;) {
			Query e = sq[i];
			if (last != null && last.compareTo(e) == 0) {
				e.answer = last.answer;
				i++;
				continue;
			}
			if (e.b >= BLOCK) {
				e.answer = stupid(e.a, e.b, w, n);
				last = e;
				i++;
			} else {
				int j = i;
				while (j < m && sq[j].b == e.b) {
					j++;
				}
				int dif = j - i;
				if (dif < e.b) {
					for (int k = i; k < j; k++) {
						Query d = sq[k];
						d.answer = stupid(d.a, d.b, w, n);
					}
				} else {
					for (int cur = n - 1; cur >= 0; cur--) {
						sum[cur] = w[cur];
						if (cur + e.b < n) {
							sum[cur] += sum[cur + e.b];
						}
					}
					for (int k = i; k < j; k++) {
						Query d = sq[k];
						d.answer = sum[d.a];
					}
				}
				i = j;
			}
		}
		for (Query e : q) {
			out.println(e.answer);
		}
		System.err.println(System.currentTimeMillis() - time);
	}

	static long stupid(int a, int b, int[] w, int n) {
		long ans = 0;
		for (int j = a; j < n; j += b) {
			ans += w[j];
		}
		return ans;
	}

	static InputReader sc;
	static PrintWriter out;

	static void debug(Object... a) {
		System.err.println(deepToString(a));
	}

	public void run() {
		try {
			File inputFile = new File("input.txt");
			if (inputFile.canRead()) {
				System.setIn(new FileInputStream(inputFile));
				System.setOut(new PrintStream("output.txt"));
			}
			sc = new StreamInputReader(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	static double nextDouble() {
		String s = sc.next();
		if (s == null) {
			return Double.NaN;
		}
		return Double.parseDouble(s);
	}

	static long nextLong() {
		return sc.nextLong();
	}

	static int nextInt() {
		return sc.nextInt();
	}

	static abstract class InputReader {
		private boolean finished = false;

		public abstract int read();

		public long nextLong() {
			int c = read();
			while (c <= 32 && c >= 0) {
				c = read();
			}
			if (c == -1) {
				finished = true;
				return Long.MIN_VALUE;
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			if (c < '0' || c > '9') {
				throw new NumberFormatException("digit expected " + (char) c
						+ " found");
			}
			long ret = 0;
			while (c >= '0' && c <= '9') {
				ret = ret * 10 + c - '0';
				c = read();
			}
			if (c > 32) {
				throw new NumberFormatException("space character expected "
						+ (char) c + " found");
			}
			return ret * sgn;
		}

		public int nextInt() {
			int c = read();
			while (c <= 32 && c >= 0) {
				c = read();
			}
			if (c == -1) {
				finished = true;
				return Integer.MIN_VALUE;
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			if (c < '0' || c > '9') {
				throw new NumberFormatException("digit expected " + (char) c
						+ " found");
			}
			int ret = 0;
			while (c >= '0' && c <= '9') {
				ret = ret * 10 + c - '0';
				c = read();
			}
			if (c > 32) {
				throw new NumberFormatException("space character expected "
						+ (char) c + " found");
			}
			return ret * sgn;
		}

		public String next() {
			int c = read();
			while (c <= 32 && c >= 0) {
				c = read();
			}
			if (c == -1) {
				finished = true;
				return null;
			}
			StringBuilder res = new StringBuilder();
			while (c > 32) {
				res.appendCodePoint(c);
				c = read();
			}
			return res.toString();
		}

		public boolean isFinished() {
			return finished;
		}

		public void setFinished(boolean finished) {
			this.finished = finished;
		}

		public abstract void close();
	}

	static class StreamInputReader extends InputReader {
		private InputStream stream;
		private byte[] buf;
		private int current, numOfChars;

		public StreamInputReader(InputStream stream) {
			this(stream, 1024);
		}

		public StreamInputReader(InputStream stream, int bufSize) {
			this.stream = stream;
			buf = new byte[bufSize];
		}

		public int read() {
			if (numOfChars < 0) {
				return -1;
			}
			if (current >= numOfChars) {
				current = 0;
				try {
					numOfChars = stream.read(buf);
				} catch (IOException e) {
					return -1;
				}
				if (numOfChars <= 0) {
					return -1;
				}
			}
			return buf[current++];
		}

		@Override
		public void close() {
			try {
				stream.close();
			} catch (IOException ignored) {

			}
		}
	}

	public static void main(String[] args) {
		new D().run();
	}
}
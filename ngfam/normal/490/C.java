import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		CHackingCypher solver = new CHackingCypher();
		solver.solve(1, in, out);
		out.close();
	}

	static class CHackingCypher {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			String s = in.nextString();
			int a = in.nextInt();
			int b = in.nextInt();


			int n = s.length();

			int[] d = new int[n];
			for (int i = 0; i < n; ++i) {
				d[i] = (int) s.charAt(i) - 48;
			}

			int[] fb = new int[n];
			fb[n - 1] = d[n - 1] % b;

			int pw10 = 1;
			for (int i = n - 2; i >= 0; --i) {
				pw10 = pw10 * 10 % b;
				fb[i] = (fb[i + 1] + pw10 * d[i]) % b;
			}


			int cur = 0;
			for (int i = 0; i + 1 < n; ++i) {
				cur = (cur * 10) + d[i];
				cur %= a;
				if (s.charAt(i + 1) == '0') continue;

				if (cur == 0 && fb[i + 1] == 0) {
					out.println("YES");
					out.println(s.substring(0, i + 1));
					out.println(s.substring(i + 1, n));

					return;
				}
			}
			out.println("NO");
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private InputReader.SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (this.numChars == -1) {
				throw new InputMismatchException();
			} else {
				if (this.curChar >= this.numChars) {
					this.curChar = 0;

					try {
						this.numChars = this.stream.read(this.buf);
					} catch (IOException var2) {
						throw new InputMismatchException();
					}

					if (this.numChars <= 0) {
						return -1;
					}
				}

				return this.buf[this.curChar++];
			}
		}

		public int nextInt() {
			int c;
			for (c = this.read(); this.isSpaceChar(c); c = this.read()) {
			}

			int sgn = 1;
			if (c == 45) {
				sgn = -1;
				c = this.read();
			}

			int res = 0;

			while (c >= 48 && c <= 57) {
				res *= 10;
				res += c - 48;
				c = this.read();
				if (this.isSpaceChar(c)) {
					return res * sgn;
				}
			}

			throw new InputMismatchException();
		}

		public String nextString() {
			int c;
			for (c = this.read(); this.isSpaceChar(c); c = this.read()) {
			}

			StringBuilder res = new StringBuilder();

			do {
				if (Character.isValidCodePoint(c)) {
					res.appendCodePoint(c);
				}

				c = this.read();
			} while (!this.isSpaceChar(c));

			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			return this.filter != null ? this.filter.isSpaceChar(c) : isWhitespace(c);
		}

		public static boolean isWhitespace(int c) {
			return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
		}

		public interface SpaceCharFilter {
			boolean isSpaceChar(int var1);

		}

	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			this.writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; ++i) {
				if (i != 0) {
					this.writer.print(' ');
				}

				this.writer.print(objects[i]);
			}

		}

		public void println(Object... objects) {
			this.print(objects);
			this.writer.println();
		}

		public void close() {
			this.writer.close();
		}

	}
}
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Stack;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
		CCheckposts solver = new CCheckposts();
		solver.solve(1, in, out);
		out.close();
	}

	static class CCheckposts {
		int cnt;
		int ans = 1;
		long all = 0;
		Stack<Vertex> stack;
		static int mod = 1000000007;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.nextInt();

			Vertex[] vertices = new Vertex[n];
			stack = new Stack<>();

			for (int i = 0; i < n; ++i) {
				vertices[i] = new Vertex();
				vertices[i].adj = new ArrayList<>();
				vertices[i].cost = in.nextInt();
			}

			int m = in.nextInt();
			for (int i = 0; i < m; ++i) {
				int u = in.nextInt();
				int v = in.nextInt();
				--u;
				--v;
				vertices[u].adj.add(vertices[v]);
			}

			for (int i = 0; i < n; ++i) {
				if (vertices[i].dead == false) vertices[i].dfs();
			}

			out.println(all + " " + ans);
		}

		class Vertex {
			boolean dead;
			int low;
			int num;
			int cost;
			ArrayList<Vertex> adj;

			void dfs() {
				low = num = ++cnt;
				stack.push(this);
				for (Vertex nxt : adj) {
					if (nxt.dead == true) continue;
					if (nxt.num > 0) {
						low = Math.min(low, nxt.num);
					} else {
						nxt.dfs();
						low = Math.min(low, nxt.low);
					}
				}

				if (low >= num) {
					int best = Integer.MAX_VALUE, way = 0;
					while (true) {
						Vertex now = stack.pop();
						if (now.cost == best) ++way;
						else if (now.cost < best) {
							best = now.cost;
							way = 1;
						}
						now.dead = true;
						if (now == this) break;
					}
					ans = (int) ((long) ans * (long) way % mod);
					all = all + best;
				}
			}

		}
//
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
}
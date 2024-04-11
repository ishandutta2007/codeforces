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
import java.util.Stack;
import java.util.ArrayList;
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
		EReachabilityFromTheCapital solver = new EReachabilityFromTheCapital();
		solver.solve(1, in, out);
		out.close();
	}

	static class EReachabilityFromTheCapital {
		int cnt;
		int cur;
		Stack<Vertex> stack;
		Vertex[] vertices;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.nextInt();
			int m = in.nextInt();
			int s = in.nextInt() - 1;

			stack = new Stack<>();

			vertices = new Vertex[n + n];
			for (int i = 0; i < n + n; ++i) {
				vertices[i] = new Vertex();
				vertices[i].adj = new ArrayList<>();
			}

			for (int i = 0; i < m; ++i) {
				int u = in.nextInt() - 1;
				int v = in.nextInt() - 1;
				vertices[u].adj.add(vertices[v]);
			}

			cur = n;
			for (int i = 0; i < n; ++i) {
				if (vertices[i].dead == 0) vertices[i].dfs();

			}


			//76908cc0
			//76908cc0
			for (int i = n; i < cur; ++i) {
				for (Vertex next : vertices[i].adj) {
					Vertex now = next.at;
					if (now == vertices[i]) continue;
					now.indegree++;
				}
			}

			int answer = 0;
			for (int i = n; i < cur; ++i) {
				if (vertices[i].indegree == 0) ++answer;
			}

			if (vertices[s].at.indegree == 0) --answer;

			out.println(answer);
		}

		class Vertex {
			ArrayList<Vertex> adj;
			int indegree;
			int low;
			int num;
			int dead;
			Vertex at;

			void dfs() {
				low = num = ++cnt;
				stack.push(this);
				for (Vertex next : adj) {
					if (next.dead == 1) continue;
					if (next.num > 0) {
						low = Math.min(low, next.num);
					} else {
						next.dfs();
						low = Math.min(low, next.low);
					}
				}

				if (low >= num) {

					while (true) {
						Vertex now = stack.pop();
						now.at = vertices[cur];
						now.dead = 1;
						for (Vertex next : now.adj) {
							now.at.adj.add(next);
						}
						if (now == this) break;
					}
					cur++;
				}
			}

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

		public void close() {
			this.writer.close();
		}

		public void println(int i) {
			this.writer.println(i);
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
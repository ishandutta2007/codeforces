import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	void solve() {
		int n = nextInt();
		char[] c = nextToken().toCharArray();
		Queue<State> q = new ArrayDeque<State>();
		q.add(new State(0, 0, 0, 0, 0));
		HashSet<State> was = new HashSet<State>();
		while (!q.isEmpty()) {
			State state = q.poll();
			if (state.n == n) {
				continue;
			}
			int x = state.n;
			State newState;
			if (c[x] == 'R') {
				newState = state.incR();
				if (!was.contains(newState)) {
					was.add(newState);
					q.add(newState);
				}
			} else if (c[x] == 'H') {
				newState = state.incH();
				if (!was.contains(newState)) {
					was.add(newState);
					q.add(newState);
				}
			} else if (c[x] == 'S') {
				newState = state.incS();
				if (!was.contains(newState)) {
					was.add(newState);
					q.add(newState);
				}
			} else if (c[x] == 'G') {
				newState = state.incG();
				if (!was.contains(newState)) {
					was.add(newState);
					q.add(newState);
				}
			} else {
				if (state.canIncG()) {
					newState = state.incG();
					if (!was.contains(newState)) {
						was.add(newState);
						q.add(newState);
					}
				}
				if (state.canIncH()) {
					newState = state.incH();
					if (!was.contains(newState)) {
						was.add(newState);
						q.add(newState);
					}
				}
				if (state.canIncR()) {
					newState = state.incR();
					if (!was.contains(newState)) {
						was.add(newState);
						q.add(newState);
					}
				}
				if (state.canIncS()) {
					newState = state.incS();
					if (!was.contains(newState)) {
						was.add(newState);
						q.add(newState);
					}
				}
			}
		}
		boolean canG = false;
		boolean canH = false;
		boolean canS = false;
		boolean canR = false;
		for (State s : was) {
			if (s.n != n) {
				continue;
			}
			canG |= s.canIncG();
			canH |= s.canIncH();
			canR |= s.canIncR();
			canS |= s.canIncS();
		}

		if (canG) {
			out.println("Gryffindor");
		}
		if (canH) {
			out.println("Hufflepuff");
		}
		if (canR) {
			out.println("Ravenclaw");
		}
		if (canS) {
			out.println("Slytherin");
		}
	}

	static class State {
		int g;
		int s;
		int h;
		int r;
		int n;

		public State(int g, int s, int h, int r, int n) {
			this.g = g;
			this.s = s;
			this.h = h;
			this.r = r;
			this.n = n;
		}

		public boolean canIncG() {
			return g <= h && g <= r && g <= s;
		}

		public State incG() {
			return new State(g + 1, s, h, r, n + 1);
		}

		public State incH() {
			return new State(g, s, h + 1, r, n + 1);
		}

		public boolean canIncH() {
			return h <= g && h <= s && h <= r;
		}

		public boolean canIncR() {
			return r <= h && r <= s && r <= g;
		}

		public State incR() {
			return new State(g, s, h, r + 1, n + 1);
		}

		public boolean canIncS() {
			return s <= g && s <= r && s <= h;
		}

		public State incS() {
			return new State(g, s + 1, h, r, n + 1);
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + g;
			result = prime * result + h;
			result = prime * result + n;
			result = prime * result + r;
			result = prime * result + s;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (g != other.g)
				return false;
			if (h != other.h)
				return false;
			if (n != other.n)
				return false;
			if (r != other.r)
				return false;
			if (s != other.s)
				return false;
			return true;
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
		new D().run();
	}
}
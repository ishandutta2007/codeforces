import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	static class State {
		int x;
		int y;
		boolean did1;
		boolean did2;

		public State(int x, int y, boolean did1, boolean did2) {
			super();
			this.x = x;
			this.y = y;
			this.did1 = did1;
			this.did2 = did2;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (did1 ? 1231 : 1237);
			result = prime * result + (did2 ? 1231 : 1237);
			result = prime * result + x;
			result = prime * result + y;
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
			if (did1 != other.did1)
				return false;
			if (did2 != other.did2)
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		State reverse() {
			return new State(y, x, did2, true);
		}

		State addVector(int vx, int vy) {
			return new State(x + vx, y + vy, did2, did1);
		}

		boolean isWin(int d) {
			return x * x + y * y > d * d;
		}

		@Override
		public String toString() {
			return "State [x=" + x + ", y=" + y + ", did1=" + did1 + ", did2="
					+ did2 + "]";
		}

	}

	static HashMap<State, Boolean> hm = new HashMap<State, Boolean>();

	static boolean go(State state, int n, int[] vx, int[] vy, int d) {
		if (hm.containsKey(state)) {
			return hm.get(state);
		}
		if (state.isWin(d)) {
			return true;
		}
		boolean ret = false;
		if (!state.did1) {
			State newState = state.reverse();
			ret |= !go(newState, n, vx, vy, d);
		}
		for (int i = 0; i < n; i++) {
			State newState = state.addVector(vx[i], vy[i]);
			ret |= !go(newState, n, vx, vy, d);
		}
		hm.put(state, ret);
		return ret;
	}

	void solve() {
		int startX = nextInt();
		int startY = nextInt();
		int n = nextInt();
		int d = nextInt();
		int[] vx = new int[n];
		int[] vy = new int[n];
		for (int i = 0; i < n; i++) {
			vx[i] = nextInt();
			vy[i] = nextInt();
		}
		if (go(new State(startX, startY, false, false), n, vx, vy, d)) {
			out.println("Anton");
		} else {
			out.println("Dasha");
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
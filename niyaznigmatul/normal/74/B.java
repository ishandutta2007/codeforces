import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	static class State {
		int n;
		int m;
		int k;
		int dir;

		public State(int n, int m, int k, int dir) {
			super();
			this.n = n;
			this.m = m;
			this.k = k;
			this.dir = dir;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + m;
			result = prime * result + n;
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
			if (m != other.m)
				return false;
			if (n != other.n)
				return false;
			return true;
		}

		public State doNothing() {
			int newDir = dir;
			if (k == 0) {
				newDir = 1;
			}
			if (k == trainLength - 1) {
				newDir = -1;
			}
			return new State(n + 1, m, k + newDir, newDir);
		}

		public State go(int w) {
			int newDir = dir;
			if (k == 0) {
				newDir = 1;
			}
			if (k == trainLength - 1) {
				newDir = -1;
			}
			return new State(n + 1, w, k + newDir, newDir);
		}

		@Override
		public String toString() {
			return "State [n=" + n + ", m=" + m + ", k=" + k + ", dir=" + dir
					+ "]";
		}

	}

	static HashMap<State, Integer> hm;
	static char[] stop;
	static int trainLength;

	void solve() {
		hm = new HashMap<State, Integer>();
		int n = nextInt();
		trainLength = n;
		int m = nextInt() - 1;
		int k = nextInt() - 1;
		nextToken();
		int dir = nextToken().equals("tail") ? 1 : -1;
		stop = nextToken().toCharArray();
		int ans = go(new State(0, m, k, dir));
		if (ans == Integer.MAX_VALUE) {
			out.println("Stowaway");
		} else {
			out.println("Controller " + ans);
		}
	}

	static int go(State state) {
		if (state.m == state.k) {
			return 0;
		}
		if (state.n == stop.length - 1) {
			return Integer.MAX_VALUE;
		}		
		if (hm.containsKey(state)) {
			return hm.get(state);
		}
		int n = state.n;
		if (stop[n] == '0') {
			int ret = Integer.MIN_VALUE;
			{
				State newState = state.doNothing();
				int got = go(newState);
				if (got != Integer.MAX_VALUE) {
					got++;
				}
				ret = Math.max(ret, got);
			}
			if (state.m + 1 < trainLength && state.m + 1 != state.k) {
				State newState = state.go(state.m + 1);
				int got = go(newState);
				if (got != Integer.MAX_VALUE) {
					got++;
				}
				ret = Math.max(ret, got);
			}
			if (state.m > 0 && state.m - 1 != state.k) {
				State newState = state.go(state.m - 1);
				int got = go(newState);
				if (got != Integer.MAX_VALUE) {
					got++;
				}
				ret = Math.max(ret, got);
			}
			hm.put(state, ret);
			return ret;
		}
		int ret = Integer.MIN_VALUE;
		for (int i = 0; i < trainLength; i++) {
			State newState = state.go(i);
			int got = go(newState);
			if (got != Integer.MAX_VALUE) {
				got++;
			}
			ret = Math.max(ret, got);
		}
		hm.put(state, ret);
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
		new B().run();
	}
}
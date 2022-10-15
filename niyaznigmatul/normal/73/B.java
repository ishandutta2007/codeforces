import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	static class Pilot implements Comparable<Pilot> {
		String name;
		int pnt;

		public Pilot(String name, int pnt) {
			super();
			this.name = name;
			this.pnt = pnt;
		}

		@Override
		public int compareTo(Pilot o) {
			if (pnt != o.pnt) {
				return -pnt + o.pnt;
			}
			return name.compareTo(o.name);
		}

		@Override
		public String toString() {
			return "Pilot [name=" + name + ", pnt=" + pnt + "]";
		}

	}

	void solve() {
		int n = nextInt();
		Pilot[] p = new Pilot[n];
		for (int i = 0; i < n; i++) {
			p[i] = new Pilot(nextToken(), nextInt());
		}
		int m = nextInt();
		int[] b = new int[n];
		for (int i = 0; i < m; i++) {
			b[i] = nextInt();
		}
		String man = nextToken();		
		Arrays.sort(p);
		Arrays.sort(b);
		for (int i = 0; i < b.length - i - 1; i++) {
			int t = b[i];
			b[i] = b[b.length - i - 1];
			b[b.length - i - 1] = t;
		}
		int id = -1;
		for (int i = 0; i < n; i++) {
			if (p[i].name.equals(man)) {
				id = i;
				break;
			}
		}
		out.println(solveMax(n, p, b, id) + " " + solveMin(n, p, b, id));
	}

	static int solveMin(int n, Pilot[] p, int[] b, int man) {
		int ourPnt = p[man].pnt + b[b.length - 1];
		int ret = man;
		for (int i = man + 1, j = b.length - 2; i < n; i++, ret++) {
			while (j >= 0) {
				int curPnt = p[i].pnt + b[j];				
				if (curPnt > ourPnt || curPnt == ourPnt
						&& p[man].name.compareTo(p[i].name) > 0) {
					break;
				}
				j--;
			}
			if (j < 0) {
				break;
			}
			j--;
		}
		return ret + 1;
	}

	static int solveMax(int n, Pilot[] p, int[] b, int man) {
		int ourPnt = p[man].pnt + b[0];
		int ret = man;
		for (int i = man - 1, j = 1; i >= 0; i--, ret--) {
			while (j < b.length) {
				int curPnt = p[i].pnt + b[j];				
				if (curPnt < ourPnt || curPnt == ourPnt
						&& p[man].name.compareTo(p[i].name) < 0) {
					break;
				}
				j++;
			}
			if (j == b.length) {
				break;
			}
			j++;
		}
		return ret + 1;
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
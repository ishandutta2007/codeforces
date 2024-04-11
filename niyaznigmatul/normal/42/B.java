import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new B().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
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

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
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

	void solve() {
		String s1 = nextToken();
		String s2 = nextToken();
		String s3 = nextToken();
		String s4 = nextToken();
		int x1 = s1.charAt(0) - 'a';
		int y1 = s1.charAt(1) - '1';
		int x2 = s2.charAt(0) - 'a';
		int y2 = s2.charAt(1) - '1';
		int x3 = s3.charAt(0) - 'a';
		int y3 = s3.charAt(1) - '1';
		int x4 = s4.charAt(0) - 'a';
		int y4 = s4.charAt(1) - '1';
		boolean[][] has = new boolean[8][8];
		has[x1][y1] = has[x2][y2] = has[x3][y3] = true;
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int x = x4 + dx;
				int y = y4 + dy;
				if (x < 0 || y < 0 || x >= 8 || y >= 8) {
					continue;
				}
				boolean ok1 = (check1(has, x1, y1, x, y));
				boolean ok2 = (check1(has, x2, y2, x, y));
				boolean ok3 = (check2(has, x3, y3, x, y));
				if (ok1 || ok2 || ok3) {
					continue;
				}
				out.println("OTHER");
				return;
			}
		}
		out.println("CHECKMATE");
	}

	boolean check2(boolean[][] has, int x, int y, int x1, int y1) {
		if (x == x1 && y == y1) {
			return false;
		}
		return (Math.abs(x - x1) <= 1 && Math.abs(y - y1) <= 1);
	}

	boolean check1(boolean[][] has, int x, int y, int x1, int y1) {
		if ((x1 != x && y1 != y) || (x == x1 && y == y1)) {
			return false;
		}
		int dx;
		int dy;
		if (x1 == x) {
			dx = 0;
			dy = y1 < y ? -1 : 1;
		} else {
			dx = x1 < x ? -1 : 1;
			dy = 0;
		}
		int xx = x + dx;
		int yy = y + dy;
		while (xx >= 0 && yy >= 0 && xx < 8 && yy < 8 && !has[xx][yy]) {
			if (xx == x1 && yy == y1) {
				return true;
			}
			xx += dx;
			yy += dy;
		}
		return xx == x1 && yy == y1;
	}
}
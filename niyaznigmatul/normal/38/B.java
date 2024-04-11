import java.io.*;
import java.util.*;

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

	void doAssert(boolean isRight, String s) {
		if (!isRight)
			throw new AssertionError(s);
	}

	boolean rookBeats(int rX, int rY, int x, int y) {
		return rX == x || rY == y;
	}

	boolean knightBeats(int kX, int kY, int x, int y) {
		final int[] DX = { 1, 2, 1, 2, -1, -2, -1, -2 };
		final int[] DY = { 2, 1, -2, -1, -2, -1, 2, 1 };
		for (int dir = 0; dir < DX.length; dir++) {
			int i = x + DX[dir];
			int j = y + DY[dir];
			if (i == kX && j == kY) {
				return true;
			}
		}
		return false;
	}

	String toString(int x, int y) {
		return "" + (char) (x + 'a') + (y + 1);
	}

	private void solve() {
		String a = sc.nextToken();
		String b = sc.nextToken();
		int xA = a.charAt(0) - 'a';
		int yA = a.charAt(1) - '1';
		int xB = b.charAt(0) - 'a';
		int yB = b.charAt(1) - '1';
		int ans = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (i == xA && j == yA || i == xB && j == yB) {
					continue;
				}
				if (knightBeats(i, j, xA, yA) || knightBeats(i, j, xB, yB)
						|| rookBeats(xA, yA, i, j) || knightBeats(xB, yB, i, j)) {
					continue;
				}
				ans++;
			}
		}
		out.println(ans);
	}
}
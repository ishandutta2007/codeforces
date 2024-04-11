import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	int gcd(int x, int y) {
		return x == 0 ? y : gcd(y % x, x);
	}

	int cnt(int x1, int y1, int x2, int y2) {
		int dx = Math.abs(x1 - x2);
		int dy = Math.abs(y1 - y2);
		int g = gcd(dx, dy);
		return g;
	}

	void solve() {
		final int M = 222;
		int n = in.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		double avarageS = 0;
		double avarageCnt = 0;

		double total = 1;
		double total2 = 1;
		int sub = 0;
		if (n < M) {
			for (int i = 0; i < n; i++) {
				total *= 2;
			}
			total2 = total;
			sub = 1 + n + n * (n - 1) / 2;
			total -= sub;
		}
		final int MAX = Math.min(50, n - 1);
		for (int i = 0; i < n; i++) {
			int j = i;
			double pr = 0.25;
			double curMul = total2 / 2;
			for (int add = 0; add < MAX; add++) {
				curMul /= 2;
				j++;
				if (j == n) {
					j = 0;
				}
				avarageS += pr * (x[i] * 1L * y[j] - x[j] * 1L * y[i]);
				if (n < M) {
					avarageCnt += cnt(x[i], y[i], x[j], y[j])
							* ((curMul - 1) / total);
				} else {
					avarageCnt += cnt(x[i], y[i], x[j], y[j]) * pr;
				}
				pr /= 2;
			}
		}
		if (n < M) {
			double mul = total2 / (total2 - sub);
			avarageS *= mul;
		}
		avarageS /= 2;
		double ans = avarageS + 1 - avarageCnt / 2;
		out.println(ans);
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return null;
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
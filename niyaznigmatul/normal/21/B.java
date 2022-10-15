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

	int gcd(int x, int y) {
		x = Math.abs(x);
		y = Math.abs(y);
		return (x == 0 || y == 0) ? x + y : gcd(y, x % y);
	}

	void solve() {
		int a1 = nextInt();
		int b1 = nextInt();
		int c1 = nextInt();
		int a2 = nextInt();
		int b2 = nextInt();
		int c2 = nextInt();
		if ((a1 == 0 && b1 == 0 && c1 != 0) || (a2 == 0 && b2 == 0 && c2 != 0)) {
			out.println(0);
			return;
		}
		if (a1 == a2 && b1 == b2 && c1 == c2) {
			out.println("-1");
			return;
		}
		if ((a1 == 0 && b1 == 0 && c1 == 0) || (a2 == 0 && b2 == 0 && c2 == 0)) {
			out.println("-1");
			return;
		}
		int[] p1 = new int[] { a1, b1, c1 };
		int[] p2 = new int[] { a2, b2, c2 };
		for (int i = 0; i < 3; i++) {
			if (p1[i] != 0 && p2[i] == 0 || p1[i] == 0 && p2[i] != 0) {
				if (a1 * b2 - a2 * b1 == 0) {
					out.println(0);
				} else {
					out.println(1);
				}
				return;
			}
		}
		int[] den = new int[3];
		int[] num = new int[3];
		for (int i = 0; i < 3; i++) {
			if (p1[i] == 0) {
				continue;
			}
			num[i] = p1[i];
			den[i] = p2[i];
			if (den[i] < 0) {
				num[i] = -num[i];
				den[i] = -den[i];
			}
			int g = gcd(num[i], den[i]);
			num[i] /= g;
			den[i] /= g;
		}
		for (int i = 0; i < 3; i++) {
			if (p1[i] == 0) {
				continue;
			}
			for (int j = i + 1; j < 3; j++) {
				if (p1[j] == 0) {
					continue;
				}
				if (num[i] != num[j] || den[i] != den[j]) {
					if (a1 * b2 - a2 * b1 == 0) {
						out.println(0);
					} else {
						out.println(1);
					}
					return;
				}
			}
		}
		out.println(-1);
	}
}
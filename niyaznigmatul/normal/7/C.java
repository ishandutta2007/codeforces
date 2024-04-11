import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
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

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long x, y;

	int gcd(int a, int b) {
		a = Math.abs(a);
		b = Math.abs(b);
		if (a == 0) {
			x = 0;
			y = 1;
			return b;
		}
		if (b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		int ret = gcd(b % a, a);
		long x0 = y - (b / a) * x;
		long y0 = x;
		x = x0;
		y = y0;
		return ret;
	}

	void solve() {
		int a = nextInt();
		int b = nextInt();
		int c = -nextInt();
		int d = gcd(a, b);
		if (a < 0) {
			x = -x;
		}
		if (b < 0) {
			y = -y;
		}
		if (c % d != 0) {
			out.println(-1);
			return;
		}
		x *= c / d;
		y *= c / d;
		out.println(x + " " + y);
	}
}
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A implements Runnable {
	public static void main(String[] args) {
		new A().run();
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

	boolean is(int x) {
		int cnt = 0;
		for (int i = 2; i <= x; i++) {
			if (x % i == 0 && hs.contains(i)) {
				++cnt;
			}
		}
		return cnt == 2;
	}

	HashSet<Integer> hs;

	void solve() {
		hs = new HashSet<Integer>();
		int n = nextInt();
		boolean[] p = new boolean[n + 1];
		for (int i = 2; i * i <= n; i++) {
			if (!p[i]) {
				for (int j = i * i; j <= n; j += i) {
					p[j] = true;
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			if (!p[i]) {
				hs.add(i);
			}
		}
		int ans = 0;
		for (int i = 4; i <= n; i++) {
			if (is(i)) {
				++ans;
			}
		}
		out.println(ans);
	}
}
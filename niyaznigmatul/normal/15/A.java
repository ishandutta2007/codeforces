import java.io.*;
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

	class House {
		int x, t;

		public House(int x, int t) {
			this.x = x;
			this.t = t;
		}

	}

	void solve() {
		int n = nextInt();
		int t = nextInt();
		House[] h = new House[n];
		for (int i = 0; i < n; i++) {
			h[i] = new House(nextInt(), nextInt());
		}
		Arrays.sort(h, new Comparator<House>() {
			@Override
			public int compare(House o1, House o2) {
				return o1.x < o2.x ? -1 : o1.x > o2.x ? 1 : 0;
			}
		});
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0
					|| (h[i].x - h[i - 1].x) * 2 - h[i].t - h[i - 1].t >= 2 * t) {
				++ans;
			}
			if (i == n - 1
					|| (h[i + 1].x - h[i].x) * 2 - h[i + 1].t - h[i].t > 2 * t) {
				++ans;
			}
		}
		out.println(ans);
	}
}
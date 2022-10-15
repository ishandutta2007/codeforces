import java.io.*;
import java.math.*;
import java.util.*;

public class B {
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

	void solve() {
		int n = nextInt();
		int k = nextInt();
		int xc = k / 2;
		int yc = xc;
		int[] l = new int[k];
		int[] r = new int[k];
		Arrays.fill(l, -1);
		for (int it = 0; it < n; it++) {
			int m = nextInt();
			int cur = 0;
			for (int i = 0; i < m; i++) {
				cur += xc + Math.abs(i - yc);
			}
			int mi = Integer.MAX_VALUE, miX = -1, miY = -1;
			for (int i = 0; i < k; i++) {				
				int cur2 = cur;
				for (int j = 0; j + m - 1 < k; j++) {
					if (l[i] == -1 || j + m - 1 < l[i] || j > r[i]) {
						if (mi > cur2) {
							mi = cur2;
							miX = i;
							miY = j;
						}
					}
					if (j + m - 1 < xc) {
						cur2 -= m;
					} else if (j >= xc) {
						cur2 += m;
					} else {
						cur2 -= xc - j;
						cur2 += j + m - xc;
					}
				}
				if (i < xc) {
					cur -= m;
				} else {
					cur += m;
				}
			}
			if (miX == -1) {
				out.println(-1);
				continue;
			}
			if (l[miX] == -1) {
				l[miX] = miY;
				r[miX] = miY + m - 1;
			} else if (l[miX] > miY) {
				l[miX] = miY;
			} else {
				r[miX] = miY + m - 1;
			}
			out.println((miX + 1) + " " + (miY + 1) + " " + (miY + m));
		}
	}
}
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

	final int[] DX = { 1, 0, -1, 0 };
	final int[] DY = { 0, 1, 0, -1 };

	boolean check(int[] x, int[] y) {
		int[] d = new int[3];
		int k = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				d[k++] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j])
						* (y[i] - y[j]);
			}
		}
		Arrays.sort(d);
		return d[0] + d[1] == d[2]
				&& (x[0] - x[1]) * (y[0] - y[2]) - (x[0] - x[2])
						* (y[0] - y[1]) != 0;
	}

	void solve() {
		int[] x = new int[3];
		int[] y = new int[3];
		for (int i = 0; i < 3; i++) {
			x[i] = nextInt();
			y[i] = nextInt();
		}
		if (check(x.clone(), y.clone())) {
			out.println("RIGHT");
			return;
		}
		for (int i = 0; i < 3; i++) {
			for (int dir = 0; dir < 4; dir++) {
				int[] xx = x.clone();
				int[] yy = y.clone();
				xx[i] += DX[dir];
				yy[i] += DY[dir];
				if (check(xx, yy)) {
					out.println("ALMOST");
					return;
				}
			}
		}
		out.println("NEITHER");
	}
}
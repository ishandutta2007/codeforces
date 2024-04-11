import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Point {
		int x, y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	long dist(Point a, Point b) {
		int dx = a.x - b.x;
		int dy = a.y - b.y;
		return dx * 1L * dx + dy * 1L * dy;
	}

	void solve() {
		int n = in.nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(in.nextInt(), in.nextInt());
		}
		int id = 1;
		long dist = dist(a[0], a[1]);
		for (int i = 2; i < n; i++) {
			long newD = dist(a[0], a[i]);
			if (newD < dist) {
				dist = newD;
				id = i;
			}
		}
		long A = a[0].y - a[id].y;
		long B = a[id].x - a[0].x;
		long C = -(A * a[0].x + B * a[0].y);
		int id2 = -1;
		long D = Long.MAX_VALUE;
		for (int i = 1; i < n; i++) {
			if (i != id) {
				long D2 = Math.abs(A * a[i].x + B * a[i].y + C);
				if (D2 != 0 && D2 < D) {
					D = D2;
					id2 = i;
				}
			}
		}
		if (id2 == -1) {
			throw new AssertionError();
		}
		out.println("1 " + (id + 1) + " " + (id2 + 1));
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
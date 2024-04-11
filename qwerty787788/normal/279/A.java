import java.io.*;
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

	void solve() {
		ArrayList<Point> a = new ArrayList<>();
		a.add(new Point(0, 0));
		a.add(new Point(1, 0));
		for (int i = 1; i < 200; i++) {
			a.add(new Point(i, i));
			a.add(new Point(-i, i));
			a.add(new Point(-i, -i));
			a.add(new Point(i + 1, -i));
		}
		int x = in.nextInt();
		int y = in.nextInt();
		if (x == 0 && y == 0) {
			out.println(0);
			return;
		}
		int ans = -1;
		for (int it = 1; it < a.size(); it++) {
			Point p1 = a.get(it - 1);
			Point p2 = a.get(it);
			if (p1.x == p2.x) {
				if (x == p1.x && y >= Math.min(p1.y, p2.y) && y <= Math.max(p1.y, p2.y)) {
					ans = it;
					break;
				}
			} else {
				if (y == p1.y && x >= Math.min(p1.x, p2.x) && x <= Math.max(p1.x, p2.x)) {
					ans = it;
					break;
				}
			}
		}
		out.println(ans - 1);
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

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
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
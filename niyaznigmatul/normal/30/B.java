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

	int[] p, a, b;
	boolean[] was;

	boolean go(int x) {
		if (x == p.length) {
			return check();
		}
		for (int i = 0; i < p.length; i++) {
			if (was[i]) {
				continue;
			}
			was[i] = true;
			p[x] = i;
			if (go(x + 1)) {
				return true;
			}
			was[i] = false;
		}
		return false;
	}

	boolean check() {
		int[] c = new int[p.length];
		for (int i = 0; i < c.length; i++) {
			c[i] = b[p[i]];
		}
		if (c[1] > 12) {
			return false;
		}
		int[] month;
		if (c[2] % 4 == 0) {
			month = m2;
		} else {
			month = m1;
		}
		if (c[0] > month[c[1] - 1]) {
			return false;
		}
		ga.set(2000 + a[2], a[1] - 1, a[0]);
		gb.set(2000 + c[2], c[1] - 1, c[0]);
		ga.add(GregorianCalendar.DATE, 1);
		gb.add(GregorianCalendar.DATE, 1);
		while (ga.get(GregorianCalendar.DATE) == 2
				&& ga.get(GregorianCalendar.MONTH) == GregorianCalendar.FEBRUARY
				|| gb.get(GregorianCalendar.DATE) == 2
				&& gb.get(GregorianCalendar.MONTH) == GregorianCalendar.FEBRUARY) {
			ga.add(GregorianCalendar.DATE, 1);
			gb.add(GregorianCalendar.DATE, 1);
		}
		int ans = 0;
		while (ga.compareTo(gb) > 0) {
			++ans;
			if (ga.get(GregorianCalendar.YEAR) > gb.get(GregorianCalendar.YEAR)) {
				gb.add(GregorianCalendar.YEAR, 1);
			} else {
				break;
			}			
		}
		if (ga.compareTo(gb) != 0) {
			ans--;
		}
		return ans >= 18;
	}

	GregorianCalendar ga = new GregorianCalendar();
	GregorianCalendar gb = new GregorianCalendar();
	final int[] m1 = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	final int[] m2 = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	void solve() {
		String[] s1 = nextToken().split("\\.");
		String[] s2 = nextToken().split("\\.");
		a = new int[] { Integer.parseInt(s1[0]), Integer.parseInt(s1[1]),
				Integer.parseInt(s1[2]) };
		b = new int[] { Integer.parseInt(s2[0]), Integer.parseInt(s2[1]),
				Integer.parseInt(s2[2]) };
		p = new int[a.length];
		was = new boolean[p.length];
		for (int i = 0; i < p.length; i++) {
			p[i] = i;
		}
		if (go(0)) {
			out.println("YES");
		} else {
			out.println("NO");
		}
	}
}
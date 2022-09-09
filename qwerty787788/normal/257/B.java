import java.io.*;
import java.util.*;

public class CF159DIV2 {
	FastScanner in;
	PrintWriter out;

	class Answ {
		int first, second;

		public Answ(int first, int second) {
			super();
			this.first = first;
			this.second = second;
		}

	}

	Answ ans(int n, int m, Answ cur, boolean first, int last) {
		if (n == 0 && m == 0)
			return cur;
		if (first) {
			if ((last == 0 && n != 0) || m == 0) {
				Answ tmp = ans(n - 1, m, cur, !first, 0);
				if (last == 0)
					tmp.first++;
				else
					tmp.second++;
				return tmp;
			} else {
				Answ tmp = ans(n, m - 1, cur, !first, 1);
				if (last == 1)
					tmp.first++;
				else
					tmp.second++;
				return tmp;
			}
		} else {
			if ((last == 1 && n != 0) || m == 0) {
				Answ tmp = ans(n - 1, m, cur, !first, 0);
				if (last == 0)
					tmp.first++;
				else
					tmp.second++;
				return tmp;
			} else {
				Answ tmp = ans(n, m - 1, cur, !first, 1);
				if (last == 1)
					tmp.first++;
				else
					tmp.second++;
				return tmp;
			}
		}
	}

	void solve2(int n, int m) {
		//int n = in.nextInt();
		//int m = in.nextInt();
		Answ a1 = ans(n - 1, m, new Answ(0, 0), false, 0);
		Answ a2 = ans(n, m - 1, new Answ(0, 0), false, 1);
		if (a1.first > a2.first) {
			out.print("(" + a1.first + ", " + a1.second+") ");
		} else {
			out.print("(" + a2.first + ", " + a2.second+") ");
		}
	}
	
	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		if (n >= m) {
			out.println((n - 1) + " " + m);
		} else {
			out.println((m - 1) + " " + n);
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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
		new CF159DIV2().runIO();
	}
}
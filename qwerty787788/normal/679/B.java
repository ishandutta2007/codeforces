import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Pair {
		long a, b;

		public Pair(long a, long b) {
			super();
			this.a = a;
			this.b = b;
		}

		@Override
		public String toString() {
			return "Pair [a=" + a + ", b=" + b + "]";
		}

	}

	HashMap<Long, Pair> ans = new HashMap<>();

	Pair getAns(long max) {
		if (max == 0) {
			return new Pair(0, 0);
		}
		Pair z = ans.get(max);
		if (z != null) {
			return z;
		}
		long vv = (long) Math.pow(max, 1. / 3) + 10;
		while (vv * vv * vv > max) {
			vv--;
		}
		Pair res;
		Pair left = getAns(vv * vv * vv - 1);
		res = left;
		if (vv <= max) {
			Pair tmp = getAns(max - vv * vv * vv);
			if (tmp.a + 1 >= res.a) {
				res = new Pair(tmp.a + 1, tmp.b + vv * vv * vv);
			}
		}
		ans.put(max, res);
		return res;
	}

	void solve() {
		long val = in.nextLong();
		Pair res = getAns(val);
		out.println(res.a + " " + res.b);
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
		new CF().runIO();
	}
}
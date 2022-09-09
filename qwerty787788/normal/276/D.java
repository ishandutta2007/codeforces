import java.io.*;
import java.util.*;

public class CFDiv1 {
	FastScanner in;
	PrintWriter out;

	boolean canBe(int from, long curVal, long l, long r) {
		if (curVal > r)
			return false;
		for (int i = 0; i <= from; i++)
			curVal += 1L << i;
		if (curVal >= l)
			return true;
		return false;
	}

	long stupid(long l, long r) {
		long ans = 0;
		for (long i = l; i <= r; i++)
			for (long j = l; j <= r; j++)
				ans = Math.max(ans, i ^ j);
		return ans;
	}

	long solve2(long l, long r) {
		long min = 0;
		long max = 0;
		for (int i = 62; i >= 0; i--) {
			boolean max0 = canBe(i - 1, max, l, r);
			boolean max1 = canBe(i - 1, max | (1L << i), l, r);
			boolean min0 = canBe(i - 1, min, l, r);
			boolean min1 = canBe(i - 1, min | (1L << i), l, r);
			if (max0 && min1 && max > min) {
				min = min | (1L << i);
			} else {
				if (max1 && min0) {
					max |= (1L << i);
				} else {
					if (max1 && min1) {
						max |= (1L << i);
						min |= 1L << i;
					} else {

					}
				}
			}
		}
		return min ^ max;
	}

	void solve() {
		out.println(solve2(in.nextLong(), in.nextLong()));
//		System.err.println(solve2(4, 9));
//		Random rnd = new Random(312);
//		for (int test = 0; test < 10000; test++) {
//			System.err.println(test);
//			int l = rnd.nextInt(100);
//			int r = rnd.nextInt(100) + l;
//			long v1 = stupid(l, r);
//			long v2 = solve2(l, r);
//			if (v1 != v2) {
//				System.err.println(v1 + " " + v2);
//				System.err.println(l + " " + r);
//				throw new AssertionError();
//			}
//		}
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
		new CFDiv1().runIO();
	}
}
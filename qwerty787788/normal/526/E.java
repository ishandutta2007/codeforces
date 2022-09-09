import java.io.*;
import java.util.*;

public class Test {
	FastScanner in;
	PrintWriter out;

	long[] getCount(int[] a, int from, long b) {
		int result = 1;
		boolean firstRow = true;
		long sum = 0;
		for (int i = from; i < from || firstRow;) {
			sum += a[i];
			if (sum > b) {
				sum = a[i];
				result++;
			}
			i++;
			if (i == a.length) {
				i = 0;
				firstRow = false;
			}
		}
		return new long[] { result, sum };
	}

	int correct(int[] a, int b) {
		int result = Integer.MAX_VALUE;
		for (int start = 0; start < a.length; start++) {
			result = (int) Math.min(result, getCount(a, start, b)[0]);
		}
		return result;
	}

	int my(int[] a, long b) {
		long[] tmp = getCount(a, 0, b);
		if (tmp[0] == 1) {
			return 1;
		}
		int pos = 0;
		long more = b - tmp[1];
		while (more >= a[pos]) {
			more -= a[pos];
			pos++;
		}
		return (int) getCount(a, pos, b)[0];
	}

	void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < q; i++) {
			long b = in.nextLong();
			out.println(my(a, b));
		}
	}

	void solve123() {
		final int MAX = 6;
		Random rnd = new Random(123);
		for (int it = 0; it < 123123; it++) {
			System.err.println("iter = " + it);
			int n = 1 + rnd.nextInt(MAX);
			int[] a = new int[n];
			int maxA = 1 + rnd.nextInt(MAX);
			for (int i = 0; i < n; i++) {
				a[i] = 1 + rnd.nextInt(maxA);
			}
			int b = 1 + rnd.nextInt(MAX);
			for (int i = 0; i < n; i++) {
				b = Math.max(b, a[i]);
			}

			if (it == 8) {
			}
			int corr = correct(a, b);
			int fast = my(a, b);
			if (corr != fast) {
				System.err.println(Arrays.toString(a));
				System.err.println("correct = " + corr);
				System.err.println("my = " + fast);
				System.err.println("b = " + b);
				throw new AssertionError();
			}
		}
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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new Test().runIO();
	}
}
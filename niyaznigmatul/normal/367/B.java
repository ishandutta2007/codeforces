import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int p = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[] b = new int[m];
		for (int i = 0; i < m; i++) {
			b[i] = nextInt();
		}
		int[] c = ArrayUtils.sortAndUnique(b);
		for (int i = 0; i < n; i++) {
			a[i] = Arrays.binarySearch(c, a[i]);
		}
		for (int i = 0; i < m; i++) {
			b[i] = Arrays.binarySearch(c, b[i]);
		}
		int[] count = new int[c.length];
		boolean[] ans = new boolean[n];
		for (int i = 0; i < p; i++) {
			if (i + (long) (m - 1) * p >= n) {
				continue;
			}
			Arrays.fill(count, 0);
			for (int j : b) {
				count[j]++;
			}
			int zeros = 0;
			for (int k = i; k < m * p + i && k < n; k += p) {
				int x = a[k];
				if (x >= 0) {
					if (count[x] == 0) {
						--zeros;
					}
					count[x]--;
					if (count[x] == 0) {
						++zeros;
					}
				}
			}
			if (zeros == c.length) {
				ans[i] = true;
			}
			for (int k = m * p + i; k < n; k += p) {
				int x = a[k - m * p];
				if (x >= 0) {
					if (count[x] == 0) {
						--zeros;
					}
					++count[x];
					if (count[x] == 0) {
						++zeros;
					}
				}
				x = a[k];
				if (x >= 0) {
					if (count[x] == 0) {
						--zeros;
					}
					--count[x];
					if (count[x] == 0) {
						++zeros;
					}
				}
				if (zeros == c.length) {
					ans[k - (m - 1) * p] = true;
				}
			}
		}
		int[] as = new int[n];
		int ac = 0;
		for (int i = 0; i < n; i++) {
			if (ans[i]) {
				as[ac++] = i;
			}
		}
		out.println(ac);
		for (int i = 0; i < ac; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(as[i] + 1);
		}
		out.println();
	}

	static class ArrayUtils {

		static final long seed = System.nanoTime();

		static final Random rand = new Random(seed);

		public static boolean nextPermutation(int[] a) {
			for (int i = a.length - 2; i >= 0; i--) {
				if (a[i] < a[i + 1]) {
					int cur = i + 1;
					for (int j = i + 2; j < a.length; j++) {
						if (a[j] > a[i] && a[j] < a[cur]) {
							cur = j;
						}
					}
					{
						int t = a[cur];
						a[cur] = a[i];
						a[i] = t;
					}
					for (int j = i + 1, k = a.length - 1; j < k; j++, k--) {
						int t = a[j];
						a[j] = a[k];
						a[k] = t;
					}
					return true;
				}
			}
			return false;
		}

		public static long countNumberOfInversions(int[] a) {
			return inversions(a, null, 0, a.length);
		}

		static long inversions(int[] a, int[] b, int left, int right) {
			if (b == null) {
				b = new int[a.length];
			}
			if (left + 1 >= right) {
				return 0;
			}
			int middle = left + right >> 1;
			long ret = inversions(a, b, left, middle)
					+ inversions(a, b, middle, right);
			for (int i = left, j = middle, k = 0; i < middle || j < right; k++) {
				if (j >= right || i < middle && a[i] <= a[j]) {
					ret += j - middle;
					b[k] = a[i++];
				} else {
					b[k] = a[j++];
				}
			}
			for (int i = left; i < right; i++) {
				a[i] = b[i - left];
			}
			return ret;
		}

		public static long countNumberOfInversions(double[] a) {
			return inversions(a, null, 0, a.length);
		}

		static long inversions(double[] a, double[] b, int left, int right) {
			if (b == null) {
				b = new double[a.length];
			}
			if (left + 1 >= right) {
				return 0;
			}
			int middle = left + right >> 1;
			long ret = inversions(a, b, left, middle)
					+ inversions(a, b, middle, right);
			for (int i = left, j = middle, k = 0; i < middle || j < right; k++) {
				if (j >= right || i < middle && a[i] <= a[j]) {
					ret += j - middle;
					b[k] = a[i++];
				} else {
					b[k] = a[j++];
				}
			}
			for (int i = left; i < right; i++) {
				a[i] = b[i - left];
			}
			return ret;
		}

		static public int[] toPrimitiveArrayInteger(List<Integer> list) {
			int[] ret = new int[list.size()];
			for (int i = 0; i < ret.length; i++) {
				ret[i] = list.get(i);
			}
			return ret;
		}

		static public long[] toPrimitiveArrayLong(List<Long> list) {
			long[] ret = new long[list.size()];
			for (int i = 0; i < ret.length; i++) {
				ret[i] = list.get(i);
			}
			return ret;
		}

		static public double[] toPrimitiveArraysDouble(List<Double> list) {
			double[] ret = new double[list.size()];
			for (int i = 0; i < ret.length; i++) {
				ret[i] = list.get(i);
			}
			return ret;
		}

		static public int[] sortAndUnique(int[] a) {
			int[] ret = a.clone();
			sort(ret);
			if (ret.length == 0) {
				return ret;
			}
			int last = ret[0];
			int j = 1;
			for (int i = 1; i < ret.length; i++) {
				if (last != ret[i]) {
					ret[j++] = ret[i];
					last = ret[i];
				}
			}
			return Arrays.copyOf(ret, j);
		}

		static public long[] sortAndUnique(long[] a) {
			long[] ret = a.clone();
			sort(ret);
			if (ret.length == 0) {
				return ret;
			}
			long last = ret[0];
			int j = 1;
			for (int i = 1; i < ret.length; i++) {
				if (last != ret[i]) {
					ret[j++] = ret[i];
					last = ret[i];
				}
			}
			return Arrays.copyOf(ret, j);
		}

		public static void sort(int[] a) {
			shuffle(a);
			Arrays.sort(a);
		}

		public static void shuffle(int[] a) {
			for (int i = 0; i < a.length; i++) {
				int j = rand.nextInt(i + 1);
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}

		public static void sort(double[] a) {
			shuffle(a);
			Arrays.sort(a);
		}

		public static void shuffle(double[] a) {
			for (int i = 0; i < a.length; i++) {
				int j = rand.nextInt(i + 1);
				double t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}

		public static void sort(long[] a) {
			shuffle(a);
			Arrays.sort(a);
		}

		public static void shuffle(long[] a) {
			for (int i = 0; i < a.length; i++) {
				int j = rand.nextInt(i + 1);
				long t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}

		public static <T> void shuffle(T[] a) {
			for (int i = 0; i < a.length; i++) {
				int j = rand.nextInt(i + 1);
				T t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}

		public static int[] reverse(int[] a) {
			int n = a.length;
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = a[n - i - 1];
			}
			return ret;
		}

		public static long[] reverse(long[] a) {
			int n = a.length;
			long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = a[n - i - 1];
			}
			return ret;
		}

		public static double[] reverse(double[] a) {
			int n = a.length;
			double[] ret = new double[n];
			for (int i = 0; i < n; i++) {
				ret[i] = a[n - i - 1];
			}
			return ret;
		}

		public static <T> T[] reverse(T[] a) {
			int n = a.length;
			T[] ret = a.clone();
			for (int i = 0; i < n; i++) {
				ret[i] = a[n - i - 1];
			}
			return ret;
		}

	}

	public static void main(String[] args) throws Exception {
		File file = new File("b.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			// output = new PrintStream("b.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
import java.io.*;
import java.util.*;

public class F {
	FastScanner in;
	PrintWriter out;

	class MyBitSet {
		int n;
		long[] a;

		public MyBitSet(int n) {
			this.n = n;
			a = new long[(n + 63) >> 6];
		}

		public MyBitSet(String s) {
			n = s.length();
			a = new long[(n + 63) >> 6];
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == '1') {
					set(i);
				}
			}
		}

		void set(int bit) {
			a[bit >> 6] |= 1L << (bit & 63);
		}

		void shiftRightAndOr(int sz) {
			int full = sz >> 6;
			int small = sz & 63;
			for (int i = a.length - full - 1; i >= 0; i--) {
				if (small != 0 && i + full + 1 < a.length) {
					a[i + full + 1] |= a[i] >>> (64 - small);
				}
				a[i + full] |= a[i] << small;
			}
		}

		void rotateLeft(int sz) {
			sz %= n;
			long[] b = new long[(n + 63) >> 6];
			int full = sz >> 6;
			int small = sz & 63;
			for (int i = full; i < a.length; i++) {
				b[i - full] |= a[i] >>> small;
			}
			if (small != 0) {
				for (int i = full + 1; i < a.length; i++) {
					b[i - 1 - full] |= a[i] << (64 - small);
				}
			}
			if (sz != 0) {
				int right = n - sz;
				full = right >> 6;
				small = right & 63;
				for (int i = 0; i + full < a.length; i++) {
					b[i + full] |= a[i] << small;
				}
				if (small != 0) {
					for (int i = 0; i + full + 1 < a.length; i++) {
						b[i + full + 1] |= a[i] >>> (64 - small);
					}
				}
			}
			a = b;
		}

		int get(int bit) {
			return (int) ((a[bit >> 6] >> (bit & 63)) & 1);
		}

		public String toString() {
			char[] res = new char[n];
			for (int i = 0; i < n; i++) {
				res[i] = get(i) == 1 ? '1' : '0';
			}
			return new String(res);
		}

		void clear() {
			Arrays.fill(a, 0);
		}

		void andNot(MyBitSet another) {
			for (int i = 0; i < a.length; i++) {
				a[i] &= ~another.a[i];
			}
		}
	}

	int SQRT = 100;

	int getMin(ArrayList<Integer> cycles, int k) {
		MyBitSet bitSet = new MyBitSet(k + 1);
		bitSet.set(0);
		int[] cntLen = new int[SQRT];
		// long START = System.currentTimeMillis();
		for (int len : cycles) {
			if (len < SQRT) {
				cntLen[len]++;
			} else {
				bitSet.shiftRightAndOr(len);
			}
		}
		// System.err.println(System.currentTimeMillis() - START);
		boolean[] f = new boolean[k + 1];
		for (int i = 0; i <= k; i++) {
			f[i] = bitSet.get(i) == 1;
		}
		int[] save = new int[k + 1];
		for (int len = 1; len < SQRT; len++) {
			if (cntLen[len] == 0) {
				continue;
			}
			int saveIter = 0;
			for (int mod = 0; mod < len; mod++) {
				int sum = 0;
				int sub = (1 + cntLen[len]) * len;
				for (int pos = mod; pos <= k; pos += len) {
					sum += f[pos] ? 1 : 0;
					if (pos - sub >= 0) {
						sum -= f[pos - sub] ? 1 : 0;
					}
					if (sum > 0) {
						save[saveIter++] = pos;
					}
				}
			}
			for (int i = 0; i < saveIter; i++) {
				f[save[i]] = true;
			}
		}
		// System.err.println(System.currentTimeMillis() - START);
		return f[k] ? k : (k + 1);
	}

	int getMax(ArrayList<Integer> cycles, int k) {
		int res = 0;
		int odd = 0;
		for (int len : cycles) {
			int tmp = Math.min(k, len / 2);
			res += 2 * tmp;
			k -= tmp;
			if (len % 2 == 1) {
				odd++;
			}
		}
		res += Math.min(k, odd);
		return res;
	}

	ArrayList<Integer> getCyclesLen(int[] a) {
		int n = a.length;
		boolean[] was = new boolean[n];
		ArrayList<Integer> res = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			if (was[i]) {
				continue;
			}
			int len = 0;
			int cur = i;
			while (!was[cur]) {
				was[cur] = true;
				cur = a[cur];
				len++;
			}
			res.add(len);
		}
		Collections.sort(res);
		return res;
	}

	void solve123() {
		long START = System.currentTimeMillis();
		ArrayList<Integer> cycles = new ArrayList<Integer>();
		final int MAX = (int) 1e6;
		int sum = 0;
		for (int i = 2; i <= 100; i++) {
			sum += i;
			cycles.add(i);

		}
		Random rnd = new Random(123);
		for (int i = 0; i < 10000; i++) {
			cycles.add(rnd.nextInt(100000));
		}
		System.err.println(getMin(cycles, MAX - 2) + " "
				+ getMax(cycles, MAX - 2));
		System.err.println(System.currentTimeMillis() - START);
	}

	void solve33() {
		final int M = 1000;
		Random rnd = new Random(123);
		for (int it = 0; it < 123123; it++) {
			System.err.println("ot = " + it);
			int n = 1 + rnd.nextInt(M);
			int[] p = new int[n];
			for (int i = 0; i < n; i++) {
				int id = rnd.nextInt(i + 1);
				p[i] = p[id];
				p[id] = i;
			}
			int k = rnd.nextInt(n + 1);
			int prMin = -1, prMax = -1;
			for (SQRT = 1; SQRT < 1000; SQRT++) {
				int min = getMin(getCyclesLen(p), k);
				int max = getMax(getCyclesLen(p), k);
				if (prMin != -1 && prMin != min) {
					System.err.println(min + "  " + prMin);
					System.err.println("SQRT = " + SQRT);
					System.err.println(Arrays.toString(p) + " " + k);
					System.err.println(getCyclesLen(p));
					System.err.println("k = " + k);
					ArrayList<Integer> tmp = getCyclesLen(p);
					getMin(tmp, k);
					throw new AssertionError();
				}
				if (prMax != -1 && prMax != max) {
					throw new AssertionError();
				}
				prMin = min;
				prMax = max;
			}
		}
	}

	void solve1323() {
		Random rnd = new Random(123);
		for (int it = 0; it < 123123; it++) {
			System.err.println("iter = " + it);
			final int n = 1 + rnd.nextInt(1000);
			boolean[] z = new boolean[n];
			MyBitSet bs = new MyBitSet(n);
			for (int i = 0; i < n; i++) {
				z[i] = rnd.nextBoolean();
				if (z[i]) {
					bs.set(i);
				}
			}
			int shift = rnd.nextInt(n);
			for (int i = n - 1; i >= shift; i--) {
				z[i] |= z[i - shift];
			}
			bs.shiftRightAndOr(shift);
			for (int i = 0; i < n; i++) {
				if ((bs.get(i) == 1) != z[i]) {
					throw new AssertionError();
				}
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt() - 1;
		}
		ArrayList<Integer> cycles = getCyclesLen(a);
		out.println(getMin(cycles, k) + " " + getMax(cycles, k));
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
		new F().runIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	long x;
	
	final int LOG = 5;
	final int DIV = 1 << LOG;
	final int DIVM1 = DIV - 1;

	long getNextX() {
		x = (x * 37 + 10007) % 1000000007;
		return x;
	}

	int n;
	int[] a;
	int[] b;
	int d;

	void swap(int[] a, int p1, int p2) {
		int v1 = a[p1];
		a[p1] = a[p2];
		a[p2] = v1;
	}

	void initAB() {
		for (int i = 0; i < n; i = i + 1) {
			a[i] = i + 1;
		}
		for (int i = 0; i < n; i = i + 1) {
			swap(a, i, (int) (getNextX() % (i + 1)));
		}
		for (int i = 0; i < n; i = i + 1) {
			if (i < d)
				b[i] = 1;
			else
				b[i] = 0;
		}
		for (int i = 0; i < n; i = i + 1) {
			swap(b, i, (int) (getNextX() % (i + 1)));
		}
	}

	class MBitSet {
		int[] vals;
		int n;

		MBitSet(int[] a, int shift) {
			n = 1 + a.length / DIV + 1;
			vals = new int[n];
			for (int i = 0; i < a.length; i++)
				if (a[i] == 1) {
					int pos = i + shift;
					vals[pos >> LOG] |= 1 << (pos & DIVM1);
				}
		}

		MBitSet(int n) {
			this.n = 1 + n / DIV + 1;
			vals = new int[this.n];
		}

		void set(int pos) {
			vals[pos >> LOG] ^= 1 << (pos & DIVM1);
		}

	}

	void solve() {
		n = in.nextInt();
		d = in.nextInt();
		x = in.nextInt();
		int[] c = new int[n];
		a = new int[n];
		b = new int[n];
		initAB();
		int[] pos = new int[n];
		for (int i = 0; i < n; i++) {
			pos[a[i] - 1] = i;
		}
		MBitSet[] bs = new MBitSet[DIV];
		for (int i = 0; i < DIV; i++)
			bs[i] = new MBitSet(b, i);
		MBitSet curNotSet = new MBitSet(n);
		for (int i = 0; i < n; i++)
			curNotSet.set(i);
		for (int i = n - 1; i >= 0; i--) {
			int p = pos[i];
			int start = p / DIV;
			int xx = p & DIVM1;
			for (int j = start; j < curNotSet.n; j++) {
				int tt = curNotSet.vals[j] & (bs[xx].vals[j - start]);
				while (tt != 0) {
					int v = Integer.numberOfTrailingZeros(tt);
					int posit = j * DIV + v;
					c[posit] = i + 1;
					curNotSet.set(posit);
					tt ^= 1 << v;
				}
			}

		}
		for (int i = 0; i < n; i++) {
			 out.println(c[i]);
		}
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
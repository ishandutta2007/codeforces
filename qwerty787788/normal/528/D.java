import java.io.*;
import java.util.*;

public class CF_D {
	FastScanner in;
	PrintWriter out;

	void FFT(double[] re, double[] im, boolean invert) {
		int n = re.length;
		if (im.length != n)
			throw new AssertionError("Sizes of arrays differ");
		if (Integer.bitCount(n) != 1)
			throw new AssertionError("N is not power of 2");
		if (n != 1) {
			int m = n / 2;
			double[] re1 = new double[m];
			double[] im1 = new double[m];
			double[] re2 = new double[m];
			double[] im2 = new double[m];
			for (int i = 0; i < n; i += 2) {
				re1[i / 2] = re[i];
				im1[i / 2] = im[i];
				re2[i / 2] = re[i + 1];
				im2[i / 2] = im[i + 1];
			}
			FFT(re1, im1, invert);
			FFT(re2, im2, invert);
			double angle = (invert ? -1 : 1) * Math.PI * 2 / n;
			double epsR = Math.cos(angle);
			double epsI = Math.sin(angle);
			double curR = 1;
			double curI = 0;
			for (int i = 0; i < m; i++) {
				double real = curR * re2[i] - curI * im2[i];
				double imag = curI * re2[i] + curR * im2[i];
				re[i] = re1[i] + real;
				im[i] = im1[i] + imag;
				real = -real;
				imag = -imag;
				re[i + m] = re1[i] + real;
				im[i + m] = im1[i] + imag;
				double nR = curR * epsR - curI * epsI;
				double nI = curR * epsI + curI * epsR;
				curR = nR;
				curI = nI;
				if (invert) {
					re[i] /= 2.;
					im[i] /= 2;
					re[i + m] /= 2;
					im[i + m] /= 2;
				}
			}
		}
	}

	int[] mul(boolean[] a, boolean[] b) {
		int len = Math.max(a.length, b.length) * 2;
		int mLen = 1;
		while (mLen < len)
			mLen *= 2;
		double[] r1 = new double[mLen];
		double[] i1 = new double[mLen];
		for (int i = 0; i < a.length; i++)
			r1[i] = a[i] ? 1 : 0;
		double[] r2 = new double[mLen];
		double[] i2 = new double[mLen];
		for (int i = 0; i < b.length; i++)
			r2[i] = b[i] ? 1 : 0;
		FFT(r1, i1, false);
		FFT(r2, i2, false);
		double[] rNew = new double[mLen];
		double[] iNew = new double[mLen];
		for (int i = 0; i < mLen; i++) {
			rNew[i] = r1[i] * r2[i] - i1[i] * i2[i];
			iNew[i] = r1[i] * i2[i] + r2[i] * i1[i];
		}
		FFT(rNew, iNew, true);
		int[] res = new int[mLen];
		for (int i = 0; i < mLen; i++)
			res[i] = (int) Math.round(rNew[i]);
		return res;
	}

	int[] canStartHere(boolean[] a, boolean[] b, int k) {
		int n = a.length;
		int m = b.length;
		int[] res = new int[n - m + 1];
		int[] left = new int[n];
		int[] right = new int[n];
		for (int i = 0; i < a.length; i++) {
			left[i] = Integer.MIN_VALUE / 2;
			if (i != 0) {
				left[i] = left[i - 1];
			}
			if (a[i]) {
				left[i] = i;
			}
		}
		for (int i = a.length - 1; i >= 0; i--) {
			right[i] = Integer.MAX_VALUE / 2 - 10;
			if (i != a.length - 1) {
				right[i] = right[i + 1];
			}
			if (a[i]) {
				right[i] = i;
			}
		}
		for (int i = 0; i < a.length; i++) {
			if (i - left[i] <= k) {
				a[i] = true;
			}
			if (right[i] - i <= k) {
				a[i] = true;
			}
		}
		for (int i = 0; i < b.length / 2; i++) {
			boolean tmp = b[i];
			b[i] = b[b.length - 1 - i];
			b[b.length - 1 - i] = tmp;
		}
		int[] xx = mul(a, b);
		for (int i = 0; i < res.length; i++) {
			res[i] = xx[b.length - 1 + i];
		}
		return res;
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		String s = in.next();
		String t = in.next();
		boolean[] a = new boolean[n];
		boolean[] b = new boolean[m];
		int[] can = new int[n - m + 1];
		for (char c : new char[] { 'A', 'C', 'G', 'T' }) {
			Arrays.fill(a, false);
			Arrays.fill(b, false);
			for (int i = 0; i < n; i++) {
				if (s.charAt(i) == c) {
					a[i] = true;
				}
			}
			for (int i = 0; i < m; i++) {
				if (t.charAt(i) == c) {
					b[i] = true;
				}
			}
			int[] tmp = canStartHere(a, b, k);
			for (int i = 0; i < tmp.length; i++) {
				can[i] += tmp[i];
			}
		}
		int res = 0;
		for (int i = 0; i < can.length; i++) {
			res += can[i] == m ? 1 : 0;
		}
		out.println(res);
	}

	void run() {
		try {
			in = new FastScanner(new File("cd.in"));
			out = new PrintWriter(new File("cd.out"));

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
		new CF_D().runIO();
	}
}
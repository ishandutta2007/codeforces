import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class E {
	FastScanner in;
	PrintWriter out;

	final int mod = (int) 1e9 + 7;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			a[i] = in.nextInt();
		}
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
		}
		BigInteger need = new BigInteger(in.next());
		int[] needA = new int[n];
		for (int i = 0; i + 1 < n; i++) {
			if (a[i] != 1) {
				needA[i] = need.mod(BigInteger.valueOf(a[i])).intValue();
				need = need.divide(BigInteger.valueOf(a[i]));
			}
		}
		if (need.compareTo(BigInteger.valueOf((int) 1e9)) > 0) {
			out.println(0);
			return;
		}
		needA[n - 1] = need.intValue();
		int[] cnt = new int[] { 1 };
		int[] sum = new int[] { 1 };
		for (int i = 0; i < n;) {
			int j = i;
			int sumBI = 1 + b[i];
			while (j != n - 1 && a[j] == 1) {
				j++;
				sumBI += b[j];
			}
			int div = i == 0 ? 1 : a[i - 1];
			sumBI += (1 + sum.length / div);
			int[] nextSum = new int[sumBI];
			int[] nextCnt = new int[sumBI];
			int beforeNeed = i == 0 ? 0 : needA[i - 1];
			int it = 0;
			for (int k = beforeNeed; k < cnt.length; k += div) {
				nextCnt[it++] = cnt[k];
			}
			updateSum(nextCnt, nextSum);
			for (int k = i; k <= j; k++) {
				int how = b[k];
				for (int l = 0; l < nextCnt.length; l++) {
					nextCnt[l] = nextSum[l];
					if (l - how - 1 >= 0) {
						nextCnt[l] -= nextSum[l - how - 1];
						if (nextCnt[l] < 0) {
							nextCnt[l] += mod;
						}
					}
				}
				updateSum(nextCnt, nextSum);
			}
			i = j + 1;
			sum = nextSum;
			cnt = nextCnt;
		}
		if (needA[n - 1] >= cnt.length) {
			out.println(0);
		} else {
			out.println(cnt[needA[n - 1]]);
		}
	}

	void updateSum(int[] val, int[] sum) {
		sum[0] = val[0];
		for (int i = 1; i < sum.length; i++) {
			sum[i] = sum[i - 1] + val[i];
			if (sum[i] >= mod) {
				sum[i] -= mod;
			}
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
		new E().runIO();
	}
}
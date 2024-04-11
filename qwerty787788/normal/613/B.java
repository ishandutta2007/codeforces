import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class O implements Comparable<O> {
		int id;
		int value;
		int nvalue;

		public O(int id, int value) {
			super();
			this.id = id;
			this.value = value;
		}

		@Override
		public int compareTo(O arg0) {
			return Integer.compare(value, arg0.value);
		}

	}

	void solve() {
		int n = in.nextInt();
		int A = in.nextInt();
		int cf = in.nextInt();
		int cm = in.nextInt();
		long m = in.nextLong();
		O[] a = new O[n];
		for (int i = 0; i < n; i++) {
			a[i] = new O(i, in.nextInt());
		}
		Arrays.sort(a);
		long[] sum = new long[n + 1];
		for (int i = 0; i < n; i++) {
			sum[i + 1] = sum[i] + a[i].value;
		}
		long best = -1;
		int bestCntA = -1;
		int minValue = -1;
		for (int cntA = 0; cntA <= n; cntA++) {
			long cur = cf * cntA;
			int tmpMax = 0;
			if (cntA == n) {
				cur += A * 1L * cm;
			} else {
				int left = 1, right = n - cntA + 1;
				while (right - left > 1) {
					int mid = (left + right) >> 1;
					long need = a[mid - 1].value * 1L * mid;
					long have = sum[mid];
					if (have + m < need) {
						right = mid;
					} else {
						left = mid;
					}
				}
				long need = a[left - 1].value * 1L * left;
				long have = sum[left];
				long more = m - (need - have);
				long maxCan = a[left - 1].value + more / left;
				//if (left != n) {
					//maxCan = Math.min(maxCan, a[left].value);
				//} else {
					maxCan = Math.min(maxCan, A);
				//}
				tmpMax = (int) maxCan;
				cur += maxCan * cm;
			}
			if (cur > best) {
				best = cur;
				bestCntA = cntA;
				minValue = tmpMax;
			}
			if (cntA == n) {
				break;
			}
			m -= A - a[n - 1 - cntA].value;
			if (m < 0) {
				break;
			}
		}
		for (int i = 0; i < bestCntA; i++) {
			a[n - 1 - i].nvalue = A;
		}
		for (int i = 0; i < n; i++) {
			if (a[i].nvalue != A) {
				a[i].nvalue = Math.max(a[i].value, minValue);
			}
		}
		Arrays.sort(a, new Comparator<O>() {

			@Override
			public int compare(O o1, O o2) {
				return Integer.compare(o1.id, o2.id);
			}
		});
		out.println(best);
		for (O o : a) {
			out.print(o.nvalue + " ");
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
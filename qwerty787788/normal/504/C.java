import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt() - 1;
		}
		boolean alrOk = true;
		for (int i = 0; i < n; i++) {
			if (a[i] != a[n - 1 - i]) {
				alrOk = false;
			}
		}
		if (alrOk) {
			long ans = n * 1L * (n + 1) / 2;
			out.println(ans);
			return;
		}
		int[] sum = new int[n];
		for (int i = 0; i < n; i++) {
			sum[a[i]]++;
		}
		int cntOdd = 0;
		for (int i = 0; i < n; i++)
			if (sum[i] % 2 != 0) {
				cntOdd++;
			}
		if (cntOdd > 1) {
			out.println(0);
			return;
		}
		int f = 0;
		while (a[f] == a[n - 1 - f]) {
			f++;
		}
		long ans = (f + 1) * 1L * (1 + f);
		ans += getAns(a, f, n - 1 - f) * 1L * (f + 1);
		for (int i = f, j = n - 1 - f; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		ans += getAns(a, f, n - 1 - f) * 1L * (f + 1);
		out.println(ans);
	}

	long getAns(int[] a, int l, int r) {
		int mid = (a.length - 1) / 2;
		int n = a.length;
		while (a[mid] == a[n - 1 - mid]) {
			mid--;
		}
		int[] cnt = new int[n];
		for (int i = l; i <= mid; i++) {
			cnt[a[i]]++;
			cnt[a[n - 1 - i]]--;
		}
		boolean ok = true;
		for (int i = 0; i < n; i++) {
			if (cnt[i] != 0) {
				ok = false;
			}
		}
		if (ok) {
			return r - mid;
		}
		Arrays.fill(cnt, 0);
		for (int i = l; i <= r; i++)
			cnt[a[i]]--;
		int totalNegative = 0;
		for (int i = 0; i < n; i++) {
			if (cnt[i] < 0) {
				totalNegative++;
			}
		}
		for (int i = l; i <= r; i++) {
			cnt[a[i]] += 2;
			if (cnt[a[i]] >= 0 && cnt[a[i]] - 2 < 0) {
				totalNegative--;
			}
			if (totalNegative == 0) {
				return r - i;
			}
		}
		return 0;
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
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
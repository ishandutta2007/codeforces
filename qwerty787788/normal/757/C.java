import java.io.*;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	void solve() {
		Random rnd = new Random();
		int n = in.nextInt();
		int m = in.nextInt();
		int[] count = new int[m];
		long[] vals = new long[m];
		for (int i = 0; i < n; i++) {
			int cnt = in.nextInt();
			int[] a = new int[cnt];
			long[] xors = new long[cnt];
			for (int j = 0; j < cnt; j++) {
				xors[j] = rnd.nextLong();
			}
			for (int j = 0; j < cnt; j++) {
				a[j] = in.nextInt() - 1;
				count[a[j]] = 0;
			}
			for (int j = 0; j < cnt; j++) {
				count[a[j]]++;
			}
			for (int j = 0; j < cnt; j++) {
				if (count[a[j]] != 0) {
					vals[a[j]] ^= xors[count[a[j]] - 1];
					count[a[j]] = 0;
				}
			}
		}
		Arrays.sort(vals);
		final int mod = (int) 1e9 + 7;
		int[] fact = new int[m + 1];
		fact[0] = 1;
		for (int i = 1; i <= m; i++) {
			fact[i] = (int) ((fact[i - 1] * 1L * i) % mod);
		}
		int res = 1;
		for (int i = 0; i < m;) {
			int j = i;
			while (j != m && vals[i] == vals[j]) {
				j++;
			}
			res = (int) ((res * 1L * fact[j - i]) % mod);
			i = j;
		}
		out.println(res);
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
		new C().runIO();
	}
}
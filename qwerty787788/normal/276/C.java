import java.io.*;
import java.util.*;

public class CFDiv1 {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();

		int[] sum = new int[n + 1];
		for (int i = 0; i < q; i++) {
			int l = in.nextInt() - 1;
			int r = in.nextInt();
			sum[l]++;
			sum[r]--;
		}
		int[] val = new int[n];
		int cur = 0;
		for (int i = 0; i < n; i++) {
			cur += sum[i];
			val[i] = cur;
		}
		Arrays.sort(val);
		Random rnd = new Random();
		for (int i = 0; i < n; i++) {
			int t = rnd.nextInt(i + 1);
			if (t != i) {
				int tmp = a[i];
				a[i] = a[t];
				a[t] = tmp;
			}
		}
		Arrays.sort(a);
		long ans = 0;
		for (int i = 0; i < n; i++)
			ans += a[i] * 1L * val[i];
		out.println(ans);
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
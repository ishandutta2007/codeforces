import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		if (sum % 3 != 0) {
			out.println(0);
			return;
		}
		sum /= 3;
		boolean[] canEndHere = new boolean[n];
		boolean[] canStartHere = new boolean[n];
		long curS = 0;
		for (int i = 0; i < n; i++) {
			curS += a[i];
			if (curS == sum) {
				canEndHere[i] = true;
			}
		}
		curS = 0;
		for (int i = n - 1; i >= 0; i--) {
			curS += a[i];
			if (curS == sum) {
				canStartHere[i] = true;
			}
		}
		long result = 0;
		long add = 0;
		for (int end = n - 1; end >=0; end--) {
			if (end + 2 < n && canStartHere[end + 2])
				add++;
			if (canEndHere[end]) {
				result += add;
			}
		}
		out.println(result);
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
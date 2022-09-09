import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		final int MAX = 7;
		ArrayList<Integer> all = new ArrayList<>();
		int[] f = new int[n + 1];
		Arrays.fill(f, Integer.MAX_VALUE);
		for (int st = 1; st < 1 << MAX; st++) {
			int number = 0;
			for (int i = 0; i < MAX; i++) {
				number = number * 10;
				if (((1 << i) & st) != 0) {
					number++;
				}
			}
			if (number <= n) {
				all.add(number);
			}
		}
		f[0] = 0;
		int[] last = new int[n + 1];
		for (int i = 0; i < n; i++) {
			for (int add : all) {
				if (i + add <= n && f[i + add] > f[i] + 1) {
					f[i + add] = f[i] + 1;
					last[i + add] = add;
				}
			}
		}
		out.println(f[n]);
		int cur = n;
		for (int i = 0; i < f[n]; i++) {
			out.print(last[cur]);
			cur -= last[cur];
			out.print(" ");
		}
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
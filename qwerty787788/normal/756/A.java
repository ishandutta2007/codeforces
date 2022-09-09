import java.io.*;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = in.nextInt() - 1;
		}
		int cycles = 0;
		boolean[] was = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (was[i]) {
				continue;
			}
			int cur = i;
			cycles++;
			while (!was[cur]) {
				was[cur] = true;
				cur = p[cur];
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += in.nextInt();
		}
		int res = 0;
		if (sum % 2 == 0) {
			res++;
		}
		if (cycles != 1) {
			res += cycles;
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
		new A().runIO();
	}
}
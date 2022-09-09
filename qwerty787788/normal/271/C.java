import java.io.*;
import java.util.*;

public class CF271 {
	FastScanner in;
	PrintWriter out;

	long mul = 37;
	int MAX = 2000;
	int[] pow = new int[MAX];
	long mod = (int) 1e9 + 7;
	int[] hash = new int[MAX];

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < k; i++) {
			if (i * 2 + 1 >= n) {
				out.println(-1);
				return;
			}
			a[i * 2] = i;
			a[i * 2 + 1] = i;
		}
		int curSt = k * 2;
		for (int i = 0; i < k; i++) {
			if (curSt + i >= n) {
				out.println(-1);
				return;
			}
			a[curSt + i] = i;
		}
		int i2 = k;
		while (curSt + i2  < n) {
			a[curSt+i2] = k - 1;
			i2++;
		}
		for (int i = 0; i < n; i++)
			out.print((a[i] + 1) + " ");
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
	}

	public static void main(String[] args) {
		new CF271().runIO();
	}
}
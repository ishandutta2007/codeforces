import java.io.*;
import java.util.*;

public class CF271 {
	FastScanner in;
	PrintWriter out;

	int MAX = (int) 1e6;

	void solve() {
		boolean[] isPrime = new boolean[MAX+1];
		Arrays.fill(isPrime, true);
		isPrime[1] = false;
		for (int i = 1; i < MAX; i++)
			if (isPrime[i])
				for (int j = 2; j * i <= MAX; j++)
					isPrime[j * i] = false;
		int n = in.nextInt();
		int m = in.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j =0; j < m; j++)
				a[i][j] = in.nextInt();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int add = 0;
				while (!isPrime[a[i][j] + add])
					add++;
				a[i][j] = add;
			}
		int ans = Integer.MAX_VALUE;
		for (int i =0; i < n; i++) {
			int curS = 0;
			for (int j = 0; j < m; j++)
				curS += a[i][j];
			ans = Math.min(ans, curS);
		}
		for (int j =0; j < m; j++) {
			int curS = 0;
			for (int i = 0; i < n; i++)
				curS += a[i][j];
			ans = Math.min(ans, curS);
		}
		out.println(ans);
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
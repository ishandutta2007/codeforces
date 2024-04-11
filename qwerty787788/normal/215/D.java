import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	long m;
	
	private long add(long t, long T, long x, long cost) {
		long min = cost;
		if (t + m > T) min += m * x;
		if (T > t) {
			long use = 1 + (m - 1) / (T - t);
			min = Math.min(min, use * cost);
			if (use > 2)
				min = Math.min(min, (use - 1) * cost + x * (m - (use - 2) * (T - t)));
		}
		return min;
	}
	
	public void solve() throws IOException {
		int n = in.nextInt();
		m = in.nextInt();
		long ans = 0;
		for (int i = 0; i < n; i++) {
			long t = in.nextInt();
			long T = in.nextInt();
			long x = in.nextInt();
			long cost = in.nextInt();
			ans += add(t, T, x, cost);
		}
		out.println(ans);
	}

	public void run() {
		try {
			//in = new FastScanner(new File("input.txt"));
			//out = new PrintWriter(new File("output.txt"));

			 in = new FastScanner(System.in);
			 out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}
import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		int m = in.nextInt();
		int[] b = new int[m];
		for (int i = 0; i < m; i++)
			b[i] = in.nextInt();
		int max = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if ((b[j] % a[i]) == 0)
					if (b[j] / a[i] > max)
						max = b[j] / a[i];
		int sum = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if ((b[j] % a[i]) == 0)
					if (b[j] / a[i] == max)
						sum++;
		out.println(sum);
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
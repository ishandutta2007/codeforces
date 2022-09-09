import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int n = in.nextInt();
		double Rout = 0;
		for (int i = 0; i < n; i++)
			Rout = Math.max(Rout, in.nextInt());
		int m = in.nextInt();
		double Roout = 0;
		for (int i = 0; i < m; i++)
			Roout = Math.max(Roout, in.nextInt());
		int k = in.nextInt();
		double Roin = Double.MAX_VALUE;
		for (int i = 0; i < k; i++)
			Roin = Math.min(Roin, in.nextInt());		
		int a = in.nextInt();
		int b = in.nextInt();
		double alpha = (a + 0.) / (b + 0.);
		double betta = Roout / Roin;
		double r = Rout / Math.sqrt(1. + alpha / betta);
		out.printf("%.10f", r);
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
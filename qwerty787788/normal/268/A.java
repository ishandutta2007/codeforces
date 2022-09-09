import java.io.*;
import java.util.*;

public class CFDIV2 {

	FastScanner in;
	PrintWriter out;

	void solve() throws Exception {
		int n = in.nextInt();
		int[] h = new int[n];
		int[] v = new int[n];
		for (int i= 0; i < n; i++) {
			h[i]= in.nextInt();
			v[i] = in.nextInt();
		}
		int ans = 0;
		for (int i =0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i != j)
					if (h[i] == v[j])
						ans++;
		out.println(ans);
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new CFDIV2().run();
	}
}
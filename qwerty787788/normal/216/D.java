import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;
	
	public void solve() throws IOException {
		int n = in.nextInt();
		long ans = 0;
		int[][] a = new int[n][];
		for (int i = 0; i < n; i++) {
			int k = in.nextInt();
			a[i] = new int[k];
			for (int j = 0; j < k; j++)
				a[i][j] = in.nextInt();
			Arrays.sort(a[i]);
		}
		for (int i = 0; i < n; i++) {
			if (a[i].length != 0) {
				int i1 = (i - 1 + n) % n;
				int i2 = (i + 1) % n;
				int it1 = 0;
				int it2 = 0;
				while (it1 < a[i1].length && a[i1][it1] <= a[i][0])
					it1++;
				while (it2 < a[i2].length && a[i2][it2] <= a[i][0])
					it2++;
				for (int j = 1; j < a[i].length; j++) {
					int s1 = 0;
					int s2 = 0;
					while (it1 < a[i1].length && a[i1][it1] <= a[i][j]) {
						if (a[i1][it1] != a[i][j]) s1++;
						it1++;
					}
					while (it2 < a[i2].length && a[i2][it2] <= a[i][j]) {
						if (a[i2][it2] != a[i][j]) s2++;
						it2++;
					}
					if (s1 != s2) ans++;
				}
			}
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

		String nextLine() {
			String s = null;
			try {
				s = br.readLine();
			} catch(IOException e) {
				e.printStackTrace();
			}
			return s;
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
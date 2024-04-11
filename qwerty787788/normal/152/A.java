import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		int a[][] = new int[n][m];
		int max[] = new int[m];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < s.length(); j++) {
				a[i][j] = (int)s.charAt(j);
			}
		}
		for (int i = 0; i < m; i++) {
			max[i] = 0;
			for (int j = 0; j < n; j++) {
				if (a[j][i] > max[i]) {
					max[i] = a[j][i];
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			boolean best = false;
			for (int j = 0; j < m; j++)
				if (max[j] == a[i][j]) best = true;
			if (best) ans++;
		}
		out.println(ans);
	}

	public void run() {
		try {
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
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}
import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int n = in.nextInt();
		int k = in.nextInt();
		int a[] = new int[n];
		int sum[] = new int[n + 1];
		HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int r = -1;
		int ok = 0;
		long ans = 0;
		for (int l = 0; l < n; l++) {
			if (l != 0) {
				int x = a[l - 1];
				int y = hm.get(x);
				hm.remove(x);
				sum[y]--;
				sum[y - 1]++;
				if (y == k) ok--;
				hm.put(x, y - 1);
			}
			while (r < n - 1 && ok == 0) {
				r++;
				int x = a[r];
				if (hm.containsKey(x)) {
					int y = hm.get(x);
					hm.remove(x);
					y++;
					if (y == k) ok++;
					sum[y - 1]--;
					sum[y]++;
					hm.put(x, y);
				} else {
					hm.put(x, 1);
					sum[1] ++;
					if (k == 1) ok++;
				}
			}
			if (r >= n || (r == n - 1 && ok == 0)) break;
			ans += (n - r);
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
					String s = br.readLine();
					if (s == null) return s;
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return null;
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}
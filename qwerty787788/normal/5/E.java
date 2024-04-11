import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;


	public void solve() throws IOException {
		int n = in.nextInt();
		int[] b = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = in.nextInt();
		int max = 0;
		for (int i = 0; i < n; i++)
			if (b[i] > b[max]) max = i;
		int[] a = new int[n];
		boolean[] saw = new boolean[n];
		for (int i = 0; i < n; i++)
			a[i] = b[(i + max) % n];
		long ans = 0;
		ArrayList<Integer> value = new ArrayList<Integer>();
		ArrayList<Integer> cnt = new ArrayList<Integer>();
		value.add(a[0]);
		cnt.add(1);
		for (int i = 1; i < n; i++) {
			int j = value.size() - 1;
			while (true) {
				if (value.get(j) < a[i]) {
					ans += cnt.get(j);
					value.remove(j);
					cnt.remove(j);
				} else
				if (value.get(j) > a[i]) {
					ans ++;
					value.add(a[i]);
					cnt.add(1);
					if (j == 0 && cnt.get(0) == 1) saw[i] = true;
					break;
				} else
				if (value.get(j) == a[i]) {
					ans += cnt.get(j);
					int cntNew = cnt.get(j) + 1;
					cnt.remove(j);
					cnt.add(cntNew);
					if (j != 0) ans ++;
					if (j == 0) saw[i] = true;
					if (j == 1 && cnt.get(0) == 1) saw[i] = true;
					break;
				}
				j--;
			}
		}
		int m = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (saw[i]) break; else {
				if (a[i] >= max) {
					ans++;
					max = a[i];
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
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}
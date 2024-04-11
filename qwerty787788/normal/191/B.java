import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;
	
	public void solve() throws IOException {
		int n = in.nextInt();
		int k = in.nextInt();
		long money = in.nextLong();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		int used = 0;
		int best = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			int add = a[i];
			if (money - add < 0) best = i;
			used++;
			if (k == 1) {
				add = 0;
			} else {
				if (used >= k) {
					int min = pq.peek();
					if (min < add) {
						pq.remove();
						pq.add(add);
						add = add - min;
					} else {
						add = 0;
					}
				} else {
					pq.add(add);
				}
			}
			money -= add;
		}
		out.println(best + 1);
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
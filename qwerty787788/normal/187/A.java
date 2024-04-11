import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int N;
	int arr[], a[];

	public void solve() throws IOException {
		N = in.nextInt();
		a = new int[N];
		arr = new int[N + 1];
		for (int i = 0; i < N; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < N; i++) {
			int x = in.nextInt();
			arr[x] = i + 1;
		}
		int sum = 0, now = -1;
		for (int i = 0; i < N; i++) {
			int t = arr[a[i]];
			if (t < now) break;
			now=t;
			sum++;
		}
		out.println(N - sum);
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
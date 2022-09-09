import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int h = in.nextInt();
		int m = in.nextInt();
		int n = in.nextInt();
		int[] hash = new int[h];
		for (int i = 0; i < h; i++)
			hash[i] = -1;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			String s = in.next();
			if (s.equals("-")) {
				int id = in.nextInt();
				for (int j = 0; j < h; j++)
					if (hash[j] == id) {
						hash[j] = -1;
						break;
					}
			} else {
				int id = in.nextInt();
				int v = (in.nextInt()) % h;
				while (hash[v] != -1) {
					v = (v + m) % h;
					ans++;
				}
				hash[v] = id;
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
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}
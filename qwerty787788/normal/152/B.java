import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		long n = in.nextInt();
		long m = in.nextInt();
		long x = in.nextInt();
		long y = in.nextInt();
		long k = in.nextInt();
		long ans = 0;
		for (int i = 0; i < k; i++) {
			long dx = in.nextInt();
			long dy = in.nextInt();
			long moves = (int) 1e9;
			if (x + dx * moves > n) {
				moves = (n - x) / dx;
			}
			if (x + dx * moves < 1) {
				moves = (x - 1) / (-dx);
			}
			if (y + dy * moves > m) {
				moves = (m - y) / dy;
			}
			if (y + dy * moves < 1) {
				moves = (y - 1) / (-dy);
			}
			ans += moves;
			x += dx * moves;
			y += dy * moves;
		}
		out.println(ans);
	}

	public void run() {
		try {
			//in = new FastScanner(new File("input.txt"));
			//out = new PrintWriter(new File("output.txt"));
			
			  in = new FastScanner(System.in); out = new
			  PrintWriter(System.out);
			 
			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		/*FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}*/

		
		  FastScanner(InputStream f) { br = new BufferedReader(new
		  InputStreamReader(f)); }
		 

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
import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	final long MAX = 1000000007;
	
	long binpow (long a, long n) {
		if (n == 0)
			return 1;
		if (n % 2 == 1)
			return ((binpow (a, n-1) % MAX) * a) % MAX;
		else {
			long b = binpow (a, n/2) % MAX;
			return (b * b) % MAX;
		}
	}
	
	public void solve() throws IOException {
		long N = in.nextLong();
		long ans;
		if (N == 0) ans = 1; else ans = (binpow(2, N - 1) % MAX) * ((1 + binpow(2, N)) % MAX); 
		out.println(ans % MAX);
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
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}
import java.io.*;
import java.util.*;

public class CF {

	long gcd(long x, long y) {
		return x == 0 ? y : gcd(y % x, x);
	}
	
	void solve() {
		int n = in.nextInt();
		long res = 0;
		long zn = 0;
		for (int i = 2; i <= n - 1; i++) {
			int cur = n;
			while (cur != 0) {
				res += cur % i;
				cur /= i;
			}
			zn++;
		}
		long g = gcd(res, zn);
		res /= g;
		zn /= g;
		out.println(res + "/" + zn);
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}
	
	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		solve();
		
		out.close();
	}

	public static void main(String[] args) {
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}
		
		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int len(long x) {
		if (x < 10) return 1; 
		return 1 + len(x / 10);
	}
	
	long pow(int x) {
		if (x < 1) return 1;
		long ans = 1;
		for (int i = 0; i < x; i++)
			ans *= 10;
		return ans;
	}
	
	long f_digit(long x) {
		if (x < 10) return x;
		return f_digit(x / 10);
	}
	
	long without_first(long x) {
		if (x < 10) return 1;
		long s = 1;
		long tmp = x;
		while (tmp != 0) {
			tmp /= 10;
			if (tmp != 0) s *= 10;
		}
		s *= f_digit(x);
		return x - s;
	}
	
	long f(long r) {
		if (r == 0) return 0;
		long sum = 0;
		int z = len(r);
		for (int i = 1; i < z; i++)
			sum += 9 * pow(i - 2);
		long x = f_digit(r);
		sum += (x - 1) * pow(z - 2);
		if (x <= r % 10) {
			if (r < 100) sum++; else
				sum += without_first(r / 10) + 1;
		} else {
			if (r >= 100)
				sum += without_first(r / 10);
		}
		return sum;
	}
	
	boolean ok(long x) {
		if (f_digit(x) == (x % 10)) return true;
		return false;
	}
	
	public void solve() throws IOException {
		long l = in.nextLong();
		long r = in.nextLong();
		out.println(f(r) - f(l - 1));
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
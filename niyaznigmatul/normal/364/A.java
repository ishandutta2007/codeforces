import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int a = nextInt();
		String s = nextToken();
		int[] count = new int[s.length() * 9 + 1];
		for (int i = 0; i < s.length(); i++) {
			int cur = 0;
			for (int j = i; j < s.length(); j++) {
				cur += s.charAt(j) - '0';
				count[cur]++;
			}
		}
		long ans = 0;
		if (a == 0) {
			out.println((long) count[0]
					* (s.length() * (s.length() + 1) - count[0]));
			return;
		} else {
			for (int i = 1; i < count.length; i++) {
				if (a % i != 0)
					continue;
				if (i <= a / i && a / i < count.length) {
					ans += (long) count[i] * count[a / i];
					if (i != a / i) {
						ans += (long) count[i] * count[a / i];
					}
				}
			}
		}
		out.println(ans);
	}

	public static void main(String[] args) throws Exception {
		File file = new File("a.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			// output = new PrintStream("a.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
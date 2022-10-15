import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int first = 0;
		int last = n;
		int[] ans = new int[n];
		int cn = 0;
		for (int i = 0; i < k - 1; i++) {
			if ((i & 1) == 0) {
				ans[cn++] = first++;
			} else {
				ans[cn++] = --last;
			}
		}
		if ((k & 1) == 0) {
			while (last > first) {
				ans[cn++] = --last;
			}
		} else {
			while (first < last) {
				ans[cn++] = first++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (i > 0)
				out.print(' ');
			out.print(ans[i] + 1);
		}
		out.println();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("a.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("a.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
		br.close();
	}

	static boolean hasNext() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String next() throws IOException {
		return hasNext() ? st.nextToken() : null;
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
}
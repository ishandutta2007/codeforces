import static java.lang.Math.abs;
import static java.lang.Math.min;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.*;
import java.util.Scanner;

public class A {
	void solve(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int[] b = a.clone();
		sort(b);
		{
			int last = b[0];
			int j = 1;
			for (int i = 1; i < n; i++) {
				if (last != b[i]) {
					b[j++] = b[i];
				}
				last = b[i];
			}
			b = copyOf(b, j);
		}
		int m = b.length;
		for (int i = 0; i < n; i++) {
			a[i] = binarySearch(b, a[i]);
		}
		long[] dp = new long[m];
		for (int i = 0; i < n; i++) {
			long[] next = new long[m];
			fill(next, Long.MAX_VALUE);
			long z = b[a[i]];
			for (int j = 0; j < m; j++) {
				if (j > 0) {
					next[j] = next[j - 1];
				}
				long cur = dp[j] + abs(z - b[j]);
				next[j] = min(next[j], cur);
			}
			dp = next;
		}
		long ans = Long.MAX_VALUE;
		for (int i = 0; i < m; i++) {
			ans = min(ans, dp[i]);
		}
		out.println(ans);
	}

	public static void main(String[] args) throws IOException {
		File file = new File("a.in");
		if (file.exists()) {
			System.setIn(new FileInputStream(file));
			System.setOut(new PrintStream(new File("a.out")));
		}
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		new A().solve(in, out);
		out.close();
	}
}
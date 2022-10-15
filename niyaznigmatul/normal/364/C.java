import java.io.*;
import java.util.*;

public class C {

	static int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19 };

	static void solve() throws IOException {
		int n = nextInt();
		for (int k = 2; k < primes.length; k++) {
			List<Integer>[] pows = new List[k];
			for (int i = 0; i < k; i++) {
				pows[i] = new ArrayList<>();
				int x = 1;
				while (x <= n * n) {
					pows[i].add(x);
					x *= primes[i];
				}
			}
			answer = new ArrayList<>();
			count = new int[k];
			zero = new boolean[k];
			go(0, k, n, pows, 1);
			if (answer.size() >= n) {
				for (int i : answer) {
					out.print(i + " ");
				}
				return;
			}
		}
		throw new AssertionError();
	}

	static List<Integer> answer;
	static boolean[] zero;
	static int[] count;

	static void go(int x, int k, int n, List<Integer>[] pows, long mul) {
		if (mul > 2 * n * n)
			return;
		if (x == k) {
			answer.add((int) mul);
			for (int i = 0; i < k; i++) {
				if (zero[i]) {
					++count[i];
				}
			}
			return;
		}
		for (int i = 0; i < k; i++) {
			if (zero[i] && (1 + count[i]) * 2 > n)
				return;
		}
		for (int i = 0; i < pows[x].size(); i++) {
			if (answer.size() >= n)
				return;
			if (i == 0) {
				zero[x] = true;
			} else {
				zero[x] = false;
			}
			go(x + 1, k, n, pows, mul * pows[x].get(i));
		}
	}

	public static void main(String[] args) throws Exception {
		File file = new File("c.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			// output = new PrintStream("c.out");
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
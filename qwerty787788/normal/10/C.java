import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		// for (int n = 1; n <= 100; n++) {
		int n = in.nextInt();
		int[] ans = new int[Math.max(100, n + 1)];
		for (int i = 0; i < 10; i++)
			ans[i] = i;
		for (int i = 1; i < Math.max(100, n + 1); i++) {
			ans[i] = ans[(ans[i / 10] + i % 10)];
		}
		int[] sum = new int[10];
		for (int i = 1; i <= n; i++)
			sum[ans[i]]++;
		long res = 0;
		for (int f = 1; f < 10; f++) {
			for (int s = 1; s < 10; s++) {
				long cur = sum[f];
				cur *= sum[s];
				int th = ans[f * s];
				cur *= sum[th];
				res += cur;
			}
		}
		for (int i = 1; i <= n; i++) {
			int max = n / i;
			res -= max;
		}
		// out.println(n + ": " + res);
		out.println(res);
		// }
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solve() {
		in = new InputReader(new File("object.in"));
		try {
			out = new PrintWriter(new File("object.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		realSolve();

		out.close();
	}

	void solveIO() {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	public static void main(String[] args) {
		new CF().solveIO();
	}
}
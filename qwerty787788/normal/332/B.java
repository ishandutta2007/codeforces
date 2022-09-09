import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		long[] sum = new long[n];
		for (int i = 0; i < n; i++)
			sum[i] = (i == 0 ? 0 : sum[i - 1]) + a[i];
		long[] maxK = new long[n];
		int[] fromK = new int[n];
		for (int i = k - 1; i < n; i++) {
			if (i >= k) {
				maxK[i] = maxK[i - 1];
				fromK[i] = fromK[i - 1];
			}
			long s1 = sum[i] - (i == k - 1 ? 0 : sum[i - k]);
			if (s1 > maxK[i]) {
				maxK[i] = s1;
				fromK[i] = i - k + 1;
			}
		}
		long bestSum = Long.MIN_VALUE;
		int bestFr1 = -1, bestFr2 = -1;
		for (int second = k; second + k <= n; second++) {
			long s1 = sum[second + k - 1] - sum[second - 1];
			long s2 = s1 + maxK[second - 1];
			if (s2 > bestSum) {
				bestSum = s2;
				bestFr1 = fromK[second - 1];
				bestFr2 = second;
			}
		}
		out.println((bestFr1 + 1) + " " + (bestFr2 + 1));
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
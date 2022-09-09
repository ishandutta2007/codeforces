import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		HashMap<Integer, Long> hm = new HashMap<>();
		HashMap<Integer, Integer> hm2 = new HashMap<>();
		long curSum = 0;
		long best = Long.MIN_VALUE;
		int bestFr = 0, bestTo = 0;
		for (int i = 0; i < n; i++) {
			Long x = hm.get(a[i]);
			if (x != null) {
				long cost = curSum + a[i] - x;
				if (a[i] < 0)
					cost += a[i];
				if (cost > best) {
					best = cost;
					bestFr = hm2.get(a[i]);
					bestTo = i;
				}
			}
			if (x == null || x > curSum) {
				hm.put(a[i], curSum);
				hm2.put(a[i], i);
			}
			if (a[i] > 0)
				curSum += a[i];
		}
		int rem = n - 2;
		for (int i = bestFr + 1; i <= bestTo - 1; i++) {
			if (a[i] > 0)
				rem--;
		}
		out.println(best + " " + rem);
		for (int i = 0; i < bestFr; i++)
			out.print((i + 1) + " ");
		for (int i = bestFr + 1; i <= bestTo - 1; i++)
			if (a[i] <= 0)
				out.print((i + 1) + " ");
		for (int i = bestTo + 1; i < n; i++)
			out.print((i + 1) + " ");
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
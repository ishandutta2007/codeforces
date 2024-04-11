import java.io.*;
import java.util.*;

public class CF {

	int[] b;
	long[] a;

	int[] next;
	int n;
	long result = Long.MAX_VALUE;

	void go(int v) {
		if (v == n) {
			long[] curA = new long[n];
			int[] curB = new int[n];
			for (int i = 0; i < n; i++) {
				curA[i] = a[i];
				curB[i] = b[i];
			}
			int cntMax = 0;
			long res = n;
			for (int i = 0; i < n; i++) {
				res += b[i] == 1 ? 0 : curB[i];
				if (next[i] == n) {
					cntMax++;
				} else {
					if (curA[next[i]] % a[i] != 0)
						return;
					curA[next[i]] /= a[i];
					curB[next[i]] -= b[i];
				}
			}
			if (cntMax != 1) {
				res++;
			}
			result = Math.min(result, res);
		} else {
			for (int i = v + 1; i <= n; i++) {
				next[v] = i;
				go(v + 1);
			}
		}
	}

	void realSolve() throws IOException {
		n = in.nextInt();
		a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextLong();
		Arrays.sort(a);
		b = new int[n];
		for (int i = 0; i < n; i++) {
			long tmp = a[i];
			for (int j = 2; j * 1L * j <= tmp; j++) {
				while (tmp % j == 0) {
					tmp /= j;
					b[i]++;
				}
			}
			if (tmp != 1)
				b[i]++;
		}
		next = new int[n];
		go(0);
		out.println(result);
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

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	void solve() throws IOException {
		in = new InputReader(new File("input.txt"));
		out = new PrintWriter(new File("output.txt"));

		realSolve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
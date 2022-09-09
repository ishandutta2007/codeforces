import java.io.*;
import java.util.*;

public class CF {

	Random rnd = new Random(123);

	int[] gen(int n) {
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = rnd.nextInt(1000) + 1;
		res[0] = 1;
		Arrays.sort(res);
		for (int i = 0; i < n / 2; i++) {
			res[i] ^= res[n - i - 1];
			res[n - i - 1] ^= res[i];
			res[i] ^= res[n - i - 1];
		}
		return res;
	}

	long res(long x, int[] a) {
		long res = 0;
		for (int i = 0; i < a.length; i++) {
			long sz = x / a[i];
			x -= sz * a[i];
			res += sz;
		}
		return res;
	}

	long sol(int[] a) {
		int n = a.length;
		long best = Long.MAX_VALUE;
		for (int i = 1; i < n; i++)
			for (int j = i; j < n; j++) {
				int need = a[i - 1] - 1;
				int cnt = 0;
				int sum = 0;
				for (int k = 0; k <= j; k++) {
					cnt += need / a[k];
					sum += a[k] * (need / a[k]);
					need %= a[k];
				}
				sum += a[j];
				cnt++;
				if (cnt < res(sum, a)) {
					best = Math.min(best, sum);
				}
			}
		return best == Long.MAX_VALUE ? -1 : best;
	}

	void realSolve() {
		
		  int n = in.nextInt(); int[] a = new int[n]; for (int i = 0; i < n ;i
		  ++) a[i] = in.nextInt(); out.println(sol(a));
		 /*
		while (true) {
			// int n = in.nextInt();
			int n = 5;
			int[] a = gen(n);// new int[n];

			// for (int i = 0; i < n; i++)
			// a[i] = in.nextInt();
			// for (int i = 0; i < n; i++) {
			// System.out.print(a[i] + " ");
			// }
			//System.out.println();
			int MAX = (int) 1e6;
			int[] dpOk = new int[MAX + 1];
			Arrays.fill(dpOk, Integer.MAX_VALUE / 2);
			dpOk[0] = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j <= MAX; j++)
					if (j + a[i] <= MAX)
						dpOk[j + a[i]] = Math.min(dpOk[j + a[i]], dpOk[j] + 1);
			int[] dpNotOk = new int[MAX + 1];
			Arrays.fill(dpNotOk, Integer.MAX_VALUE / 2);
			dpNotOk[0] = 0;
			for (int i = 1; i <= MAX; i++)
				for (int j = n - 1; j >= 0; j--)
					if (a[j] <= i)
						dpNotOk[i] = dpNotOk[i - a[j]] + 1;
			long ans = -1;
			boolean found = false;
			for (int i = 0; i <= MAX; i++)
				if (dpNotOk[i] != dpOk[i]) {
					// System.out.println(i);
					ans = i;
					found = true;
					break;
				}
			if (!found) {
				ans = -1;
			}
			// System.out.println(-1);
			long ans2 = sol(a);
			if (ans2 != ans) {
				System.err.println(ans2 + " " + ans);
				System.err.println(Arrays.toString(a));
				return;
			}
			System.err.println(rnd.nextBoolean());
		}
		*/
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
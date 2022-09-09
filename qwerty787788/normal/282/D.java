import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] a;
	int[] mul = new int[5];

	int st(int[] x) {
		int s = 0;
		for (int i = x.length - 1; i >= 0; i--) {
			s += x[i] * mul[i];
		}
		return s;
	}

	int st_3(int x1, int x2, int x3) {
		int s = x1 * mul[0] + x2 * mul[1] + x3 * mul[2];
		return s;
	}

	int st_2(int x1, int x2) {
		int s = x1 * mul[0] + x2 * mul[1];
		return s;
	}

	int st_1(int x1) {
		int s = x1 * mul[0];
		return s;
	}

	int n;

	boolean sol3(int[] a) {
		int total = 1;
		for (int i = 0; i < n; i++) {
			total *= a[i] + 1;
		}
		boolean[][] firstWin = new boolean[n + 2][total];

		for (int x1 = 0; x1 <= a[0]; x1++)
			for (int x2 = 0; x2 <= a[1]; x2++)
				for (int x3 = 0; x3 <= a[2]; x3++) {
					int st = st_3(x1, x2, x3);
					boolean canSub = true;
					if (x1 == 0 || x2 == 0 || x3 == 0)
						canSub = false;
					boolean w = false;
					if (canSub) {
						int st2 = st_3(x1 - 1, x2 - 1, x3 - 1);
						if (!firstWin[0][st2] || firstWin[n + 1][st2])
							w = true;
					}
					firstWin[n + 1][st] = w;

					if (x1 > 0) {
						int st2 = st_3(x1 - 1, x2, x3);
						if (!firstWin[0][st2] || firstWin[1][st2])
							w |= firstWin[1][st] = true;
					}
					if (x2 > 0) {
						int st2 = st_3(x1, x2 - 1, x3);
						if (!firstWin[0][st2] || firstWin[2][st2])
							w |= firstWin[2][st] = true;
					}
					if (x3 > 0) {
						int st2 = st_3(x1, x2, x3 - 1);
						if (!firstWin[0][st2] || firstWin[3][st2])
							w |= firstWin[3][st] = true;
					}
					firstWin[0][st] = w;
				}
		return (firstWin[0][total - 1]);
	}

	boolean sol2(int[] a) {
		int total = 1;
		for (int i = 0; i < n; i++) {
			total *= a[i] + 1;
		}
		boolean[][] firstWin = new boolean[n + 2][total];

		for (int x1 = 0; x1 <= a[0]; x1++)
			for (int x2 = 0; x2 <= a[1]; x2++) {
				int st = st_2(x1, x2);
				boolean canSub = true;
				if (x1 == 0 || x2 == 0)
					canSub = false;
				boolean w = false;
				if (canSub) {
					int st2 = st_2(x1 - 1, x2 - 1);
					if (!firstWin[0][st2] || firstWin[n + 1][st2])
						w = true;
				}
				firstWin[n + 1][st] = w;

				if (x1 > 0) {
					int st2 = st_2(x1 - 1, x2);
					if (!firstWin[0][st2] || firstWin[1][st2])
						w |= firstWin[1][st] = true;
				}
				if (x2 > 0) {
					int st2 = st_2(x1, x2 - 1);
					if (!firstWin[0][st2] || firstWin[2][st2])
						w |= firstWin[2][st] = true;
				}

				firstWin[0][st] = w;
			}
		return (firstWin[0][total - 1]);
	}

	boolean sol1(int[] a) {
		int total = 1;
		for (int i = 0; i < n; i++) {
			total *= a[i] + 1;
		}
		boolean[][] firstWin = new boolean[n + 2][total];

		for (int x1 = 0; x1 <= a[0]; x1++) {
			int st = st_1(x1);
			boolean canSub = true;
			if (x1 == 0)
				canSub = false;
			boolean w = false;
			if (canSub) {
				int st2 = st_1(x1 - 1);
				if (!firstWin[0][st2] || firstWin[n + 1][st2])
					w = true;
			}
			firstWin[n + 1][st] = w;

			if (x1 > 0) {
				int st2 = st_1(x1 - 1);
				if (!firstWin[0][st2] || firstWin[1][st2])
					w |= firstWin[1][st] = true;
			}

			firstWin[0][st] = w;
		}
		return (firstWin[0][total - 1]);
	}

	void solve() {

		n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		// int[] mul = new int[n];
		mul[n - 1] = 1;
		for (int i = n - 1; i > 0; i--) {
			mul[i - 1] = mul[i] * (a[i] + 1);
		}
		boolean sol = false;
		if (n == 3) {
			sol = sol3(a);
		}
		if (n == 2) {
			sol = sol2(a);
		}
		if (n == 1) {
			sol = sol1(a);
		}
		if (sol)
			out.println("BitLGM");
		else
			out.println("BitAryo");
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
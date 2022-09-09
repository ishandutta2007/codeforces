import java.io.*;
import java.util.*;

public class CF {

	int MAX = (int) 1e6;
	int[] MAX_DIGIT = new int[MAX + 1];
	int[][][] ans1 = new int[2][10][MAX + 1]; // (cnt; res)

	void precalc() {
		for (int i = 0; i <= MAX; i++)
			MAX_DIGIT[i] = Math.max(i % 10, MAX_DIGIT[i / 10]);
		for (int maxDigit = 1; maxDigit < 10; maxDigit++) {
			Arrays.fill(ans1[0][maxDigit], Integer.MAX_VALUE);
			for (int val = 0; val <= MAX; val++) {
				int nextVal = val - Math.max(maxDigit, MAX_DIGIT[val]);
				if (nextVal < 0) {
					ans1[0][maxDigit][val] = 1;
					ans1[1][maxDigit][val] = nextVal;
				} else {
					ans1[0][maxDigit][val] = 1 + ans1[0][maxDigit][nextVal];
					ans1[1][maxDigit][val] = ans1[1][maxDigit][nextVal];
				}
			}
		}
	}

	long getAns2(int xx) {
		int[] ans = new int[xx + 1];
		Arrays.fill(ans, Integer.MAX_VALUE / 2);
		ans[0] = 0;
		for (int i = 1; i <= xx; i++) {
			String s = Integer.toString(i);
			for (int x = 0; x < s.length(); x++) {
				int z = s.charAt(x) - '0';
				ans[i] = Math.min(ans[i], 1 + ans[i - z]);
			}
		}
		return ans[xx];
	}

	long getAns(int h1, int h2) {
		long res = 0;
		while (h1 > 0) {
			res += ans1[0][MAX_DIGIT[h1]][h2];
			h2 = (int) ans1[1][MAX_DIGIT[h1]][h2];
			h1--;
			if (h2 < 0)
				h2 += MAX;
		}
		while (h2 > 0) {
			res++;
			h2 -= MAX_DIGIT[h2];
		}
		return res;
	}

	void realSolve() {
		// long st = System.currentTimeMillis();
		precalc();
		// System.err.println(System.currentTimeMillis() - st);
		// for (int x = 0 * (int) (1e6) - 0; x <= 1e7; x++) {
		// System.err.println(x);
		// long x = (long) 1e12;
		long x = in.nextLong();
		// long x = in.nextLong();
		long h1 = x / 1000000;
		long h2 = x % 1000000;
		long v1 = getAns((int) h1, (int) h2);
		// long v2 = getAns2((int) x);
		// long v2 = 0;
		// if (v1 != v2) {
		// System.err.println(x + " " + v1 + " " + v2);
		out.println(v1);
		// throw new AssertionError(x + " " + v1 + " " + v2);
		// }

		// out.println(getAns((int) h1, (int) h2) + " " + getAns2((int) x));
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
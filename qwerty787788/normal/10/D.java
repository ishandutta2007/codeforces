import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		int m = in.nextInt();
		int[] b = new int[m];
		for (int i = 0; i < m; i++)
			b[i] = in.nextInt();
		int[][] dp = new int[n + 1][m + 1];
		int[][] type = new int[n + 1][m + 1];
		int[][] type2 = new int[n + 1][m + 1];
		HashMap<Integer, Integer> hm = new HashMap<>();
		for (int i = 0; i < n; i++) {
			hm.clear();
			for (int j = 0; j < m; j++) {
				if (a[i] == b[j]) {
					dp[i + 1][j + 1] = 1;
					type[i + 1][j + 1] = -1;
					for (int last = 0; last < i; last++) {
						if (a[last] >= a[i])
							continue;
						Integer cc = hm.get(a[last]);
						if (cc != null) {
							if (dp[last + 1][cc + 1] + 1 > dp[i + 1][j + 1]) {
								dp[i + 1][j + 1] = dp[last + 1][cc + 1] + 1;
								type[i + 1][j + 1] = last;
								type2[i + 1][j + 1] = cc;
							}
						}
					}
				}
				hm.put(b[j], j);
			}
		}
		int maxI = -1, maxJ = -1;
		int maxLen = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (dp[i + 1][j + 1] > maxLen) {
					maxLen = dp[i + 1][j + 1];
					maxI = i + 1;
					maxJ = j + 1;
				}
		out.println(maxLen);
		int curI = maxI;
		int curJ = maxJ;
		ArrayList<Integer> ans = new ArrayList<>();
		while (maxLen > 0) {
			ans.add(a[curI - 1]);
			int ni = type[curI][curJ] + 1;
			int nj = type2[curI][curJ] + 1;
			curI = ni;
			curJ = nj;
			maxLen--;
		}
		for (int i = ans.size() - 1; i >= 0; i--) {
			out.print(ans.get(i) + " ");
		}
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
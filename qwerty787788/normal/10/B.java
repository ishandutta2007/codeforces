import java.io.*;
import java.util.*;

public class CF {

	long sum(int fr, int to, int cx) {
		if (to < fr)
			return 0;
		int res = 0;
		if (to <= cx || fr >= cx) {
			res = Math.abs(cx - fr) + Math.abs(cx - to);
			res *= to - fr + 1;
			return res / 2;
		}
		return sum(fr, cx, cx) + sum(cx + 1, to, cx);
	}

	void realSolve() {
		int n = in.nextInt();
		int k = in.nextInt();
		boolean[][] f = new boolean[k][k];
		int[][] maxFree = new int[k][k + 1];
		for (int i = 0; i < k; i++) {
			for (int j = k - 1; j >= 0; j--) {
				maxFree[i][j] = maxFree[i][j + 1] + 1;
			}
		}

		for (int i = 0; i < n; i++) {
			int bestR = -1, bestL = -1;
			long bestF = Long.MAX_VALUE;
			int m = in.nextInt();
			int xc = k / 2;
			for (int row = 0; row < k; row++)
				for (int col = 0; col < k; col++)
					if (maxFree[row][col] >= m) {
						long ff = m * Math.abs(row - xc);
						ff += sum(col, col + m - 1, xc);
						boolean ok = false;
						if (ff < bestF)
							ok = true;
						if (ff == bestF) {
							if (row < bestR) {
								ok = true;
							}
							if (row == bestR) {
								if (col < bestL) {
									ok = true;
								}
							}
						}
						if (ok) {
							bestF = ff;
							bestL = col;
							bestR = row;
						}
					}
			if (bestR == -1) {
				out.println(-1);
			} else {
				out.println((bestR + 1) + " " + (bestL + 1) + " " + (bestL + m));
				for (int ii = bestL; ii < bestL + m; ii++)
					maxFree[bestR][ii] = 0;
				for (int ii = bestL - 1; ii >= 0; ii--)
					maxFree[bestR][ii] = Math.min(maxFree[bestR][ii], maxFree[bestR][ii + 1] + 1);
			}
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
import java.io.*;
import java.util.*;

public class CF {

	void realSolve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		boolean[] row = new boolean[n];
		boolean[] col = new boolean[n];
		Arrays.fill(row, true);
		Arrays.fill(col, true);
		for (int i = 0; i < m; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			row[x] = false;
			col[y] = false;
		}
		int res = 0;
		for (int i = 1; i < n / 2; i++) {
			boolean r1 = row[i];
			boolean r2 = row[n - i - 1];
			boolean c1 = col[i];
			boolean c2 = col[n - i - 1];
			if (r1)
				res++;
			if (c1)
				res++;
			if (r2)
				res++;
			if (c2)
				res++;

		}
		if (n % 2 == 1) {
			if (row[n / 2] || col[n / 2])
				res++;
		}
		out.println(res);
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

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {

	void realSolve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = in.nextInt();
		int l = 0, r = (int) 1e9 + 10;
		int[][] id = new int[m][m];
		int it=0;
		while (r - l > 1) {
			it++;
			int med = (l + r) / 2;
			boolean ok = false;
			for (int i = 0; i < n; i++) {
				ArrayList<Integer> all = new ArrayList<>();
				for (int j = 0; j < m; j++)
					if (a[i][j] >= med)
						all.add(j);
				for (int x = 0; x < all.size(); x++) {
					if (ok)
						break;
					for (int y = x + 1; y < all.size(); y++) {
						if (id[all.get(x)][all.get(y)] == it) {
							ok = true;
							break;
						}
						id[all.get(x)][all.get(y)] = it;
					}
				}
			}
			if (ok)
				l = med;
			else
				r = med;
		}
		out.println(l);
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
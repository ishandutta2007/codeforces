import java.io.*;
import java.util.*;

public class CF {

	int[] dx = { -1, 0, 0, 1 };
	int[] dy = { 0, -1, 1, 0 };

	void realSolve() {
		int n = in.nextInt();
		int m = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++)
			s[i] = in.next();
		int xs = -1;
		int ys = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (s[i].charAt(j) == 'E') {
					xs = i;
					ys = j;
				}
		int[][] h = new int[n][m];
		for (int i = 0; i < n; i++)
			Arrays.fill(h[i], Integer.MAX_VALUE / 2);
		ArrayList<Integer> qx = new ArrayList<>();
		ArrayList<Integer> qy = new ArrayList<>();
		qx.add(xs);
		qy.add(ys);
		int it = 0;
		h[xs][ys] = 0;
		while (it < qx.size()) {
			int x = qx.get(it);
			int y = qy.get(it++);
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < n)
					if (ny >= 0 && ny < m)
						if (h[nx][ny] == Integer.MAX_VALUE / 2
								&& s[nx].charAt(ny) != 'T') {
							h[nx][ny] = h[x][y] + 1;
							qx.add(nx);
							qy.add(ny);
						}
			}
		}
		int res = 0;
		int need = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (s[i].charAt(j) == 'S')
					need = h[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (s[i].charAt(j) >= '0' && s[i].charAt(j) <= '9')
					if (h[i][j] <= need)
						res += s[i].charAt(j) - '0';
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
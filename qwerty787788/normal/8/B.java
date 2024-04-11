import java.io.*;
import java.util.*;

public class CF {

	int MAX = 110;
	boolean[][] f = new boolean[MAX * 2][MAX * 2];
	String move = "UDLR";
	int[] dx = { 0, 0, -1, 1 };
	int[] dy = { 1, -1, 0, 0 };

	void realSolve() {
		String s = in.next();
		int x = MAX, y = MAX;
		f[x][y] = true;
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			int id = move.indexOf(c);
			x += dx[id];
			y += dy[id];
			f[x][y] = true;
		}
		int[][] len = new int[MAX * 2][MAX * 2];
		for (int i = 0; i < len.length; i++)
			Arrays.fill(len[i], Integer.MAX_VALUE / 2);
		len[MAX][MAX] = 0;
		int it = 0;
		ArrayList<Integer> qx = new ArrayList<>();
		ArrayList<Integer> qy = new ArrayList<>();
		qx.add(MAX);
		qy.add(MAX);
		while (it < qx.size()) {
			int cx = qx.get(it);
			int cy = qy.get(it++);
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (f[nx][ny] && len[nx][ny] == Integer.MAX_VALUE / 2) {
					qx.add(nx);
					qy.add(ny);
					len[nx][ny] = len[cx][cy] + 1;
				}
			}
		}
		out.println(len[x][y] == s.length() ? "OK" : "BUG");
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
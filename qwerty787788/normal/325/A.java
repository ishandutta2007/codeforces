import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		int n = in.nextInt();
		long minX = Long.MAX_VALUE;
		long minY = Long.MAX_VALUE;
		long maxX = Long.MIN_VALUE;
		long maxY = Long.MIN_VALUE;
		long s = 0;
		for (int i = 0; i < n; i++) {
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			int x2 = in.nextInt();
			int y2 = in.nextInt();
			minX = Math.min(minX, x1);
			minY = Math.min(minY, y1);
			maxX = Math.max(maxX, x2);
			maxY = Math.max(maxY, y2);
			s += (x2 - x1) * 1L * (y2 - y1);
		}
		long s1 = maxX - minX;
		long s2 = maxY - minY;
		if (s1 != s2 || s1 * s2 != s) {
			out.println("NO");
		} else {
			out.println("YES");
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
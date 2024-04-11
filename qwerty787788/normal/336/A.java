import java.io.*;
import java.util.*;

public class CF {

	void realSolve() throws IOException {
		int x = in.nextInt();
		int y = in.nextInt();
		int z = Math.abs(x) + Math.abs(y);
		if (x > 0 && y > 0) {
			out.println("0 " + z + " " + z + " 0");
			return;
		}
		if (x < 0 && y > 0) {
			out.println(-z + " 0 0 " + z);
			return;
		}
		if (x > 0 && y < 0 ) {
			out.println("0 " + (-z) + " " + z + " 0");
			return;
		}
		if (x < 0 && y < 0) {
			out.println(-z + " 0 0 " + (-z));
			return;
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
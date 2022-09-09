import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		String s = in.next();
		String ans = in.next();
		char[] res = new char[s.length()];
		int it = 0;
		boolean[] was = new boolean[s.length()];
		boolean f = false;
		for (int id = 1; id < 10; id++) {
			for (int i = 0; i < s.length(); i++)
				if (s.charAt(i) == ('0' + id))
					if (!f) {
						res[it++] = (char) ('0' + id);
						f = true;
						was[i] = true;
					}
		}
		for (int id = 0; id < 10; id++)
			for (int i = 0; i < s.length(); i++)
				if (s.charAt(i) == ('0' + id))
					if (!was[i])
						res[it++] = s.charAt(i);
		String ok = new String(res);
		if (ok.equals(ans)) {
			out.println("OK");
		} else {
			out.println("WRONG_ANSWER");
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
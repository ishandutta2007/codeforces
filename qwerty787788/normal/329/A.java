import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		int n = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.next();
		}
		int bad = 0;
		for (int i = 0; i < n; i++) {
			boolean ok = false;
			for (int j = 0; j < n; j++)
				if (s[i].charAt(j) == '.')
					ok = true;
			if (!ok)
				bad |= 1;
		}
		for (int i = 0; i < n; i++) {
			boolean ok = false;
			for (int j = 0; j < n; j++)
				if (s[j].charAt(i) == '.')
					ok = true;
			if (!ok)
				bad |= 2;
		}
		if (bad == 3) {
			out.println(-1);
			return;
		}
		if (bad == 0 || bad == 1) {
			for (int i = 0; i < n; i++) {
				int f = -1;
				for (int j = 0; j < n; j++) {
					if (s[j].charAt(i) == '.')
						f = j;
				}
				out.println((f + 1) + " " + (i + 1));
			}
		} else {
			for (int i = 0; i < n; i++) {
				int f = -1;
				for (int j = 0; j < n; j++) {
					if (s[i].charAt(j) == '.')
						f = j;
				}
				out.println((i + 1) + " " + (f + 1));
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
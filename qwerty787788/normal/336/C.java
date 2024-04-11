import java.io.*;
import java.util.*;

public class CF {

	void realSolve() throws IOException {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int v = 31; v >= 0; v--) {
			int need = 1 << v;
			int res = -1;
			for (int i = 0; i < n; i++) {
				if ((need & a[i]) != 0) {
					res &= a[i];
				}
			}
			int canT = need - 1;
			canT &= res;
			int res2 = -1;
			ArrayList<Integer> result = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if ((need & a[i]) != 0 && ((canT & a[i]) == 0)) {
					res2 &= a[i];
					result.add(a[i]);
				}
			}
			if (res2 != 0 && res2 != -1) {
				out.println(result.size());
				for (int x = 0; x < result.size(); x++) {
					out.print(result.get(x) + " ");
				}
				return;
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
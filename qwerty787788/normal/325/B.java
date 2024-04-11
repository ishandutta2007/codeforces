import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		long n = in.nextLong();
		long add = 1;
		ArrayList<Long> ans = new ArrayList<>();
		while (add <= n + 1) {
			long l = 0, r = (long) 2e9 + 1000;
			while (r - l > 1) {
				long m = (l + r) / 2;
				double ss = (add - 1 + (m - 1) / 2) * 1. * m;
				boolean biggerOrEq = false;
				if (ss > n * 2) {
					biggerOrEq = true;
				} else {
					long ss2 = (add - 1 + (m - 1) / 2) * m;
					if (ss2 >= n)
						biggerOrEq = true;
				}
				if (biggerOrEq) {
					r = m;
				} else {
					l = m;
				}
			}
			if (r % 2 != 0) {
				if (r * ((r - 1) / 2 + add - 1) == n) {
					ans.add(r * add);
				}
			}
			add *= 2;
		}
		Collections.sort(ans);
		if (ans.size() == 0) {
			out.println(-1);
		} else {
			for (long x : ans) {
				out.println(x);
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
import java.io.*;
import java.util.*;

public class CF {
	
	int ans(int x) {
		if (x == 0)
			return 0;
		if (x == 2)
			return 3;
		if (x % 2 == 0) {
			for (int i = 1; i <= x; i++) {
				if (i % 4 == 0 || i % 4 == 1) {
					if (i * (i - 1) / 2 >= x)
						return i - 1;
				}
			}
		}
		for (int i = 1; i <= x; i++) {
			if (i % 4 == 1 || i % 4 == 2) {
				if (i * (i + 1) / 2 >= x)
					return i;
			}
		}
		return 0;
	}

	void realSolve() {
		int x = Math.abs(in.nextInt());
		out.print(ans(x));
		/*
		if (x == 0) {
			out.println(0);
		} else {
			TreeSet<Integer> can = new TreeSet<>();
			TreeSet<Integer> was = new TreeSet<>();
			can.add(0);
			for (int move = 1; move < 40; move++) {
				TreeSet<Integer> can2 = new TreeSet<>();
				for (int xx : can) {
					can2.add(xx - move);
					can2.add(xx + move);
				}
				can = can2;
				out.print(move + "( " + move * (move + 1) / 2 + "): ");
				for (int xx : can2) {
					if (xx >= 0) {
						if (!was.contains(xx)) {
							out.print(xx + " ");
							was.add(xx);
							ans[xx] = move;
						}
					}
				}
				out.println();
			}
		}
		for (int i = 1; i <= 100; i+=2) {
			out.println(i + ": " + (ans[i]-ans(i)));
		}
		*/
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
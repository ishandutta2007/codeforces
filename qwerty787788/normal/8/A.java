import java.io.*;
import java.util.*;

public class CF {

	int[] prefixFunction(String s) {
		int n = s.length();
		int[] res = new int[n];
		for (int i = 1; i < n; i++) {
			int j = res[i - 1];
			while (j > 0 && s.charAt(j) != s.charAt(i))
				j = res[j - 1];
			if (s.charAt(i) == s.charAt(j))
				j++;
			res[i] = j;
		}
		return res;
	}

	boolean canForward(String s, String first, String second) {
		int[] p1 = prefixFunction(first + "#" + s);
		int firstPos = -1;
		for (int i = first.length() + 1; i < p1.length; i++)
			if (p1[i] == first.length()) {
				firstPos = i - first.length();
				break;
			}
		int[] p2 = prefixFunction(second + "#" + s);
		int secondPos = -1;
		for (int i = second.length() + 1; i < p2.length; i++)
			if (p2[i] == second.length()) {
				secondPos = i - second.length();
			}
		if (firstPos == -1 || secondPos == -1)
			return false;
		return secondPos - second.length() >= firstPos;
	}

	void realSolve() {
		String s = in.next();
		String first = in.next();
		String second = in.next();
		boolean forward = canForward(s, first, second);
		boolean backward = canForward(
				new StringBuilder(s).reverse().toString(), first, second);
		if (!forward && !backward) {
			out.println("fantasy");
		} else {
			if (forward && backward) {
				out.println("both");
			} else {
				if (forward) {
					out.println("forward");
				} else {
					out.println("backward");
				}
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
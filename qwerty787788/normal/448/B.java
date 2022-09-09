import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	boolean onlyRemove(String s, String t) {
		int it = 0;
		for (int i = 0; i < t.length(); i++) {
			while (it != s.length() && s.charAt(it) != t.charAt(i))
				it++;
			if (it == s.length())
				return false;
			it++;
		}
		return true;
	}

	boolean onlySwap(String s, String t) {
		if (s.length() != t.length())
			return false;
		int[] a = new int[1000];
		for (int i = 0; i < s.length(); i++)
			a[s.charAt(i)]++;
		for (int i = 0; i < t.length(); i++)
			a[t.charAt(i)]--;
		for (int i = 0; i < 1000; i++)
			if (a[i] != 0)
				return false;
		return true;
	}

	boolean SwapAndDel(String s, String t) {
		int[] a = new int[1000];
		for (int i = 0; i < s.length(); i++)
			a[s.charAt(i)]++;
		for (int i = 0; i < t.length(); i++)
			a[t.charAt(i)]--;
		for (int i = 0; i < 1000; i++)
			if (a[i] < 0)
				return false;
		return true;
	}

	void solve() {
		String s = in.next(), t = in.next();
		if (onlyRemove(s, t)) {
			out.println("automaton");
		} else {
			if (onlySwap(s, t)) {
				out.println("array");
			} else {
				if (SwapAndDel(s, t)) {
					out.println("both");
				} else {
					out.println("need tree");
				}
			}
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
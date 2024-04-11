import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt() + 1;
		String[] s = new String[n];
		s[0] = "<3";
		for (int i = 1; i < n; i++)
			s[i] = in.next() + "<3";
		String ss = in.next();
		int it = 0;
		for (int i1 = 0; i1 < n; i1++)
			for (int i2 = 0; i2 < s[i1].length(); i2++) {
				char c = s[i1].charAt(i2);
				while (it < ss.length() && ss.charAt(it) != c)
					it++;
				if (it == ss.length()) {
					out.println("no");
					return;
				}
it++;
			}
		out.println("yes");
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
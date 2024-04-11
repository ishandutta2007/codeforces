import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		String s = in.next();
		int n = s.length();
		int min = 1;
		for (int i = 1; i < n; i++) {
			if (s.charAt(i) == '0') {
				int j = i;
				while (j < n && s.charAt(j) == '0')
					j++;
				int len = j - i + 1;
				int curLen = i - 1;
				if (len > curLen
						|| (len == curLen && s.charAt(0) < s.charAt(i - 1))) {
					min = j;
				}
				i = j - 1;
			} else {
				if (i == 1 && s.charAt(i) > s.charAt(0)) {
					min++;
				}
			}
		}
		int ans = 1;
		for (int i = min; i < n; i++)
			if (s.charAt(i) != '0')
				ans++;
		out.println(ans);
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
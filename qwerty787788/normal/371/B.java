import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int a = in.nextInt();
		int b = in.nextInt();
		int cA = a;
		int[] t = new int[] { 2, 3, 5 };
		for (int j = 0; j < 3; j++)
			while (cA % t[j] == 0)
				cA /= t[j];
		int cB = b;
		for (int j = 0; j < 3; j++)
			while (cB % t[j] == 0)
				cB /= t[j];
		if (cA != cB) {
			out.println(-1);
			return;
		}
		int res = 0;
		for (int j = 0; j < 3; j++) {
			int f1 = 0;
			while (a % t[j] == 0) {
				a /= t[j];
				f1++;
			}
			int f2 = 0;
			while (b % t[j] == 0) {
				b /= t[j];
				f2++;
			}
			res += Math.abs(f1 - f2);
		}
		out.println(res);
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
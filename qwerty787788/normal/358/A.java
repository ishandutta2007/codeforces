import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt() ;
		int[] x = new int[n];
		for (int i = 0; i < n; i++)
			x[i] = in.nextInt();
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - 1; j++) {
				int x1 = x[i], x2 = x[i + 1];
				int y1 = x[j], y2 = x[j + 1];
				if (x1 > x2) {
					int tmp = x1;
					x1 = x2;
					x2 = tmp;
				}
				if (y1 > y2) {
					int tmp = y1;
					y1 = y2;
					y2 = tmp;
				}
				if (x1> y1 && x1 < y2 && (x2 < y1 || x2 > y2)) {
					out.println("yes");
					return;
				}
				if (x2 > y1 && x2 < y2 && (x1 < y1 || x1 > y2)) {
					out.println("yes");
					return;
				}
			}
		out.println("no");
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
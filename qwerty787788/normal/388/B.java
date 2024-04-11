import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int k = in.nextInt();
		int maxBit = 0;
		for (int i = 0; i < 31; i++)
			if (((1 << i) & k) != 0)
				maxBit = i;
//		System.err.println(maxBit);
		ArrayList<Integer> cur1 = new ArrayList<>();
		ArrayList<Integer> cur2 = new ArrayList<>();
		ArrayList<Integer> cur3 = new ArrayList<>();
		int it = 2;
		cur1.add(it++);
		cur2.add(it++);
		cur3.add(it++);
		int MAX = 100;
		boolean[][] g = new boolean[MAX][MAX];
		g[0][2] = g[0][3] = g[0][4] = true;
		for (int i = maxBit - 1; i >= 0; i--) {
			// if (((1<<i)&k) == 0) {
			g[cur1.get(cur1.size() - 1)][it] = true;
			g[cur1.get(cur1.size() - 1)][it + 1] = true;
			g[cur2.get(cur2.size() - 1)][it] = true;
			g[cur2.get(cur2.size() - 1)][it + 1] = true;
			if (((1 << i) & k) != 0) {
				g[cur3.get(cur3.size() - 1)][it] = true;
				g[cur3.get(cur3.size() - 1)][it + 1] = true;
			}
			g[cur3.get(cur3.size() - 1)][it + 2] = true;
			cur1.add(it++);
			cur2.add(it++);
			cur3.add(it++);
			// }
		}
		g[cur1.get(cur1.size() - 1)][1] = true;
		out.println(it);
		for (int i = 0; i < it; i++) {
			for (int j = 0; j < it; j++) {
				if (g[i][j] || g[j][i]) {
					out.print("Y");
				} else {
					out.print("N");
				}
			}
			out.println();
		}
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
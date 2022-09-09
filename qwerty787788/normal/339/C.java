import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		String s = in.next();
		int m = in.nextInt();
		int[][][] last = new int[11][10][m];
		int[][][] was =new int[11][10][m];
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 10; j++)
				Arrays.fill(last[i][j], -1);
		for (int i = 0; i < 10; i++) {
			if (s.charAt(i) == '1') {
				last[i + 1][i][0] = i;
			}
		}
		for (int i = 0; i < m - 1; i++) {
			for (int diff = 1; diff <= 10; diff++) {
				for (int last1 = 0; last1 < 10; last1++)
					if (last[diff][last1][i] != -1) {
						for (int next = 0; next < 10; next++)
							if (s.charAt(next) == '1')
								if (next != last1) {
									int newSum = diff - next - 1;
									if (newSum < 0) {
										last[-newSum][next][i + 1] = diff;
										was[-newSum][next][i + 1] = last1;
									}
								}
					}
			}
		}
		for (int diff = 1; diff < 11; diff++)
			for (int last1 = 0; last1 < 10; last1++)
				if (last[diff][last1][m - 1] != -1) {
					out.println("YES");
					ArrayList<Integer> ans = new ArrayList<>();
					for (int cur = m - 1; cur >= 0; cur--) {
						ans.add(last1 + 1);
						int was1 = was[diff][last1][cur];
						int diff2 = last[diff][last1][cur];
						diff = diff2;
						last1 = was1;
					}
					for (int i = ans.size() - 1; i >= 0; i--) {
						out.print(ans.get(i) + " ");
					}
					return;
				}
		out.println("NO");
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
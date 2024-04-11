import java.io.*;
import java.util.*;

public class CF {

	ArrayList<Integer> g = new ArrayList<>();

	int MAX = 50;
	ArrayList<Integer>[] hs = new ArrayList[MAX];
	int[] add = { 0, 4, 7 };

	void go(int curSum) {
		if (g.size() == 6) {
			if (hs[curSum] != null)
				return;
			ArrayList<Integer> tmp = new ArrayList<>();
			for (int x : g)
				tmp.add(x);
			hs[curSum] = tmp;
		} else {
			for (int i = 0; i < 3; i++) {
				g.add(add[i]);
				go(curSum + add[i]);
				g.remove(g.size() - 1);
			}
		}
	}

	void solve() {
		go(0);

		String[] numbers = new String[10];
		for (int i = 0; i < 10; i++) {
			char[] c = new char[1];
			c[0] = (char) ('0' + i);
			numbers[i] = new String(c);
		}
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			String need = in.next();
			int[][] last = new int[need.length() + 1][10];
			int[][] last2 = new int[need.length() + 1][10];
			for (int len = 0; len < need.length() + 1; len++) {
				Arrays.fill(last[len], -1);
			}
			last[0][0] = 0;
			for (int j = need.length() - 1; j >= 0; j--) {
				int was = need.length() - 1 - j;
				for (int ll = 0; ll < 10; ll++)
					if (last[was][ll] != -1) {
						for (int next = 0; next < MAX; next++)
							if (hs[next] != null) {
								int would = ll + next;
								if (would % 10 == need.charAt(j) - '0') {
									last[was + 1][would / 10] = next;
									last2[was + 1][would / 10] = ll;
								}
							}
					}
			}
			if (last[last.length - 1][0] == -1) {
				out.println(-1);
			} else {
				ArrayList<Integer> needSum = new ArrayList<>();
				int cur = 0;
				for (int j = last.length - 1; j > 0; j--) {
					needSum.add(last[j][cur]);
					cur = last2[j][cur];
				}
				String[] ans = new String[6];
				for (int j = 0; j < 6; j++) {
					ans[j] = "";
				}
				for (int j = 0; j < needSum.size(); j++) {
					int need1 = needSum.get(j);
					ArrayList<Integer> tmp = hs[need1];
					for (int k = 0; k < 6; k++) {
						if (tmp.get(k) != 0 || ans[k].length() != 0)
							ans[k] = ans[k] + numbers[tmp.get(k)];
					}
				}
				for (int j = 0; j < 6; j++)
					if (ans[j].length() == 0)
						ans[j] = "0";
				for (int j = 0; j < 6; j++) {
					out.print(ans[j] + " ");
				}
				out.println();
			}
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
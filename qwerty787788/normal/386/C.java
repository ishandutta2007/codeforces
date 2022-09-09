import java.io.*;
import java.util.*;

public class CF {

	Random rnd = new Random(123);
	
	String gen(int n) {
		char[]res = new char[n];
		for (int i =0; i < n; i++) {
			res[i] = (char) ('a' + rnd.nextInt(26));
		}
		return new String(res);
	}
	
	void solve() {
		String s = in.next();
		int MAX = 20;
		int n = s.length();
		int[][] diff = new int[MAX][n];
		for (int i = 0; i < n; i++)
			diff[0][i] = 1 << (s.charAt(i) - 'a');
		for (int j = 1; j < MAX; j++) {
			for (int i = 0; i < n; i++) {
				diff[j][i] = diff[j - 1][i];
				int next = i + (1 << (j - 1));
				if (next < n)
					diff[j][i] |= diff[j - 1][next];
			}
		}
		int max = Integer.bitCount(diff[MAX - 1][0]);
		out.println(max);
		long[] res = new long[max];
		for (int fr = 0;fr < n; fr++) {
			int nowFrom = fr;
			int nowDiff = diff[0][fr];
			while (true) {
				int fro = nowFrom;
				nowFrom++;
				for (int i = MAX - 1; i >= 0; i--) {
					if (nowFrom >= n) {
						nowFrom = n;
						break;
					}
					if ((diff[i][nowFrom] | nowDiff) == nowDiff) {
						nowFrom += 1 << i;
					}
					if (nowFrom >= n) {
						nowFrom = n;
						break;
					}
				}
				res[Integer.bitCount(nowDiff) - 1] += (nowFrom - fro);
				if (nowFrom == n)
					break;
				nowDiff |= diff[0][nowFrom];
			}
		}
		for (int i = 0; i < max; i++)
			out.println(res[i]);
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
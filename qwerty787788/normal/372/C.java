import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int d = in.nextInt();
		int[] ai = new int[m];
		int[] bi = new int[m];
		int[] ti = new int[m];
		for (int i = 0; i < m; i++) {
			ai[i] = in.nextInt()-1;
			bi[i] = in.nextInt();
			ti[i] = in.nextInt();
		}
		long[] nowMax = new long[n];
		long[] nowMax2 = new long[n];
		for (int i = 0; i < m; i++) {
			ArrayList<Integer> where = new ArrayList<>();
			ArrayList<Long> howMuch = new ArrayList<>();
			int iter = 0;
			int nowIter = 0;
			int dist = (int) Math.min((int) 1e9, (ti[i] - (i == 0 ? 0
					: ti[i - 1])) * 1L * d);
			for (int j = 0; j < n; j++) {
				int need = Math.min(n, j + dist + 1);
				while (nowIter < need) {
					long val = nowMax[nowIter];
					while (howMuch.size() > 0
							&& howMuch.get(howMuch.size() - 1) < val) {
						howMuch.remove(howMuch.size() - 1);
						where.remove(where.size() - 1);
					}
					howMuch.add(val);
					where.add(nowIter);
					nowIter++;
				}
				iter = Math.min(iter, where.size() - 1);
				while (where.get(iter) + dist < j)
					iter++;
				long best = howMuch.get(iter);
				nowMax2[j] = best - Math.abs(j - ai[i]);
			}
			long[] tmp = nowMax;
			nowMax = nowMax2;
			nowMax2 = tmp;
		}
		long ans = Long.MIN_VALUE;
		for (int i = 0; i < n; i++)
			ans = Math.max(ans, nowMax[i]);
		for (int i = 0; i < m; i++)
			ans += bi[i];
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
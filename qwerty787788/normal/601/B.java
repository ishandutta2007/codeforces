import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Solver {
		ArrayList<Integer> pos = new ArrayList<>();
		ArrayList<Integer> diffs = new ArrayList<>();
		int last = -1;
		long ans = 0;
		int cnt = 1;
		long curSum = 0;

		Solver(int last) {
			this.last = last;
		}

		void addNumber(int x) {
			int curDiff = Math.abs(x - last);
			while (diffs.size() > 0 && diffs.get(diffs.size() - 1) <= curDiff) {
				int curFrom = diffs.size() == 1 ? 0 : pos.get(pos.size() - 2);
				int len = pos.get(pos.size() - 1) - curFrom;
				curSum -= len * 1L * diffs.get(diffs.size() - 1);
				diffs.remove(diffs.size() - 1);
				pos.remove(pos.size() - 1);
			}
			int curFrom = diffs.size() == 0 ? 0 : pos.get(pos.size() - 1);
			curSum += (cnt - curFrom) * 1L * curDiff;
			diffs.add(curDiff);
			pos.add(cnt);
			last = x;
			cnt++;
			ans += curSum;
		}
	}

	void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		for (int i = 0; i < q; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			Solver solve = new Solver(a[fr]);
			for (int j = fr + 1; j <= to; j++) {
				solve.addNumber(a[j]);
			}
			out.println(solve.ans);
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
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
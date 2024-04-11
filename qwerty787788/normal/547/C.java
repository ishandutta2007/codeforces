import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final int MAX = (int) (1e6 * 0.7);
	int[] minD;
	int[] cnt;

	long answer;

	void solve() {
		minD = new int[MAX];
		for (int i = 1; i < MAX; i++) {
			minD[i] = i;
		}
		for (int i = 2; i < MAX; i++) {
			if (minD[i] == i) {
				for (int j = i + i; j < MAX; j += i) {
					minD[j] = Math.min(minD[j], i);
				}
			}
		}
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		cnt = new int[MAX];
		boolean[] nowOn = new boolean[n];
		ArrayList<Integer> primes = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			int id = in.nextInt() - 1;
			primes.clear();
			int v = a[id];
			while (v != 1) {
				int pr = minD[v];
				primes.add(pr);
				while (v % pr == 0) {
					v /= pr;
				}
			}
			int add = nowOn[id] ? -1 : 1;
			nowOn[id] = !nowOn[id];
			int sz = primes.size();
			for (int st = 0; st < 1 << sz; st++) {
				int cur = 1;
				for (int j = 0; j < sz; j++) {
					if (((1 << j) & st) != 0) {
						cur *= primes.get(j);
					}
				}
				int mul = (Integer.bitCount(st) % 2) == 0 ? 1 : -1;
				if (add == 1) {
					answer += cnt[cur] * mul;
					cnt[cur]++;
				} else {
					cnt[cur]--;
					answer -= cnt[cur] * mul;
				}
			}
			out.println(answer);
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
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
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	Random rnd = new Random(33);

	final int MOD = (int) 1e9 + 9;
	final int MAX = (int) 1e5 * 3 + 5;
	final int MAX_OPER = 1000;
	int[] fib;
	int[] fibSum;

	void solve() {
		precalc();
		int n = in.nextInt();
		int m = in.nextInt();
		Fenwick f = new Fenwick(n);
		for (int i = 0; i < n; i++) {
			int t = in.nextInt();
			f.add(i, t);
		}
		f.update();
		int[] left = new int[m], right = new int[m], type = new int[m];
		for (int i = 0; i < m; i++) {
			type[i] = in.nextInt();
			left[i] = in.nextInt() - 1;
			right[i] = in.nextInt() - 1;
		}
		int updFrom = 0;
		int oper = 0;
		int[] add = new int[n + 2];
		for (int i = 0; i < m; i++) {
			if (type[i] == 2) {
				int result = f.get(left[i], right[i]);
				for (int j = updFrom; j < i; j++)
					if (type[j] == 1) {
						int l = 0, r = right[j] - left[j];
						l = Math.max(l, left[i] - left[j]);
						r = Math.min(r, right[i] - left[j]);
						if (r >= l) {
							result += getSum(l, r);
							if (result >= MOD)
								result -= MOD;
						}
					}
				out.println(result);
			}
			oper++;
			if (oper == MAX_OPER) {
				oper = 0;
				Arrays.fill(add, 0);
				while (updFrom <= i) {
					if (type[updFrom] == 1) {
						add[left[updFrom]]++;
						if (add[left[updFrom]] == MOD)
							add[left[updFrom]] = 0;
						int length = right[updFrom] - left[updFrom] + 1;
						add[right[updFrom] + 1] -= fib[length];
						if (add[right[updFrom] + 1] < 0)
							add[right[updFrom] + 1] += MOD;
						add[right[updFrom] + 2] -= fib[length - 1];
						if (add[right[updFrom] + 2] < 0)
							add[right[updFrom] + 2] += MOD;
					}
					updFrom++;
				}
				int prev2 = 0, prev1 = 0;
				for (int j = 0; j < n; j++) {
					add[j] += prev1;
					if (add[j] >= MOD)
						add[j] -= MOD;
					add[j] += prev2;
					if (add[j] >= MOD)
						add[j] -= MOD;
					prev2 = prev1;
					prev1 = add[j];
					if (add[j] != 0) {
						f.add(j, add[j]);
					}
				}
				f.update();
			}
		}
	}

	void precalc() {
		fib = new int[MAX];
		fib[0] = fib[1] = 1;
		for (int i = 2; i < MAX; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
			if (fib[i] >= MOD)
				fib[i] -= MOD;
		}
		fibSum = new int[MAX];
		for (int i = 0; i < MAX; i++) {
			fibSum[i] = (i == 0 ? 0 : fibSum[i - 1]) + fib[i];
			if (fibSum[i] >= MOD)
				fibSum[i] -= MOD;
		}
	}

	class Fenwick {
		int n;
		int[] sum;
		int[] vals;

		Fenwick(int n) {
			this.n = n;
			sum = new int[n];
			vals = new int[n];
		}

		void update() {
			int tmp = 0;
			for (int i = 0; i < n; i++) {
				tmp += vals[i];
				if (tmp >= MOD)
					tmp -= MOD;
				sum[i] = tmp;
			}
		}

		int get(int l, int r) {
			int result = sum[r] - (l == 0 ? 0 : sum[l - 1]);
			if (result < 0)
				return result + MOD;
			return result;
		}

		void add(int pos, int val) {
			vals[pos] += val;
			if (vals[pos] >= MOD)
				vals[pos] -= MOD;
		}
	}

	int getSum(int from, int to) {
		int result = fibSum[to] - (from == 0 ? 0 : fibSum[from - 1]);
		if (result < 0)
			result += MOD;
		return result;
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
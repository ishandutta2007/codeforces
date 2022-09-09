import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF_D {

	long mod = (long) 1e9 + 7;

	int MAX = 100004;
	long[] fact = new long[MAX];
	long[] factInv = new long[MAX];

	long c(int n, int k) {
		if (k < 0 || k > n)
			return 0;
		if (k == 0 || k == n)
			return 1;
		long res = fact[n];
		res = (res * factInv[k]) % mod;
		res = (res * factInv[n - k]) % mod;
		return res;
	}

	long getFree(int n) {
		if (n <= 1)
			return 1;
		long ans = 2;
		for (int mid = 2; mid < n; mid++) {
			long tmp = c(n - 1, mid - 1);
			ans = (ans + tmp) % mod;
		}
		return ans;
	}
	
	void prec() {
		fact[0] = 1;
		BigInteger modB = BigInteger.valueOf(mod);
		for (int i = 1; i < MAX; i++) {
			fact[i] = (fact[i - 1] * 1L * i) % mod;
			BigInteger inv = BigInteger.valueOf(fact[i]).modInverse(modB);
			factInv[i] = inv.longValue();
		}
	}

	long smart(int[] a) {
		int n = a.length;
		if (n == 1) {
			return 1;
		}
		boolean notZ = false;
		for (int i = 0; i < n; i++) {
			if (a[i] != 0)
				notZ = true;
		}
		if (!notZ) {
			return getFree(n);
		}
		int[] where = new int[n];
		Arrays.fill(where, -1);
		for (int i = 0; i < n; i++) {
			if (a[i] != 0)
				where[a[i] - 1] = i;
		}
		int left = -1, right = -1;
		for (int i = 0; i < n; i++)
			if (where[i] != -1) {
				left = where[i];
				right = where[i];
				break;
			}
		for (int i = 0; i < n; i++)
			if (where[i] != -1) {
				if (where[i] > left && where[i] < right) {
					return 0;
				}
				left = Math.min(left, where[i]);
				right = Math.max(right, where[i]);
			}
		// left from min
		long result = 0;
		{
			long res = 1;
			int last = 0;
			int med = -1;
			for (int i = 0; i < n; i++)
				if (where[i] != -1) {
					left = where[i];
					right = where[i];
					med = left;
					last = i;
					break;
				}
			left = left - last;
			res = getFree(last);
			for (int i = last + 1; i < n; i++)
				if (where[i] != -1) {
					int cntNew = i - last - 1;
					if (where[i] < med) {
						int freeLeft = left - where[i] - 1;
						int needRight = cntNew - freeLeft;
						res = (res * c(cntNew, freeLeft)) % mod;
						left = left - freeLeft - 1;
						right = right + needRight;
					} else {
						int freeRight = where[i] - right - 1;
						int needLeft = cntNew - freeRight;
						res = (res * c(cntNew, freeRight)) % mod;
						left = left - needLeft;
						right = right + freeRight + 1;
					}
					last = i;
				}
			int more = n - 1 - last;
			int freeLeft = left;
			res = (res * c(more, freeLeft)) % mod;
			result = (result + res) % mod;
		}
		if (where[0] == -1) {
			long res = 1;
			int last = 0;
			int med = -1;
			for (int i = 0; i < n; i++)
				if (where[i] != -1) {
					left = where[i];
					right = where[i];
					med = left;
					last = i;
					break;
				}
			right = right + last;
			res = getFree(last);
			for (int i = last + 1; i < n; i++)
				if (where[i] != -1) {
					int cntNew = i - last - 1;
					if (where[i] < med) {
						int freeLeft = left - where[i] - 1;
						int needRight = cntNew - freeLeft;
						res = (res * c(cntNew, freeLeft)) % mod;
						left = left - freeLeft - 1;
						right = right + needRight;
					} else {
						int freeRight = where[i] - right - 1;
						int needLeft = cntNew - freeRight;
						res = (res * c(cntNew, freeRight)) % mod;
						left = left - needLeft;
						right = right + freeRight + 1;
					}
					last = i;
				}
			int more = n - 1 - last;
			int freeLeft = left;
			res = (res * c(more, freeLeft)) % mod;
			result = (result + res) % mod;
		}
		return result;
	}

	ArrayList<int[]> orders;

	void go(int[] cur, int now, boolean[] used) {
		if (now == cur.length) {
			orders.add(cur.clone());
		} else {
			for (int i = 0; i < cur.length; i++)
				if (!used[i]) {
					used[i] = true;
					cur[now] = i;
					go(cur, now + 1, used);
					used[i] = false;
				}
		}
	}

	int stupid(int[] a) {
		int n = a.length;
		orders = new ArrayList<>();
		go(new int[n], 0, new boolean[n]);
		int res = 0;
		for (int[] o : orders) {
			boolean ok = true;
			for (int i = 0; i < n; i++)
				if (a[i] != 0)
					if (o[i] != a[i] - 1)
						ok = false;
			if (!ok)
				continue;
			int[] where = new int[n];
			for (int i = 0; i < n; i++)
				where[o[i]] = i;
			boolean[] used = new boolean[n + 1];
			for (int i = 0; i < n; i++) {
				int w = where[i];
				if (used[w] && used[w + 1]) {
					ok = false;
					break;
				}
				used[w] = used[w + 1] = true;
			}
			if (ok)
				res++;
		}
		return res;
	}

	void solve2() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		out.println(smart(a));
	}

	void stress() {
		Random rnd = new Random(123);
		for (int it = 0; it < 100000; it++) {
			System.err.println(it);
			int n = 1 + rnd.nextInt(8);
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = i;
				int x = rnd.nextInt(i + 1);
				int tmp = a[x];
				a[x] = a[i];
				a[i] = tmp;
			}
			for (int i = 0; i < n; i++)
					a[i] = rnd.nextBoolean() ? a[i] + 1 : 0;
			int sma = (int) smart(a.clone());
			int stu = stupid(a.clone());
			if (sma != stu) {
				System.err.println(Arrays.toString(a));
				System.err.println("sma = " + sma + ", stu =  " + stu);
				int smar = (int) smart(a.clone());
				throw new AssertionError();
			}
		}
	}

	void solve() {
		prec();
		solve2();
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
		new CF_D().run();
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
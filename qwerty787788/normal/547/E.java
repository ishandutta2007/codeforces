import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final Random rnd = new Random();
	final int MOD1 = BigInteger.valueOf((int) 1e9 + rnd.nextInt((int) 1e7))
			.nextProbablePrime().intValue();
	final int MOD2 = BigInteger.valueOf((int) 1e9 + rnd.nextInt((int) 1e7))
			.nextProbablePrime().intValue();
	final int MAX = (int) 1e5 * 2 + 123;
	final int mul = 239;

	int[] getHash(String s, int[] pow, int mod) {
		int[] res = new int[s.length() + 1];
		for (int i = 0; i < s.length(); i++) {
			res[i + 1] = (int) ((res[i] * 1L * pow[1] + s.charAt(i)) % mod);
		}
		return res;
	}

	long getHash(int[] hash, int mul, int from, int to, int mod) {
		long res = (hash[to] - hash[from - 1] * 1L * mul) % mod;
		if (res < 0) {
			res += mod;
		}
		return res;
	}

	long getHash(int[] hash1, int[] hash2, int mul1, int mul2, int from,
			int to, int mod1, int mod2) {
		long h1 = getHash(hash1, mul1, from, to, mod1);
		long h2 = getHash(hash2, mul2, from, to, mod2);
		return (h1 << 30) ^ h2;
	}

	void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.next();
		}
		ArrayList<Integer>[] len = new ArrayList[MAX];
		for (int i = 0; i < MAX; i++) {
			len[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			len[s[i].length()].add(i);
		}
		int[][][] hashes = new int[2][n][];
		int[] pow1 = new int[MAX];
		int[] pow2 = new int[MAX];
		pow1[0] = 1;
		pow2[0] = 1;
		for (int i = 1; i < MAX; i++) {
			pow1[i] = (int) (pow1[i - 1] * 1L * mul % MOD1);
			pow2[i] = (int) (pow2[i - 1] * 1L * mul % MOD2);
		}
		for (int i = 0; i < n; i++) {
			hashes[0][i] = getHash(s[i], pow1, MOD1);
			hashes[1][i] = getHash(s[i], pow2, MOD2);
		}
		ArrayList<Q>[] allQ = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			allQ[i] = new ArrayList<>();
		}
		for (int i = 0; i < q; i++) {
			Q qu = new Q(i, in.nextInt() - 1, in.nextInt() - 1);
			int k = in.nextInt() - 1;
			allQ[k].add(qu);
		}
		int[] answer = new int[q];
		long[] hhh = new long[n];
		for (int l = 0; l < len.length; l++) {
			if (len[l].size() == 0) {
				continue;
			}
			HashMap<Long, ArrayList<Integer>> allOcc = new HashMap<>();
			for (int id : len[l]) {
				long hh = getHash(hashes[0][id], hashes[1][id], pow1[l],
						pow2[l], 1, l, MOD1, MOD2);
				hhh[id] = hh;
				if (!allOcc.containsKey(hh)) {
					allOcc.put(hh, new ArrayList<Integer>());
				}
			}
			for (int i = 0; i < n; i++) {
				for (int pos = l; pos <= s[i].length(); pos++) {
					long hh = getHash(hashes[0][i], hashes[1][i], pow1[l],
							pow2[l], pos - l + 1, pos, MOD1, MOD2);
					ArrayList<Integer> occ = allOcc.get(hh);
					if (occ != null) {
						occ.add(i);
					}
				}
			}
			for (int id : len[l]) {
				ArrayList<Integer> all = allOcc.get(hhh[id]);
				for (Q qu : allQ[id]) {
					answer[qu.id] = getLessOrEq(all, qu.r)
							- getLessOrEq(all, qu.l - 1);
				}
			}
		}
		for (int i = 0; i < q; i++) {
			out.println(answer[i]);
		}
	}

	int getLessOrEq(ArrayList<Integer> all, int value) {
		int l = -1, r = all.size();
		while (r - l > 1) {
			int mid = (l + r) >>> 1;
			if (all.get(mid) <= value) {
				l = mid;
			} else {
				r = mid;
			}
		}
		return r;
	}

	class Q {
		int id, l, r;

		public Q(int id, int l, int r) {
			super();
			this.id = id;
			this.l = l;
			this.r = r;
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
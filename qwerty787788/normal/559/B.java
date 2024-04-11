import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	final int MAX = 2 * (int) 1e5 + 19;
	HashHelper helper = new HashHelper(MAX);

	class Pair {
		int x, y;

		public Pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		private CF getOuterType() {
			return CF.this;
		}

	}

	int get(StringHash hash, int l, int r) {
		long h = hash.getLongHash(l, r);
		Integer ans = ids.get(h);
		if (ans != null) {
			return ans;
		}
		if ((r - l + 1) % 2 == 0) {
			int m = (l + r) >>> 1;
			int id1 = get(hash, l, m);
			int id2 = get(hash, m + 1, r);
			if (id1 > id2) {
				int tmp = id1;
				id1 = id2;
				id2 = tmp;
			}
			Pair p = new Pair(id1, id2);
			Integer value = ids2.get(p);
			if (value != null) {
				ids.put(h, value);
				return value;
			}
			int count = ids.size();
			ids.put(h, count);
			ids2.put(p, count);
			return count;
		} else {
			int count = ids.size();
			ids.put(h, count);
			return count;
		}
	}

	HashMap<Long, Integer> ids = new HashMap<>();
	HashMap<Pair, Integer> ids2 = new HashMap<>();

	void solve() {
		String s1 = in.next();
		String s2 = in.next();
		StringHash hash1 = helper.generateHash(s1);
		StringHash hash2 = helper.generateHash(s2);
		out.println(get(hash1, 0, s1.length() - 1) == get(hash2, 0,
				s2.length() - 1) ? "YES" : "NO");
	}

	private class StringHash {
		private int[] val1, val2;
		private HashHelper helper;
		String s;

		public StringHash(int[] val1, int[] val2, HashHelper helper, String s) {
			super();
			this.val1 = val1;
			this.val2 = val2;
			this.helper = helper;
			this.s = s;
		}

		public int getIntHash(int l, int r) {
			if (r < l) {
				return 0;
			}
			long result = val1[r + 1] - val1[l] * 1L * helper.pow1[r - l + 1];
			result %= helper.MOD1;
			if (result < 0) {
				result += helper.MOD1;
			}
			return (int) result;
		}

		public long getHashWithLength(int l, int r) {
			if (r < l) {
				return 0;
			}
			return ((long) getIntHash(l, r) << 32) ^ (r - l + 1);
		}

		public long getLongHash(int l, int r) {
			if (r < l) {
				return 0;
			}
			long res;
			{
				long result = val1[r + 1] - val1[l] * 1L
						* helper.pow1[r - l + 1];
				result %= helper.MOD1;
				if (result < 0) {
					result += helper.MOD1;
				}
				res = result;
			}
			{
				long result = val2[r + 1] - val2[l] * 1L
						* helper.pow2[r - l + 1];
				result %= helper.MOD2;
				if (result < 0) {
					result += helper.MOD2;
				}
				res = (res << 32) ^ result;
			}
			return res;
		}
	}

	private class HashHelper {
		final Random rnd = new Random();
		final int BILLION = (int) 1e9;
		final int MUL = 239;
		final int MOD1 = BigInteger
				.valueOf(BILLION + rnd.nextInt(BILLION / 10))
				.nextProbablePrime().intValue();
		final int MOD2 = BigInteger
				.valueOf(BILLION + rnd.nextInt(BILLION / 10))
				.nextProbablePrime().intValue();
		int[] pow1, pow2;

		public HashHelper(final int n) {
			pow1 = new int[n];
			pow2 = new int[n];
			pow1[0] = pow2[0] = 1;
			for (int i = 1; i < n; i++) {
				pow1[i] = (int) (pow1[i - 1] * 1L * MUL % MOD1);
				pow2[i] = (int) (pow2[i - 1] * 1L * MUL % MOD2);
			}
		}

		StringHash generateHash(String s) {
			return new StringHash(generateIntHash(s, MOD1), generateIntHash(s,
					MOD2), this, s);
		}

		public int compareInt(StringHash s1, int from1, int to1, StringHash s2,
				int from2, int to2) {
			int len = Math.min(to1 - from1, to2 - from2) + 1;
			int l = 0, r = len + 1;
			while (r - l > 1) {
				int mid = (l + r) >>> 1;
				if (s1.getIntHash(from1, from1 + mid - 1) == s2.getIntHash(
						from2, from2 + mid - 1)) {
					l = mid;
				} else {
					r = mid;
				}
			}
			if (l == len) {
				if (to1 - from1 == to2 - from2) {
					return 0;
				}
				return (to1 - from1) - (to2 - from2);
			}
			return s1.s.charAt(from1 + l) - s2.s.charAt(from2 + l);
		}

		long addHashWithLengths(long hash1, long hash2) {
			int h1 = getHashFromHashWithLength(hash1), h2 = getHashFromHashWithLength(hash2);
			int l1 = getLengthFromHashWithLength(hash1), l2 = getLengthFromHashWithLength(hash2);
			int newHash = (int) ((h1 * 1L * pow1[l2] + h2) % MOD1);
			return ((long) newHash << 32) ^ (l1 + l2);
		}

		int getLengthFromHashWithLength(long hash) {
			return (int) (hash & -1);
		}

		int getHashFromHashWithLength(long hash) {
			return (int) (hash >> 32);
		}

		public int compareLong(StringHash s1, int from1, int to1,
				StringHash s2, int from2, int to2) {
			int len = Math.min(to1 - from1, to2 - from2) + 1;
			int l = 0, r = len + 1;
			while (r - l > 1) {
				int mid = (l + r) >>> 1;
				if (s1.getLongHash(from1, from1 + mid - 1) == s2.getLongHash(
						from2, from2 + mid - 1)) {
					l = mid;
				} else {
					r = mid;
				}
			}
			if (l == len) {
				if (to1 - from1 == to2 - from2) {
					return 0;
				}
				return (to1 - from1) - (to2 - from2);
			}
			return s1.s.charAt(from1 + l) - s2.s.charAt(from2 + l);
		}

		private int[] generateIntHash(String s, int MOD) {
			int[] result = new int[s.length() + 1];
			for (int i = 0; i < s.length(); i++) {
				result[i + 1] = (int) ((result[i] * 1L * MUL + s.charAt(i)) % MOD);
			}
			return result;
		}
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return null;
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Query implements Comparable<Query> {
		int i, j, id;
		int answer;

		public Query(int i, int j, int id) {
			super();
			this.i = i;
			this.j = j;
			this.id = id;
		}

		@Override
		public int compareTo(Query o) {
			if (j != o.j)
				return Integer.compare(j, o.j);
			return Integer.compare(i, o.i);
		}

	}

	int[] a;
	int[] sum;
	final int MAX = 20;
	int[][] min;
	int[] maxPowerOfTwo;

	int getMin(int from, int to) {
		int len = to - from + 1;
		int maxPower = maxPowerOfTwo[len];
		return Math.min(min[maxPower][from], min[maxPower][to - (1 << maxPower)
				+ 1]);
	}

	int getAnswer(int from, int i, int j) {
		int res = sum[j] - (from == 0 ? 0 : sum[from - 1]);
		res += getMin(from, j) * (i - (j - from));
		return res;
	}

	int firstOkI(int from1, int from2, int curJ) {
		int minI = curJ - from1;
		int val1 = getAnswer(from1, minI, curJ), val2 = getAnswer(from2, minI,
				curJ);
		if (val1 < val2)
			return minI;
		int val11 = getAnswer(from1, minI + 1, curJ), val22 = getAnswer(from2,
				minI + 1, curJ);
		int dVal1 = (val11 - val1) - (val22 - val2);
		if (dVal1 > 0)
			throw new AssertionError();
		if (dVal1 == 0)
			return Integer.MAX_VALUE;
		dVal1 = -dVal1;
		int turns = (val1 - val2 + dVal1 - 1) / dVal1;
		return minI + turns;
	}

	void solve() {
		int n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		min = new int[MAX][n];
		for (int i = 0; i < n; i++) {
			min[0][i] = a[i];
		}
		maxPowerOfTwo = new int[1 << MAX];
		for (int i = 2; i < maxPowerOfTwo.length; i++) {
			maxPowerOfTwo[i] = maxPowerOfTwo[i / 2] + 1;
		}
		for (int i = 1; i < MAX; i++)
			for (int j = 0; j < n; j++) {
				int next = j + (1 << (i - 1));
				min[i][j] = min[i - 1][j];
				if (next < n) {
					min[i][j] = Math.min(min[i][j], min[i - 1][next]);
				}
			}
		sum = new int[n];
		for (int i = 0; i < n; i++) {
			sum[i] = a[i];
			if (i != 0)
				sum[i] += sum[i - 1];
		}
		int m = in.nextInt();
		Query[] q = new Query[m];
		for (int i = 0; i < m; i++) {
			q[i] = new Query(in.nextInt() - 1, in.nextInt() - 1, i);
		}
		Arrays.sort(q);
		int qIt = 0;
		ArrayList<Integer> ids = new ArrayList<>();
		for (int curJ = 0; curJ < n; curJ++) {
			while (ids.size() > 1) {
				int now = ids.size();
				int nowFrom = firstOkI(ids.get(now - 2), ids.get(now - 1), curJ);
				int nextFrom = firstOkI(ids.get(now - 1), curJ, curJ);
				if (nextFrom >= nowFrom) {
					ids.remove(now - 1);
				} else {
					break;
				}
			}
			ids.add(curJ);
			while (qIt < q.length && q[qIt].j == curJ) {
				Query qq = q[qIt++];
				int needI = qq.i;
				int l = 0, r = ids.size();
				while (r - l > 1) {
					int med = (l + r) >> 1;
					int first = firstOkI(ids.get(med - 1), ids.get(med), curJ);
					if (first > needI) {
						l = med;
					} else {
						r = med;
					}
				}
				qq.answer = getAnswer(ids.get(l), needI, curJ);
			}
		}
		int[] ans = new int[m];
		for (Query qq : q) {
			ans[qq.id] = qq.answer;
		}
		for (int i = 0; i < m; i++) {
			out.println(ans[i] + " ");
		}
	}

	void solve2() {
		Random rnd = new Random(12523);
		int n = 20;
		int[][] a = new int[n][n];
		int[][] from = new int[n][n];
		for (int i = 0; i < n; i++) {
			a[0][i] = rnd.nextInt(100);
			from[0][i] = i;
		}
		for (int i = 1; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (a[i - 1][j - 1] < a[i - 1][j]) {
					from[i][j] = from[i - 1][j - 1];
					a[i][j] = a[i - 1][j - 1] + a[0][j];
				} else {
					from[i][j] = from[i - 1][j];
					a[i][j] = a[i - 1][j] + a[0][j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.err.printf("%03d ", from[i][j]);
			}
			System.err.println();
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
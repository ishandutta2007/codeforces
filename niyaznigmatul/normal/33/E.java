import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {
	public static void main(String[] args) {
		new E().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	int timeToInt(String s) {
		int p = s.indexOf(":");
		int h = Integer.parseInt(s.substring(0, p));
		int m = Integer.parseInt(s.substring(p + 1));
		return h * 60 + m;
	}

	void solve() {
		int m = nextInt();
		int n = nextInt();
		int k = nextInt();
		String[] names = new String[m];
		for (int i = 0; i < names.length; i++) {
			names[i] = nextToken();
		}
		int[] times = new int[m];
		for (int i = 0; i < times.length; i++) {
			times[i] = nextInt();
		}
		HashMap<String, Integer> workNames = new HashMap<String, Integer>();
		for (int i = 0; i < times.length; i++) {
			workNames.put(names[i], times[i]);
		}
		boolean[] busy = new boolean[1440];
		int dayTime = 1440;
		for (int i = 0; i < 4; i++) {
			String[] t = nextToken().split("\\Q-\\E");
			int t1 = timeToInt(t[0]);
			int t2 = timeToInt(t[1]);
			for (int j = t1; j <= t2; j++) {
				busy[j] = true;
				dayTime--;
			}
		}
		Work[] works = new Work[n];
		for (int i = 0; i < n; i++) {
			String name = nextToken();
			int day = nextInt();
			int t = timeToInt(nextToken());
			int e = 0;
			for (int j = 0; j < t; j++) {
				if (!busy[j]) {
					e++;
				}
			}
			int reward = nextInt();
			if (!workNames.containsKey(name)) {
				continue;
			}
			works[i] = new Work(workNames.get(name), (day - 1) * dayTime + e,
					reward, i);
		}
		Arrays.sort(works, new Comparator<Work>() {
			@Override
			public int compare(Work o1, Work o2) {
				if (o1 == null && o2 == null) {
					return 0;
				}
				if (o1 == null) {
					return -1;
				}
				if (o2 == null) {
					return 1;
				}
				return o1.deadLine < o2.deadLine ? -1
						: o1.deadLine > o2.deadLine ? 1 : 0;
			}
		});
		int[][] dp = new int[n + 1][dayTime * k + 1];
		for (int i = 1; i <= n; i++) {
			Work e = works[i - 1];
			if (e == null) {
				for (int j = 0; j < dp[i].length; j++) {
					dp[i][j] = dp[i - 1][j];
				}
				continue;
			}
			dp[i][0] = 0;
			for (int j = 1; j < dp[i].length; j++) {
				dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
				if (j >= e.length && j <= e.deadLine) {
					dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - e.length]
							+ e.reward);
				}
			}
		}
		out.println(dp[n][dayTime * k]);
		ArrayList<DoneWork> doneWork = new ArrayList<E.DoneWork>();
		for (int i = n, j = dayTime * k; i > 0 && j > 0;) {
			Work e = works[i - 1];
			if (dp[i][j] == dp[i][j - 1]) {
				j--;
			} else if (dp[i][j] == dp[i - 1][j]) {
				i--;
			} else if (e != null && j >= e.length && j <= e.deadLine) {
				if (dp[i][j] == dp[i - 1][j - e.length] + e.reward) {
					doneWork.add(new DoneWork(e.num, j - e.length, j - 1));
					i--;
					j -= e.length;
				}
			} else {
				throw new AssertionError();
			}
		}
		Collections.reverse(doneWork);
		out.println(doneWork.size());
		for (DoneWork e : doneWork) {
			out.println((1 + e.num) + " " + getTime(busy, e.t1, dayTime) + " "
					+ getTime(busy, e.t2, dayTime));
		}
	}

	String getTime(boolean[] busy, int t, int dayTime) {
		return (t / dayTime + 1) + " " + getTime(busy, t % dayTime);
	}

	String getTime(boolean[] busy, int t) {
		t++;
		for (int i = 0; i < busy.length; i++) {
			if (!busy[i]) {
				--t;
				if (t == 0) {
					return getTime(i);
				}
			}
		}
		throw new AssertionError();
	}

	String getTime(int x) {
		int h = x / 60;
		int m = x % 60;
		String s1 = h + "";
		String s2 = m + "";
		if (s1.length() < 2) {
			s1 = "0" + s1;
		}
		if (s2.length() < 2) {
			s2 = "0" + s2;
		}
		return s1 + ":" + s2;
	}

	class DoneWork {
		int num;
		int t1;
		int t2;

		public DoneWork(int num, int t1, int t2) {
			this.num = num;
			this.t1 = t1;
			this.t2 = t2;
		}

	}

	class Work {
		int length;
		int deadLine;
		int reward;
		int num;

		public Work(int length, int deadLine, int reward, int num) {
			this.length = length;
			this.deadLine = deadLine;
			this.reward = reward;
			this.num = num;
		}

	}
}
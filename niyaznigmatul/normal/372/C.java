import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int d = nextInt();
		int[] dp = new int[n];
		int curTime = 1;
		int[] a = new int[m];
		int[] t = new int[m];
		int[] b = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = nextInt() - 1;
			b[i] = nextInt();
			t[i] = nextInt();
		}
		QueueMin qm = new QueueMin(n);
		int[] next = new int[n];
		for (int i = 0; i < m; i++) {
			qm.head = qm.tail = 0;
			long dd = (long) d * (t[i] - curTime);
			int cur = 0;
			int cur2 = 0;
			for (int w = 0; w < n; w++) {
				while (w - dd > cur) {
					qm.poll(dp[cur++]);
				}
				while (cur2 < n && cur2 <= w + dd) {
					qm.add(dp[cur2++]);
				}
				int cost = Math.abs(w - a[i]);
				next[w] = qm.getMin() + cost;
			}
			int[] tt = next;
			next = dp;
			dp = tt;
			curTime = t[i];
		}
		long ans = Long.MAX_VALUE;
		for (int i : dp) {
			ans = Math.min(ans, i);
		}
		ans = -ans;
		for (int i : b) {
			ans += i;
		}
		out.println(ans);
	}

	static class QueueMin {
		int[] a;
		int head;
		int tail;

		public QueueMin(int n) {
			a = new int[n];
			head = tail = 0;
		}

		void add(int x) {
			while (tail > head && a[tail - 1] > x) {
				--tail;
			}
			a[tail++] = x;
		}

		int getMin() {
			if (tail - head == 0) {
				return Integer.MAX_VALUE;
			}
			return a[head];
		}

		void poll(int x) {
			if (a[head] == x) {
				++head;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		File file = new File("c.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			// output = new PrintStream("c.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static class MinSegmentTree {
		int[] min;
		int[] minId;
		int n;

		public MinSegmentTree(int n) {
			this.n = Integer.highestOneBit(n) << 1;
			min = new int[this.n * 2];
			minId = new int[this.n * 2];
			for (int i = 0; i < n; i++) {
				minId[i + n] = i;
			}
			for (int i = 0; i < n; i++) {
				set(i, Integer.MAX_VALUE);
			}
		}

		public void set(int x, int y) {
			x += n;
			min[x] = y;
			while (x > 1) {
				x >>= 1;
				int left = min[x << 1];
				int right = min[(x << 1) | 1];
				if (left <= right) {
					min[x] = left;
					minId[x] = minId[x << 1];
				} else {
					min[x] = right;
					minId[x] = minId[(x << 1) | 1];
				}
			}
		}

		public void add(int x, int y) {
			x += n;
			min[x] += y;
			while (x > 1) {
				x >>= 1;
				int left = min[x << 1];
				int right = min[(x << 1) | 1];
				if (left <= right) {
					min[x] = left;
					minId[x] = minId[x << 1];
				} else {
					min[x] = right;
					minId[x] = minId[(x << 1) | 1];
				}
			}
		}

		public int getMin(int left, int right) {
			--right;
			left += n;
			right += n;
			int ret = Integer.MAX_VALUE;
			while (left <= right) {
				if ((left & 1) == 1) {
					ret = Math.min(ret, min[left]);
					left++;
				}
				if ((right & 1) == 0) {
					ret = Math.min(ret, min[right]);
					right--;
				}
				left >>= 1;
				right >>= 1;
			}
			return ret;
		}

	}

}
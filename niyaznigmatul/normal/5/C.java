import java.io.*;
import java.util.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new Thread(new C()).start();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
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

	final int maxB = 1000000;
	final int maxN = (1 << 20);

	void update(int x, int y) {
		x += maxN;
		tr[x] = y;
		while (x > 1) {
			x /= 2;
			tr[x] = Math.min(tr[2 * x], tr[2 * x + 1]);
		}
	}

	int getMin(int l, int r) {
		l += maxN;
		r += maxN;
		if (l > r) {
			return Integer.MAX_VALUE;
		}
		int ret = Integer.MAX_VALUE;
		while (l <= r) {
			if ((l & 1) == 1) {
				ret = Math.min(ret, tr[l]);
				l++;
			}
			if ((r & 1) == 0) {
				ret = Math.min(ret, tr[r]);
				r--;
			}
			l /= 2;
			r /= 2;
		}
		return ret;
	}

	int[] tr;

	void solve() {
		char[] c = nextToken().toCharArray();
		int[] mi = new int[maxB * 2 + 1];
		int cur = maxB;
		int difAns = 0;
		Arrays.fill(mi, 3000000);
		tr = new int[2 * maxN + 4];
		Arrays.fill(tr, 2000000);
		mi[maxB] = -1;
		for (int i = 0; i < c.length; i++) {
			if (c[i] == '(') {
				cur++;
			} else {
				cur--;
			}
			if (mi[cur] < i && getMin(mi[cur] + 1, i - 1) >= cur) {
				if (i - mi[cur] > difAns) {
					difAns = i - mi[cur];
				}
			} else {
				mi[cur] = i;
			}
			update(i, cur);
		}
		if (difAns == 0) {
			out.println("0 1");
			return;
		}
		Arrays.fill(tr, 2000000);
		Arrays.fill(mi, 3000000);
		cur = maxB;
		int kol = 0;
		mi[maxB] = -1;
		for (int i = 0; i < c.length; i++) {
			if (c[i] == '(') {
				cur++;
			} else {
				cur--;
			}
			if (mi[cur] < i && getMin(mi[cur] + 1, i - 1) >= cur) {
				if (i - mi[cur] == difAns) {
					kol++;
				}
			} else {
				mi[cur] = i;
			}
			update(i, cur);
		}
		out.println(difAns + " " + kol);
	}
}
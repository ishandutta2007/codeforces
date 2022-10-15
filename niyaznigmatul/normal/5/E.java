import java.io.*;
import java.util.*;

public class E implements Runnable {
	public static void main(String[] args) {
		new Thread(new E()).start();
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

	void solve() {
		int n = nextInt();
		int[] a = new int[n];
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			max = Math.max(max, a[i]);
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == max) {
				int[] b = new int[n + 1];
				System.arraycopy(a, i, b, 0, a.length - i);
				System.arraycopy(a, 0, b, a.length - i, i);
				a = b;
				b[n] = max;
				n++;
				break;
			}
		}
		out.println(solve1(a, max) + solve2(a, max) + solve3(a, max));
	}

	static long solve1(int[] a, int max) {
		long ret = 0;
		int[] numbers = new int[a.length];
		int[] count = new int[a.length];
		int cur = 0;
		for (int i = 0; i < a.length; i++) {
			if (a[i] == max) {
				cur = 0;
				continue;
			}
			while (cur > 0 && a[i] > numbers[cur - 1]) {
				ret++;
				--cur;
			}
			if (cur > 0) {
				if (numbers[cur - 1] == a[i]) {
					ret += count[cur - 1];
				}
				if (numbers[0] > a[i]) {
					ret++;
				}
			}
			numbers[cur] = a[i];
			if (cur > 0 && a[i] == numbers[cur - 1]) {
				count[cur] = count[cur - 1] + 1;
			} else {
				count[cur] = 1;
			}
			cur++;
		}
		System.err.println(ret);
		return ret;
	}

	static long solve2(int[] a, int max) {
		long ret = 0;
		int count = 0;
		for (int i = 0; i + 1 < a.length; i++) {
			if (a[i] != max) {
				continue;
			}
			count++;
		}
		if (count == 1) {
			boolean[] was = new boolean[a.length];
			for (int i = 0; i < a.length; i++) {
				if (a[i] != max) {
					continue;
				}
				int got = Integer.MIN_VALUE;
				for (int j = i - 1; j >= 0 && a[j] != max; j--) {
					if (a[j] >= got && !was[j]) {
						ret++;
						was[j] = true;
					}
					got = Math.max(got, a[j]);
				}
				got = Integer.MIN_VALUE;
				for (int j = i + 1; j < a.length && a[j] != max; j++) {
					if (a[j] >= got && !was[j]) {
						ret++;
						was[j] = true;
					}
					got = Math.max(got, a[j]);
				}
			}
		} else {
			for (int i = 0; i < a.length; i++) {
				if (a[i] != max) {
					continue;
				}
				int got = Integer.MIN_VALUE;
				for (int j = i - 1; j >= 0 && a[j] != max; j--) {
					if (a[j] >= got) {
						ret++;
					}
					got = Math.max(got, a[j]);
				}
				got = Integer.MIN_VALUE;
				for (int j = i + 1; j < a.length && a[j] != max; j++) {
					if (a[j] >= got) {
						ret++;
					}
					got = Math.max(got, a[j]);
				}
			}
		}
		System.err.println(ret);
		return ret;
	}

	static long solve3(int[] a, int max) {
		long ret = 0;
		for (int i = 0; i + 1 < a.length; i++) {
			if (a[i] == max) {
				ret++;
			}
		}
		ret = ret * (ret - 1) >> 1;
		System.err.println(ret);
		return ret;
	}
}
import java.io.*;
import java.util.*;

public class B_MaxBuzzIdea implements Runnable {
	public static void main(String[] args) {
		new Thread(new B_MaxBuzzIdea()).start();
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

	class W implements Comparable<W> {
		int x, num, sum;

		public W(int x, int num) {
			super();
			this.x = x;
			this.num = num;
			sum = x;
		}

		@Override
		public int compareTo(W o) {
			if (x > o.x) {
				return -1;
			}
			if (x < o.x) {
				return 1;
			}
			return 0;
		}
	}

	void solve() {
		int n = nextInt();
		int v = nextInt();
		ArrayList<W> a = new ArrayList<W>();
		ArrayList<W> b = new ArrayList<W>();
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			if (x == 1) {
				a.add(new W(y, i + 1));
			} else {
				b.add(new W(y, i + 1));
			}
		}
		Collections.sort(a);
		Collections.sort(b);
		for (int i = 1; i < a.size(); i++) {
			a.get(i).sum += a.get(i - 1).sum;
		}
		for (int i = 1; i < b.size(); i++) {
			b.get(i).sum += b.get(i - 1).sum;
		}
		int ans = 0;
		int ansH = -1;
		for (int i = 0; i <= b.size(); i++) {
			if (i * 2 > v) {
				break;
			}
			int g = 0;
			if (i != 0) {
				g += b.get(i - 1).sum;
			}
			int j = Math.min(v - i * 2, a.size());
			if (j != 0) {
				g += a.get(j - 1).sum;
			}
			if (g > ans) {
				ans = g;
				ansH = i;
			}
		}
		out.println(ans);
		for (int i = 0; i < ansH; i++) {
			out.print(b.get(i).num + " ");
		}
		for (int i = 0; i < Math.min(v - ansH * 2, a.size()); i++) {
			out.print(a.get(i).num + " ");
		}
	}
}
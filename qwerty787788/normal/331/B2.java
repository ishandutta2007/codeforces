import java.io.*;
import java.util.*;

public class CF {

	class SegmentTree {
		int[] t;
		int n;

		public SegmentTree(int n) {
			this.n = n;
			t = new int[n];
		}

		int sum(int r) {
			int result = 0;
			for (; r >= 0; r = (r & (r + 1)) - 1)
				result += t[r];
			return result;
		}

		void inc(int i, int delta) {
			for (; i < n; i = (i | (i + 1)))
				t[i] += delta;
		}

		int sum(int l, int r) {
			if (r < l)
				return 0;
			return sum(r) - sum(l - 1);
		}
	}
	
	int n;
	boolean[] notOk;
	SegmentTree st;
	int[] pos;
	
	void update(int x) {
		if (x < 0 || x >= n - 1)
			return;
		boolean realVal = pos[x + 1] < pos[x];
		if (realVal == notOk[x])
			return;
		if (realVal) {
			st.inc(x, 1);
		} else {
			st.inc(x, -1);
		}
		notOk[x] = realVal;
	}

	void realSolve() {
		n = in.nextInt();
		pos = new int[n];
		int[] who = new int[n];
		for (int i = 0; i < n; i++) {
			int t = in.nextInt() - 1;
			pos[t] = i;
			who[i] = t;
		}
		notOk = new boolean[n];
		for (int i = 0; i < n - 1; i++)
			if (pos[i + 1] < pos[i])
				notOk[i] = true;
		int q = in.nextInt();
		st = new SegmentTree(n + 1);
		for (int i = 0; i < n - 1; i++)
			if (notOk[i])
				st.inc(i, 1);
		for (int qe = 0; qe < q; qe++) {
			int type = in.nextInt();
			if (type == 1) {
				// ask
				int fr = in.nextInt() - 1;
				int to = in.nextInt() - 1;
				int res = st.sum(fr, to - 1) + 1;
				out.println(res);
			} else {
				int wh1 = in.nextInt() - 1;
				int wh2 = in.nextInt() - 1;
				int x = who[wh1];
				int y = who[wh2];
				int tmp = pos[x];
				pos[x] = pos[y];
				pos[y] = tmp;
				who[wh1] = y;
				who[wh2] = x;
				update(x - 1);
				update(x);
				update(y - 1);
				update(y);
			}
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

	void solve() {
		in = new InputReader(new File("object.in"));
		try {
			out = new PrintWriter(new File("object.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		realSolve();

		out.close();
	}

	void solveIO() {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	public static void main(String[] args) {
		new CF().solveIO();
	}
}
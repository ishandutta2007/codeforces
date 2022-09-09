import java.io.*;
import java.util.*;

public class CF {

	class Number {
		int val, pos, id;

		Number(int val, int pos, int id) {
			this.val = val;
			this.pos = pos;
			this.id = id;
		}
	}

	class SegmentTree {
		int n;
		int[] t;

		SegmentTree(int n) {
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

		int get(int l, int r) {
			if (l > r)
				return 0;
			return sum(r) - sum(l - 1);
		}
	}

	void solve() {
//		long sta = System.currentTimeMillis();
		int n = in.nextInt();
		int k = in.nextInt();
		int[] pos = new int[n];
		for (int i = 0; i < n; i++)
			pos[in.nextInt() - 1] = i;
		boolean[] has = new boolean[n];
		for (int i = 0; i < k; i++)
			has[in.nextInt() - 1] = true;
		long ans = 0;
		SegmentTree st = new SegmentTree(n);
		TreeSet<Integer> positions = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			if (!has[i]) {
				Integer left = positions.lower(pos[i]);
				if (left == null)
					left = -1;
				Integer right = positions.higher(pos[i]);
				if (right == null)
					right = n;
				ans += right - left - 1 - st.get(left + 1, right - 1);
				st.inc(pos[i], 1);
			} else {
				positions.add(pos[i]);
			}
		}
		out.println(ans);
//		System.err.println(System.currentTimeMillis() - sta);
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
		new CF().run();
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
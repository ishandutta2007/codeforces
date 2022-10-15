import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[][] v = new int[30][n + 1];
		int[] l = new int[m];
		int[] r = new int[m];
		int[] q = new int[m];
		for (int i = 0; i < m; i++) {
			l[i] = nextInt() - 1;
			r[i] = nextInt();
			q[i] = nextInt();
			for (int j = 0; j < 30; j++) {
				if (((q[i] >> j) & 1) == 1) {
					v[j][l[i]]++;
					v[j][r[i]]--;
				}
			}
		}
		int[] ans = new int[n];
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				for (int j = 0; j < 30; j++) {
					v[j][i] += v[j][i - 1];
				}
			}
			for (int j = 0; j < 30; j++) {
				if (v[j][i] > 0) {
					ans[i] |= 1 << j;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			set(i, ans[i]);
		}
		for (int i = 0; i < m; i++) {
			if (get(l[i], r[i]) != q[i]) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			if (i > 0)
				out.print(' ');
			out.print(ans[i]);
		}
		out.println();
	}

	static void set(int v, int x) {
		v += N;
		tr[v] = x;
		while (v > 1) {
			v >>= 1;
			tr[v] = tr[v * 2] & tr[v * 2 + 1];
		}
	}

	static int get(int l, int r) {
		--r;
		l += N;
		r += N;
		int ans = -1;
		while (l <= r) {
			if ((l & 1) == 1) {
				ans &= tr[l++];
			}
			if ((r & 1) == 0) {
				ans &= tr[r--];
			}
			l >>= 1;
			r >>= 1;
		}
		return ans;
	}

	static final int N = 1 << 17;

	static int[] tr = new int[N * 2];

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("b.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("b.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
		br.close();
	}

	static boolean hasNext() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String next() throws IOException {
		return hasNext() ? st.nextToken() : null;
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
}
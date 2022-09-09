import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
		}
		int[] id1 = getId(a);
		int[] id2 = getId(b);
		int[] myId = new int[n - 1];
		int mod = 2;
		int add = 0;
		for (int i = n - 2; i >= 0; i--) {
			myId[i] = (id1[i] + id2[i] + add) % mod;
			add = (id1[i] + id2[i] + add) / mod;
			mod++;
		}
		int[] ans = genPerm(myId);

		for (int i = 0; i < ans.length; i++) {
			out.print(ans[i] + " ");
		}
	}

	int[] genPerm(int[] id) {
		int n = id.length + 1;
		Fenwick f = new Fenwick(n);
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			int l = -1, r = n;
			int myid = i == n - 1 ? 0 : id[i];
			myid++;
			while (r - l > 1) {
				int mid = (l + r) >>> 1;
				if (mid + 1 - f.get(mid) >= myid) {
					r = mid;
				} else {
					l = mid;
				}
			}
			res[i] = r;
			f.add(res[i], 1);
		}
		return res;
	}

	class Fenwick {
		int[] s;
		int n;

		public Fenwick(int n) {
			this.n = n;
			s = new int[n];
		}

		void add(int pos, int val) {
			while (pos < n) {
				s[pos] += val;
				pos = pos | (pos + 1);
			}
		}

		int get(int pos) {
			int res = 0;
			while (pos >= 0) {
				res += s[pos];
				pos = (pos & (pos + 1)) - 1;
			}
			return res;
		}
	}

	int[] getId(int[] perm) {
		int n = perm.length;
		int[] res = new int[n - 1];
		Fenwick f = new Fenwick(n);
		for (int i = 0; i < n - 1; i++) {
			res[i] = perm[i] - f.get(perm[i]);
			f.add(perm[i], 1);
		}
		return res;
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
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
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		int res = 0;
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		ArrayList<Integer> cur = new ArrayList<>();
		int[] nextBiggerRight = new int[n];
		Arrays.fill(nextBiggerRight, -1);
		for (int i = 0; i < n; i++) {
			int val = a[i];
			while (cur.size() > 0 && a[cur.get(cur.size() - 1)] < val) {
				int tmp = cur.get(cur.size() - 1);
				nextBiggerRight[tmp] = i;
				cur.remove(cur.size() - 1);
			}
			cur.add(i);
		}
		
		cur = new ArrayList<>();
		int[] nextBiggerLeft = new int[n];
		Arrays.fill(nextBiggerLeft, -1);
		for (int i = n - 1; i >= 0; i--) {
			int val = a[i];
			while (cur.size() > 0 && a[cur.get(cur.size() - 1)] < val) {
				int tmp = cur.get(cur.size() - 1);
				nextBiggerLeft[tmp] = i;
				cur.remove(cur.size() - 1);
			}
			cur.add(i);
		}
		for (int maxPos = 0; maxPos < n; maxPos++) {
			int it1 = maxPos + 1;
			while (it1 != -1 && it1 < n && a[it1] < a[maxPos]) {
				res = Math.max(res, a[maxPos] ^ a[it1]);
				it1 = nextBiggerRight[it1];
			}
			int it2 = maxPos - 1;
			while (it2 != -1 && a[it2] < a[maxPos]) {
				res = Math.max(res, a[maxPos] ^ a[it2]);
				it2 = nextBiggerLeft[it2];
			}
		}
		out.println(res);
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
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
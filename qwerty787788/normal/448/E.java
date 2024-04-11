import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	HashMap<Long, ArrayList<Long>> divs = new HashMap<>();

	ArrayList<Long> getDivs(long x) {
		if (divs.containsKey(x))
			return divs.get(x);
		ArrayList<Long> ans = new ArrayList<>();
		ArrayList<Long> ans2 = new ArrayList<>();
		for (int y = 1; y * 1L * y <= x; y++) {
			if (x % y == 0) {
				ans.add(y + 0L);
				if (y * 1L * y != x) {
					ans2.add(x / y);
				}
			}
		}
		for (int i = ans2.size() - 1; i >= 0; i--) {
			ans.add(ans2.get(i));
		}
		divs.put(x, ans);
		return ans;
	}

	int done = 0;

	void print(long x, long k) {
		if (k == 0 || x == 1) {
			out.print(x);
			out.print(" ");
			done++;
		} else {
			ArrayList<Long> z = getDivs(x);
			for (int i = 0; i < z.size(); i++) {
				print(z.get(i), k - 1);
				if (done == (int) 1e5)
					return;
			}
		}
	}

	void solve() {
		print(in.nextLong(), in.nextLong());
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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
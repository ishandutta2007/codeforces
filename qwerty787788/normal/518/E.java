import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final String resS = "Incorrect sequence";

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			String tmp = in.next();
			if (tmp.equals("?")) {
				a[i] = Integer.MAX_VALUE;
			} else {
				a[i] = Integer.parseInt(tmp);
			}
		}
		for (int start = 0; start < k; start++) {
			ArrayList<Integer> tmp = new ArrayList<>();
			for (int i = start; i < n; i += k) {
				tmp.add(a[i]);
			}
			ArrayList<Integer> res = solve(tmp);
			if (res == null) {
				out.println(resS);
				return;
			}
			int it = 0;
			for (int i = start; i < n; i += k) {
				a[i] = res.get(it++);
			}
		}
		for (int i = 0; i + k < n; i++) {
			if (a[i] >= a[i + k]) {
				out.println(resS);
				return;
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(a[i] + " ");
		}
	}

	ArrayList<Integer> solve(ArrayList<Integer> a) {
		for (int i = 0; i < a.size(); i++) {
			if (a.get(i) != Integer.MAX_VALUE) {
				continue;
			}
			int j = i;
			while (j != a.size() && a.get(j) == Integer.MAX_VALUE) {
				j++;
			}
			int from = -(int) 1e9 - 1000000;
			int to = (int) 1e9 + 1000000;
			if (i != 0) {
				from = a.get(i - 1) + 1;
			}
			if (j != a.size()) {
				to = a.get(j) - 1;
			}
			int cnt = j - i;
			if (cnt > to - from + 1) {
				return null;
			}
			int startFrom = -((cnt - 1) / 2);
			startFrom = Math.max(startFrom, from);
			startFrom = Math.min(startFrom, to - cnt + 1);
			for (int k = 0; k < cnt; k++) {
				a.set(i + k, startFrom + k);
			}
			i = j - 1;
		}
		return a;
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
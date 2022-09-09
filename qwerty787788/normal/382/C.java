import java.io.*;
import java.util.*;

public class CF {

	TreeSet<Integer> get(int[] a, int d) {
		TreeSet<Integer> res = new TreeSet<>();
		int n = a.length;
		int need = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1] != a[i] + d) {
				if (a[i + 1] == a[i] + d * 2) {
					need++;
					res.add(a[i] + d);
					if (need > 1) {
						res = new TreeSet<>();
						return res;
					}
				} else {
					res = new TreeSet<>();
					return res;
				}
			}
		}
		if (need == 0) {
			res.add(a[0] - d);
			res.add(a[a.length - 1] + d);
		}
		return res;
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		Arrays.sort(a);
		if (n == 1) {
			out.println(-1);
			return;
		}
		int d = a[1] - a[0];
		TreeSet<Integer> res = get(a, d);
		if (d % 2 == 0 && d != 0) {
			TreeSet<Integer> more = get(a, d / 2);
			for (int x : more)
				res.add(x);
		}
		out.println(res.size());
		for (int x : res) {
			out.print(x+" ");
		}
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
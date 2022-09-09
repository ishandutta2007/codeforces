import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		long fromStart = 0, fromEnd = 0;
		// start moves first
		ArrayList<Integer> res = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int si = in.nextInt();
			int[] a = new int[si];
			for (int j = 0; j < si; j++) {
				a[j] = in.nextInt();
			}
			for (int j = 0; j < si / 2; j++) {
				fromStart += a[j];
				fromEnd += a[a.length - j - 1];
			}
			if (si % 2 != 0) {
				res.add(a[a.length / 2]);
			}
		}
		Collections.sort(res);
		boolean moveStart = true;
		for (int i = res.size() - 1; i >= 0; i--) {
			int val = res.get(i);
			if (moveStart) {
				fromStart += val;
			} else {
				fromEnd += val;
			}
			moveStart = !moveStart;
		}
		out.println(fromStart + " " + fromEnd);
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
import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int m = in.nextInt();
		long tot = 0;
		ArrayList<Integer> arr = new ArrayList<>();
		int MAX = (int) 1e5 + 5;
		int[] ty = new int[m];
		int[] l = new int[m];
		int[] c = new int[m];
		for (int i = 0; i < m; i++) {
			ty[i] = in.nextInt();
			l[i] = in.nextInt();
			if (ty[i] == 2) {
				c[i] = in.nextInt();
			}
		}
		int n = in.nextInt();
		long[] ask = new long[n];
		for (int i = 0; i < n; i++)
			ask[i] = in.nextLong();
		int it = 0;
		for (int i = 0; i < m; i++) {
			if (it == n)
				break;
			int type = ty[i];
			if (type == 1) {
				int xi = l[i];
				tot++;
				if (tot < MAX)
					arr.add(xi);
				if (tot == ask[it]) {
					it++;
					out.print(xi + " ");
				}
			} else {
				int li = l[i];
				int ci = c[i];
				int more = 0;
				for (int j = 0; j < ci; j++) {
					for (int k = 0; k < li; k++) {
						if (tot + more < MAX) {
							arr.add(arr.get(k));
							more++;
						} else {
							break;
						}
					}
					if (tot + more < MAX) {
					} else {
						break;
					}
				}
				long nTot = tot + li * 1L * ci;
				while (it < n && ask[it] <= nTot) {
					long more1 = ask[it] - tot - 1;
					more1 %= li;
					out.print(arr.get((int) more1) + " ");
					it++;
				}
				tot += li * 1L * ci;
			}
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
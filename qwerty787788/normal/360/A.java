import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] type = new int[m];
		int[] l = new int[m];
		int[] r = new int[m];
		int[] d = new int[m];
		int[] max = new int[m];
		for (int i = 0; i < m; i++) {
			type[i] = in.nextInt();
			if (type[i] == 1) {
				l[i] = in.nextInt() - 1;
				r[i] = in.nextInt() - 1;
				d[i] = in.nextInt();
			} else {
				l[i] = in.nextInt() - 1;
				r[i] = in.nextInt() - 1;
				max[i] = in.nextInt();
			}
		}
		int[] curMax = new int[n];
		int[] curAdd = new int[n];
		Arrays.fill(curMax, (int) 1e9);
		for (int i = 0; i < m; i++) {
			if (type[i] == 1) {
				for (int j = l[i]; j <= r[i]; j++)
					curAdd[j] += d[i];
			} else {
				for (int j = l[i]; j <= r[i]; j++) {
					curMax[j] = Math.min(curMax[j], max[i] - curAdd[j]);
				}
			}
		}
		int[] real = new int[n];
		for (int i = 0; i < n; i++)
			real[i] = curMax[i];
		for (int i = 0; i < m; i++) {
			if (type[i] == 1) {
				for (int j = l[i]; j <= r[i]; j++)
					real[j] += d[i];
			} else {
				int ma = Integer.MIN_VALUE;
				for (int j = l[i]; j <= r[i]; j++) {
					ma = Math.max(ma, real[j]);
				}
				if (ma != max[i]) {
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.print(curMax[i] + " ");
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
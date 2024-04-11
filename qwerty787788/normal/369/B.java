import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int l = in.nextInt();
		int r = in.nextInt();
		int sAll = in.nextInt();
		int sK = in.nextInt();
		int[] a = new int[n];
		int su = 0;
		for (int i = 0; i < n; i++) {
			a[i] = l;
			su += l;
		}
		while (su < sAll) {
			for (int j = n - 1; j >= 0; j--) {
				if (su < sAll) {
					su++;
					a[j]++;
				} else {
					break;
				}
			}
		}
		int topK = 0;
		for (int i = 0; i < k; i++)
			topK += a[n - i - 1];
		while (topK < sK) {
			int left = 0;
			for (int i = n - 1; i >= 0; i--) {
				while (a[left] == l)
					left++;
				while (a[i] < r && topK < sK) {
					a[i]++;
					topK++;
					a[left]--;
					if (topK == sK)
						break;
					while (a[left] == l)
						left++;
				}
				if (topK == sK)
					break;
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(a[i] + " ");
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
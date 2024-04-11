import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		boolean[] used = new boolean[n];
		for (int i =0 ; i <n ;i++)
			a[i] = in.nextInt();
		int maxCnt = 0, cnt = 0;
		for (int i=0 ; i< n; i++) {
			if (!used[i]) {
				int tmp = 0;
				for (int j = i; j < n; j++) {
					if (a[i] == a[j]) {
						used[j] = true;
						tmp++;
					}
				}
				maxCnt = Math.max(maxCnt, tmp);
				cnt++;
			}
		}
		out.println(maxCnt +" " + cnt);
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
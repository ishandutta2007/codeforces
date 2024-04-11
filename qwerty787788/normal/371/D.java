import java.io.*;
import java.util.*;

public class CF {

	TreeSet<Integer> free = new TreeSet<>();
	int[] now;
	int[] a;
	int n;

	void go(int v, int cnt) {
		Integer x = free.higher(v - 1);
		if (x == null) {
			return;
		}
		v = x;
		int can = Math.min(cnt, a[v] - now[v]);
		cnt -= can;
		now[v] += can;
		if (now[v] == a[v])
			free.remove(v);
		if (cnt > 0)
			go(v + 1, cnt);
	}

	void solve() {
		n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		for (int i = 0; i < n; i++)
			free.add(i);
		int m = in.nextInt();
		now = new int[n];
		for (int i = 0; i < m; i++) {
			int type = in.nextInt();
			if (type == 1) {
				go(in.nextInt() - 1, in.nextInt());
			} else {
				out.println(now[in.nextInt() - 1]);
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
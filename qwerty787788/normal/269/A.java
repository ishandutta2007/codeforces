import java.io.*;
import java.util.*;

public class CF165Div1 {
	FastScanner in;
	PrintWriter out;

	class Lar implements Comparable<Lar> {
		int k;
		long cnt;

		public Lar(int k, int cnt) {
			super();
			this.k = k;
			this.cnt = cnt;
		}

		@Override
		public int compareTo(Lar o) {
			return k - o.k;
		}
		
	}
	
	void solve() {
		int n = in.nextInt();
		Lar[] a = new Lar[n];
		for (int i = 0; i < n; i++)
			a[i] = new Lar(in.nextInt(), in.nextInt());
		Arrays.sort(a);
		Lar cur = new Lar(a[0].k, (int) a[0].cnt);
		for (int i = 1; i < n; i++) {
			while (cur.cnt != 1 && cur.k < a[i].k) {
				cur.cnt = 1 + (cur.cnt - 1) / 4;
				cur.k++;
			}
			cur.k = a[i].k;
			cur.cnt = Math.max(cur.cnt, a[i].cnt);
		}
		while (cur.cnt != 1) {
			cur.cnt = 1 + (cur.cnt - 1) / 4;
			cur.k++;
		}
		if (cur.k == a[n - 1].k)
			cur.k++;
		out.println(cur.k);
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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
		new CF165Div1().runIO();
	}
}
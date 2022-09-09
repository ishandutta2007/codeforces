import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Obj implements Comparable<Obj> {
		int id;
		int h;

		public Obj(int id, int h) {
			super();
			this.id = id;
			this.h = h;
		}

		@Override
		public int compareTo(Obj o) {
			return Integer.compare(h, o.h);
		}

	}

	Obj[] a;
	int n;
	int cnt = 0;

	void solve() {
		n = in.nextInt();
		a = new Obj[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Obj(i, in.nextInt());
		}
		Arrays.sort(a);
		int pos3 = -1;
		int pos21 = -1, pos22 = -1;
		for (int i = 0; i + 2 < n; i++) {
			if (a[i].h == a[i + 2].h) {
				pos3 = i;
			}
		}
		if (pos3 != -1) {
			out.println("YES");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < pos3; j++) {
					out.print(a[j].id + 1);
					out.print(" ");
				}
				for (int k = 0; k < 3; k++) {
					out.print(a[pos3 + (i + k) % 3].id + 1);
					out.print(" ");
				}
				for (int j = pos3 + 3; j < n; j++) {
					out.print(a[j].id + 1);
					out.print(" ");
				}
				out.println();
			}
			return;
		}
		for (int i = 0; i + 1 < n; i++) {
			if (a[i].h == a[i + 1].h) {
				if (pos21 == -1) {
					pos21 = i;
				} else {
					pos22 = i;
				}
			}
		}
		if (pos22 == -1) {
			out.println("NO");
			return;
		}
		out.println("YES");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < pos21; j++) {
				out.print(a[j].id + 1);
				out.print(" ");
			}
			if (i == 0 || i == 2) {
				out.print(a[pos21].id + 1);
				out.print(" ");
				out.print(a[pos21 + 1].id + 1);
				out.print(" ");
			} else {
				out.print(a[pos21 + 1].id + 1);
				out.print(" ");
				out.print(a[pos21].id + 1);
				out.print(" ");
			}
			for (int j = pos21 + 2; j < pos22; j++) {
				out.print(a[j].id + 1);
				out.print(" ");
			}
			if (i == 0 || i == 1) {
				out.print(a[pos22].id + 1);
				out.print(" ");
				out.print(a[pos22 + 1].id + 1);
				out.print(" ");
			} else {
				out.print(a[pos22 + 1].id + 1);
				out.print(" ");
				out.print(a[pos22].id + 1);
				out.print(" ");
			}
			for (int j = pos22 + 2; j < n; j++) {
				out.print(a[j].id + 1);
				out.print(" ");
			}
			out.println();
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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}
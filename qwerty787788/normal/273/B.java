import java.io.*;
import java.util.*;

public class CFDiv1 {
	FastScanner in;
	PrintWriter out;

	class Obj implements Comparable<Obj> {
		int x, y;

		public Obj(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Obj o) {
			if (o.x == x)
				return y - o.y;
			return x - o.x;
		}

	}

	void solve() {
		int n = in.nextInt();
		Obj[] a = new Obj[2 * n];
		for (int i = 0; i < n; i++) {
			a[i] = new Obj(in.nextInt(), i + 1);
		}
		for (int i = 0; i < n; i++) {
			a[i + n] = new Obj(in.nextInt(), i + 1);
		}
		Arrays.sort(a);
		int m = in.nextInt();
		long ans = 1;
		int st = 0;
		while (true) {
			if (st >= 2 * n)
				break;
			int sp = st;
			while (sp < 2 * n && a[sp].x == a[st].x)
				sp++;
			int len = sp - st;
			for (int i = st; i < sp; i++) {
				if (len > 1 && a[i + 1].y == a[i].y) {
					long add = (len * 1L * (len - 1) / 2) % m;
					ans = (ans * add) % m;
					i++;
					len -= 2;
				} else {
					ans = (ans * len) % m;
					len--;
				}
			}
			st = sp;
		}
		out.println(ans % m);
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
		new CFDiv1().runIO();
	}
}
import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	class Block implements Comparable<Block> {
		int begin;
		int len;
		boolean deleted;

		public Block(int begin, int len) {
			super();
			this.begin = begin;
			this.len = len;
		}

		@Override
		public int compareTo(Block o) {
			if (begin < o.begin) {
				return -1;
			}
			if (begin > o.begin) {
				return 1;
			}
			return 0;
		}
	}

	ArrayList<Block> d;
	int m, id;
	boolean[] used;

	String alloc(int x) {
		for (int i = 0; i < m; i++) {
			int j = i;
			while (j < m && !used[j]) {
				++j;
			}
			if (j - i >= x) {
				id++;
				d.add(new Block(i, x));
				for (int z = i; z < i + x; z++) {
					used[z] = true;
				}
				return id + "";
			}
			i = j;
		}
		return "NULL";
	}

	void erase(int x) {
		--x;
		if (x < 0 || x >= id || d.get(x).deleted) {
			out.println("ILLEGAL_ERASE_ARGUMENT");
			return;
		}
		for (int i = 0; i < d.get(x).len; i++) {
			used[d.get(x).begin + i] = false;
		}
		d.get(x).deleted = true;
	}

	void defragment() {
		Arrays.fill(used, false);
		int cur = 0;
		ArrayList<Block> e = new ArrayList<Block>();
		for (Block r : d) {
			if (r.deleted) {
				continue;
			}
			e.add(r);
		}
		Collections.sort(e);
		for (int i = 0; i < e.size(); i++) {
			e.get(i).begin = cur;
			for (int j = 0; j < e.get(i).len; j++) {
				used[cur++] = true;
			}
		}
	}

	void solve() {
		int t = nextInt();
		m = nextInt();
		id = 0;
		d = new ArrayList<Block>();
		used = new boolean[m];
		for (int i = 0; i < t; i++) {
			String s = nextToken();
			if (s.equals("alloc")) {
				int x = nextInt();
				out.println(alloc(x));
			} else if (s.equals("erase")) {
				int x = nextInt();
				erase(x);
			} else if (s.equals("defragment")) {
				defragment();
			}
		}
	}
}
import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class CF22 {
	FastScanner in;
	PrintWriter out;

	class Pair implements Comparable<Pair> {
		int x, y;

		public Pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			if (x != o.x)
				return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
		}

		@Override
		public String toString() {
			return "Pair [x=" + x + ", y=" + y + "]";
		}

	}

	Pair gen(String s) {
		Pair p = new Pair(0, s.length());
		for (int i = 0; i < s.length(); i++)
			if (s.charAt(i) == 'r') {
				p.x++;
			}
		return p;
	}

	HashMap<String, Integer> hm = new HashMap<>();

	int getId(String s) {
		Integer x = hm.get(s);
		if (x != null)
			return x;
		hm.put(s, hm.size());
		result.add(gen(s));
		g.add(new ArrayList<Integer>());
		return hm.size() - 1;
	}

	ArrayList<Pair> result = new ArrayList<>();
	ArrayList<ArrayList<Integer>> g = new ArrayList<>();

	class Pair2 implements Comparable<Pair2> {
		int pos;
		Pair p;

		public Pair2(int pos, Pair p) {
			super();
			this.pos = pos;
			this.p = p;
		}

		@Override
		public int compareTo(Pair2 o) {
			return p.compareTo(o.p);
		}

		@Override
		public String toString() {
			return "Pair2 [pos=" + pos + ", p=" + p + "]";
		}

	}

	boolean[] was;

	void go(int v, Pair p) {
		if (was[v])
			return;
		was[v] = true;
		result.set(v, p);
		for (int to : g.get(v)) {
			go(to, p);
		}
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = getId(in.next().toLowerCase());
		}
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int s = getId(in.next().toLowerCase());
			int toId = getId(in.next().toLowerCase());
			g.get(toId).add(s);
		}
		Pair2[] all = new Pair2[hm.size()];
		for (int i = 0; i < hm.size(); i++) {
			all[i] = new Pair2(i, result.get(i));
		}
		Arrays.sort(all);
		was = new boolean[hm.size()];
		for (int i = 0; i < all.length; i++) {
			go(all[i].pos, all[i].p);
		}

		long resLen = 0;
		int cntR = 0;
		for (int i = 0; i < n; i++) {
			Pair another = result.get(a[i]);
			resLen += another.y;
			cntR += another.x;
		}
		out.println(cntR + " " + resLen);
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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF22().runIO();
	}
}
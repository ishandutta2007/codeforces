import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	long ansFrom, ansTo;

	class Segment implements Comparable<Segment> {
		long from, to;

		public Segment(long from, long to) {
			super();
			this.from = from;
			this.to = to;
		}

		@Override
		public int compareTo(Segment o) {
			if (from == o.from) {
				return Long.compare(to, o.to);
			}
			return Long.compare(from, o.from);
		}

	}

	void solve() {
		int h = in.nextInt();
		int q = in.nextInt();
		long[] from = new long[h];
		long[] to = new long[h];
		from[0] = 1;
		to[0] = 1;
		for (int i = 1; i < h; i++) {
			from[i] = from[i - 1] * 2;
			to[i] = to[i - 1] * 2 + 1;
		}
		ArrayList<Segment> allQ = new ArrayList<>();
		ansFrom = from[h - 1];
		ansTo = to[h - 1];
		for (int qq = 0; qq < q; qq++) {
			int layer = in.nextInt();
			long fromLayer = in.nextLong();
			long toLayer = in.nextLong();
			int ans = in.nextInt();
			int add = h - layer;
			fromLayer = fromLayer << add;
			toLayer = ((toLayer + 1) << add) - 1;
			if (ans == 1) {
				ansFrom = Math.max(ansFrom, fromLayer);
				ansTo = Math.min(ansTo, toLayer);
			} else {
				allQ.add(new Segment(fromLayer, toLayer));
			}
		}
		if (ansFrom > ansTo) {
			out.println("Game cheated!");
			return;
		}
		TreeSet<Segment> ts = new TreeSet<>();
		ts.add(new Segment(ansFrom, ansTo));
		for (Segment rem : allQ) {
			while (true) {
				Segment z = ts.lower(new Segment(rem.to + 1, -1));
				if (z == null) {
					break;
				}
				if (z.to < rem.from) {
					break;
				}
				if (z.to > rem.to) {
					ts.remove(z);
					if (z.from < rem.from) {
						ts.add(new Segment(z.from, rem.from - 1));
					}
					ts.add(new Segment(rem.to + 1, z.to));
					continue;
				}
				if (z.from >= rem.from) {
					ts.remove(z);
					continue;
				}
				ts.remove(z);
				ts.add(new Segment(z.from, rem.from - 1));
				break;
			}
		}
		if (ts.size() == 0) {
			out.println("Game cheated!");
			return;
		}
		if (ts.size() > 1) {
			out.println("Data not sufficient!");
			return;
		}
		Segment z = ts.pollFirst();
		if (z.from == z.to) {
			out.println(z.from);
			return;
		}
		out.println("Data not sufficient!");
		return;
	}

	void check(long value) {

	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
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
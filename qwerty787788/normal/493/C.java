import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Obj implements Comparable<Obj> {
		int pos;
		int id;

		public Obj(int pos, int id) {
			super();
			this.pos = pos;
			this.id = id;
		}

		@Override
		public int compareTo(Obj o) {
			return Integer.compare(pos, o.pos);
		}

	}

	void solve() {
		int n = in.nextInt();
		ArrayList<Obj> all = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			all.add(new Obj(in.nextInt(), 0));
		}
		int m = in.nextInt();
		for (int i = 0; i < m; i++) {
			all.add(new Obj(in.nextInt(), 1));
		}
		Collections.sort(all);
		int curA = 0, curB = 0;
		int curD = 0;
		for (Obj o : all) {
			if (o.id == 0) {
				if (o.pos <= curD) {
					curA += 2;
				} else {
					curA += 3;
				}
			} else {
				if (o.pos <= curD) {
					curB += 2;
				} else {
					curB += 3;
				}
			}
		}
		int bestA = curA;
		int bestB = curB;
		for (int i = 0; i < all.size();) {
			while (i < all.size() && all.get(i).pos <= curD) {
				i++;
			}
			if (i == all.size())
				break;
			curD = all.get(i).pos;
			for (int j = i; j < all.size() && all.get(j).pos == curD; j++) {
				if (all.get(j).id == 0) {
					curA--;
				} else {
					curB--;
				}
			}
			if (curA - curB > bestA - bestB) {
				bestA = curA;
				bestB = curB;
			}
			if (curA - curB == bestA - bestB && curA > bestA) {
				bestA = curA;
				bestB = curB;
			}
		}
		out.println(bestA + ":" + bestB);
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
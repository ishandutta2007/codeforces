import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Pos {
		int x, y;

		public Pos(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pos other = (Pos) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		private CF getOuterType() {
			return CF.this;
		}

	}

	HashMap<Pos, Integer> hm = new HashMap<>();

	class Cube implements Comparable<Cube> {
		int value;
		Pos p;
		int id;

		public Cube(int value, Pos p, int id) {
			super();
			this.value = value;
			this.p = p;
			this.id = id;
		}

		@Override
		public int compareTo(Cube o) {
			return Integer.compare(value, o.value);
		}

	}

	boolean canUseCube(Cube x) {
		for (int dx = -1; dx <= 1; dx++) {
			Integer z = hm.get(new Pos(x.p.x + dx, x.p.y + 1));
			if (z != null) {
				if (down[z] == 1) {
					return false;
				}
			}
		}
		return true;
	}

	int[] down;

	void solve() {
		int n = in.nextInt();
		Cube[] a = new Cube[n];
		for (int i = 0; i < n; i++) {
			Pos p = new Pos(in.nextInt(), in.nextInt());
			hm.put(p, i);
			a[i] = new Cube(i, p, i);
		}
		down = new int[n];
		for (int i = 0; i < n; i++) {
			if (a[i].p.y == 0) {
				down[i] = Integer.MAX_VALUE / 2;
			} else {
				for (int dx = -1; dx <= 1; dx++) {
					if (hm.containsKey(new Pos(a[i].p.x + dx, a[i].p.y - 1))) {
						down[i]++;
					}
				}
			}
		}
		TreeSet<Cube> allCubesCanUse = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			if (canUseCube(a[i])) {
				allCubesCanUse.add(a[i]);
			}
		}
		final int mod = (int) 1e9 + 9;
		int res = 0;
		for (int move = 0; move < n; move++) {
			Cube cur = (move % 2 == 0) ? allCubesCanUse.last() : allCubesCanUse
					.first();
//			System.err.println(cur.id);
			res = (int) ((res * 1L * n + cur.id) % mod);
			allCubesCanUse.remove(cur);
			hm.remove(cur.p);
			for (int dx = -1; dx <= 1; dx++) {
				Integer id = hm.get(new Pos(cur.p.x + dx, cur.p.y + 1));
				if (id != null) {
					down[id]--;
					if (down[id] == 1) {
						for (int dx2 = -1; dx2 <= 1; dx2++) {
							Integer id2 = hm.get(new Pos(cur.p.x + dx + dx2,
									cur.p.y));
							if (id2 != null) {
								allCubesCanUse.remove(a[id2]);
							}
						}
					}
				}
				Integer id2 = hm.get(new Pos(cur.p.x + dx, cur.p.y - 1));
				if (id2 != null) {
					if (canUseCube(a[id2])) {
						allCubesCanUse.add(a[id2]);
					}
				}
			}
		}
		out.println(res);
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
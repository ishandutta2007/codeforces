import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Point {
		int x, y;
		Point[][] ne;
		boolean[] check;
		int id;

		Point(int x, int y, int id) {
			this.x = x;
			this.y = y;
			this.id = id;
			check = new boolean[2];
			ne = new Point[2][2];
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + ", ne=" + Arrays.toString(ne)
					+ ", check=" + Arrays.toString(check) + ", id=" + id + "]";
		}

	}

	void solve() {
		int n = in.nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(in.nextInt(), in.nextInt(), i);
		}
		Comparator<Point> yComp = new Comparator<CF.Point>() {

			@Override
			public int compare(Point o1, Point o2) {
				if (o1.y == o2.y)
					return Integer.compare(o1.x, o2.x);
				return Integer.compare(o1.y, o2.y);
			}
		};
		Comparator<Point> xComp = new Comparator<CF.Point>() {

			@Override
			public int compare(Point o1, Point o2) {
				if (o1.x == o2.x)
					return Integer.compare(o1.y, o2.y);
				return Integer.compare(o1.x, o2.x);
			}
		};
		Arrays.sort(a, xComp);
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				a[i].ne[0][0] = a[i - 1];
			}
			if (i < n - 1) {
				a[i].ne[0][1] = a[i + 1];
			}
		}
		Arrays.sort(a, yComp);
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				a[i].ne[1][0] = a[i - 1];
			}
			if (i < n - 1) {
				a[i].ne[1][1] = a[i + 1];
			}
		}
		ArrayList<Integer> queue = new ArrayList<>();
		ArrayList<Integer> coord = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (a[i].ne[0][1] != null && a[i].x + 1 < a[i].ne[0][1].x) {
				queue.add(a[i].id);
				coord.add(0);
			}
			if (a[i].ne[1][1] != null && a[i].y + 1 < a[i].ne[1][1].y) {
				queue.add(a[i].id);
				coord.add(1);
			}
		}
		Arrays.sort(a, new Comparator<Point>() {

			@Override
			public int compare(Point o1, Point o2) {
				return Integer.compare(o1.id, o2.id);
			}
		});
		int comps = 1;
		int it = 0;
		while (it < queue.size()) {
			int v = queue.get(it);
			int cc = coord.get(it++);
			a[v].check[cc] = false;
			if (a[v].ne[cc][1] != null) {
				boolean ok = false;
				if (cc == 0) {
					if (a[v].x + 1 < a[v].ne[cc][1].x) {
						ok = true;
					}
				} else {
					if (a[v].y + 1 < a[v].ne[cc][1].y) {
						ok = true;
					}
				}
				if (ok) {
					int sz = 1;
					Point left = a[v], right = a[v].ne[cc][1];
					boolean leftPartSmaller = true;
					while (true) {
						Point leftNext = left.ne[cc][0];
						Point rightNext = right.ne[cc][1];
						if (leftNext == null) {
							break;
						}
						if (rightNext == null) {
							leftPartSmaller = false;
							break;
						}
						left = leftNext;
						right = rightNext;
						sz++;
					}
					Point[] newPart = new Point[sz];
					int iter = 0;
					comps++;
					if (leftPartSmaller) {
						Point cur = a[v];
						while (cur != null) {
							newPart[iter++] = cur;
							cur = cur.ne[cc][0];
						}
					} else {
						Point cur = a[v].ne[cc][1];
						while (cur != null) {
							newPart[iter++] = cur;
							cur = cur.ne[cc][1];
						}
					}
					a[v].ne[cc][1].ne[cc][0] = null;
					a[v].ne[cc][1] = null;
					for (Point p : newPart) {
						for (int co = 0; co < 2; co++) {
							if (co == cc)
								continue;
							Point prev = p.ne[co][0];
							Point next = p.ne[co][1];
							if (prev != null) {
								prev.ne[co][1] = next;
								if (next != null) {
									if (co == 0) {
										if (prev.x + 1 < next.x) {
											if (!prev.check[co]) {
												queue.add(prev.id);
												prev.check[co] = true;
												coord.add(co);
											}
										}
									} else {
										if (prev.y + 1 < next.y) {
											if (!prev.check[co]) {
												queue.add(prev.id);
												prev.check[co] = true;
												coord.add(co);
											}
										}
									}
								}
							}
							if (next != null) {
								next.ne[co][0] = prev;
							}
						}
					}
					Arrays.sort(newPart, cc == 0 ? yComp : xComp);
					for (int i = 0; i < newPart.length; i++) {
						if (i == 0) {
							newPart[i].ne[1 - cc][0] = null;
						} else {
							newPart[i].ne[1 - cc][0] = newPart[i - 1];
						}
						if (i == newPart.length - 1) {
							newPart[i].ne[1 - cc][1] = null;
						} else {
							newPart[i].ne[1 - cc][1] = newPart[i + 1];
						}
					}
					for (int i = 0; i < newPart.length; i++) {
						if (newPart[i].ne[1 - cc][1] != null) {
							if (1 - cc == 0) {
								if (newPart[i].x + 1 < newPart[i].ne[1 - cc][1].x) {
									if (!newPart[i].check[1 - cc]) {
										newPart[i].check[1 - cc] = true;
										queue.add(newPart[i].id);
										coord.add(1 - cc);
									}
								}
							} else {
								if (newPart[i].y + 1 < newPart[i].ne[1 - cc][1].y) {
									if (!newPart[i].check[1 - cc]) {
										newPart[i].check[1 - cc] = true;
										queue.add(newPart[i].id);
										coord.add(1 - cc);
									}
								}
							}
						}
					}
				}
			}
		}
		out.println(comps);
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
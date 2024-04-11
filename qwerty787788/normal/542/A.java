import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Segment implements Comparable<Segment> {
		int id;
		int from, to;
		int len;
		int sortedId;

		Segment(int from, int to, int id) {
			this.from = from;
			this.to = to;
			this.id = id;
			this.len = to - from;
		}

		@Override
		public int compareTo(Segment o) {
			return -Integer.compare(len, o.len);
		}
	}

	class SegmentWithCoef {
		int from, to, coef, id;

		public SegmentWithCoef(int from, int to, int coef, int id) {
			super();
			this.from = from;
			this.to = to;
			this.coef = coef;
			this.id = id;
		}

	}

	class Event implements Comparable<Event> {
		int type;
		int id;
		int time;

		public Event(int type, int id, int time) {
			super();
			this.type = type;
			this.id = id;
			this.time = time;
		}

		@Override
		public int compareTo(Event o) {
			return Integer.compare(time, o.time);
		}

	}

	int size(Segment s1, SegmentWithCoef s2) {
		int res = Math.min(s2.to, s1.to) - Math.max(s1.from, s2.from);
		return Math.max(res, 0);
	}

	class Pos implements Comparable<Pos> {
		int type;
		int id;
		int value;

		Pos(int type, int id, int value) {
			this.type = type;
			this.id = id;
			this.value = value;
		}

		@Override
		public int compareTo(Pos o) {
			if (value == o.value) {
				return Integer.compare(type, o.type);
			}
			return Integer.compare(value, o.value);
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		Segment[] a = new Segment[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Segment(in.nextInt(), in.nextInt(), i);
		}
		ArrayList<Event> allEvents = new ArrayList<>();
		for (Segment seg : a) {
			allEvents.add(new Event(+1, seg.id, seg.from));
			allEvents.add(new Event(-1, seg.id, seg.to));
		}
		SegmentWithCoef[] bSaved = new SegmentWithCoef[m];
		SegmentWithCoef[] b = new SegmentWithCoef[m];
		for (int i = 0; i < m; i++) {
			b[i] = new SegmentWithCoef(in.nextInt(), in.nextInt(),
					in.nextInt(), i);
			bSaved[i] = b[i];
		}
		long ans = 0;
		int ans1 = -1, ans2 = -1;
		{
			Collections.sort(allEvents);
			int evIt = 0;
			Arrays.sort(b, new Comparator<SegmentWithCoef>() {
				@Override
				public int compare(SegmentWithCoef o1, SegmentWithCoef o2) {
					return Integer.compare(o1.from, o2.from);
				}
			});
			TreeSet<Segment> ts = new TreeSet<>(new Comparator<Segment>() {
				@Override
				public int compare(Segment o1, Segment o2) {
					if (o1.to == o2.to) {
						return Integer.compare(o1.id, o2.id);
					}
					return Integer.compare(o1.to, o2.to);
				}
			});
			for (SegmentWithCoef seg : b) {
				while (evIt != allEvents.size()
						&& allEvents.get(evIt).time <= seg.from) {
					Event e = allEvents.get(evIt++);
					if (e.type == 1) {
						ts.add(a[e.id]);
					} else {
						ts.remove(a[e.id]);
					}
				}
				if (ts.size() != 0) {
					Segment anotherSeg = ts.last();
					int sz = size(anotherSeg, seg);
					if (sz > 0) {
						long curAns = sz * 1L * seg.coef;
						if (curAns > ans) {
							ans = curAns;
							ans1 = anotherSeg.id;
							ans2 = seg.id;
						}
					}
				}
			}
		}
		{
			Collections.sort(allEvents, new Comparator<Event>() {
				@Override
				public int compare(Event o1, Event o2) {
					return -Integer.compare(o1.time, o2.time);
				}
			});
			int evIt = 0;
			Arrays.sort(b, new Comparator<SegmentWithCoef>() {
				@Override
				public int compare(SegmentWithCoef o1, SegmentWithCoef o2) {
					return -Integer.compare(o1.to, o2.to);
				}
			});
			TreeSet<Segment> ts = new TreeSet<>(new Comparator<Segment>() {
				@Override
				public int compare(Segment o1, Segment o2) {
					if (o1.from == o2.from) {
						return Integer.compare(o1.id, o2.id);
					}
					return Integer.compare(o1.from, o2.from);
				}
			});
			for (SegmentWithCoef seg : b) {
				while (evIt != allEvents.size()
						&& allEvents.get(evIt).time >= seg.to) {
					Event e = allEvents.get(evIt++);
					if (e.type == -1) {
						ts.add(a[e.id]);
					} else {
						ts.remove(a[e.id]);
					}
				}
				if (ts.size() != 0) {
					Segment anotherSeg = ts.first();
					if (anotherSeg != null) {
						int sz = size(anotherSeg, seg);
						if (sz > 0) {
							long curAns = sz * 1L * seg.coef;
							if (curAns > ans) {
								ans = curAns;
								ans1 = anotherSeg.id;
								ans2 = seg.id;
							}
						}
					}
				}
			}
		}
		ArrayList<Pos> allPos = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			allPos.add(new Pos(0, a[i].id, a[i].to));
		}
		for (int i = 0; i < m; i++) {
			allPos.add(new Pos(1, b[i].id, b[i].to));
		}
		Collections.sort(allPos);
		int[] usePosA = new int[n];
		int[] usePosB = new int[m];
		for (int i = 0; i < allPos.size(); i++) {
			Pos p = allPos.get(i);
			if (p.type == 0) {
				usePosA[p.id] = i;
			} else {
				usePosB[p.id] = i;
			}
		}
		int[] coefs = new int[m];
		for (int i = 0; i < m; i++) {
			coefs[b[i].id] = b[i].coef;
		}
		SegmentTree st = new SegmentTree(coefs);
		Arrays.sort(a, new Comparator<Segment>() {

			@Override
			public int compare(Segment o1, Segment o2) {
				return Integer.compare(o1.from, o2.from);
			}
		});
		Arrays.sort(b, new Comparator<SegmentWithCoef>() {
			@Override
			public int compare(SegmentWithCoef o1, SegmentWithCoef o2) {
				return Integer.compare(o1.from, o2.from);
			}
		});
		int it = 0;
		for (Segment s : a) {
			while (it != b.length && b[it].from <= s.from) {
				SegmentWithCoef seg = b[it++];
				st.update(0, 0, st.n - 1, usePosB[seg.id], seg.id);
			}
			int id = st.getMax(0, 0, st.n - 1, usePosA[s.id], st.n - 1);
			if (id != -1) {
				SegmentWithCoef seg = bSaved[id];
				int sz = size(s, seg);
				if (sz != 0) {
					long curAns = sz * 1L * seg.coef;
					if (curAns > ans) {
						ans = curAns;
						ans1 = s.id;
						ans2 = seg.id;
					}
				}
			}
		}
		out.println(ans);
		if (ans != 0) {
			out.println((1 + ans1) + " " + (1 + ans2));
		}
	}

	class SegmentTree {
		int[] maxId;
		int[] vals;
		int n;

		SegmentTree(int[] vals) {
			this.vals = vals;
			this.n = 1000000;
			maxId = new int[n * 4];
			Arrays.fill(maxId, -1);
		}

		void update(int v, int l, int r, int need, int value) {
			if (l == r) {
				maxId[v] = value;
			} else {
				int m = (l + r) >>> 1;
				if (need <= m) {
					update(v * 2 + 1, l, m, need, value);
				} else {
					update(v * 2 + 2, m + 1, r, need, value);
				}
				maxId[v] = getMax(maxId[v * 2 + 1], maxId[v * 2 + 2]);
			}
		}

		int getMax(int v, int l, int r, int needL, int needR) {
			if (needL > needR) {
				return -1;
			}
			if (l == needL && r == needR) {
				return maxId[v];
			}
			int m = (l + r) >>> 1;
			return getMax(getMax(v * 2 + 1, l, m, needL, Math.min(needR, m)),
					getMax(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR));
		}

		int getMax(int x, int y) {
			if (x == -1 || y == -1) {
				return x == -1 ? y : x;
			}
			return vals[x] > vals[y] ? x : y;
		}
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
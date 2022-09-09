import java.io.*;
import java.util.*;

public class CF {

	class Road {
		int fr, to, c;

		Road(int fr, int to, int c) {
			this.fr = fr;
			this.to = to;
			this.c = c;
		}
	}

	class Road2 {
		int fr, to;
		int l, r;
		int id;
		int now;

		Road2(int fr, int to, int l, int r, int id) {
			this.fr = fr;
			this.to = to;
			this.l = l;
			this.r = r;
			this.id = id;
			this.now = l;
		}
	}

	ArrayList<Road>[] g;
	ArrayList<Road2>[] g2;

	class Event {
		int who;
		int where;
		long time;

		Event(int who, int where, long time) {
			this.who = who;
			this.where = where;
			this.time = time;
		}
	}

	int n, m, k;

	boolean canWin(int s1, int s2, int f) {
		if (s1 == f && s2 != f) {
			int[] ans = new int[k];
			for (int i = 0; i < n; i++)
				for (Road2 r : g2[i])
					ans[r.id] = r.now;
			out.println("WIN");
			for (int i = 0; i < k; i++)
				out.print(ans[i] + " ");
			return true;
		}
		boolean[] was1 = new boolean[n];
		boolean[] was2 = new boolean[n];
		was1[s1] = true;
		was2[s2] = true;
		PriorityQueue<Event> pq = new PriorityQueue<>(10,
				new Comparator<Event>() {
					@Override
					public int compare(Event o1, Event o2) {
						if (o1.time != o2.time)
							return Long.compare(o1.time, o2.time);
						return -Integer.compare(o1.who, o2.who);
					}
				});
		pq.add(new Event(0, s1, 0));
		pq.add(new Event(1, s2, 0));
		long[] d1 = new long[n];
		long[] d2 = new long[n];
		Arrays.fill(d1, Long.MAX_VALUE);
		Arrays.fill(d2, Long.MAX_VALUE);
		d1[s1] = 0;
		d2[s2] = 0;
		for (int i = 0; i < n; i++)
			for (Road2 r : g2[i])
				r.now = -1;
		while (pq.size() > 0) {
			Event e = pq.poll();
			int v = e.where;
			if (e.who == 0) {
				if (d1[v] != e.time)
					continue;
			}
			if (e.who == 1) {
				if (d2[v] != e.time)
					continue;
			}
			if (v == f) {
				if (e.who == 0) {
					int[] ans = new int[k];
					for (int i = 0; i < n; i++)
						for (Road2 r : g2[i])
							ans[r.id] = r.now == -1 ? r.l : r.now;
					out.println("WIN");
					for (int i = 0; i < k; i++)
						out.print(ans[i] + " ");
					return true;
				} else {
					return false;
				}
			}
			for (int i = 0; i < g[v].size(); i++) {
				int next = g[v].get(i).to;
				long time = e.time + g[v].get(i).c;
				if (e.who == 0) {
					if (d1[next] > time) {
						d1[next] = time;
						was1[next] = true;
						pq.add(new Event(0, next, time));
					}
				}
				if (e.who == 1) {
					if (d2[next] > time) {
						d2[next] = time;
						was2[next] = true;
						pq.add(new Event(1, next, time));
					}
				}
			}
			for (int i = 0; i < g2[v].size(); i++) {
				Road2 r = g2[v].get(i);
				int next = r.to;
				if (r.now == -1) {
					if (e.who == 0) {
						r.now = r.l;
					} else {
						r.now = r.r;
					}
				}
				long time = e.time + r.now;
				if (e.who == 0) {
					if (d1[next] > time) {
						d1[next] = time;
						was1[next] = true;
						pq.add(new Event(0, next, time));
					}
				}
				if (e.who == 1) {
					if (d2[next] > time) {
						d2[next] = time;
						was2[next] = true;
						pq.add(new Event(1, next, time));
					}
				}
			}
		}
		return true;
	}

	boolean canDraw(int s1, int s2, int f) {
		if (s1 == f) {
			int[] ans = new int[k];
			for (int i = 0; i < n; i++)
				for (Road2 r : g2[i])
					ans[r.id] = r.l;
			out.println("DRAW");
			for (int i = 0; i < k; i++)
				out.print(ans[i] + " ");
			return true;
		}
		boolean[] was1 = new boolean[n];
		boolean[] was2 = new boolean[n];
		was1[s1] = true;
		was2[s2] = true;
		PriorityQueue<Event> pq = new PriorityQueue<>(10,
				new Comparator<Event>() {
					@Override
					public int compare(Event o1, Event o2) {
						if (o1.time != o2.time)
							return Long.compare(o1.time, o2.time);
						return Integer.compare(o1.who, o2.who);
					}
				});
		pq.add(new Event(0, s1, 0));
		pq.add(new Event(1, s2, 0));
		long[] d1 = new long[n];
		long[] d2 = new long[n];
		Arrays.fill(d1, Long.MAX_VALUE);
		Arrays.fill(d2, Long.MAX_VALUE);
		d1[s1] = 0;
		d2[s2] = 0;
		for (int i = 0; i < n; i++)
			for (Road2 r : g2[i])
				r.now = -1;
		while (pq.size() > 0) {
			Event e = pq.poll();
			int v = e.where;
			if (e.who == 0) {
				if (d1[v] != e.time)
					continue;
			}
			if (e.who == 1) {
				if (d2[v] != e.time)
					continue;
			}
			if (v == f) {
				if (e.who == 0) {
					int[] ans = new int[k];
					for (int i = 0; i < n; i++)
						for (Road2 r : g2[i])
							ans[r.id] = r.now == -1 ? r.l : r.now;
					out.println("DRAW");
					for (int i = 0; i < k; i++)
						out.print(ans[i] + " ");
					return true;
				} else {
					return false;
				}
			}
			for (int i = 0; i < g[v].size(); i++) {
				int next = g[v].get(i).to;
				long time = e.time + g[v].get(i).c;
				if (e.who == 0) {
					if (d1[next] > time) {
						d1[next] = time;
						was1[next] = true;
						pq.add(new Event(0, next, time));
					}
				}
				if (e.who == 1) {
					if (d2[next] > time) {
						d2[next] = time;
						was2[next] = true;
						pq.add(new Event(1, next, time));
					}
				}
			}
			for (int i = 0; i < g2[v].size(); i++) {
				Road2 r = g2[v].get(i);
				int next = r.to;
				if (r.now == -1) {
					if (e.who == 0) {
						r.now = r.l;
					} else {
						r.now = r.r;
					}
				}
				long time = e.time + r.now;
				if (e.who == 0) {
					if (d1[next] > time) {
						d1[next] = time;
						was1[next] = true;
						pq.add(new Event(0, next, time));
					}
				}
				if (e.who == 1) {
					if (d2[next] > time) {
						d2[next] = time;
						was2[next] = true;
						pq.add(new Event(1, next, time));
					}
				}
			}
		}
		return true;
	}

	void solve() {
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		int s1 = in.nextInt() - 1;
		int s2 = in.nextInt() - 1;
		int f = in.nextInt() - 1;
		g = new ArrayList[n];
		g2 = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
			g2[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			int c = in.nextInt();
			Road r = new Road(fr, to, c);
			g[fr].add(r);
		}
		for (int i = 0; i < k; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			int l = in.nextInt();
			int r = in.nextInt();
			Road2 ro = new Road2(fr, to, l, r, i);
			g2[fr].add(ro);
		}
		if (canWin(s1, s2, f))
			return;
		if (canDraw(s1, s2, f))
			return;
		out.println("LOSE");
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
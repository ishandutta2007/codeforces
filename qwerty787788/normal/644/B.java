import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	class Event implements Comparable<Event> {
		int type;
		// 0 - add
		// 1 - done
		int id;
		long time;

		public Event(int type, int id, long time) {
			super();
			this.type = type;
			this.id = id;
			this.time = time;
		}

		@Override
		public int compareTo(Event o) {
			if (time != o.time) {
				return Long.compare(time, o.time);
			}
			return -Integer.compare(type, o.type);
		}

	}

	void solve() {
		int n = in.nextInt();
		int b = in.nextInt() + 1;
		int[] time = new int[n];
		int[] need = new int[n];
		for (int i = 0; i < n; i++) {
			time[i] = in.nextInt();
			need[i] = in.nextInt();
		}
		long[] result = new long[n];
		PriorityQueue<Event> pq = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			pq.add(new Event(0, i, time[i]));
		}
		int cnt = 0;
		long lastTime = 0;
		while (pq.size() > 0) {
			Event e = pq.poll();
			if (e.type == 1) {
				cnt--;
			} else {
				if (cnt == b) {
					result[e.id] = -1;
				} else {
					cnt++;
					lastTime = Math.max(lastTime, time[e.id]);
					lastTime += need[e.id];
					result[e.id] = lastTime;
					pq.add(new Event(1, e.id, result[e.id]));
				}
			}
		}
		for (long t : result) {
			out.print(t + " ");
		}
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
		new B().runIO();
	}
}
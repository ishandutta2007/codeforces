import java.io.*;
import java.util.*;

public class CF {
	void solve() {
		int n = in.nextInt();
		int l = in.nextInt();
		int v1 = in.nextInt();
		int v2 = in.nextInt();
		final long up = l * 1L * v2;
		final long down = v1 + v2;
		f = up / (down + 0.);
		int[] pos = new int[n];
		for (int i = 0; i < n; i++) {
			pos[i] = in.nextInt();
		}
		ArrayList<Event> allEvents = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			for (int add = 0; add < 2; add++) {
				allEvents.add(new Event(pos[i] + add * 2L * l, true));
				allEvents.add(new Event(pos[i] + add * 2L * l, false));
			}
		}
		Collections.sort(allEvents, new Comparator<Event>() {

			@Override
			public int compare(Event o1, Event o2) {
				if (o1.add == o2.add) {
					return Long.compare(o1.pos, o2.pos);
				}
				if (!o1.add && o2.add) {
					return -compare(o2, o1);
				}
				// -1 if o1.pos - up / down < o2.pos
				long xx = (o1.pos - o2.pos) * down - up;
				return xx < 0 ? -1 : 1;
			}
		});
		double curTime = 0;
		int curCnt = 0;
		double[] ans = new double[n + 1];
		for (Event e : allEvents) {
			double diff = Math.max(0, Math.min(e.realTime, 2.0 * l) - curTime);
			ans[curCnt] += diff / (2.0 * l);
			curCnt += e.add ? 1 : -1;
			curTime = Math.max(curTime, e.realTime);
		}
		for (double z : ans) {
			out.println(z);
		}
	}

	double f;

	class Event {
		long pos;
		boolean add;
		double realTime;

		public Event(long pos, boolean add) {
			super();
			this.pos = pos;
			this.add = add;
			realTime = add ? pos - f : pos;
		}

		@Override
		public String toString() {
			return "Event [pos=" + pos + ", add=" + add + ", realTime="
					+ realTime + "]";
		}

	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}
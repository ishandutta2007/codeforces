import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	static class TypeEvent implements Comparable<TypeEvent> {
		long time;
		int type;
		int id;
		static int all = 0;

		public TypeEvent(long time, int type) {
			super();
			this.time = time;
			this.type = type;
			id = all++;
		}

		@Override
		public int compareTo(TypeEvent e) {
			if (time != e.time) {
				return time < e.time ? -1 : time > e.time ? 1 : 0;
			}
			return id - e.id;
		}
	}

	static class Event implements Comparable<Event> {
		long time;
		long waitTime;
		int id;
		int came;
		static int all = 0;

		public Event(long time) {
			super();
			this.time = time;
			id = all++;
		}

		@Override
		public int compareTo(Event e) {
			if (time != e.time) {
				return time < e.time ? -1 : time > e.time ? 1 : 0;
			}
			if (waitTime != e.waitTime) {
				return waitTime < e.waitTime ? 1 : waitTime > e.waitTime ? -1
						: 0;
			}
			return id - e.id;
		}

		@Override
		public String toString() {
			return "Event [time=" + time + ", waitTime=" + waitTime + ", id="
					+ id + ", came=" + came + "]";
		}

	}

	void solve() {

		int k1 = nextInt();
		int k2 = nextInt();
		int k3 = nextInt();
		int t1 = nextInt();
		int t2 = nextInt();
		int t3 = nextInt();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		NavigableSet<Event> first = new TreeSet<Event>();
		NavigableSet<Event> second = new TreeSet<Event>();
		NavigableSet<Event> third = new TreeSet<Event>();
		k1 = Math.min(k1, n);
		k2 = Math.min(k2, n);
		k3 = Math.min(k3, n);
		for (int i = 0; i < k1; i++) {
			first.add(new Event(0));
		}
		for (int i = 0; i < k2; i++) {
			second.add(new Event(0));
		}
		for (int i = 0; i < k3; i++) {
			third.add(new Event(0));
		}
		NavigableSet<Event> firstStart = new TreeSet<Event>();
		NavigableSet<Event> secondStart = new TreeSet<Event>();
		NavigableSet<Event> thirdStart = new TreeSet<Event>();
		long ans = 0;
		for (int i = 0; i < n; i++) {
			firstStart.add(new Event(a[i]));
		}
		while (!firstStart.isEmpty() || !secondStart.isEmpty()
				|| !thirdStart.isEmpty()) {
			Event e1 = firstStart.isEmpty() ? EVINF : firstStart.first();
			Event e2 = secondStart.isEmpty() ? EVINF : secondStart.first();
			Event e3 = thirdStart.isEmpty() ? EVINF : thirdStart.first();
			if (e1.compareTo(e2) <= 0 && e1.compareTo(e3) <= 0) {
				firstStart.pollFirst();
				Event e = first.pollFirst();
				long newTime = Math.max(e1.time, e.time) + t1;
				e.time = newTime;
				e1.waitTime += newTime - e1.time - t1;
				e1.time = newTime;
				first.add(e);
				secondStart.add(e1);
				ans = Math.max(ans, e1.waitTime);
			} else if (e2.compareTo(e3) <= 0) {
				secondStart.pollFirst();
				Event e = second.pollFirst();
				long newTime = Math.max(e2.time, e.time) + t2;
				e.time = newTime;
				e2.waitTime += newTime - e2.time - t2;
				e2.time = newTime;
				second.add(e);
				thirdStart.add(e2);
				ans = Math.max(ans, e2.waitTime);
			} else {
				thirdStart.pollFirst();
				Event e = third.pollFirst();
				long newTime = Math.max(e3.time, e.time) + t3;
				e.time = newTime;
				e3.waitTime += newTime - e3.time - t3;
				e3.time = newTime;
				third.add(e);
				ans = Math.max(ans, e3.waitTime);
			}
		}
		out.println(ans + t1 + t2 + t3);
	}

	static final Event EVINF = new Event(Long.MAX_VALUE);

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

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
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

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}
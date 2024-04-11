import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {
	static List<Integer> allLucky = new ArrayList<Integer>();
	static {
		allLucky.add(4);
		allLucky.add(7);
		for (int i = 0; i < allLucky.size(); i++) {
			int j = allLucky.get(i);
			{
				long e = j * 10L + 4;
				if (e < Integer.MAX_VALUE) {
					allLucky.add((int) e);
				}
			}

			{
				long e = j * 10L + 7;
				if (e < Integer.MAX_VALUE) {
					allLucky.add((int) e);
				}
			}
		}
	}

	static Set<Integer> luckies = new HashSet<Integer>();

	static {
		for (int i : allLucky) {
			luckies.add(i);
		}
	}

	static class Element implements Comparable<Element> {
		int x;
		int n;

		@Override
		public String toString() {
			return "Element [x=" + x + ", n=" + n + "]";
		}

		public Element(int x, int n) {
			super();
			this.x = x;
			this.n = n;
		}

		@Override
		public int compareTo(Element o) {
			return x - o.x;
		}

	}

	static class Answer {
		int a;
		int b;

		public Answer(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}

	}

	static List<Answer> solve(int[] numbers) {
		int n = numbers.length;
		Element[] a = new Element[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Element(numbers[i], i);
		}
		int id = -1;
		for (int i = 0; i < n; i++) {
			if (luckies.contains(a[i].x)) {
				id = i;
				break;
			}
		}
		Element[] b = a.clone();
		Arrays.sort(b);
		if (Arrays.equals(a, b)) {
			return new ArrayList<Answer>();
		}
		if (id == -1) {
			return null;
		}
		boolean[] did = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				did[i] = true;
			}
		}
		List<Answer> ans = new ArrayList<Answer>();
		int cur = 0;
		while (cur < n) {
			while (b[id] != a[id]) {
				int newId = b[id].n;
				swap(id, b[id].n, ans, a);
				did[id] = true;
				id = newId;
			}
			while (cur < n && did[cur] || cur == id) {
				cur++;
			}
			if (cur < n) {
				int newId = cur;
				swap(cur, id, ans, a);
				id = newId;
			}
		}
		// for (int i = 1; i < n; i++) {
		// if (a[i].x < a[i - 1].x) {
		// throw new AssertionError();
		// }
		// }
		// if (ans.size() > 2 * n) {
		// throw new AssertionError();
		// }
		return ans;
	}

	void solve() {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		List<Answer> ans = solve(a);
		if (ans == null) {
			out.println(-1);
			return;
		}
		out.println(ans.size());
		for (Answer e : ans) {
			out.println((1 + e.a) + " " + (1 + e.b));
		}
	}

	static Random rand = new Random();

	static void test() {
		int q = 0;
		while (true) {
			if (++q == 100) {
				System.err.println("Test");
				q = 0;
			}
			int[] a = new int[rand.nextInt(100000) + 1];
			for (int i = 0; i < a.length; i++) {
				a[i] = rand.nextInt(100);
			}
			int e = rand.nextInt(5) + 1;
			for (int i = 0; i < e; i++) {
				a[rand.nextInt(a.length)] = allLucky.get(rand.nextInt(allLucky
						.size()));
			}
			solve(a);
		}
	}

	static void swap(int x, int y, List<Answer> ans, Element[] a) {
		{
			int t = a[x].n;
			a[x].n = a[y].n;
			a[y].n = t;
		}
		{
			Element t = a[x];
			a[x] = a[y];
			a[y] = t;
		}
		ans.add(new Answer(x, y));
	}

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
		new D().run();
	}
}
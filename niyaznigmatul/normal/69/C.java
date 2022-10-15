import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	static class Art {
		String name;
		int[] count;

		public Art(String name, int[] count) {
			super();
			this.name = name;
			this.count = count;
		}

	}

	void solve() {
		int k = nextInt();
		int n = nextInt();
		int m = nextInt();
		int q = nextInt();
		HashMap<String, Integer> arts = new HashMap<String, Integer>();
		String[] simpleArts = new String[n];
		for (int i = 0; i < n; i++) {
			simpleArts[i] = nextToken();
			arts.put(simpleArts[i], i);
		}
		Art[] complexArts = new Art[m];
		for (int i = 0; i < m; i++) {
			String s = sc.nextLine();
			int[] count = new int[n];
			int col = s.indexOf(':');
			String name = s.substring(0, col);
			s = s.substring(col + 1);
			String[] t = s.split(",");
			for (int j = 0; j < t.length; j++) {
				t[j] = t[j].trim();
				if (t[j].isEmpty()) {
					continue;
				}
				String[] e = t[j].split(" ");
				int art = arts.get(e[0]);
				count[art] += Integer.parseInt(e[1]);
			}
			complexArts[i] = new Art(name, count);
		}
		int[][] countArts = new int[k][n + m];
		for (int i = 0; i < q; i++) {
			int man = nextInt() - 1;
			int art = arts.get(nextToken());
			countArts[man][art]++;
			for (int j = 0; j < m; j++) {
				boolean can = true;
				for (int t = 0; t < n; t++) {
					if (countArts[man][t] < complexArts[j].count[t]) {
						can = false;
						break;
					}
				}
				if (can) {
					countArts[man][n + j]++;
					for (int t = 0; t < n; t++) {
						countArts[man][t] -= complexArts[j].count[t];
					}
					break;
				}
			}
		}
		for (int i = 0; i < k; i++) {
			ArrayList<Answer> ans = new ArrayList<Answer>();
			for (int j = 0; j < n + m; j++) {
				if (countArts[i][j] > 0) {
					ans.add(new Answer(j < n ? simpleArts[j] : complexArts[j
							- n].name, countArts[i][j]));
				}
			}
			Collections.sort(ans);
			out.println(ans.size());
			for (Answer e : ans) {
				out.println(e.name + " " + e.count);
			}
		}
	}

	static class Answer implements Comparable<Answer> {
		String name;
		int count;

		public Answer(String name, int count) {
			super();
			this.name = name;
			this.count = count;
		}

		@Override
		public int compareTo(Answer o) {
			return name.compareTo(o.name);
		}
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
		new C().run();
	}
}
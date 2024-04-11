import java.io.*;
import java.util.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new C().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
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

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
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

	void solve() {
		int n = nextInt();
		HashMap<Integer, ArrayList<Integer>> hm = new HashMap<Integer, ArrayList<Integer>>();
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			if (!hm.containsKey(x)) {
				hm.put(x, new ArrayList<Integer>(2));
			}
			hm.get(x).add(y);
			if (!hm.containsKey(y)) {
				hm.put(y, new ArrayList<Integer>(2));
			}
			hm.get(y).add(x);
		}
		int odd = -1;
		for (int i : hm.keySet()) {
			if (hm.get(i).size() % 2 == 1) {
				odd = i;
				break;
			}
		}
		if (odd == -1) {
			throw new AssertionError();
		}
		HashSet<Integer> was = new HashSet<Integer>();
		that: for (int i = odd;;) {
			was.add(i);
			out.print(i + " ");
			for (int j : hm.get(i)) {
				if (was.contains(j)) {
					continue;
				}
				i = j;
				continue that;
			}
			break;
		}
	}
}
import java.io.*;
import java.math.*;
import java.util.*;

public class C {
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

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		HashMap<String, Integer> dict = new HashMap<String, Integer>();
		for (int i = 0; i < m; i++) {
			String s = nextToken();
			if (dict.containsKey(s)) {
				dict.put(s, dict.get(s) + 1);
			} else {
				dict.put(s, 1);
			}
		}
		int[] e = new int[dict.size()];
		int k = 0;
		for (String s : dict.keySet()) {
			e[k++] = dict.get(s);
		}
		Arrays.sort(a);
		Arrays.sort(e);
		int ansMin = 0, ansMax = 0;
		for (int i = 0; i < e.length; i++) {
			ansMin += e[i] * a[e.length - i - 1];
			ansMax += e[i] * a[a.length - e.length + i];
		}
		out.println(ansMin + " " + ansMax);
	}
}
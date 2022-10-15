import java.io.*;
import java.math.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
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

	ArrayList<Integer> kmp(String t, String s) {
		s = t + "@" + s;
		int n = s.length();
		int[] p = new int[n];
		p[0] = -1;
		int k = -1;
		ArrayList<Integer> ret = new ArrayList<Integer>();
		for (int i = 1; i < n; i++) {
			while (k > -1 && s.charAt(i) != s.charAt(k + 1)) {
				k = p[k];
			}
			if (s.charAt(i) == s.charAt(k + 1)) {
				++k;
			}
			if (k == t.length() - 1) {
				ret.add(i - t.length());
			}
			p[i] = k;
		}
		return ret;
	}

	void solve() {
		String s = nextToken();
		String s1 = nextToken();
		String s2 = nextToken();
		ArrayList<Integer> a = kmp(s1, s);
		ArrayList<Integer> b = kmp(s2, s);
		boolean forward = !a.isEmpty() && !b.isEmpty()
				&& a.get(0) < b.get(b.size() - 1) - s2.length() + 1;
		s = new StringBuilder(s).reverse().toString();
		a = kmp(s1, s);
		b = kmp(s2, s);
		boolean backward = !a.isEmpty() && !b.isEmpty()
				&& a.get(0) < b.get(b.size() - 1) - s2.length() + 1;
		if (forward && backward) {
			out.println("both");
		} else if (forward) {
			out.println("forward");
		} else if (backward) {
			out.println("backward");
		} else {
			out.println("fantasy");
		}
	}
}
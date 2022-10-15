import java.io.*;
import java.util.*;
import java.math.*;

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

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
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

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class Segment {
		int l, r;

		public Segment(int l, int r) {
			this.l = l;
			this.r = r;
		}

	}

	void solve() {
		String[] s = nextToken().split(",");
		TreeSet<Integer> a = new TreeSet<Integer>();
		for (String e : s) {
			a.add(Integer.parseInt(e));
		}
		int last = Integer.MIN_VALUE;
		ArrayList<Segment> ans = new ArrayList<C.Segment>();
		for (int i : a) {
			if (last == i - 1) {
				ans.get(ans.size() - 1).r = i;
			} else {
				ans.add(new Segment(i, i));
			}
			last = i;
		}
		boolean first = true;
		for (Segment e : ans) {
			if (!first) {
				out.print(",");
			} else {
				first = false;
			}
			if (e.l == e.r) {
				out.print(e.l);
			} else {
				out.print(e.l + "-" + e.r);
			}
		}
		out.println();
	}
}
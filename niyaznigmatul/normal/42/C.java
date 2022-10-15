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

	void solve() {
		int[] a = new int[4];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
		}
		int[] add = new int[4];
		int[] shr = new int[4];
		for (int i = 0; i < a.length; i++) {
			int x = a[i];
			while (x != 1) {
				if ((x & 1) == 1) {
					x++;
					add[i]++;
				}
				x >>= 1;
				shr[i]++;
			}
		}
		int[] b = a.clone();
		int count = 1000;
		int q = 0;
		StringBuilder sb = new StringBuilder();
		loop: while (++q < count) {
			if (b[0] == 1 && b[1] == 1 && b[2] == 1 && b[3] == 1) {
				out.println(sb);
				return;
			}
			for (int i = 0; i < a.length; i++) {
				int j = (i + 1) & 3;
				if ((b[i] != 1 || b[j] != 1) && (b[i] & 1) == 1
						&& (b[j] & 1) == 1) {
					sb.append("+" + (i + 1)).append("\n");
					b[i]++;
					b[j]++;
					continue loop;
				}
				if ((b[i] & 1) == 0 && (b[j] & 1) == 0) {
					sb.append("/" + (i + 1)).append("\n");
					b[i] >>= 1;
					b[j] >>= 1;
					continue loop;
				}
			}
			for (int i = 0; i < a.length; i++) {
				int j = (i + 1) & 3;
				if (b[i] != 1 || b[j] != 1) {
					sb.append("+" + (i + 1)).append("\n");
					b[i]++;
					b[j]++;
					continue loop;
				}
			}
		}
		out.println(-1);
	}
}
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		long l = in.nextLong(), r = in.nextLong(), k = in.nextLong();
		if (r - l < 14) {
			int bestSt = 0;
			long bestXor = Long.MAX_VALUE;
			int len = (int) (r - l + 1);
			for (int st = 1; st < 1 << len; st++) {
				if (Integer.bitCount(st) <= k) {
					long curXor = 0;
					for (int i = 0; i < len; i++) {
						if (((1 << i) & st) != 0) {
							curXor ^= l + i;
						}
					}
					if (curXor < bestXor) {
						bestXor = curXor;
						bestSt = st;
					}
				}
			}
			out.println(bestXor);
			out.println(Integer.bitCount(bestSt));
			for (int i = 0; i < len; i++)
				if (((1 << i) & bestSt) != 0) {
					out.print((l + i) + " ");
				}
		} else {
			if (k == 1) {
				out.println(l);
				out.println(1);
				out.println(l);
			} else {
				if (k == 2) {
					out.println(1);
					out.println(2);
					long from = (l / 2) * 2 + 2;
					out.println(from + " " + (from + 1));
				} else {
					if (k >= 4) {
						out.println(0);
						out.println(4);
						long from = (l / 4) * 4 + 4;
						for (int i = 0; i < 4; i++) {
							out.print(from + i);
							out.print(" ");
						}
					} else {
						long min = 1, mid = 2, max = 3;
						while (true) {
							if (max > r)
								break;
							if (min >= l) {
								out.println(0);
								out.println(3);
								out.println(min + " " + mid + " " + max);
								return;
							}
							min = min * 2 + 1;
							mid = mid * 2 + 1;
							max = max * 2;
						}
						out.println(1);
						out.println(2);
						long from = (l / 2) * 2 + 2;
						out.println(from + " " + (from + 1));
					}
				}
			}
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
		new CF().runIO();
	}
}
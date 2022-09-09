import java.io.*;
import java.util.*;

public class SolutionA {
	FastScanner in;
	PrintWriter out;

	int width = 100000;
	int height = 100;
	int h1, h2, n;
	double eps = 1e-10;

	void solve() {
		h1 = in.nextInt();
		h2 = in.nextInt();
		n = in.nextInt();
		int[][] cost = new int[2][width];
		int[][] mirrorId = new int[2][width];
		for (int i = 0; i < n; i++) {
			int v = in.nextInt();
			char c = in.next().charAt(0);
			int a = in.nextInt();
			int b = in.nextInt();
			int type = c == 'F' ? 0 : 1;
			for (int k = a; k < b; k++) {
				cost[type][k] = v;
				mirrorId[type][k] = i + 1;
			}
		}
		int ans = 0;
			for (int s = -100; s <= 100; s++) {
				if (s == 0) continue;
				double y2 = (Math.abs(s) % 2 == 0 ? height * s + h2 : height * (s + 1) - h2);
				double dy = y2 - h1;
				int curSum = 0;
				int curSide = s > 0 ? 1 : 0; // up - 0;
				boolean ok = true;
				int[] lastMirror = new int[2];
				for (int i = 0; i < Math.abs(s); i++) {
					double curYChange = s > 0 ? (i + 1) * height - h1 : h1 + i * height;
					double curX = Math.abs((curYChange / dy)) * width;
					int x = (int) (curX + eps);
					if (mirrorId[curSide][x] == 0 || mirrorId[curSide][x] == lastMirror[curSide]) {
						ok = false;
						break;
					} else {
						lastMirror[curSide] = mirrorId[curSide][x];
						curSum += cost[curSide][x];
					}
					curSide = 1 - curSide;
				}
				if (ok)
					ans = Math.max(ans, curSum);
			}
		out.println(ans);
	}

	void run() {
		try {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter(new File("output.txt"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
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
	}

	public static void main(String[] args) {
		new SolutionA().runIO();
	}
}
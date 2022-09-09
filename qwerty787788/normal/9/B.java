import java.io.*;
import java.util.*;

public class CF {

	int n;
	int res = 0;

	void go(long cur) {
		if (cur <= n)
			res++;
		if (cur > n)
			return;
		go(cur * 10 + 1);
		go(cur * 10);
	}

	void realSolve() {
		n = in.nextInt();
		int vb = in.nextInt();
		int vs = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		int x = in.nextInt();
		int y = in.nextInt();
		double min = 100000000;
		long dist = Long.MAX_VALUE;
		int res = -1;
		for (int i = 1; i < n; i++) {
			long dx = x - a[i];
			long dy = y;
			long curDist = dx * dx + dy * dy;
			double time = a[i] / (0. + vb) + Math.sqrt(curDist) / vs;
			if (time < min || (Math.abs(time - min) < 1e-10 && curDist < dist)) {
				dist = curDist;
				min = time;
				res = i + 1;
			}
		}
		out.println(res);
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solve() {
		in = new InputReader(new File("object.in"));
		try {
			out = new PrintWriter(new File("object.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		realSolve();

		out.close();
	}

	void solveIO() {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	public static void main(String[] args) {
		new CF().solveIO();
	}
}
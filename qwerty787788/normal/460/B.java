import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	long foo(long x) {
		if (x < 10)
			return x;
		return (x % 10) + foo(x / 10);
	}

	void solve() {
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		ArrayList<Integer> answer = new ArrayList<>();
		for (int sum = 1; sum < 111; sum++) {
			long x = 1;
			for (int i = 0; i < a; i++)
				x *= sum;
			x *= b;
			x += c;
			if (foo(x) == sum && x > 0 && x < 1e9) {
				answer.add((int) x);
			}
		}
		Collections.sort(answer);
		out.println(answer.size());
		for (int x : answer)
			out.print(x + " ");
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
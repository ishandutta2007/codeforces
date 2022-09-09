import java.io.*;
import java.util.*;

public class CF {

	void realSolve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] cost = new int[n];
		for (int i = 0; i < n; i++)
			cost[i] = in.nextInt();
		Arrays.sort(cost);
		HashMap<String, Integer> hm = new HashMap<>();
		int it = 0;
		int[] sz = new int[m];
		for (int i = 0; i < m; i++) {
			String s = in.next();
			Integer id = hm.get(s);
			if (id == null) {
				hm.put(s, it);
				id = it++;
			}
			sz[id]++;
		}
		Arrays.sort(sz);
		int max = 0;
		for (int i = 0; i < m; i++) {
			if (n - i - 1 >= 0)
				max += sz[m - i - 1] * cost[n - i - 1];
		}
		int min = 0;
		for (int i = 0; i < m; i++) {
			if (i < n)
				min += sz[m - i - 1] * cost[i];
		}
		out.println(min + " " + max);
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
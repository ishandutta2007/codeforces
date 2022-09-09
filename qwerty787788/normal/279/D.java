import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		ArrayList<Integer>[] canG = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			canG[i] = new ArrayList<>();
			for (int j = 0; j < i; j++)
				for (int k = j; k < i; k++)
					if (a[j] + a[k] == a[i]) {
						int mask = (1 << j) | (1 << k);
						canG[i].add(mask);
					}
		}
		int max = 1 << n;
		boolean[] can = new boolean[max];
		can[1] = true;
		int ans = Integer.MAX_VALUE;
		for (int mask = 1; mask < max; mask++)
			if (can[mask]) {
				boolean canGetNext = false;
				int need = -1;
				for (int i = 0; i < n; i++)
					if (((1 << i) & mask) != 0)
						need = i + 1;
				if (need == n) {
					ans = Math.min(Integer.bitCount(mask), ans);
					continue;
				}
				for (int m : canG[need]) {
					if ((mask & m) == m) {
						canGetNext = true;
						break;
					}
				}
				if (canGetNext) {
					int nextMask = mask | (1 << need);
					can[nextMask] = true;
					for (int i = 0; i < need; i++)
						if ((nextMask & (1 << i)) != 0)
							can[nextMask ^ (1 << i)] = true;
				}
			}
		if (ans == Integer.MAX_VALUE)
			ans = -1;
		out.println(ans);
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

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
		new CF().runIO();
	}
}
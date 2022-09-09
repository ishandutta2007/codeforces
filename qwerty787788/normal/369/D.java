import java.io.*;
import java.util.*;

public class CF {

	class State {
		int f, s, t;

		State(int f, int s, int t) {
			this.f = f;
			this.s = s;
			this.t = t;
		}
	}

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++)
			p[i] = in.nextInt();
		if (n == 1) {
			out.println(1);
			return;
		}
		ArrayList<State> states = new ArrayList<>();
		states.add(new State(0, 1, 0));
		boolean[][] can = new boolean[n + 1][n + 1];
		can[0][1] = true;
		int it = 0;
		int[] maxP = new int[n + 1];
		for (int i = n - 1; i >= 0; i--)
			maxP[i] = Math.max(maxP[i + 1], p[i]);
		while (it < states.size()) {
			State st = states.get(it++);
			if (st.s == n)
				continue;
			if (st.t == k)
				continue;
			int fKilled = maxP[st.s];
			int sKilled = p[st.f];
			// firstKilled
			if (fKilled > 0 && sKilled < 100) {
				if (!can[st.s][st.s + 1]) {
					can[st.s][st.s + 1] = true;
					states.add(new State(st.s, st.s + 1, st.t + 1));
				}
			}
			// secondKilled
			if (fKilled < 100 && sKilled > 0) {
				if (!can[st.f][st.s + 1]) {
					can[st.f][st.s + 1] = true;
					states.add(new State(st.f, st.s + 1, st.t + 1));
				}
			}
			// bothKilled
			if (fKilled > 0 && sKilled > 0) {
				int n2 = st.s + 2;
				if (n2 > n)
					n2--;
				if (!can[st.s + 1][n2]) {
					can[st.s + 1][n2] = true;
					states.add(new State(st.s + 1, n2, st.t + 1));
				}
			}
		}
		int r = 0;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				if (can[i][j])
					r++;
		out.println(r);
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}
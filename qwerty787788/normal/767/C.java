import java.io.*;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	int[][] g;
	int[] t;
	int needT;
	int[] sumT;

	void solve() {
		int n = in.nextInt();
		int[] gSz = new int[n];
		g = new int[n][];
		t = new int[n];
		int root = 0;
		int sum = 0;
		int[] pr = new int[n];
		for (int i = 0; i < n; i++) {
			int prev = in.nextInt() - 1;
			t[i] = in.nextInt();
			sum += t[i];
			if (prev == -1) {
				root = i;
				pr[i] = -1;
			} else {
				gSz[prev]++;
				pr[i] = prev;
			}
		}
		for (int i = 0; i < n; i++) {
			g[i] = new int[gSz[i]];
		}
		for (int i = 0; i < n; i++) {
			if (pr[i] != -1) {
				gSz[pr[i]]--;
				g[pr[i]][gSz[pr[i]]] = i;
			}
		}
		if (sum % 3 != 0) {
			out.println(-1);
			return;
		}
		needT = sum / 3;
		sumT = new int[n];
		int[] q = new int[n];
		int qIt = 0, qSz = 0;
		q[qSz++] = root;
		while (qIt < qSz) {
			int v = q[qIt++];
			for (int to : g[v]) {
				q[qSz++] = to;
			}
		}
		int[] answer = new int[n];
		for (int vIt = n - 1; vIt >=0 ;vIt--) {
			int v = q[vIt];
			sumT[v] = t[v];
			int resC = -1;
			for (int i = 0; i < g[v].length; i++) {
				int to = g[v][i];
				int rec = answer[to];
				if (rec != -1) {
					if (resC != -1) {
						out.println((resC + 1) + " " + (rec + 1));
						return;
					}
					resC = rec;
				}
				sumT[v] += sumT[to];
			}
			if (resC != -1 && sumT[v] - needT == needT && vIt != 0) {
				out.println((v + 1) + " " + (resC + 1));
				return;
			}
			if (resC != -1) {
				answer[v] = resC;
				continue;
			}
			if (sumT[v] == needT) {
				answer[v] = v;
				continue;
			}
			answer[v]= -1;
		}
		out.println(-1);
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new C().runIO();
	}
}
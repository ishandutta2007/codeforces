import java.io.*;
import java.util.*;

public class CF153DIV1 {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] q = new int[n];
		for (int i = 0; i < n; i++) {
			q[i] = in.nextInt();
		}
		int[] need = new int[n];
		for (int i = 0; i < n; i++)
			need[i] = in.nextInt();
		int[][] cur = new int[500][n];
		for (int i = 0; i < n; i++)
			cur[250][i] = i + 1;
		for (int move = 1; move <= 110; move++) {
			for (int i = 0; i < n; i++)
				cur[250 + move][i] = cur[250 + move - 1][q[i] - 1];
		}
		for (int move = 1; move <= 110; move++) {
			for (int i = 0; i < n; i++) {
				cur[250 - move][q[i] - 1] = cur[250 - move + 1][i];
			}
		}
		boolean[] same = new boolean[500];
		for (int i = 0; i < 500; i++) {
			boolean ok = true;
			for (int j = 0; j < n; j++)
				if (cur[i][j] != need[j]) {
					ok = false;
					break;
				}
			if (ok) same[i] = true;
		}
		boolean[][] can = new boolean[k + 1][500];
		can[0][250] = true;
		for (int move = 0; move < k; move++)
			for (int i = 0; i < 500; i++)
				if (!same[i] && can[move][i]) {
					if (i > 0)
						can[move + 1][i - 1] = true;
					if (i < 500 - 1)
						can[move + 1][i + 1] = true;
				}
		boolean ans  = false;
		for (int i = 0; i < 500; i++)
			if (same[i] && can[k][i])
				ans = true;
		if (ans) 
			out.println("YES"); else
				out.println("NO");
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
	}

	public static void main(String[] args) {
		new CF153DIV1().runIO();
	}
}
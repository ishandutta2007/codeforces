import java.io.*;
import java.util.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int[][][][] dp;
	int[][][][][] last;
	int[] h;
	int n;
	
	void update(int dead, int h1, int h2, int h3, int s, int d1, int l1, int l2, int l3, int d2) {
		if (h1 == 0 && dead < n - 3) {
			update(dead + 1, h2, h3, dead + 3 < n ? h[dead + 3] + 1 : 0, s, d1, l1, l2, l3, d2);
			return;
		}
		int s2 = dp[dead][h1][h2][h3];
		if (s2 == -1 || s2 > s) {
			dp[dead][h1][h2][h3] = s;
			last[dead][h1][h2][h3][0] = d1;
			last[dead][h1][h2][h3][1] = l1;
			last[dead][h1][h2][h3][2] = l2;
			last[dead][h1][h2][h3][3] = l3;
			last[dead][h1][h2][h3][4] = d2;
		}
	}
	
	void solve() {
		n = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		h = new int[n];
		for (int i = 0; i < n; i++) {
			h[i] = in.nextInt();
		}
		dp = new int[n + 1][17][17][17];
		last = new int[n + 1][17][17][17][5];
		for (int dead = 0; dead <= n; dead++)
			for (int h1 = 0; h1 <= 16; h1++)
				for (int h2 = 0; h2 <= 16; h2++)
					for (int h3 = 0; h3 <= 16; h3++) {
						dp[dead][h1][h2][h3] = -1;
					}
		dp[0][h[0] + 1][h[1] + 1][h[2] + 1] = 0;
		for (int dead = 0; dead <= n - 2; dead++)
			for (int sumH = 48; sumH >= 0; sumH--)
				for (int h1 = 0; h1 <= Math.min(16, sumH); h1++)
					for (int h2 = 0; h2 <= Math.min(16, sumH - h1); h2++) {
						int h3 = sumH - h1 - h2;
						if (h3 > 16)
							continue;
						int s = dp[dead][h1][h2][h3];
						if (s == -1)
							continue;
						if (dead != 0) 
							update(dead, Math.max(0, h1 - a), Math.max(0, h2 - b), Math.max(0, h3), s + 1, dead, h1, h2, h3, dead);							
						if (dead != n - 2)
							update(dead, Math.max(0, h1 - b), Math.max(0, h2 - a), Math.max(0, h3 - b), s + 1, dead, h1, h2, h3, dead + 1);
					}
		out.println(dp[n - 3][0][0][0]);
		int dead = n - 3;
		int h1 = 0;
		int h2 = 0;
		int h3 = 0;
		while (dead != 0 || h1 != h[0] + 1 || h2 != h[1] + 1 || h3 != h[2] + 1) {
			int newDead = last[dead][h1][h2][h3][0];
			int newH1 = last[dead][h1][h2][h3][1];
			int newH2 = last[dead][h1][h2][h3][2];
			int newH3 = last[dead][h1][h2][h3][3];
			out.print((last[dead][h1][h2][h3][4]+1) + " ");
			dead = newDead;
			h1 = newH1;
			h2 = newH2;
			h3 = newH3;
		}
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
		new Solution().runIO();
	}
}
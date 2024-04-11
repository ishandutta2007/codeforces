import java.io.*;
import java.util.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new Thread(new B()).start();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	final int[] DX = { 1, 0, -1, 0 };
	final int[] DY = { 0, 1, 0, -1 };

	void solve() {
		int n = nextInt();
		int m = nextInt();
		char ch = nextToken().charAt(0);
		char[][] c = new char[n][];
		for (int i = 0; i < n; i++) {
			c[i] = nextToken().toCharArray();
		}
		HashSet<Character> g = new HashSet<Character>();
		g.add(ch);
		g.add('.');
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] != ch) {
					continue;
				}
				for (int dir = 0; dir < 4; dir++) {
					int xx = i + DX[dir];
					int yy = j + DY[dir];
					if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
						continue;
					}
					g.add(c[xx][yy]);
				}
			}
		}
		out.println(g.size() - 2);
	}
}
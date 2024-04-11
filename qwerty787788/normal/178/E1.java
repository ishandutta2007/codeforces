import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int N;
	int circles = 0;
	int boxes = 0;
	
	int [][] a;
	boolean [][] was;
	
	class point {
		int x;
		int y;
		point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	boolean ok (int x, int y) {
		if (x < 0 || x >= N || y < 0 || y >= N) return false;
		if (was[x][y] || a[x][y] == 0) return false;
		return true;
	}
	
	void rec(int x, int y) {
		ArrayList<point> tmp = new ArrayList<point>();
		tmp.add(new point(x, y));
		int from = 0;
		was[x][y] = true;
		while (from < tmp.size()) {
			point now = tmp.get(from);
			for (int nx = now.x - 1; nx <= now.x + 1; nx++)
				for (int ny = now.y - 1; ny <= now.y + 1; ny++)
					if (ok(nx, ny)) {
						was[nx][ny] = true;
						tmp.add(new point(nx, ny));
					}
			from++;
		}
		//
		long cmx = 0, cmy = 0;
		long R2 = 0;
		for (int i = 0; i < tmp.size(); i++) {
			cmx += tmp.get(i).x;
			cmy += tmp.get(i).y;
		}
		cmx /= tmp.size();
		cmy /= tmp.size();
		for (int i = 0; i < tmp.size(); i++) {
			long x1 = (tmp.get(i).x - cmx)*(tmp.get(i).x - cmx) + (tmp.get(i).y - cmy)*(tmp.get(i).y - cmy);
			if (x1 > R2) R2 = x1; 
		}
		long S = (long) (0.93 * Math.PI * R2);
		if (tmp.size() > S) circles++; else boxes++;
		
	}
	
	public void solve() throws IOException {
		N = in.nextInt();
		a = new int[N][N];
		was = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a[i][j] = in.nextInt();
				was[i][j] = false;
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!was[i][j] && a[i][j] == 1) {
					rec(i, j);
				}
		out.print(circles);
		out.print(" ");
		out.print(boxes);
	}

	public void run() {
		try {
			//in = new FastScanner(new File("input.txt"));
			//out = new PrintWriter(new File("output.txt"));

			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}
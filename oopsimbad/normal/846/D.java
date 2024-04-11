import java.io.*;
import java.text.*;
import java.util.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	int n,m,k,q;
	Point[] parr;
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(f.readLine());
		n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken()); k = Integer.parseInt(st.nextToken());q = Integer.parseInt(st.nextToken());
		parr = new Point[q];
		for(int i = 0; i < q; i++) parr[i] = new Point(f.readLine());
		Arrays.sort(parr);
		int l = 0, h = q;
		while(l < h) {
			int m = (l+h)/2;
			if(update(m)) h = m;
			else l = m+1;
		}
		System.out.println(l == q ? -1 : parr[l].t);
	}
	public boolean update(int index) {
		int max = 0;
		int[][] dp = new int[n][m];
		boolean[][] mat = new boolean[n][m];
		for(int i = 0; i <= index; i++) mat[parr[i].r][parr[i].c] = true;
		for(int r = 0; r < n; r++) {
			for(int c = 0; c < m; c++) {
				if(!mat[r][c]) continue;
				if(r == 0 || c == 0) dp[r][c] = 1;
				else dp[r][c] = Math.min(dp[r][c-1], Math.min(dp[r-1][c],dp[r-1][c-1])) + 1;
				max = Math.max(max,dp[r][c]);
			}	
		}
		return max >= k;
	}
	class Point implements Comparable<Point> {
		int r, c, t;
		public Point(String s) {
			StringTokenizer st = new StringTokenizer(s);
			r = Integer.parseInt(st.nextToken())-1;
			c = Integer.parseInt(st.nextToken())-1;
			t = Integer.parseInt(st.nextToken());
		}
		public int compareTo(Point p) {
			if(t != p.t) return t - p.t;
			if(r != p.r) return r - p.r;
			return c - p.c;
		}
	}
}
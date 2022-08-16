import java.io.*;
import java.util.*;

public class C {
  static class Point {
    int x, y;
    Point(int _x, int _y) {
     x = _x; y = _y; 
    }
    public String toString() {
      return String.format("%d %d", x, y);
    }
  }
  static int n, m, vis[][], vid;
  static char a[][];
  static boolean valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
  }
  static Point dp[][][];
  static String DIR = "DULR";
  static int dx[] = {1, -1, 0, 0};
  static int dy[] = {0,  0,-1, 1}; 
  static Point solve(int x, int y, int dir) {
    if (!valid(x, y)) {
      return null;
    }
    if (dp[x][y][dir] != null) {
      return dp[x][y][dir] = solve(dp[x][y][dir].x, dp[x][y][dir].y, dir);
    }
    if (vis[x][y] == vid || a[x][y] == '.') {
        return dp[x][y][dir] = solve(x + dx[dir], y + dy[dir], dir);
    }
    return dp[x][y][dir]=new Point(x, y);
  }
	public static void main (String args[]) throws Exception {		
		BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
    String tmp[] = in.readLine().split(" ");
    n = Integer.parseInt( tmp[0] ); m = Integer.parseInt( tmp[1] );
    a = new char[n][];
    for (int i=0; i < n; i++) {
      a[i] = in.readLine().toCharArray();
    }
    
    vis = new int[n][m];
    dp = new Point[n][m][4];
    vid = 0;
    int ans = 0, count = 0;
    for (int x=0; x < n; x++)
    for (int y=0; y < m; y++) 
    if (a[x][y] != '.') {
      ++vid;
      for (Point z[][] : dp)
      for (Point q[] : z)
        Arrays.fill(q, null);
      int len = 0;
      int cx = x, cy = y;
      while (valid(cx, cy)) {
        vis[cx][cy] = vid;
        Arrays.fill( dp[cx][cy], null );
        len++;
        Point z = solve(cx, cy, DIR.indexOf( a[cx][cy] ));
        if (z == null) break;
        cx = z.x;
        cy = z.y;
      }
      
      if (len > ans) {
        ans = len; count = 1; 
      } else if (len == ans) {
        count++;
      }
    }
    System.out.println( ans + " " + count );
	}
}
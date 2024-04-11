import java.io.*; 
import java.text.*; 
import java.util.*; 
import java.math.*;
public class template { 
    public static void main(String[] args) throws Exception {
        new template().run();
    } 
    public void run() throws Exception { 
        FastScanner f = new FastScanner(); 
        PrintWriter out = new PrintWriter(System.out); 
        ///
        int asdf = f.nextInt();
        while(asdf-->0) {
            int n = f.nextInt(), m = f.nextInt();
            mat = new char[n][];
            vis = new boolean[n][m];
            for(int i = 0; i < n; i++) mat[i] = f.next().toCharArray();
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(mat[i][j] == 'B') {
                        if(i != 0 && mat[i-1][j] == '.') mat[i-1][j] ='#';
                        if(i != n-1 && mat[i+1][j] == '.') mat[i+1][j] ='#';
                        if(j != 0 && mat[i][j-1] == '.') mat[i][j-1] ='#';
                        if(j != m-1 && mat[i][j+1] == '.') mat[i][j+1] ='#';
                    }
                }
            }
            recur(n-1, m-1);
            boolean b = true;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(mat[i][j] == 'B' && vis[i][j]) b = false;
                    else if(mat[i][j] == 'G' && !vis[i][j]) b = false;
            out.println(b ? "Yes" : "No");
        }
///
		out.flush();
	}
    boolean[][] vis;
    char[][] mat;
    public void recur(int r, int c) {
        if(r < 0 || c < 0 || r >= mat.length || c >= mat[0].length || vis[r][c] || mat[r][c] == '#') return;
        vis[r][c] = true;
        recur(r+1, c);
        recur(r, c+1);
        recur(r-1, c);
        recur(r, c-1);
    }
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in), 32768);
			tokenizer = null;
		}
		public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch(IOException e) {
				throw new RuntimeException(e);
			}
		}
	}
}
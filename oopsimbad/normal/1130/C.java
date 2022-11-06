import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	int[][] mat;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		mat = new int[n][n];
		int sr = f.nextInt()-1, sc = f.nextInt()-1;
		int er = f.nextInt()-1, ec = f.nextInt()-1;
		for(int i = 0; i < n; i++) {
			char[] c = f.next().toCharArray();
			for(int j = 0; j < n; j++)
				if(c[j] == '1') mat[i][j] = -1;
		}
		recur(sr,sc,1);
		recur(er,ec,2);
		long min = Integer.MAX_VALUE;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(mat[i][j] == 1)
					for(int a = 0; a < n; a++)
						for(int b = 0; b < n; b++)
							if(mat[a][b] == 2)
								min = Math.min(min, (i-a) * (i-a) + (j-b) * (j-b));
		if(mat[sr][sc] == mat[er][ec]) min = 0;
		out.println(min);
		out.flush();
	}
	public void recur(int r, int c, int v) {
		if(r < 0 || c < 0 || r >= mat.length || c >= mat.length || mat[r][c] == v || mat[r][c] == -1) return;
		mat[r][c] = v;
		recur(r+1,c,v);
		recur(r-1,c,v);
		recur(r,c-1,v);
		recur(r,c+1,v);
	}
    static class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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
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
		int r = f.nextInt(), c = f.nextInt();
		mat = new char[r][];
		boolean poss = true;
		int erow = 0, ecol = 0;
		for(int i = 0; i < r; i++) {
			mat[i] = f.next().toCharArray();
			boolean s = false, e = false;
			for(int j = 0; j < c; j++) {
				if(mat[i][j] == '#') {
					if(e) poss = false;
					if(!s) s = true;
				} else if(s) e = true;
			}
			if(!s) erow++;
		}
		for(int j = 0; j < c; j++) {
			boolean s = false, e = false;
			for(int i = 0; i < r; i++) {
				if(mat[i][j] == '#') {
					if(e) poss = false;
					if(!s) s = true;
				} else if(s) e = true;
			}
			if(!s) ecol++;
		}
		if(!poss || erow == 0 && ecol != 0 || ecol == 0 && erow != 0) out.println(-1);
		else {
			int cnt = 0;
			vis = new boolean[r][c];
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
					if(!vis[i][j] && mat[i][j] == '#') {
						cnt++;
						fill(i,j);
					}
			out.println(cnt);
		}
		out.flush();
	}
	char[][] mat;
	boolean[][] vis;
	public void fill(int r, int c) {
		if(r < 0 || c < 0 || r >= mat.length || c >= mat[0].length || vis[r][c] || mat[r][c] == '.') return;
		vis[r][c] = true;
		fill(r,c+1);
		fill(r,c-1);
		fill(r+1,c);
		fill(r-1,c);
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
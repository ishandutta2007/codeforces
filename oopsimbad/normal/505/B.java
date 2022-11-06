import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	int[][] par;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt();
		par = new int[m][n];
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) par[i][j] = j;
		while(m-->0) union(f.nextInt()-1,f.nextInt()-1,f.nextInt()-1);
		int q = f.nextInt();
		while(q-->0) {
			int cnt = 0;
			int x = f.nextInt()-1, y = f.nextInt()-1;
			for(int i = 0; i < par.length; i++) {
				if(find(x,i) == find(y,i)) cnt++;
			}
			out.println(cnt);
		}
		out.flush();
	}
	public int find(int x, int d) {
		if(par[d][x] == x) return x;
		return par[d][x] = find(par[d][x],d);
	}
	public void union(int x, int y, int d) {
		par[d][find(x,d)] = find(y,d);
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
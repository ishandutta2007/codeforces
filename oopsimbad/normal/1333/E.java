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
		int n = f.nextInt();
		if(n <= 2) out.println(-1);
		else if(n == 3) {
			out.println("7 3 9");
			out.println("8 4 5");
			out.println("1 2 6");
		} else {
			int[][] mat = new int[n][n];
			mat[0][n-1] = n*n;
			int v = 0;
			mat[n-1][n-2] = n*n-1;
			for(int i = 1; i < n; i++)
				mat[i][n-1] = n*n-i-1;
			for(int i = n-3; i >= 0; i--)
				mat[n-1][i] = ++v;
			for(int i = 1; i < n-1; i++) {
				int st = v;
				for(int j = 0; j < n-1; j++)
					mat[n-i-1][j] = ++v;
				if(i % 2 == 1) {
					mat[n-i-1][1] = v;
					mat[n-i-1][n-2] = st+2;
				} else {
					mat[n-i-1][0] = v;
					mat[n-i-1][n-2] = st+1;
				}
			}
			for(int i = 0; i < n-1; i++)
				mat[0][i] = ++v;
			for(int[] i : mat) {
				for(int j : i) out.print(j + " ");
				out.println();
			}
		}
///
		out.flush(); 
	}
///
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
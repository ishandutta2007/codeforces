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
		char[][] mat = new char[r][c];
		for(int i = 0; i < r; i++)
			mat[i] = f.next().toCharArray();
		boolean works = true;
		boolean[][] marked = new boolean[r][c];
		boolean a = false;
		boolean b = false;
		int _1 = 0, _2 = 0, _3 = 0, _4 = 0, _5 = 0, _6 = 0;
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++) {
				if(marked[i][j]) continue;
				if(mat[i][j] == '*') {
					if(a && b) works = false;
					else if(a) {
						b = true;
						_4 = j;
						_5 = i;
						int k = j;
						while(k < c && mat[i][k] == '*') {
							marked[i][k] = true;
							k++;
						}
						_6 = k-1;
					}
					else {
						a = true;
						int k = i;
						_1 = k;
						_2 = j;
						while(k < r && mat[k][j] == '*') {
							marked[k][j] = true;
							k++;
						}
						_3 = k-1;
					}

				}
			}
		out.println(works && a && b && _4 < _2 && _2 < _6 && _1 < _5 && _5 < _3 ? "YES" : "NO");
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
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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int r = f.nextInt(), c = f.nextInt();
			char[][] mat = new char[r][c];
			int[] a = new int[r], b = new int[c];
			for(int i = 0; i < r; i++) {
				mat[i] = f.next().toCharArray();
				for(int j = 0; j < c; j++) {
					if(mat[i][j] != '*') {
						a[i]++; b[j]++;
					}
				}
			}
			int min = r+c;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					min = Math.min(min, a[i]+b[j] - (mat[i][j] == '*' ? 0 : 1));
				}
			}
			out.println(min);
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
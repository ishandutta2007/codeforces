import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int r = f.nextInt(), c = f.nextInt();
		char[][] mat = new char[r][];
		for(int i = 0; i < r; i++)
			mat[i] = f.nextLine().toCharArray();
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(mat[i][j] != 'S') continue;
				if(i != 0) {
					if(mat[i-1][j] == 'W') {
						System.out.println("No");
						return;
					}
					else if(mat[i-1][j] != 'S')
						mat[i-1][j] = 'D';
				}
				if(j != 0) {
					if(mat[i][j-1] == 'W') {
						System.out.println("No");
						return;
					}
					else if(mat[i][j-1] != 'S')
						mat[i][j-1] = 'D';
					
				}
				if(i != r-1) {
					if(mat[i+1][j] == 'W') {
						System.out.println("No");
						return;
					}
					else if(mat[i+1][j] != 'S')
						mat[i+1][j] = 'D';
				}
				if(j != c-1) {
					if(mat[i][j+1] == 'W') {
						System.out.println("No");
						return;
					}
					else if(mat[i][j+1] != 'S')
						mat[i][j+1] = 'D';
				}
			}
		}
		System.out.println("Yes");
		for(char[] cc : mat)
			System.out.println(cc);
		out.flush();
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
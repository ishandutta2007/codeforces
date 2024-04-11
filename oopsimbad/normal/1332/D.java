import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
 
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int MAX = (1 << 18) - 1;
		int[][] mat = new int[3][3];
		mat[0][0] = mat[2][1] = mat[1][2] = MAX;
		mat[0][1] = mat[0][2] = mat[2][2] = n;
		mat[1][0] = mat[1][1] = mat[2][0] = MAX-n;
		out.println("3 3");
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) out.print(mat[i][j] + " ");
			out.println();
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
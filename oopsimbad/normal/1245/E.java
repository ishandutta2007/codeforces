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
		int[][] h = new int[10][10];
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				h[i][j] = f.nextInt();
		double[][] exp = new double[10][10];
		int[][] cr = new int[10][10];
		int[][] cc = new int[10][10];
		for(int i = 0; i < 10; i++) {
			if(i % 2 == 0) {
				for(int j = 0; j < 9; j++)
					cc[i][j] = 1;
				cr[i][9] = 1;
			}
			else {
				for(int j = 1; j < 10; j++)
					cc[i][j] = -1;
				cr[i][0] = 1;
			}
		}
		int r = 0, c = 1;
		int ind = 1;
		double[] prev = new double[100];
		while(r != 10) {
			double ans = 0;
			for(int i = ind-1; i >= 0 && i >= ind-6; i--)
				ans += prev[i];
			ans = ans/6+1;
			if(ind < 6) ans /= ind/6.0;
			exp[r][c] = ans;
			prev[ind] = Math.min(ans, exp[r-h[r][c]][c]);
			int nr = r + cr[r][c];
			int nc = c + cc[r][c];
			r = nr;
			c = nc;
			ind++;
		}
		out.println(exp[9][0]);
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
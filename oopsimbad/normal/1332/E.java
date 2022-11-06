import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
 
public class E {
	public static void main(String[] args) throws Exception {
		new E().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int m = f.nextInt();
		int l = f.nextInt();
		int r = f.nextInt();
		if(n % 2 == 1 && m % 2 == 1) {
			out.println(exp(exp(r-l+1, n), m));
			out.flush();
			return;
		}
		int even = r/2-(l+1)/2+1;
		int odd = r-l+1-even;
		long[][] mat = {{even, odd},{odd, even}};
		mat = exp(mat, n);
		mat = exp(mat, m);
		out.println(mat[0][0]);
///
		out.flush(); 
	}
	public int MOD = 998_244_353;
	public long[][] mult(long[][] a, long[][] b) {
		long[][] c = new long[a.length][b[0].length];
		for(int i = 0; i < a.length; i++)
			for(int j = 0; j < b[0].length; j++)
				for(int k = 0; k < b.length; k++)
					c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
		return c;
	}
	public long[][] exp(long[][] m, int e) {
		if(e == 1) return m;
		long[][] r = exp(m, e >> 1);
		r = mult(r, r);
		if(e%2 == 1)
			r = mult(r, m);
		return r;
	}
	public long exp(long a, int e) {
		if(e == 1) return a;
		long r = exp(a, e >> 1);
		r = r*r%MOD;
		if(e % 2 == 1)
			r = r*a % MOD;
		return r;
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
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
		long n = f.nextLong();
		int m = f.nextInt();
		long[][] mult = new long[m][m];
		for(int i = 1; i < m; i++)
			mult[i][i-1] = 1;
		mult[0][0] = mult[0][m-1] = 1;
		long[][] start = new long[1][m];
		start[0][0] = 1;
		start = mult(start,exp(mult,n));
		out.println(start[0][0]);
		out.flush();
	}
	public long[][] exp(long[][] a, long exp) {
		if(exp == 1) return a;
		long[][] res = exp(a, exp >> 1);
		res = mult(res,res);
		if((exp & 1) == 1) res = mult(res,a);
		return res;
	}
	public static final long MOD = 1_000_000_007;
	public long[][] mult(long[][] a, long[][] b) {
		long[][] c = new long[a.length][b[0].length];
		for(int i = 0; i < a.length; i++)
			for(int j = 0; j < b[0].length; j++)
				for(int k = 0; k < a[0].length; k++)
					c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
		return c;
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
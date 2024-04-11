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
		long f1 = f.nextLong();
		long f2 = f.nextLong();
		long f3 = f.nextLong();
		long c = f.nextLong();
		long[][] init = {
			{1,0,0},
			{0,1,0},
			{0,0,1}
		};
		long[][] mat = {
			{1,1,1},
			{1,0,0},
			{0,1,0},
		};
		mat = matmul(init, exp(mat, n-3));
		//for(long[] res : mat) out.println(Arrays.toString(res));
		long[][] ainit = {
			{0},
			{0},
			{0},
			{2},
			{1}
		};
		long[][] amat = {
			{1,1,1,1,0},
			{1,0,0,0,0},
			{0,1,0,0,0},
			{0,0,0,1,2},
			{0,0,0,0,1}
		};
		amat = matmul(exp(amat, n-3), ainit);
		long ans = 1;
		MOD++;
		ans = ans * exp(f3, mat[0][0]) % MOD;
		ans = ans * exp(f2, mat[0][1]) % MOD;
		ans = ans * exp(f1, mat[0][2]) % MOD;
		ans = ans * exp(c, amat[0][0]) % MOD;
		out.println(ans);
///
		out.flush(); 
	}
	long MOD = 1_000_000_006;
	public long[][] exp(long[][] m, long e) {
		if(e == 1) return m;
		long[][] res = exp(m, e >> 1);
		res = matmul(res, res);
		if((e & 1) == 1) res = matmul(res, m);
		return res;
	}
	public long exp(long m, long e) {
		if(e == 0) return 1;
		if(e == 1) return m;
		long res = exp(m, e >> 1);
		res = res * res % MOD;
		if((e & 1) == 1) res = res * m % MOD;
		return res;
	}
	public long[][] matmul(long[][] a, long[][] b) {
		long[][] res = new long[a.length][b[0].length];
		for(int i = 0; i < a.length; i++)
			for(int k = 0; k < a[0].length; k++)
				for(int j = 0; j < b[0].length; j++)
					res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
		return res;
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
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
		int n = f.nextInt(); long k = f.nextLong();
		if(k >= n) out.println(0);
		else {
			long[] fact = new long[n+1];
			long[] inv = new long[n+1];
			fact[0] = 1;
			inv[0] = 1;
			for(int i = 1; i <= n; i++) {
				fact[i] = i*fact[i-1]%MOD;
				inv[i] = inv(fact[i],MOD);
			}
			int r = (int) (n-k);
			long ways = 0;
			for(int i = 1; i <= r; i++) {
				long l = fact[r]*inv[r-i]%MOD*inv[i]%MOD*exp(i,n)%MOD;
				if((r-i) % 2 == 1) l *= -1;
				ways = ((l+ways)%MOD+MOD)%MOD;
			}
			if(k == 0)
				out.println(ways*fact[n]%MOD*inv[r]%MOD*inv[n-r]%MOD);
			else out.println(2*ways%MOD*fact[n]%MOD*inv[r]%MOD*inv[n-r]%MOD);
		}
		out.flush();
	}
	long x, y,MOD = 998244353;
	public long exp(long a, long e) {
		if(e == 0) return 1;
		if(e == 1) return a;
		long r = exp(a,e>>1);
		r = r*r%MOD;
		if((e&1) == 1) r = r*a%MOD;
		return r;
	}
	public long inv(long a, long b) {
		x = 0; y = 1;
		gcdExt(a,b);
		return (x%b+b)%b;
	}
	public void gcdExt(long a, long b) {
		if(a*b == 0) return;
		gcdExt(b%a, a);
		long nx = y - b/a*x;
		long ny = x;
		x = nx;
		y = ny;
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
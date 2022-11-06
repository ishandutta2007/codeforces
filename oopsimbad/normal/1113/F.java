import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt();
		f.next(); f.next();
		long[] fact = new long[1000001], inv = new long[1000001];
		fact[0] = inv[0] = 1;
		for(int i = 1; i < fact.length; i++) {
			fact[i] = fact[i-1] * i % MOD;
			inv[i] = inv(fact[i]);
		}
		long ans = 0;
		for(int k = Math.max(0, n-m-1); k <= n-2; k++) {
			long cur = fact[m-1] 
					* inv[n-k-2] % MOD
					* inv[m-1-(n-k-2)] % MOD
					* exp(m, k) % MOD
					* exp(n, k-1) % MOD
					* (n-k) % MOD
					* fact[n-2] % MOD
					* inv[k] % MOD;
			ans = (ans + cur) % MOD;
		}
		out.println(ans);
		out.flush();
	}
	long x, y;
	public long inv(long i) {
		gcd(i, MOD);
		return (x%MOD + MOD) % MOD;
	}
	public void gcd(long a, long b) {
		if(a * b == 0) {
			x = 0;
			y = 1;
			return;
		}
		gcd(b%a, a);
		long nx = y - b/a * x;
		long ny = x;
		x = nx;
		y = ny;
	}
	public long exp(long b, long i) {
		if(i < 0) return inv(exp(b, -i));
		if(i == 0) return 1;
		if(i == 1) return b;
		long l = exp(b, i >> 1);
		l = l*l%MOD;
		if((i & 1) == 1) l = l*b%MOD;
		return l;
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
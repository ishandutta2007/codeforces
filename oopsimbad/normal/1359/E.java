import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	long MOD = 998_244_353;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int k = f.nextInt(), n = f.nextInt();
		long[] fact = new long[k+1];
		long[] inv = new long[k+1];
		inv[0] = 1;
		fact[0] = 1;
		for(int i = 1; i <= k; i++)
			inv[i] = inv(fact[i] = fact[i-1]*i%MOD);
		long ans = 0;
		for(int i = 1; i <= k; i++) {
			int nk = k/i;
			if(nk < n) break;
			ans = (fact[nk-1]*inv[nk-n]%MOD*inv[n-1]%MOD+ans)%MOD;
		}
		out.println(ans);
		out.flush();
	}
    public long inv(long v) {
		gcd(v,MOD);
		return (x%MOD+MOD)%MOD;
	}
	long x, y;
	public void gcd(long a, long b) {
		if(a == 0 || b == 0) {
			x = 0;
			y = 1;
			return;
		}
		gcd(b%a,a);
		long nx = y-b/a*x;
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
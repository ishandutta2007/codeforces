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
		int n = f.nextInt(); long t = f.nextLong();
		long[] arr = new long[n];
		long[] fact = new long[n+1], inv = new long[n+1];
		fact[0] = inv[0] = 1;
		int[] cnt = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = f.nextLong();
			fact[i+1] = fact[i] * (i+1) % MOD;
			inv[i+1] = modInv(fact[i+1]);
			if(i != 0) arr[i] += arr[i-1];
			cnt[i] = (int) Math.min(t-arr[i], i+1);
		}
		long ans = 0;
		long psum = 1;
		int pcnt = 0;
		long cur = 500000004; 
		for(int i = 0; i < n; i++) {
			if(cnt[i] < 0) break;
			while(pcnt < cnt[i]) {
				pcnt++;
				psum = (psum + fact[i+1]*inv[pcnt]%MOD*inv[i+1-pcnt]%MOD)%MOD;
			}
			while(pcnt > cnt[i]) {
				psum = (psum - fact[i+1]*inv[pcnt]%MOD*inv[i+1-pcnt]%MOD+MOD)%MOD;
				pcnt--;
			}
			ans = (ans + cur * psum) % MOD;
			cur = cur * 500000004 % MOD;
			psum = psum * 2 % MOD;
			pcnt++;
			if(cnt[i] != i+1) psum = (psum + fact[i+1]*inv[pcnt]%MOD*inv[i+1-pcnt]%MOD) % MOD;
		}
		out.println(ans);
///
		out.flush(); 
	}
	long MOD = 1000000007, x, y;
	public long modInv(long a) {
		gcd(a, MOD);
		return (x%MOD+MOD)%MOD;
	}
	public void gcd(long a, long b) {
		if(a == 0) {
			x = 0; y = 1;
			return;
		}
		gcd(b%a,a);
		long nx = y - b/a*x;
		long ny = x;
		x = nx;
		y = ny;
		return;
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
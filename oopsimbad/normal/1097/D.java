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
		long n = f.nextLong();
		int k = f.nextInt();
		long[] inv = new long[51];
		for(int i = 1; i <= 50; i++) {
			inv[i] = modInv(i, MOD);
		}
		long[][] probs = new long[50][];
		for(int i = 0; i < 50; i++) {
			probs[i] = new long[i+1];
			Arrays.fill(probs[i], inv[i+1]);
			for(int a = 1; a < k; a++) {
				probs[i][i] = inv[i+1] * probs[i][i] % MOD;
				for(int j = i-1; j >= 0; j--)  {
					probs[i][j] = (probs[i][j] * inv[j+1] % MOD + probs[i][j+1]) % MOD;
				}
			}
		}
		long total = 1;
		long lim = (long) Math.ceil(Math.sqrt(n));
		for(long i = 2; i <= n && i <= lim; i++) {
			int cnt = 0;
			long cur = 0;
			long pow = 1;
			while(n % i == 0) {
				n /= i;
				cnt++;
			}
			if(cnt == 0) continue;
			for(int a = 0; a <= cnt; a++) {
				cur =  (cur + (pow * probs[cnt][a]) % MOD) % MOD;
				pow = (pow * i) % MOD;
			} 
			total = (total * cur) % MOD;
		}
		if(n != 1) {
			int cnt = 1;
			long cur = 0;
			long pow = 1;
			for(int a = 0; a <= cnt; a++) {
				cur =  (cur + (pow * probs[cnt][a]) % MOD) % MOD;
				pow = (pow * n) % MOD;
			} 
			total = (total * cur) % MOD;
		}
		out.println(total);
		out.flush();
	}
	public long modInv(int a, int b) {
		gcd(a,b);
		return ((x % b) + b) % b;
	}
	long x, y;
	public long gcd(int a, int b) {
		if(a == 0 || b == 0) {
			x = 0;
			y = 1;
			return a+b;
		}
		long res = gcd(b%a,a);
		long nx = y - b/a * x;
		long ny = x;
		x = nx;
		y = ny;
		return res;
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
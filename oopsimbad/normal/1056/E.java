import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final long MOD = 1_000_000_007;
	public static final long MULT = 29;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		char[] s = f.next().toCharArray();
		char[] t = f.next().toCharArray();
		long[] hasht = new long[t.length+1];
		long[] pow = new long[t.length+1];
		hasht[0] = 0;
		pow[0] = 1;
		for(int i = 1; i <= t.length; i++) {
			hasht[i] = (hasht[i-1]*MULT + t[i-1]-'a'+1) % MOD;
			pow[i] = pow[i-1]*MULT % MOD;
		}
		int _0 = 0, _1 = 0;
		for(char c : s)
			if(c == '0')
				_0++;
			else 
				_1++;
		int ans = 0;
		for(int len0 = 1; len0*_0 < t.length; len0++) {
			if((t.length-len0*_0) % _1 != 0) continue;
			int len1 = (t.length-len0*_0)/_1;
			boolean seen0 = false, seen1 = false;
			long hash1 = 0, hash0 = 0;
			int i = 0;
			boolean works = true;
			for(char c : s) {
				if(c == '0') {
					if(!seen0) {
						seen0 = true;
						hash0 = (hasht[i+len0] - hasht[i] * pow[len0] % MOD + MOD) % MOD;
					}
					if(hash0 != (hasht[i+len0] - hasht[i] * pow[len0] % MOD + MOD) % MOD) {
						works = false;
						break;
					}
					i += len0;
				} else {
					if(!seen1) {
						seen1 = true;
						hash1 = (hasht[i+len1] - hasht[i] * pow[len1] % MOD + MOD) % MOD;
					}
					if(hash1 != (hasht[i+len1] - hasht[i] * pow[len1] % MOD + MOD) % MOD) {
						works = false;
						break;
					}
					i += len1;
				}
			}
			if(works && hash0 != hash1) ans++;
		}
		out.println(ans);
		out.flush();
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
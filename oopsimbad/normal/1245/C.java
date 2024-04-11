import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static long MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		char[] c = f.next().toCharArray();
		long[] dp = new long[c.length+1];
		dp[0] = dp[1] = 1;
		for(int i = 2; i < dp.length; i++) dp[i] = (dp[i-1] + dp[i-2]) % MOD;
		long ans = 1;
		char curchar = 0;
		int cnt = 0;
		for(int i = 0; i < c.length; i++) {
			if(curchar != c[i]) {
				curchar = 0;
				ans = (ans * dp[cnt]) % MOD;
				cnt = 0;
			}
			if(c[i] == 'm' || c[i] == 'w') ans = 0;
			else if(c[i] == 'n' || c[i] == 'u') {
				curchar = c[i];
				cnt++;
			}
		}
		ans = (ans * dp[cnt]) % MOD;
		out.println(ans);
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
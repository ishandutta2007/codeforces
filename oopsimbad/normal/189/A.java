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
		int n = f.nextInt(), a = f.nextInt(), b = f.nextInt(), c = f.nextInt();
		int[] dp = new int[n+1];
		dp[0] = 1;
		for(int i = 1; i <= n; i++) {
			if(i >= a && dp[i-a] != 0) dp[i] = Math.max(dp[i-a]+1, dp[i]);
			if(i >= b && dp[i-b] != 0) dp[i] = Math.max(dp[i-b]+1, dp[i]);
			if(i >= c && dp[i-c] != 0) dp[i] = Math.max(dp[i-c]+1, dp[i]);
		}
		System.out.println(dp[n]-1);
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

    }
}
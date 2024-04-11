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
		int n = f.nextInt();
		long x = f.nextLong();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextInt();
		long[][][] dp = new long[n+1][3][3];
		for(int i = 0; i < n; i++) {
			//dp[i+1][0][0]
			//dp[i+1][0][1]
			//dp[i+1][0][2]
			dp[i+1][1][0] = Math.max(0, dp[i][1][0]) + arr[i];
			dp[i+1][1][1] = Math.max(0, Math.max(dp[i][1][0], dp[i][1][1])) + arr[i] * x;
			dp[i+1][1][2] = Math.max(Math.max(dp[i][1][0], dp[i][1][1]), dp[i][1][2])  + arr[i];
			dp[i+1][2][0] = Math.max(dp[i][2][0], dp[i+1][1][0]);
			dp[i+1][2][1] = Math.max(dp[i][2][0], dp[i+1][1][1]);
			dp[i+1][2][2] = Math.max(dp[i][2][0], dp[i+1][1][2]);
		}
		long ans = 0;
		for(long[][] a : dp)
			for(long[] b : a)
				for(long c : b)
					ans = Math.max(ans, c);
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
import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = f.nextInt();
		// h = turn, i = nextturn, j = arrind, k = player amts
		int[][][] dp = new int[2][n+1][2];
		dp[0][n][0] = dp[1][n][0] = dp[0][n][1] = dp[1][n][1] = 0;
		for(int i = n-1; i >= 0; i--) {
			if(dp[0][i+1][0] >= dp[1][i+1][0]) {
				dp[0][i][0] = dp[0][i+1][0];
				dp[0][i][1] = dp[0][i+1][1];
			} else {
				dp[0][i][0] = dp[1][i+1][0];
				dp[0][i][1] = dp[1][i+1][1];
			}
			dp[0][i][1] += arr[i];
			if(dp[0][i+1][1] >= dp[1][i+1][1]) {
				dp[1][i][0] = dp[0][i+1][0];
				dp[1][i][1] = dp[0][i+1][1];
			} else {
				dp[1][i][0] = dp[1][i+1][0];
				dp[1][i][1] = dp[1][i+1][1];
			}
			dp[1][i][0] += arr[i];
		}
		if(dp[1][0][1] > dp[0][0][1]) out.println(dp[1][0][0] + " " + dp[1][0][1]);
		else out.println(dp[0][0][0] + " " + dp[0][0][1]);
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
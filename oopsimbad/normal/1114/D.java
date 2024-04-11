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
		int n = f.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextInt();
		int[][] dp = new int[n][n];
		for(int d = 1; d < n; d++) {
			for(int i = 0; i < n-d; i++) {
				int j = i+d;
				dp[i][j] = Math.min(dp[i+1][j] + (arr[i] == arr[i+1] ? 0 : 1), dp[j][i+1] + (arr[i] == arr[j] ? 0 : 1));
				dp[j][i] = Math.min(dp[i][j-1] + (arr[j] == arr[i] ? 0 : 1), dp[j-1][i] + (arr[j] == arr[j-1] ? 0 : 1));
			}
		}
		//for(int[] i : dp)
		//	System.out.println(Arrays.toString(i));
		out.println(Math.min(dp[n-1][0],dp[0][n-1]));
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
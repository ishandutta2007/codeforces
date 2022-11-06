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
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextInt();
		int[][] dp = new int[n][2];
		int[][] map = new int[n][2];
		dp[0][0] = 2147483647; dp[0][1] = -1;
		//0 = inc 		1 = dec
		for(int i = 1; i < n; i++) {
			dp[i][0] = -1; dp[i][1] = 2147483647;
			map[i][0] = map[i][1] = -1;
			if(arr[i-1] < arr[i] && dp[i-1][0] > dp[i][0]) {
				dp[i][0] = dp[i-1][0];
				map[i][0] = 0;
			}
			if(dp[i-1][1] < arr[i] && arr[i-1] > dp[i][0]) {
				dp[i][0] = arr[i-1];
				map[i][0] = 1;
			}
			
			if(arr[i-1] > arr[i] && dp[i-1][1] < dp[i][1]) {
				dp[i][1] = dp[i-1][1];
				map[i][1] = 1;
			}
			if(dp[i-1][0] > arr[i] && arr[i-1] < dp[i][1]) {
				dp[i][1] = arr[i-1];
				map[i][1] = 0;
			}
		}
		int b = -1;
		if(map[n-1][0] != -1) b = 0;
		else if(map[n-1][1] != -1) b = 1;
		if(b == -1) {
			out.println("NO");
			out.flush();
			return;
		}
		out.println("YES");
		int[] ans = new int[n];
		for(int i = n-1; i >= 0; i--) {
			ans[i] = b;
			b = map[i][b];
		}
		for(int i : ans) out.printf("%d ", i);
		out.flush();
	}
/*
9
5 1 3 6 8 2 9 0 10 
*/
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
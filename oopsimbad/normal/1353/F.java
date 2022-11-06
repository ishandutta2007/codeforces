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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt(), m = f.nextInt();
			long[][] mat = new long[n][m];
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					mat[i][j] = f.nextLong();
			long[][] dp = new long[n][m];
			long bestans = Long.MAX_VALUE;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					long s = mat[i][j]-i-j;
					boolean pos = true;
					if(mat[0][0] < s) dp[0][0] = Long.MAX_VALUE;
					else dp[0][0] = mat[0][0]-s;
					for(int a = 0; a < n; a++)
						for(int b = 0; b < m; b++) {
							if(a == 0 && b == 0) continue;
							long min = Long.MAX_VALUE;
							if(a != 0) min = Math.min(dp[a-1][b], min);
							if(b != 0) min = Math.min(dp[a][b-1], min);
							if(mat[a][b] < s+a+b) dp[a][b] = Long.MAX_VALUE;
							else if(min == Long.MAX_VALUE) dp[a][b] = Long.MAX_VALUE;
							else dp[a][b] = mat[a][b]-s-a-b+min;
						}
					bestans = Math.min(bestans, dp[n-1][m-1]);
				}
			}
			out.println(bestans);
		}
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
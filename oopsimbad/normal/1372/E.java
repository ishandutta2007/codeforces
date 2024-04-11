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
		///
        int n = f.nextInt(), m = f.nextInt();
        int[][][] segs = new int[n][m][2];
        for(int i = 0; i < n; i++) {
            int k = f.nextInt();
            for(int j = 0; j < k; j++) {
                int l = f.nextInt()-1, r = f.nextInt()-1;
                for(int a = l; a <= r; a++) {
                    segs[i][a][0] = l;
                    segs[i][a][1] = r;
                }
            }
        }
        int[][] dp = new int[m][m];
        for(int d = 0; d < m; d++) {
            for(int l = 0; l+d < m; l++) {
                int r = l+d;
                for(int k = l; k <= r; k++) {
                    int cnt = 0;
                    for(int a = 0; a < n; a++)
                        if(l <= segs[a][k][0] && segs[a][k][1] <= r) cnt++;
                    dp[l][r] = Math.max(dp[l][r], (k == 0 ? 0 : dp[l][k-1]) + (k == m-1 ? 0 : dp[k+1][r])+cnt*cnt);
                }
            }
        }
        out.println(dp[0][m-1]);
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
		public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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
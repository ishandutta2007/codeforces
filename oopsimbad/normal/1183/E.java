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
		int n = f.nextInt(), k = f.nextInt();
		char[] c = f.next().toCharArray();
		int[][] prev = new int[n+1][26];
		long[][] dp = new long[n+1][n+1];
		int[] rec = new int[26];
		Arrays.fill(rec, -1);
		for(int i = 0; i < n; i++) {
			dp[i][0] = 1;
			for(int j = 0; j < 26; j++)
				prev[i][j] = rec[j];
			rec[c[i]-'a'] = i;
		}
		for(int i = 0; i < 26; i++)
			prev[n][i] = rec[i];
		long[] ans = new long[n+1];
		ans[0] = 1;
		for(int l = 1; l <= n; l++) {
			for(int i = 0; i <= n; i++) {
				for(int a = 0; a < 26; a++)
					if(prev[i][a] != -1) {
						dp[i][l] += dp[prev[i][a]][l-1];
						if(dp[i][l] > k) dp[i][l] = k;
					}
			}
			ans[l] = dp[n][l];
		}
		long total = 0;
		long cnt = 0;
		int j = n;
		while(cnt < k && j >= 0) {
			long add = Math.min(k-cnt, ans[j]);
			cnt += add;
			total += add * (n-j);
			j--;
		}
		if(cnt == k) out.println(total);
		else out.println(-1);
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
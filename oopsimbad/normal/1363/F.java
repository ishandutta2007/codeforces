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
			int n = f.nextInt();
			char[] s = f.next().toCharArray();
			char[] t = f.next().toCharArray();
			int[] cnts = new int[26];
			int[] cntt = new int[26];
			int[] inds = new int[n];
			int[] indt = new int[n];
			for(int i = 0; i < n; i++)
				inds[i] = cnts[s[i]-'a']++;
			for(int i = 0; i < n; i++)
				indt[i] = cntt[t[i]-'a']++;
			boolean ok = true;
			for(int i = 0; i < 26; i++) ok &= cnts[i] == cntt[i];
			if(!ok) {
				out.println(-1);
				continue;
			}
			int[][] dp = new int[n+1][n+1];
			for(int[] i : dp) Arrays.fill(i, n);
			dp[0][0] = 0;
			for(int i = 0; i < n; i++) {
				int min = n;
				int ind = -1;
				for(int j = 0; j <= n; j++) {
					min = Math.min(min, dp[i][j]);
					if(inds[i] <= ind) dp[i+1][j] = Math.min(dp[i+1][j],dp[i][j]+1);
					if(j != n && t[j] == s[i]) {
						dp[i+1][j+1] = Math.min(dp[i+1][j+1],min);
						ind = indt[j];
					}
				}
			}
			out.println(dp[n][n]);
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
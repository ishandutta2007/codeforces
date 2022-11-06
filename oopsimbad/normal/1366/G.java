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
		char[] s = f.next().toCharArray();
		char[] t = f.next().toCharArray();
		int[][] dp = new int[s.length+1][t.length+1];
		for(int[] i : dp) Arrays.fill(i, 2*s.length);
		dp[0][0] = 0;
		for(int i = 0; i < s.length; i++) {
			int skip = -1;
			if(s[i] != '.') {
				int sum = 1;
				for(int j = i+1; j < s.length; j++) {
					if(s[j] == '.') sum--;
					else sum++;
					if(sum == 0) {
						skip = j+1;
						break;
					}
				}
			}
			for(int j = 0; j <= t.length; j++) {
				if(j != t.length && s[i] == t[j]) dp[i+1][j+1] = Math.min(dp[i+1][j+1], dp[i][j]);
				dp[i+1][j] = Math.min(dp[i+1][j], dp[i][j]+1);
				if(skip != -1)
					dp[skip][j] = Math.min(dp[skip][j], dp[i][j]);
			}
		}
		out.println(dp[s.length][t.length]);
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
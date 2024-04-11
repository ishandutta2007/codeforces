import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class F {
	public static void main(String[] args) throws Exception {
		new F().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		long[][] dp = new long[n+1][10];
		for(int i = 0; i < dp.length; i++)
			for(int j = 0; j < 10; j++) dp[i][j] = Long.MIN_VALUE;
		dp[0][0] = 0;
		ArrayList<Long>[] al = new ArrayList[3];
		for(int i = 0; i < 3; i++) al[i] = new ArrayList<>();
		for(int ii = 0; ii < n; ii++) {
			int k = f.nextInt();
			for(int i = 0; i < 3; i++) al[i].clear();
			for(int i = 0; i < k; i++) {
				int a = f.nextInt()-1; long d = f.nextLong();
				al[a].add(d);
			}
			for(int i = 0; i < 3; i++) Collections.sort(al[i]);
			for(int i = 0; i < 10; i++) dp[ii+1][i] = dp[ii][i];
			{
				long max = 0;
				for(int i = 0; i < 3; i++) if(!al[i].isEmpty()) max = Math.max(max, al[i].get(al[i].size()-1));
				for(int i = 0; i < 9; i++) {
					dp[ii+1][i+1] = Math.max(dp[ii+1][i+1],dp[ii][i] + max);
				}
				dp[ii+1][0] = Math.max(dp[ii+1][0], dp[ii][9] + max * 2);
			}
			if(al[0].size() + al[1].size() >= 2 && !al[0].isEmpty()) {
				long max = 0;
				long maxc = 0;
				if(!al[1].isEmpty() && (al[0].size() == 1 || al[0].get(al[0].size()-2) < al[1].get(al[1].size()-1))) {
					max = al[0].get(al[0].size() - 1) + al[1].get(al[1].size() - 1);
					maxc = Math.max(al[0].get(al[0].size() - 1),al[1].get(al[1].size() - 1));
				} else {
					max = al[0].get(al[0].size() - 1) + al[0].get(al[0].size() - 2);
					maxc = al[0].get(al[0].size() - 1);
				}
				for(int i = 0; i < 8; i++) {
					dp[ii+1][i+2] = Math.max(dp[ii+1][i+2], dp[ii][i] + max);
				}
				dp[ii+1][0] = Math.max(dp[ii+1][0], dp[ii][8] + max + maxc);
				dp[ii+1][1] = Math.max(dp[ii+1][1], dp[ii][9] + max + maxc);
			}
			if(al[0].size() >= 3) {
				int m = al[0].size();
				long max = al[0].get(m-3) + al[0].get(m-2) + al[0].get(m-1);
				long maxc = al[0].get(m-1);
				for(int i = 0; i < 7; i++) 
					dp[ii+1][i+3] = Math.max(dp[ii+1][i+3], dp[ii][i] + max);
				dp[ii+1][0] = Math.max(dp[ii+1][0], dp[ii][7] + max + maxc);
				dp[ii+1][1] = Math.max(dp[ii+1][1], dp[ii][8] + max + maxc);
				dp[ii+1][2] = Math.max(dp[ii+1][2], dp[ii][9] + max + maxc);
			}
		}
		long ans = 0;
		for(int i = 0; i < 10; i++)
			ans = Math.max(ans, dp[n][i]);
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
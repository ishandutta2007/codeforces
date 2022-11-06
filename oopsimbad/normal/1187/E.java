import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	ArrayList<Integer>[] adj;
	int[] sz;
	long[][] dp;
	int n;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		n = f.nextInt();
		adj = new ArrayList[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
		for(int i = 0; i < n-1; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		sz = new int[n];
		dp = new long[n][2];
		dfs(0, -1);
		out.println(Math.max(dp[0][0], dp[0][1]));
///
		out.flush(); 
	}
	public void dfs(int i, int p) {
		adj[i].remove((Object) p);
		sz[i] = 1;
		long max = n;
		for(int c : adj[i]) {
			dfs(c, i);
			sz[i] += sz[c];
			dp[i][0] += dp[c][0];
			dp[i][1] += dp[c][0];
			max = Math.max(max, dp[c][1]-dp[c][0]+n-sz[c]);
		}
		dp[i][0] += sz[i];
		dp[i][1] += max;
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
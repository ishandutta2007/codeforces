import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static int MOD = 998244353;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		char[] s = f.next().toCharArray();
		char[] t = f.next().toCharArray();
		int m = t.length;
		int n = s.length;
		int[][] dp = new int[n][n];
		for(int i = 0; i < m; i++)
			if(s[0] == t[i]) dp[i][0] = 2;
		for(int i = m; i < n; i++)
			dp[i][0] = 2;
		int ans = 0;
		for(int d = 1; d < n; d++) {
			for(int j = 0; j <= n-d; j++) {
				if(j != 0 && (j-1 >= m || s[d] == t[j-1]))
					dp[j-1][d] = (dp[j-1][d]+dp[j][d-1]) % MOD;
				if(j+d <= n-1 && (j+d >= m || s[d] == t[j+d]))
						dp[j][d] = (dp[j][d]+dp[j][d-1]) % MOD;
			}
		}
		for(int d = m-1; d < n; d++)
				ans = (ans+dp[0][d])%MOD;
		out.println(ans);
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return -Integer.compare(a, p.a);
		}
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
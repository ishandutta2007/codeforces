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
		int n = f.nextInt(), a = f.nextInt(), b = f.nextInt();
		int[] dp = new int[n+1];
		char[] arr = f.next().toCharArray();
		for(int i = 0; i < n; i++) {
			dp[i+1] = dp[i] + a;
			int[] z = new int[i+1];
			int l = i, r = i;
			for(int j = i-1; j >= 0; j--) {
				if(j >= l) z[j] = Math.min(z[i + j - r], j - l + 1);
				while(j - z[j] >= 0 && arr[i-z[j]] == arr[j-z[j]])
					z[j]++;
				if(j - z[j] + 1 < l) {
					l = j - z[j] + 1;
					r = j;
				}
				dp[i+1] = Math.min(dp[i+1], b + dp[Math.max(j, i - z[j]) + 1]);
				//System.out.println(Arrays.toString(z));
			}
		}
		//System.out.println();
		//System.out.println(Arrays.toString(dp));
		out.println(dp[n]);
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
import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
import java.nio.file.Path;
public class E {
	public static void main(String[] args) throws Exception {
		new E().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int[] arr = new int[n];
		int[] dp = new int[1 << 23];
		for(int i = 0; i < n; i++) {
			arr[i] = f.nextInt();
			dp[~arr[i] & (1 << 23) - 1] = arr[i];
		}
		for(int i = 0; i < 23; i++)
			for(int j = 0; j < 1 << 23; j++)
				if(dp[j] != 0) dp[j & ~(1 << i)] = dp[j];
		for(int i = 0; i < n; i++) {
			out.print(dp[arr[i]] == 0 ? -1 : dp[arr[i]]);
			out.print(" ");
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

    }
}
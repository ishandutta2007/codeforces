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
		int[][] dist = new int[1 << 7][10];
		for(int i = 0; i < dist.length; i++)
			Arrays.fill(dist[i], -1);
		int[] dig = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
		for(int i = 0; i < dist.length; i++) {
			for(int d = 0;d < 10; d++)
				if((dig[d] & i) == i)
					dist[i][d] = Integer.bitCount(dig[d])-Integer.bitCount(i);
		}
		int n = f.nextInt(), k = f.nextInt();
		int[][] dp = new int[n+1][k+1];
		for(int[] a : dp) Arrays.fill(a, -1);
		dp[0][0] = 0;
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[n-i-1] = Integer.parseInt(f.next(), 2); 
		for(int i = 0; i < n; i++) {
			int a = arr[i];
			for(int q = 0; q < 10; q++)
				if(dist[a][q] != -1) 
					for(int j = 0; dist[a][q]+j <= k; j++)
						if(dp[i][j] != -1) dp[i+1][j+dist[a][q]] = q;
		}
		for(int i = n; i > 0; i--) {
			out.print(dp[i][k]);
			if(dp[i][k] == -1) break;
			k -= dist[arr[i-1]][dp[i][k]];
		}
		out.println();
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
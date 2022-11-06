import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class G1 {
	public static void main(String[] args) throws Exception {
		new G1().run();
    }
    int MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = f.nextInt(), t = f.nextInt();
        int[][] dp = new int[1 << n][3];
        int[] tarr = new int[n];
        int[] garr = new int[n];
        for(int i = 0; i < n; i++) {
            tarr[i] = f.nextInt();
            garr[i] = f.nextInt()-1;
            if(tarr[i] <= t) dp[1 << i][garr[i]] = 1;
        }
        int[] time = new int[1 << n];
        for(int i = 0; i < dp.length; i++) {
            for(int bi = 0; bi < n; bi++)
                if((i & 1 << bi) != 0) time[i] += tarr[bi];
        }
        for(int i = 0; i < dp.length; i++) {
            int j = time[i];
                for(int k = 0; k < 3; k++) {
                    if(dp[i][k] == 0) continue;
                    for(int bi = 0; bi < n; bi++)
                        if(tarr[bi] + j <= t && (i & 1 << bi) == 0 && garr[bi] != k) {
                                    dp[i | 1 << bi][garr[bi]] = 
                                        (dp[i | 1 << bi][garr[bi]] + dp[i][k]) % MOD;
                        }
                }
        }
        long ans = 0;
        for(int i = 0; i < dp.length; i++)
            for(int j = 0; j < 3; j++)
            if(time[i] == t) ans = (ans + dp[i][j]) % MOD;
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
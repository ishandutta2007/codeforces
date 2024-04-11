import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class codeforces {
	public static void main(String[] args) throws Exception {
		new codeforces().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
        int[] sieve = new int[5_000_010];
        Arrays.fill(sieve,-1);
        for(int i = 2; i < sieve.length; i++) {
            if(sieve[i] == -1 && sieve.length/i >= i) {
                for(int j = i*i; j < sieve.length; j += i)
                if(sieve[j] == -1)
                sieve[j] = i;
            }
        }
        long[] ans = new long[5000010];
        for(int i = 2; i < ans.length; i++)
            if(sieve[i] == -1)
                ans[i] = 1;
            else
                ans[i] = ans[sieve[i]] + ans[i/sieve[i]]; 
        
        for(int i = 1; i < ans.length; i++)
            ans[i] += ans[i-1];
        int n = f.nextInt();
        while(n-->0)
            out.println(ans[f.nextInt()] - ans[f.nextInt()]);
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
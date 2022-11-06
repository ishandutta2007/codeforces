import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static final long MOD = 998_244_353;
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		long[] arr = new long[n];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextLong();
		for(int i = 1; i < n; i++)
			arr[i] += arr[i-1];
		long sum1 = 0;
		long sum2 = 0;
		long prev = 0;
		for(int i = 0; i < n; i++) {
			long cur = ((sum1 + sum2) % MOD + arr[i]) % MOD;
			sum1 += cur;
			prev = cur;
			sum2 = (sum2 << 1) % MOD;
			sum2 = (sum2 + arr[i]) % MOD;
		}
		out.println(prev);
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
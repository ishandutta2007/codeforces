import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static final int MOD = 1_000_000_007;
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		long[] arr = new long[n];
		int l = 0, r = n-1;
		long lsum = 0, rsum = 0;
		long max = 0;
		for(int i = 0; i < n; i++) 
			arr[i] = f.nextLong();
		while(l <= r) {
			if(lsum == rsum) max = Math.max(max, lsum);
			if(lsum > rsum) {
				rsum += arr[r--];
			} else {
				lsum += arr[l++];
			}
		}
		if(lsum == rsum) max = Math.max(max, lsum);
		out.println(max);
		out.flush();
	}
	class Pair {
		int a;
		long b;
		public Pair(int a, long b) {
			this.a = a;
			this.b = b;
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
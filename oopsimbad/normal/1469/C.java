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
		int asdf = f.nextInt();
    	while(asdf-->0) {
    		int n = f.nextInt();
    		long k = f.nextLong();
    		long[] h = new long[n];
    		for(int i = 0; i < n; i++) h[i] = f.nextLong();
    		long lo = h[0], hi = h[0];
    		boolean ok = true;
    		for(int i = 1; ok && i < n-1; i++) {
    			lo -= k-1;
    			hi += k-1;
    			lo = Math.max(lo, h[i]);
    			hi = Math.min(hi, h[i]+k-1);
    			ok &= hi >= lo;
    		}
			lo -= k-1;
			hi += k-1;
    		ok &= lo <= h[n-1] && h[n-1] <= hi;
    		out.println(ok ? "Yes" : "No");
    	}
		out.flush();
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
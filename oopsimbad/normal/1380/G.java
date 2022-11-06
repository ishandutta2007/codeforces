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
		///
        int n = f.nextInt();
        Long[] arr = new Long[n];
        long MOD = 998244353;
        for(int i = 0; i < n; i++) arr[i] = f.nextLong();
        Arrays.sort(arr);
        long[] psum = new long[n];
        psum[0] = arr[0];
        for(int i = 1; i < n; i++) psum[i] = (arr[i]+psum[i-1])%MOD;
        long inv = inv(n, MOD-2, MOD);
        for(int i = 1; i <= n; i++) {
            long ans = 0;
            int s = n-i-1;
            while(s >= 0) {
                ans = (ans+psum[s])%MOD;
                s -= i;
            }
            out.print(inv*ans%MOD + " ");
        }
///
		out.flush();
	}
    public long inv(long a, long e, long m) {
        if(e == 0) return 1;
        if(e == 1) return a;
        long r = inv(a, e/2, m);
        r = r*r%m;
        if(e%2 == 1) r = r*a%m;
        return r;
    }
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in), 32768);
			tokenizer = null;
		}
		public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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
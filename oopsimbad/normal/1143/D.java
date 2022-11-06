import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		long n = f.nextInt(), k = f.nextInt();
		long a = f.nextInt(), b = f.nextInt();
		long min = n*k, max = 1;
		min = Math.min(min, getMin(a,b,n,k));
		min = Math.min(min, getMin(k-a,b,n,k));
		min = Math.min(min, getMin(a,k-b,n,k));
		min = Math.min(min, getMin(k-a,k-b,n,k));
		max = Math.max(max, getMax(a,b,n,k));
		max = Math.max(max, getMax(k-a,b,n,k));
		max = Math.max(max, getMax(a,k-b,n,k));
		max = Math.max(max, getMax(k-a,k-b,n,k));
		out.println(min + " " + max);
		out.flush();
	}
	public long getMin(long a, long b, long n, long k) {
		long ans = n*k;
		long p = Math.abs(a-b);
		long q = Math.abs(b-a);
		for(int c = 1; c <= n; c++)
			ans = Math.min(ans, Math.min(n*k/gcd(n*k, k*c+p), n*k/gcd(n*k, k*c+q)));
		return ans;
	}
	public long getMax(long a, long b, long n, long k) {
		long ans = 0;
		long p = Math.abs(a-b);
		long q = Math.abs(b-a);
		for(int c = 1; c <= n; c++)
			ans = Math.max(ans, Math.max(n*k/gcd(n*k, k*c+p), n*k/gcd(n*k, k*c+q)));
		return ans;
	}
	public long gcd(long a, long b) {
		if(a*b == 0) return a+b;
		return gcd(b%a, a);
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
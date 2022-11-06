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
			int n = f.nextInt(), q = f.nextInt();
			arr = new Long[n];
			long[] queries = new long[q];
			for(int i = 0; i < n; i++)
				arr[i] = f.nextLong();
			Arrays.sort(arr);
			psum = new long[n];
			psum[0] = arr[0];
			for(int i = 1; i < n; i++)
				psum[i] = psum[i-1] + arr[i];
			s = new HashSet<>();
			for(int i = 0; i < q; i++)
				queries[i] = f.nextInt();
			recur(0, n-1);
			for(long i : queries)
				out.println(s.contains(i) ? "Yes" : "No");
		}
		out.flush();
	}
	Long[] arr;
	long[] psum;
	HashSet<Long> s;
	public void recur(int l, int r) {
		long sum = psum[r];
		if(l != 0) sum -= psum[l-1];
		s.add(sum);
		long v = (arr[l] + arr[r])/2;
		int L = l,R = r+1;
		while(L < R) {
			int M = (L+R)/2;
			if(arr[M] <= v) L = M+1;
			else R = M;
		}
		if(L == l || L-1 == r) return;
		recur(l, L-1); recur(L, r);
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
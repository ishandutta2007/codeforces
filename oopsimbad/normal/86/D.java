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
		int n = f.nextInt(), m = f.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = f.nextInt();
		Query[] q = new Query[m];
		for(int i = 0; i < m; i++) q[i] = new Query(f.nextInt()-1, f.nextInt(), i);
		bucket = (int) Math.sqrt(n);
		Arrays.sort(q);
		int l = 0, r = 0;
		long[] ans = new long[m];
		long[] hm = new long[1000001];
		long[] hmI = new long[1000001];
		long[] temp = new long[1000001];
		long curans = 0;
		int curhmI = 0;
		for(Query qq : q) {
			if(l/bucket < qq.l/bucket) {
				l += bucket;
				r = l;
				curans = 0;
				curhmI++;
			}
			while(r < qq.r) {
				long v = hmI[arr[r]] == curhmI ? hm[arr[r]] : 0;
				hm[arr[r]] = v+1;
				hmI[arr[r]] = curhmI;
				curans += ((v+1)*(v+1)-v*v)*arr[r];
				r++;
			}
			ans[qq.i] = curans;
			for(int ll = l; ll < qq.l; ll++)
				temp[arr[ll]]++;
			
			for(int ll = l; ll < qq.l; ll++) {
				long a = hm[arr[ll]];
				long b = temp[arr[ll]];
				if(b == 0) continue;
				ans[qq.i] += arr[ll]*((a-b)*(a-b) - a*a);
				temp[arr[ll]] = 0;
			}
		}
		for(long ll : ans) out.println(ll);
		out.flush();
	}
	int bucket;
	class Query implements Comparable<Query> {
		int l, r, i;
		public Query(int a, int b, int i) {
			this.l = a;
			this.r = b;
			this.i = i;
		}
		public int compareTo(Query q) {
			int res = Integer.compare(l/bucket, q.l/bucket);
			if(res == 0) res = Integer.compare(r, q.r);
			return res;
		}
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
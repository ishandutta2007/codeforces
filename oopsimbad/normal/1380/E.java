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
		int n = f.nextInt(), q = f.nextInt();
		int[] arr = new int[n];
		par = new int[q]; sz = new int[q]; time = new int[q];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextInt()-1;
		for(int i = 0; i < q; i++) {
			par[i] = i;
			sz[i] = 1;
			time[i] = 2147483647;
		}
		for(int i = 1; i < q; i++) union(f.nextInt()-1, f.nextInt()-1, i);
		int[] ans = new int[q];
		int tot = 0;
		for(int i = 0; i < n-1; i++)
			if(arr[i] != arr[i+1]) {
				int l = 0, r = q;
				while(l < r) {
					int m = (l+r)/2;
					if(find(arr[i], m) == find(arr[i+1], m)) r = m;
					else l = m+1;
				}
				ans[l]++;
				tot++;
			}
		for(int i = 0; i < q; i++) {
			if(i != 0) ans[i] += ans[i-1];
			out.println(tot-ans[i]);
		}
		out.flush();
	}
	int[] par, sz, time;
	public int find(int x, int t) {
		if(time[x] > t) return x;
		if(x == par[x]) return x;
		return find(par[x], t);
	}
	public void union(int x, int y, int t) {
		x = find(x, t); y = find(y, t);
		if(sz[x] < sz[y]) {
			sz[y] += sz[x];
			par[x] = y;
			time[x] = t;
		} else {
			sz[x] += sz[y];
			par[y] = x;
			time[y] = t;
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
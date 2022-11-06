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
		int n = f.nextInt(), k = f.nextInt();
		Integer[] arr = new Integer[n];
		for(int i = 0; i < n; i++) arr[i] = f.nextInt();
		Arrays.sort(arr);
		seg = new long[4*SZ];
		lz = new long[4*SZ];
		int best = 2147483647;
		add(0,1);
		for(int asdf = n-1; asdf >= 0; asdf--) {
			int i = find(1)+1;
			add(i, -1);
			int a = arr[asdf];
			add(i+2, i+2+(a-1)/2, 2);
			if(a%2 == 0) add(i+2+(a-1)/2, 1);
			best = Math.min(best, find(k)+1);
		}
		out.println(best == 2147483647 ? -1 : best);
		out.flush();
	}
	long[] seg, lz;
	int SZ = 1_000_000;
	public void add(int i, long v) { add(1, 0, SZ, i, i+1, v); }
	public void add(int l, int r, long v) {add(1, 0, SZ, l, r, v); }
	public void add(int i, int l, int r, int ql, int qr, long v) {
		if(qr <= l || r <= ql) return;
		if(ql <= l && r <= qr) {
			lz[i] += v;
			return;
		}
		qr = Math.min(r, qr); ql = Math.max(l, ql);
		seg[i] += (r-l)*lz[i] + (qr-ql)*v;
		lz[2*i] += lz[i];
		lz[2*i+1] += lz[i];
		lz[i] = 0;
		int m = (l+r)/2;
		add(2*i, l, m, ql, qr, v);
		add(2*i+1, m, r, ql, qr, v);
	}
	public int find(long v) { return find(1, 0, SZ, v, 0); }
	public int find(int i, int l, int r, long v, long cur) {
		if(cur + seg[i] + lz[i]*(r-l) < v) return 2147483646;
		if(l == r-1) {
			seg[i] += lz[i];
			lz[i] = 0;
			if(cur + seg[i] >= v) return l-1;
			return l;
		}
		seg[i] += (r-l)*lz[i];
		lz[2*i] += lz[i];
		lz[2*i+1] += lz[i];
		lz[i] = 0;
		int m = (l+r)/2;
		if(seg[2*i] + (m-l)*lz[2*i] + cur < v) return find(2*i+1, m, r, v, seg[2*i] + (m-l)*lz[2*i] + cur);
		else return find(2*i, l, m, v, cur);
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
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
		int n = f.nextInt(), k = f.nextInt(), m = f.nextInt();
		seg = new int[8*n]; lz = new int[8*n];
		init(0, 0, 2*n);
		HashSet<Long> hs = new HashSet<>();
		TreeMap<Integer, Integer> tm = new TreeMap<>();
		tm.put(-1, 1);
		int max = 0;
		while(m-->0) {
			int r = f.nextInt(), c = f.nextInt();
			int i = c + Math.abs(k-r)-1;
			if(hs.add(1000000L*r+c)) {
				tm.put(i, tm.getOrDefault(i, 0)+1);
				max = Math.max(max, i);
				add(0, 0, 2*n, 0, i+1, 1);
			} else {
				if(tm.put(i, tm.get(i)-1) == 1) {
					tm.remove(i);
					max = tm.lastKey();
				}
				hs.remove(1000000L*r+c);
				add(0, 0, 2*n, 0, i+1, -1);
			}
			out.println(Math.max(get(0, 0, 2*n, 0, max+1)-n, 0));
		}
///
		out.flush();
	}
	int[] seg, lz;
	public void init(int i, int l, int r) {
		if(l == r-1) seg[i] = l;
		else {
			int m = (l+r)/2;
			init(2*i+1, l, m);
			init(2*i+2, m, r);
			seg[i] = r-1;
		}
	}
	public int add(int i, int l, int r, int ql, int qr, int v) {
		if(ql < l) ql = l;
		if(qr > r) qr = r;
		if(qr <= l || ql >= r) return seg[i]+lz[i];
		if(ql == l && qr == r) {
			lz[i] += v;
			return seg[i]+lz[i];
		} 
		if(l != r-1) {
			lz[2*i+1] += lz[i];
			lz[2*i+2] += lz[i];
			int m = (l+r)/2;
			seg[i] = Math.max(
				add(2*i+1, l, m, ql, qr, v),
				add(2*i+2, m, r, ql, qr, v));
		} else seg[i] += lz[i];
		lz[i] = 0;
		return seg[i];
	}
	public int get(int i, int l, int r, int ql, int qr) {
		if(ql < l) ql = l;
		if(qr > r) qr = r;
		if(qr <= l || ql >= r) return 0;
		if(ql == l && qr == r) return seg[i]+lz[i];
		if(l != r-1) {
			seg[i] += lz[i];
			lz[2*i+1] += lz[i];
			lz[2*i+2] += lz[i];
			lz[i] = 0;
			int m = (l+r)/2;
			return Math.max(get(2*i+1, l, m, ql, qr), get(2*i+2, m, r, ql, qr));
		}
		seg[i] += lz[i];
		lz[i] = 0;
		return seg[i];
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
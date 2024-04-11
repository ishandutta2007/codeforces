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
		seg = new int[4*n+4][2];
		sw = new boolean[4*n+4];
		char[] c = f.next().toCharArray();
		int[] arr = new int[n];
		TreeMap<Integer,Integer> ts = new TreeMap<>();
		BIT b = new BIT(n+1);
		if(c[0] == '<') b.flip(0);
		boolean[] ex = new boolean[n+1];
		ex[0] = ex[n] = true;
		for(int i = 0; i < n; i++) {
			arr[i] = c[i] == '>' ? 1  : 0;
			if(i == 0) {
				b.flip(i);
				ts.put(i,0);
			} else if(arr[i] != arr[i-1]) {
				ex[i] = true;
				int prev = ts.lastKey();
				int nv = ts.get(prev)+i-prev;
				ts.put(prev, nv);
				ts.put(i, i-prev);
				set(0, 0, n+1, prev, nv, b.get(prev));
				b.flip(i);
			}
		}
		{
			int prev = ts.lastKey();
			int nv = ts.get(prev)+n-prev;
			ts.put(prev, nv);
			ts.put(n, n-prev);
			set(0, 0, n+1, prev, nv, b.get(prev));
			b.flip(n);
			set(0, 0, n+1, n, n-prev, b.get(n));
		}
		while(q-->0) {
			int l = f.nextInt()-1, r = f.nextInt();
			swap(0, 0, n+1, l, r+1);
			boolean r1 = ex[l];
			boolean r2 = ex[r];
			if(!r1 && l != 0) {
				ex[l] = true;
				int lo = ts.lowerKey(l);
				int hi = ts.higherKey(l);
				ts.put(lo, ts.get(lo)-hi+l);
				ts.put(hi, ts.get(hi)-l+lo);
				b.flip(l);
				ts.put(l, hi-l);
				set(0, 0, n+1, lo, ts.get(lo), b.get(lo));
				set(0, 0, n+1, hi, ts.get(hi), b.get(hi));
				set(0, 0, n+1, l, ts.get(l), 0);
			} else if(l != 0) {
				int hi = ts.higherKey(l);
				b.flip(l);
				ts.put(l, hi-l);
				set(0, 0, n+1, l, ts.get(l), 0);
			} else b.flip(0);
			if(!r2 && r != n) {
				ex[r] = true;
				int lo = ts.lowerKey(r);
				int hi = ts.higherKey(r);
				ts.put(lo, ts.get(lo)-hi+r);
				ts.put(hi, ts.get(hi)-r+lo);
				b.flip(r);
				ts.put(r, r-lo);
				set(0, 0, n+1, lo, ts.get(lo), b.get(lo));
				set(0, 0, n+1, hi, ts.get(hi), b.get(hi));
				set(0, 0, n+1, r, ts.get(r), 0);
			} else if(r != n) {
				int lo = ts.lowerKey(r);
				b.flip(r);
				ts.put(r, r-lo);
				set(0, 0, n+1, r, ts.get(r), 0);
			}
			out.println(get(0, 0, n+1, l, r+1));
			if(r1 && l != 0) {
				set(0, 0, n+1, l, 0, 0);
				ts.remove(l);
				ex[l] = false;
				int lo = ts.lowerKey(l);
				int hi = ts.higherKey(l);
				ts.put(lo, ts.get(lo)-l+hi);
				ts.put(hi, ts.get(hi)-lo+l);
				set(0, 0, n+1, lo, ts.get(lo), b.get(lo));
				set(0, 0, n+1, hi, ts.get(hi), b.get(hi));
			} else if(!r1 && l != 0) {
				int lo = ts.lowerKey(l);
				ts.put(l, ts.get(l)+l-lo);
				set(0, 0, n+1, l, ts.get(l), b.get(l));
			}
			if(r2 && r != n) {
				set(0, 0, n+1, r, 0, 0);
				ts.remove(r);
				ex[r] = false;
				int lo = ts.lowerKey(r);
				int hi = ts.higherKey(r);
				ts.put(lo, ts.get(lo)-r+hi);
				ts.put(hi, ts.get(hi)-lo+r);
				set(0, 0, n+1, lo, ts.get(lo), b.get(lo));
				set(0, 0, n+1, hi, ts.get(hi), b.get(hi));
			} else if(!r2 && r != n) {
				int hi = ts.higherKey(r);
				ts.put(r, ts.get(r)+hi-r);
				set(0, 0, n+1, r, ts.get(r), b.get(r));
			}
		}
///
		out.flush();
	}
class BIT {
		boolean[] b;
		public BIT(int sz) {
			b = new boolean[sz+5];
		}
		public int get(int i) {
			i++;
			boolean res = false;
			while(i > 0) {
				res ^= b[i];
				i -= i & -i;
			}
			return res ? 1 : 0;
		}
		public void flip(int i) {
			i++;
			while(i < b.length) {
				b[i] ^= true;
				i += i & -i;
			}
		}
	}
	int[][] seg;
	boolean[] sw;
	public void prop(int i, boolean b) {
		if(!sw[i]) return;
		if(!b) {
			sw[2*i+1] ^= true;
			sw[2*i+2] ^= true;
		}
		int t = seg[i][0];
		seg[i][0] = seg[i][1];
		seg[i][1] = t;
		sw[i] = false;
	}
	public void set(int i, int l, int r, int qi, int v, int w) {
		prop(i, l==r-1);
		if(qi < l || qi >= r) return;
		if(l != r-1) {
			int m = (l+r)/2;
			set(2*i+1, l, m, qi, v, w);
			set(2*i+2, m, r, qi, v, w);
			seg[i][0] = Math.max(seg[2*i+1][0], seg[2*i+2][0]);
			seg[i][1] = Math.max(seg[2*i+1][1], seg[2*i+2][1]);
		} else {
			seg[i][0] = seg[i][1] = 0;
			seg[i][w] = v;
		}
	}
	public void swap(int i, int l, int r, int ql, int qr) {
		prop(i, l==r-1);
		if(ql < l) ql = l;
		if(qr > r) qr = r;
		if(qr <= l || ql >= r) return;
		if(ql == l && qr == r) {
			sw[i] = true;
			prop(i, l==r-1);
		} else {
			prop(i, l==r-1);
			int m = (l+r)/2;
			swap(2*i+1, l, m, ql, qr);
			swap(2*i+2, m, r, ql, qr);
			seg[i][0] = Math.max(seg[2*i+1][0], seg[2*i+2][0]);
			seg[i][1] = Math.max(seg[2*i+1][1], seg[2*i+2][1]);
		}
	}
	public int get(int i, int l, int r, int ql, int qr) {
		prop(i, l == r-1);
		if(ql < l) ql = l;
		if(qr > r) qr = r;
		if(qr <= l || ql >= r) return 0;
		if(ql == l && qr == r) return seg[i][0];
		int m = (l+r)/2;
		return Math.max(
			get(2*i+1, l, m, ql, qr),
			get(2*i+2, m, r, ql, qr)
		);
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